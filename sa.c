#include<stdio.h>
#define MAX 100
int top =-1;
int stack[MAX];
void push(int x){
    if(top>MAX-1){
        printf("stack ooverflow");
        return;
    }
    stack[++top] = x;

}
void pop(){
    if(top==-1){
        printf("stack is empty");
        return;
    }
    top--;
}
void print(){
    if(top==-1){
        printf("stack is empty");
    }else{
        int i;
        for(i=top;i>=0;i--){
            printf("%d ",stack[i]);
        }
    }
}
int peek(){
    if(top==-1)return -1;
    return stack[top];
}
int main() {
    int choice, value;
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:  
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                printf("Pushed %d onto the stack\n", value);
                break;
            
            case 2: pop();
                break;
            
            case 3:  
                value = peek();
                if (value != -1) {
                    printf("Top element is %d\n", value);
                }
                break;
            
            case 4:  
                print();
                break;
            
            case 5: 
                printf("Exiting...\n");
                return 0;
            
            default:
                printf("Invalid choice, please try again.\n");
        }
     }
 }