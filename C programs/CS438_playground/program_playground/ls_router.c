#include <stdio.h>
#include <stdlib.h>
// #include "ls_router.h"
#include "list.h"
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
    return ((neighborConnections[node1][node2] == 1) && (neighborConnections[node2][node1] == 1));
}

void setConnection(int node1, int node2)
{
    neighborConnections[node1][node2] = 1;
    neighborConnections[node2][node1] = 1;
}
Node* getNeighbors(int node){
    Node* head = NULL;

    int i;
    for(i=0;i<256;i++){
        if(neighborConnections[node][i] == 1){
            push_(head, i);
        }
    }
    return head;
}

//returns SP_Node with minimum value, NULL if no such minimum was found
SP_Node* get_min(SP_Node* head)
{
    SP_Node *curr = head;
    int min_cost = __INT_MAX__;
    while(curr!=NULL){
        if(curr->cost < min_cost){
            min_cost = curr->cost;
        }
        curr = curr->next;
    }
    //now return location in linked list
    curr = head;
    while(curr!=NULL){
        if(curr->cost == min_cost){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
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
    while(isEmpty(tentative) != 0){
        if(it_count != 0){
            //make next the node in Tentative with the lowest cost
            next_node = get_min(tentative);
            next_node_id = next_node->dest;
            //remove from tentative
            deleteNode(tentative, next_node->dest, next_node->cost, next_node->nexthop);
            //add to confirmed
            confirmed = insert_front(confirmed, next_node->dest, next_node->cost, next_node->nexthop);
        }
        int next_c = next_node->cost;
        int next_n = next_node->nexthop;
        //recalculate neighbor of next
        neighborlist = getNeighbors(next_node_id);
        //for every neighbor of the next, compute cost to reach neighbors
        while(isEmpty_(neighborlist) != 0){
            int curr_neighbor = neighborlist->data;
            int n_c = fw_table[curr_neighbor].cost;
            int n_d = fw_table[curr_neighbor].destID;
            int n_n = fw_table[curr_neighbor].nexthopID;
            cost = next_c + n_c;
            //check if neighbor is in tentative and update cost if necessary
            SP_Node* found_t = find(tentative, n_d, n_c, n_n);
            if(found_t != tentative){
                if(cost < found_t->cost){
                    //update cost
                    found_t->cost = cost;
                    //update next hop
                    found_t->nexthop = next_node;
                }
            }
            else{
                SP_Node* found_c = find(confirmed, n_d, n_c, n_n);
                //add neighbor to tentative if not found on either tentative or confirmed
                if(found_c == confirmed){
                    tentative = push(tentative, n_d, n_c, n_n);
                }
            }
            //move to next neighbor
            neighborlist = neighborlist->next;
            //increment it_count (just for debugging)
            it_count++;

        }

    }


}

int main(){
    
}