#include <stdio.h>
#define size 5 

int queue[size];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int element) {
    if ((rear + 1) % size == front) {
        printf("Queue is full\n");
    } else if (rear == -1 && front == -1) {
        front = 0, rear = 0;
        queue[rear] = element;
    } else {
        rear = (rear + 1) % size;
        queue[rear] = element;
    }
}

// Dequeue operation
void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("%d is deleted\n", queue[front]);
        front = -1,rear = -1;
    } else {
        printf("%d is deleted\n", queue[front]);
        front = (front + 1) % size;
    }
}

// Display operation
void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are: ");
        
        while (1) {
            printf("%d ", queue[front]);
            if (front == rear) break;
            front = (front + 1) % size;
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("Circular queue menu.\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
return 0;
}

