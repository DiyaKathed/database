#include <stdio.h>
#define max 5

int queue[max];
int front = -1, rear = -1;

// Enqueue operation
void enqueue(int element)
{
    if(rear==max-1)
    {
        printf("Queue is full");
    }
    else
    {
        rear++;
        queue[rear]=element;
    }
}

//Dequeue operation
void dequeue()
{
    if(front==rear)
    {
        printf("Queue is empty");
    }
    else
    {
        front++;
        printf("Element deleted is %d",queue[front]);
    }
}

//display operation
void display()
{
    if(front == rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for(int i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("Linear queue menu.\n");
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

