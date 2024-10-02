#include<Stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
    /* data */
};
void push(struct Node **top,int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next =*top;
 
    *top = newNode;


}
int pop(struct Node **top){
    if(top==NULL){
        printf("stack is empty");
        return -1;
    }
    struct Node *t = *top;
    int temp = t->data;
    *top  = (*top)->next;                                       
    free(t);
    return temp;
}
int peek(struct Node * top){
    if(top==NULL) return -1 ;
    return top->data;
}
void Display(struct Node *top){
    printf("\nthe elements are \n");
    if(top==NULL){ printf("stack is empty");}
    struct Node *temp = top;
    while(temp!=NULL){
        
        printf("%d \n",temp->data);
        temp = temp->next;
    }
}  
/// @brief 
/// @return 
int main(){
    struct Node * stack = NULL;
    int c=0 ;
    while (c!=4)
    {
        printf("\n\n enter\n1)for push\n2)for pop\n3)for display\n4) to exit\n5)to peek\n");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
        printf("");
            int data;
            printf("eneter data \n");
            scanf("%d",&data);
            push(&stack,data);
            break;
        case 2: printf("elemet %d is poped",pop(&stack));break;
        case 3 : Display(stack); break;
        case 4 : break;
        case 5 : if(peek(stack)==-1){
            printf("stack is empty");
        }else{
            printf("the top most element is :%d",peek(stack));
        };break;
        default:
            printf("eneter coorect option");
            break;
        }
    }
   
    return 0 ;
}

