#include <stdio.h>
#include <stdlib.h>

// struct packetInfo {
//     int dest;
//     int cost;   //omitting third element just to see how things compile
// };
// typedef packetInfo packetInfo;

struct queueElt{
    // int data;
    // packetInfo data;
    int data1;
    int data2;
    
    struct queueElt *next;
};

//actual queue
struct Queue{
    struct queueElt *front, *end;
};

//creating new queue element
struct queueElt* newElt(int k1, int k2){
    struct queueElt* temp = (struct queueElt* ) malloc(sizeof(struct queueElt));
    temp->data1 = k1;
    temp->data2 = k2;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->end = NULL;
    q->front = q->end;
    return q;
}

void enQueue(struct Queue* q, int k1, int k2)
{
    struct queueElt* temp = newElt(k1, k2);
    //if queue is empty
    if(q->end == NULL){
        q->front = q->end = temp;
        return;
    }
    //add to the end
    q->end->next = temp; 
    q->end = temp;
}

void deQueue(struct Queue* q)
{
    if(q->front == NULL){
        return;
    }
    //remove from the front
    struct queueElt* temp = q->front;
    q->front = q->front->next;


    //if front becomes NULL , then change end to also be NULL
    if(q->front == NULL){
        q->end = NULL;
    }
    //free dynamically allocated memory
    free(temp);
}
void tearDown(struct Queue* q)
{
    struct queueElt *curr = q->front;
    //free each element first
    struct queueElt *next;
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    free(q);
}
int isEmpty(struct Queue* q)
{
    return ((q->front == NULL) && (q->end == NULL));
}

// Driver Program to test above functions 
int main() 
{ 
    struct Queue* q = createQueue(); 
    // deQueue(q); //random check
    enQueue(q, 10, 300); 
    enQueue(q, 20, 200);
    deQueue(q);
    deQueue(q);
    
    // enQueue(q, 20); 
    // deQueue(q); 
    // deQueue(q); 
    // enQueue(q, 30); 
    // enQueue(q, 40); 
    // enQueue(q, 50); 
    // deQueue(q); 
    if(!isEmpty(q)){
    printf("Queue Front : %d. %d \n", q->front->data1, q->front->data2); 
    printf("Queue Rear : %d, %d\n", q->end->data1, q->end->data2); 

    }
    tearDown(q);
    return 0; 
} 
