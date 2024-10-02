#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int f = -1, r = -1;

// Enqueue function to add an element to the queue
void Enqueue(int element) {
    if (r == MAX - 1) { // Check if the queue is full
        printf("Queue is overflowing\n");
        return;
    }
    
    if (f == -1 && r == -1) { // If the queue is initially empty
        f = 0; 
        r = 0;
    } else {
        r++;
    }
    queue[r] = element;
    printf("Inserted %d\n", element);
}

// Dequeue function to remove an element from the queue
void dequeue() {
    if (f == -1) { // Check if the queue is empty
        printf("Queue is empty\n");
        return;
    }

    printf("Removed %d\n", queue[f]);
    if (f == r) { // If the queue has only one element
        f = -1;
        r = -1;
    } else {
        f++;
    }
}
int getfront(){
    if(f==-1){
        printf("queue is emppty");
        return-1;
    }
    return queue[f];
}
int getreare(){
    if(r==-1){
        printf("queue is full");
        return -1;
    }
    return queue[r];
}

// PrintQueue function to display the queue elements
void printqueue() {
    if (f == -1) { // Check if the queue is empty
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");
    for (int i = f; i <= r; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function with menu for queue operations
int main() {
    int c = 1;
    while (c != 4) {
        printf("\nEnter \n1) Enqueue \n2) Dequeue \n3) Print Queue \n4) Exit \n5)get front \n6)getreare \n");
        scanf("%d", &c);

        switch (c) {
        case 1:
            printf("Enter the element: ");
            int e;
            scanf("%d", &e);
            Enqueue(e);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            printqueue();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        case 5:
            printf("%d",getfront());
            break;
        case 6:
            printf("%d",getreare());
            break;         
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
