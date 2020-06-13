#include <stdio.h>
#include <stdlib.h>

#include "list.h"

// Node* head = NULL;

SP_Node* create(int dest_i, int cost_i, int nexthop_i,SP_Node* next)
{
    SP_Node* new_SP_Node = (SP_Node*)malloc(sizeof(SP_Node));
    if(new_SP_Node == NULL)
    {
        printf("Error creating a new SP_Node.\n");
        exit(0);
    }
    new_SP_Node->dest = dest_i;
    new_SP_Node->cost = cost_i;
    new_SP_Node->nexthop = nexthop_i;
    new_SP_Node->next = next;
 
    return new_SP_Node;
}
SP_Node* insert_front(SP_Node* head, int dest_i, int cost_i, int nexthop_i)
{
    SP_Node* toinsert = create(dest_i, cost_i, nexthop_i, head);
    head = toinsert;
    return head;
}

SP_Node* push(SP_Node* head, int dest_i, int cost_i, int nexthop_i){
    if(head == NULL){
        // printf("starting new list!\n");
        // new element
        head = create(dest_i, cost_i, nexthop_i,NULL);
        
    }
        
    else{
        /* go to the last SP_Node */
        SP_Node *cursor = head;
        while(cursor->next != NULL)
            cursor = cursor->next;
    
        /* create a new SP_Node */
        SP_Node* new_SP_Node =  create(dest_i, cost_i, nexthop_i,NULL);
        cursor->next = new_SP_Node;
    }
 
    return head;
}

int isEmpty(SP_Node* head)
{
    return head==NULL;
}

SP_Node* find(SP_Node* head, int dest_f, int cost_f, int nexthop_f, int opt)
{

    SP_Node* curr = head;
    if(curr==NULL){
        return NULL;
    }
    if(opt == DEST_FLAG){
        while(curr->dest != dest_f){
            if(curr->next == NULL){
                return NULL;
            }
            else{
                curr = curr->next;
            }
        }
    }
    else{
        // printf("default flag here...\n");
        // printf("to find: <%d, %d, %d>\n", dest_f, cost_f, nexthop_f);
        // printf("starting curr: <%d, %d, %d>\n", curr->dest, curr->cost, curr->nexthop);

        while((curr->dest != dest_f) || (curr->cost != cost_f) || (curr->nexthop != nexthop_f)){
            // printf("I'm still in it!\n");
            if(curr->next == NULL){
                return NULL;
            }
            else{
                curr = curr->next;
            }
        }
    }
    // printf("found <%d, %d, %d>\n", curr->dest, curr->cost, curr->nexthop);

    return curr;
}

//delete a link with given key
void deleteNode(SP_Node **head_ref, int dest_f, int cost_f, int nexthop_f) 
{ 
    // Store head node 
    SP_Node* temp = *head_ref, *prev; 
    // If head node itself holds the key to be deleted 
    while((temp != NULL) && (temp->dest == dest_f) && (temp->cost == cost_f) && (temp->nexthop == nexthop_f))
    { 
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while((temp != NULL) && ((temp->dest != dest_f) || (temp->cost != cost_f) || (temp->nexthop != nexthop_f)))
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 

/*
    remove all element of the list
*/
void teardown(SP_Node *head)
{
    SP_Node* curr = head;
    SP_Node* next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    
    // free(head);
}
/* Function to print SP_Nodes in a given linked list. fpitr is used 
   to access the function to be used for printing current SP_Node data. 
   Note that different data types need different specifier in printf() */
void printList(struct SP_Node *SP_Node) 
{ 
    printf("---------------------------\n");
    while (SP_Node != NULL) 
    { 
        // (*fptr)(SP_Node); 
        // printf("dest: %d | cost: %d | nexthop: %d\n", SP_Node->dest, SP_Node->cost, SP_Node->nexthop);
        printf("<dest, cost, nexthop> : <%d, %d, %d>\n", SP_Node->dest, SP_Node->cost, SP_Node->nexthop);
        SP_Node = SP_Node->next; 
    } 
    printf("\\ nothing left to print!\n");
    printf("---------------------------\n");

} 

//node methods
Node* create_(int data,Node* next)
{
    Node* new_Node = (Node*)malloc(sizeof(Node));
    if(new_Node == NULL)
    {
        printf("Error creating a new Node.\n");
        exit(0);
    }
    new_Node->data = data;
    new_Node->next = next;
 
    return new_Node;
}
Node* insert_front_(Node* head, int data)
{
    Node* toinsert = create_(data, head);
    head = toinsert;
    return head;
}

Node* push_(Node* head, int data){
    if(head == NULL){
        // printf("starting new list!\n");
        //new element
        head = create_(data,NULL);
        
    }
        
    else{
        /* go to the last Node */
        Node *cursor = head;
        while(cursor->next != NULL)
            cursor = cursor->next;
    
        /* create a new Node */
        Node* new_Node =  create_(data,NULL);
        cursor->next = new_Node;
    }
 
    return head;
}

int isEmpty_(Node* head)
{
    return head==NULL;
}

Node* find_(Node* head, int data)
{
    Node* curr = head;
    if(curr==NULL){
        return NULL;
    }

    while(curr->data){
        if(curr->next == NULL){
            return NULL;
        }
        else{
            curr = curr->next;
        }
    }
    return curr;
}

//delete a link with given key
void deleteNode_(Node **head_ref, int data) 
{ 
    // printf("head_ref: %d\n", head_ref);
    // printNode(*head_ref);
    // Store head node 
    Node* temp = *head_ref, *prev; 
    // printf("top of deleteNode\n");
    // If head node itself holds the key to be deleted 
    while((temp != NULL) && (temp->data == data))
    { 
        // printf("changed heads\n");
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while((temp != NULL) && (temp->data != data))
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    // If key was not present in linked list 
    if (temp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = temp->next; 
  
    free(temp);  // Free memory 
} 

/*
    remove all element of the list
*/
void teardown_(Node *head)
{
    Node* curr = head;
    Node* next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    
    // free(head);
}
/* Function to print Nodes in a given linked list. fpitr is used 
   to access the function to be used for printing current Node data. 
   Note that different data types need different specifier in printf() */
void printList_(struct Node *Node) 
{ 
    printf("---------------------------\n");

    printf("<");
    while (Node != NULL) 
    { 
        // (*fptr)(Node); 
        printf("%d, ", Node->data);
        Node = Node->next; 
    } 

    printf(">\nnothing left to print!\n");
    printf("---------------------------\n");

} 