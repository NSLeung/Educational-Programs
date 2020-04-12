#ifndef LIST_H
#define LIST_H

#define DEST_FLAG 0
#define DEFAULT 1
typedef struct SP_Node
{
    int dest;
    int cost;
    int nexthop;
    struct SP_Node* next;
} SP_Node;

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

SP_Node* create(int dest_i, int cost_i, int nexthop_i,SP_Node* next);
SP_Node* insert_front(SP_Node* head, int dest_i, int cost_i, int nexthop_i);
SP_Node* push(SP_Node* head, int dest_i, int cost_i, int nexthop_i);
int isEmpty(SP_Node* head);
SP_Node* find(SP_Node* head, int dest_f, int cost_f, int nexthop_f, int opt);
void deleteNode(SP_Node** head, int dest_f, int cost_f, int nexthop_f);
void teardown(SP_Node *head);
void printList(struct SP_Node *SP_Node);

Node* create_(int data,Node* next);
Node* insert_front_(Node* head, int data);
Node* push_(Node* head, int data);
int isEmpty_(Node* head);
Node* find_(Node* head, int data);
void deleteNode_(Node** head, int data);
void teardown_(Node *head);
void printList_(struct Node *node);

#endif