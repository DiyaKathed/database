#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *front, *rear, *newnode, *temp;
int ch;

void enqueue()
{
    newnode = malloc(sizeof(struct node));
       
    printf("Enter the data for newnode: ");
    scanf("%d", &(newnode->data)); 
    if(front == NULL)
    {
        front = newnode;
        newnode -> next = NULL;
    }
    else
    {
        rear = front;
        while(rear -> next!= NULL)
        {
            rear = rear -> next;
        }
            rear -> next = newnode;
            newnode -> next = NULL;
     }
}

void dequeue()
{    
    if(front == NULL)
    {
        printf("Empty Queue");
        }
        else
        {
            rear = front;
            front = front -> next;
            rear -> next = NULL;
            printf("Element deleted is %d\n",rear -> data);
            free(rear);
            }
}

void display()
{
    int num = 0;
    rear = front;
    printf("Address of head is: %p\n", &front);
    while (rear != NULL) {
        printf("Address of node: %p\n", rear);
        printf("Data at node: %d\n", rear->data);
        rear = rear->next;
        num++;
    }
    printf("%d Node\n",num); 
}

int main() {
    int choice;
    front = rear = NULL;

    while (1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    enqueue();
                    break;
                }
            case 2:
                {
                    dequeue();
                    break;
                }
            case 3:
                {
                    display();
                    break;
                }
            case 4:
                {
                    return 0;
                }
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
