#include<stdio.h>

int top , n = 5; 

void push(int a[]) {
    int ele;
    if(top == n - 1) {
        printf("Stack is full\n");
        return;
    } else {
        (top)++;
        printf("Enter an element at position %d: ",top);
        scanf("%d", &ele);
        a[top] = ele;
        printf("Element %d pushed at %d\n", ele, top);
    }
    printf("\n\n");
}

void pop(int a[]) {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    } else {
        printf("Popped element is: %d\n", a[top]);
        (top)--;
    }
    printf("\n\n");
}

void printStack(int a[]) {
    if(top == -1) {
        printf("\nStack is empty\n");
        return;
    } else {
        printf("\nStack elements (top to bottom):\n");
        for(int i = top; i >= 0; i--) {
            printf("Position %d = %d\n", i, a[i]);
        }
    }
    printf("\n\n");
}

int main() {
    int a[5];
    top = -1;     // Initialize top to -1
    int c,j;

    while(1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c) {
            case 1:
                do{
                push(a);  
                printf("Enter 1 to continue pushing:");
                scanf("%d",&j);
                }
                while(j==1);
                break;
            case 2:
                do{
                pop(a);
                printf("Enter 1 to continue popping:");
                scanf("%d",&j);
                }
                while(j==1);
                break;
            case 3:
                printStack(a);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }
    return 0;
}

