#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int dest;
    int cost;
    int nexthop;
    struct Node* next;
} Node;
// Node* head = NULL;
void printNode(Node* node)
{
    printf("dest: %d | cost: %d | nexthop: %d\n", node->dest, node->cost, node->nexthop);

}
/* Function to print nodes in a given linked list. fpitr is used 
   to access the function to be used for printing current node data. 
   Note that different data types need different specifier in printf() */
void printList(struct Node *node) 
{ 
    Node* curr = node;
    while (curr != NULL) 
    { 
        // (*fptr)(node); 
        printNode(curr);
        curr = curr->next; 
    } 
    printf("done printing!\n");
} 
Node* create(int dest_i, int cost_i, int nexthop_i,Node* next)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->dest = dest_i;
    new_node->cost = cost_i;
    new_node->nexthop = nexthop_i;
    new_node->next = next;
 
    return new_node;
}
void insert_front(Node* head, int dest_i, int cost_i, int nexthop_i)
{
    Node* toinsert = (Node*) malloc(sizeof(Node));
    toinsert->dest = dest_i;
    toinsert->cost = cost_i;
    toinsert->nexthop = nexthop_i;

    toinsert->next = head;
    head = toinsert;
}

Node* push(Node* head_ref, int dest_i, int cost_i, int nexthop_i){
    if((head_ref) == NULL){
        printf("starting new list!\n");
        //new element
        (head_ref) = create(dest_i, cost_i, nexthop_i,NULL);
        
    }
        
    else{
        /* go to the last node */
        Node *cursor = head_ref;
        while(cursor->next != NULL)
            cursor = cursor->next;
    
        /* create a new node */
        Node* new_node =  create(dest_i, cost_i, nexthop_i,NULL);
        cursor->next = new_node;
    }
 
    return head_ref;
}

int isEmpty(Node* head)
{
    return head==NULL;
}

Node* find(Node* head, int dest_f, int cost_f, int nexthop_f)
{
    Node* curr = head;
    if(curr==NULL){
        return NULL;
    }

    while((curr->dest != dest_f) && (curr->cost != cost_f) && (curr->nexthop != nexthop_f)){
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
Node* delete(Node* head, int dest_f, int cost_f, int nexthop_f) {

   //start from the first link
   Node* curr = head;
   Node* previous = NULL;
	
   //if list is empty
   if(head == NULL) {
      return NULL;
   }

   //navigate through list
    while((curr->dest != dest_f) && (curr->cost != cost_f) && (curr->nexthop != nexthop_f)){

      //if it is last node
      if(curr->next == NULL) {
         return NULL;
      } else {
         //store reference to current link
         previous = curr;
         //move to next link
         curr = curr->next;
      }
   }

   //found a match, update the link
   if(curr == head) {
      //change first to point to next link
      head = head->next;
   } else {
      //bypass the current link
      previous->next = curr->next;
   }    
	
   return curr;
}

/* Given a reference (pointer to pointer) to the head of a list 
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(Node **head_ref, int dest_f, int cost_f, int nexthop_f) 
{ 
    // printf("head_ref: %d\n", head_ref);
    // printNode(*head_ref);
    // Store head node 
    Node* temp = *head_ref, *prev; 
    // printf("top of deleteNode\n");
    // If head node itself holds the key to be deleted 
    while((temp != NULL) && (temp->dest == dest_f) && (temp->cost == cost_f) && (temp->nexthop == nexthop_f))
    { 
        // printf("changed heads\n");
        *head_ref = temp->next;   // Changed head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while((temp != NULL) && (temp->dest != dest_f) && (temp->cost != cost_f) && (temp->nexthop != nexthop_f))
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
void dispose(Node *head)
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




int main(){
    Node* head = NULL;
    head = push(head, 1, 2, 3);
    head = push(head, 2, 3, 4);
    head = push(head, 5,8, 2);
    // push(head, 1, 2, 3);
    // push(head, 2, 3, 4);
    // push(head, 5,8, 2);
    printList(head);
    // Node* tofind = find(head, 2, 3, 3);
    // printList(head);
    // printNode(tofind);
    printf("here!\n");
    //delete something
    deleteNode(&head, 1, 2, 3);
    // printNode(head);
    printList(head);

    dispose(head);
    // printList(head);

}