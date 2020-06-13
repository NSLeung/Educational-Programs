#include <stdio.h>
#include <stdlib.h>
// #include "ls_router.h"
#include "list.h"
#include <string.h>
// #include "monitor_neighbors.h"

struct fw_table_entry{
    int destID;
    unsigned int cost;
    int nexthopID;       
    // sequence number     
};

int neighborConnections[256][256];
struct fw_table_entry fw_table[256];

int isConnected(int node1, int node2)
{
    return ((neighborConnections[node1][node2] > 0) && (neighborConnections[node2][node1] > 0));
}

void setConnection(int node1, int node2, int weight)
{
    neighborConnections[node1][node2] = weight;
    neighborConnections[node2][node1] = weight;
}
int getLinkCost(int node1, int node2)
{
    return neighborConnections[node1][node2];
}
void printMatrix(){
    int i, j;
    for(i=0;i<256;i++){
        for(j=0;j<256;j++){
            printf("%d ", neighborConnections[i][j]);
        }
        printf("\n");
    }
}
Node* getNeighbors(int node){
    Node* head = NULL;

    int i;
    for(i=0;i<256;i++){
        if(neighborConnections[node][i] > 0){
            // printf("neighbor %d was found\n", i);
            head = push_(head, i);
        }
    }
    return head;
}

//returns SP_Node with minimum value, NULL if no such minimum was found
SP_Node* get_min(SP_Node* head)
{
    SP_Node *curr = head;
    int d, n;
    int min_cost = __INT_MAX__;
    while(curr!=NULL){
        if(curr->cost < min_cost){
            min_cost = curr->cost;
            d = curr->dest;
            n = curr->nexthop;
        }
        curr = curr->next;
    }
    // printf("min found for <%d, %d, %d>\n", d, min_cost, n);

    SP_Node *ret = find(head, d, min_cost, n, DEFAULT);
    // printf("ret <%d, %d, %d>\n", ret->dest, ret->cost, ret->nexthop);
    return ret;

    //now return location in linked list
    // curr = head;
    // while(curr!=NULL){
    //     if(curr->cost == min_cost){
    //         return curr;
    //     }
    //     curr = curr->next;
    // }
    // return NULL;
}
void printSummary(SP_Node* confirmed, SP_Node* tentative, int level, int d, int c, int n)
{
    printf("---------------------------------------\n");
    printf("LEVEL %d\n", level);
    printf("Inspecting next: <%d, %d, %d>\n", d, c, n);
    printf("CONFIRMED::\n");
    printList(confirmed);
    printf("TENTATIVE::\n");
    printList(tentative);
    // printf("---------------------------------------\n");
}

void dijkstra(int srcnode)
{
    SP_Node* confirmed = NULL; //act as queue by repeatedly inserting at front so we can access faster
    SP_Node* tentative = NULL;    

    //first initialize confirmed with starting node
    confirmed = insert_front(confirmed, srcnode, 0, -1);
    //call it node next
    SP_Node* next_node = confirmed;
    Node* neighborlist;
    
    int cost;
    int next_node_id = srcnode;

    int it_count = 0;

    //while tentative is not empty
    while((isEmpty(tentative) != 1) || (it_count == 0)){
        int next_c, next_n;
        
        // printf("hello\n");
        if(it_count != 0){
            // printf("here's tentative before calling min::\n");
            printList(tentative);
            //make next the node in Tentative with the lowest cost
            next_node = get_min(tentative);
            
            next_node_id = next_node->dest;
            next_c = next_node->cost;
            next_n = next_node->nexthop;
            //remove from tentative
            deleteNode(&tentative, next_node_id, next_c, next_n);
            //add to confirmed
            confirmed = insert_front(confirmed, next_node_id, next_c, next_n);
        }

        next_c = next_node->cost;
        next_n = next_node->nexthop;
        //recalculate neighbor of next
        neighborlist = getNeighbors(next_node_id);
        
        
        printSummary(confirmed, tentative, it_count, next_node_id, next_c, next_n);
        printf("NEIGHBORS of %d: \n", next_node_id);
        printList_(neighborlist);
        printf("\n\n\n");
        //for every neighbor of the next, compute cost to reach neighbors
        while(isEmpty_(neighborlist) != 1){
            
            int curr_neighbor = neighborlist->data;
            // int n_c = fw_table[curr_neighbor].cost;
            // int n_d = fw_table[curr_neighbor].destID;
            // int n_n = fw_table[curr_neighbor].nexthopID;
            int n_c = getLinkCost(next_node_id, curr_neighbor);
            int n_d = curr_neighbor;
            // int n_n = (next_node_id == srcnode) ? n_d : next_node_id;
            int n_n = (next_node_id == srcnode) ? n_d : next_n;

            cost = next_c + n_c;
            printf("inspecting neighbor %d: <%d, %d, %d>\n", curr_neighbor, n_d, cost, n_n );
            //check if neighbor is in tentative and update cost if necessary (just find by id)
            SP_Node* found_t = find(tentative, n_d, cost, n_n, DEST_FLAG);
            printf("TENTATIVE::\n");
            printList(tentative);
            // if(found_t != tentative){
            if(found_t != NULL){
                printf("Node <%d, ?, ?> was found in TENTATIVE\n", found_t->dest);
                if(cost < found_t->cost){
                    printf("new cost %d was found to be cheaper than %d\n", cost, found_t->cost);
                    //update cost
                    found_t->cost = cost;
                    //update next hop
                    // found_t->nexthop = next_node_id;
                    found_t->nexthop = next_n;  //should inherit from previous
                }
            }
            else{
                SP_Node* found_c = find(confirmed, n_d, cost, n_n, DEST_FLAG);
                printf("CONFIRMED::\n");
                printList(confirmed);
                //add neighbor to tentative if not found on either tentative or confirmed
                if(found_c == NULL){
                    printf("<%d,%d, %d> was found not found in either (pushed to tentative now)\n", n_d, cost, n_n);
                    // printf("<%d,%d, %d> was found not found in either (pushed to tentative now)\n", n_d, cost, next_n);

                    tentative = push(tentative, n_d, cost, n_n);
                    // tentative = push(tentative, n_d, cost, next_n);

                }
            }
            //move to next neighbor
            neighborlist = neighborlist->next;
            printf("\n\n\n");
            

        }
        //increment it_count (just for debugging)
            it_count++;
        

    }


}
void test_1()
{
//set up example from class
    memset(neighborConnections, 0, sizeof(neighborConnections[0][0]) * 256 * 256);
    //fw_table represents the actual connections 'up' in the graph
    setConnection(0,1, 5);
    setConnection(1,2, 3);
    setConnection(2,3, 2);
    setConnection(0,2, 10);
    setConnection(1,3, 11);

    // printMatrix();

    
    int globalMyID = 3;
    // fw_table[globalMyID].destID = 2;
    // fw_table[globalMyID].cost = 2

    dijkstra(globalMyID);
}
void test_2(){
    memset(neighborConnections, 0, sizeof(neighborConnections[0][0]) * 256 * 256);
    setConnection(0, 1, 2);
    setConnection(0,3,1);
    setConnection(1,3,2);
    setConnection(1,2,3);
    setConnection(2,3,3);
    setConnection(2,4,1);
    setConnection(3,4,1);
    setConnection(2,5,5);
    setConnection(4,5,2);
    setConnection(0,2,5);

    dijkstra(0);

}
void test_3(){
    memset(neighborConnections, 0, sizeof(neighborConnections[0][0]) * 256 * 256);
    setConnection(0, 1, 4);
    setConnection(0,7,8);
    setConnection(1,7,11);
    setConnection(1,2,8);
    setConnection(7,8,7);
    setConnection(7,6,1);
    setConnection(8,6,6);
    setConnection(2,8,2);
    setConnection(2,3,7);
    setConnection(2,5,4);
    setConnection(6,5,2);
    setConnection(3,5,14);
    setConnection(3,4,9);
    setConnection(4,5,10);

    dijkstra(0);

}

int main(){
    
    test_3();
    return 0;   
}