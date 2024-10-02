#include<stdio.h>
#include<stdlib.h>
typedef struct  Node {
     int data;
     struct Node * next;
}Node;

Node * NOdecreate(int data){
    Node * new = (Node *)malloc(sizeof(Node ));
    new->data=data;
    new->next=NULL;
    return new;
}
void Enqueue(int data,Node * * front){
    Node *n = NOdecreate(data); 
    if(*front==NULL){
        *front = n;
        return;
        
    }else{
          Node *r = * front;
        while (r->next!=NULL)
        {
            r= r->next;
        }
        r->next = n;

        
    }

}
int dequeue(Node **front){
    if(*front==NULL){
        printf("it empty ");
        return -1;
    }
    Node *temp = * front;
    *front = temp->next;
    int d = temp->data;
    free(temp);
    return d;
}