#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node  *next;
  
};
struct Node * newNode(int data){
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));
    new->data=data;
    new->next=NULL;
    return new;
}

void add(struct Node **head,int data){
    struct Node * new = newNode(data);
    struct Node * temp = *head;
    if(*head==NULL){
     
        *head = new;
    }else{
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=new;
    }

}
void deletnode(struct Node **head,int location){
    if(*head==NULL){
        printf("list is empty");
    return;}
    struct Node * D_node = *head;
    struct Node *temp = *head;
    int i =1;
    while (i<location)
    {
        temp=temp->next;
        i++;
    }
    D_node=temp->next;
    temp->next=D_node->next;
    free(D_node);

    
}
void reverse(struct Node **head) {
    struct Node *prev = NULL;
    struct Node *current = *head;
    struct Node *next = NULL;

    while (current != NULL) {
        // Store the next node
        next = current->next;
        // Reverse the current node's pointer
        current->next = prev;
        // Move pointers one position forward
        prev = current;
        current = next;
    }
    
    // Update the head pointer to the new first node
    *head = prev;
}
void insert_beg(struct Node **head,int data){
    if(*head==NULL){
        *head=newNode(data);
    }
    struct Node * new = newNode(data);
    new->next=*head;
    *head=new;


    
}
void update(struct Node **head,int old ){
    if(*head==NULL){
        printf("list is empty");
        return;
    }
    int new;
    printf("enter the new data :");
    scanf("%d",&new);
    struct Node * temp = *head;
    while (temp->data!=old)
    {
        temp=temp->next;
    }
    temp->data=new;
    

}
void print_list(struct Node *head){
    struct Node *temp = head;
    printf("the values are");
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp = temp->next;
    }
}
int main(){
    struct Node * stack = NULL;
    int c=0 ;
    while (c!=4)
    {
        printf("\n\n enter\n1)for add\n2)for deletion\n3)for display\n4) to exit\n5)to insert at beg\n6)update\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
        printf("");
            int data;
            printf("eneter data \n");
            scanf("%d",&data);
            add(&stack,data);
            break;
        case 2: 
        printf("enter the location of node you want to delete");
        int l;
        scanf("%d",&l);
        deletnode(&stack,l);
            ;break;
        case 3 : print_list(stack); break;
        case 4 : break;
        case 5 : 
            printf("");
            int d;
            printf("eneter data \n");
            scanf("%d",&d);
            insert_beg(&stack,d);
            break;
        case 6: printf("enter the value you want to change");
                int old;
                scanf("%d",&old);
                update(&stack,old);
                break;
        default :printf("worng input");break;
        }
    }
   
    return 0 ;
    
}