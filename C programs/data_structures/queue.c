#include <stdio.h>
#include <stdlib.h>

struct queueElt{
    int data;
    struct queueElt *next;
};

//actual queue
struct Queue{
    struct queueElt *front, *end;
};

//creating new queue element
struct queueElt* newElt(int k){
    struct queueElt* temp = (struct queueElt* ) malloc(sizeof(struct queueElt));
    temp->data = k;
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

void enQueue(struct Queue* q, int k)
{
    struct queueElt* temp = newElt(k);
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

// Driver Program to test above functions 
int main() 
{ 
    struct Queue* q = createQueue(); 
    deQueue(q); //random check
    enQueue(q, 10); 
    enQueue(q, 20); 
    deQueue(q); 
    deQueue(q); 
    enQueue(q, 30); 
    enQueue(q, 40); 
    enQueue(q, 50); 
    deQueue(q); 
    printf("Queue Front : %d \n", q->front->data); 
    printf("Queue Rear : %d", q->end->data); 
    tearDown(q);
    return 0; 
} 
