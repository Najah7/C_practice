#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node* next;
    int data;
}Node;

Node* head = NULL;
Node* tail = NULL;

void enqueue(int x)
{
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->next = NULL;
    p->data = x;
    if (tail==NULL) head=p;
    else tail->next=p;
    tail=p;
    return;
}

int dequeue(void)
{
    int retval;
    Node* p;
    if (head==NULL)
    {
    	printf("キューにデータがありません");
        return -1;
    }
    p = head;
    retval = p->data;
    head = p->next;
    free(p);
    return retval;
}

int firstdata_queue(void)
{
    if(head==NULL) return -1;
    else return head->data;
}

void print_queue(void)
{
    Node* p;
    for (p =head; p != NULL; p= p->next)
    {
    	printf("%d\n",p->data);
    }
    return;
}
