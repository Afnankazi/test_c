#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node * next;
    struct Node * prev;
    
}Node;
Node * createNode(int data){
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data  =data;
    newNode ->next = NULL;
    newNode -> prev =NULL;
    return newNode;
}
void append(Node **head,int data){
    Node* newNode = createNode(data);
    if(*head==NULL){
        *head=newNode;
    }else{
        Node * temp = *head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;
    }
}
void insert_beg(Node **head ,int data){
    Node * newNode = createNode(data);
    if(*head ==NULL){
        *head = newNode;
    }else{
        newNode->next=*head;
        (*head)->prev=newNode;
        *head=newNode;
    }
}
void insert(Node **head,int position){
    int data,i=1;
    printf("enter the data");
    scanf("%d",&data);
    Node * newNode = createNode(data);
    if(position==1){
        insert_beg(head,data);
        return;
    }
    Node * temp = *head;
    while(i<position){
        if(temp==NULL){printf("postion not found ");return;}
        temp=temp->next;
        i++;
    }
    newNode->next=temp->next;
    newNode->prev = temp;
    if(temp->next!=NULL){
        temp->next->prev=newNode;
    }
    temp ->next=newNode;    

}
void delete(Node **head) {
    printf("Enter the position: ");
    int position;
    scanf("%d", &position);

    if (*head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *temp = *head;
    int i = 1;

    // Traverse to the node at the specified position
    while (i < position && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position not found.\n");
        return;
    }

    // If the node to delete is the first node
    if (temp == *head) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else if (temp->next == NULL) {  // If the node to delete is the last node
        temp->prev->next = NULL;
    } else {  // If the node to delete is in the middle
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node at position %d deleted.\n", position);
}

void print_List(Node * head){
    if(head==NULL){
        printf("null");
        return;
    }
    Node * temp = head;
    printf("\nthe elements are \n");
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    return;
}
int main(){
    struct Node * stack = NULL;
    int c=0 ;
    while (c!=6)
    {
        printf("\n\n enter\n1)for add\n2)for print\n3)insert at begining \n4)insert in the middle\n5)delete\n6)exit\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
        printf("");
            int data;
            printf("eneter data \n");
            scanf("%d",&data);
            append(&stack,data);
            break;
        case 2:print_List(stack);break;
        case  3: printf("enter the data to be inserted in the beg :");
                int dat;
                scanf("%d",&dat);
                insert_beg(&stack,dat);
                break;
        case 4: printf("enter the position");
                int pos;
                scanf("%d",&pos);
                insert(&stack,pos);
        case 5: delete(&stack);  break;              
        case 6:break;
        default:break;
        }
    }         
}