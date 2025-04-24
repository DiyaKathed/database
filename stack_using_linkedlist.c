#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top, *newnode, *temp;
int ch;
void push()
{
    newnode = malloc(sizeof(struct node));
       
    printf("Enter the data for newnode: ");
    scanf("%d", &(newnode->data));  

    newnode->next = top;
    top = newnode;
}

void pop()
{    
    if(top == NULL)
    {
        printf("Empty Stack");
        }
        else
        {
            temp = top;
            top = top -> next;
            temp -> next = NULL;
            free(temp);
            }
}

void display()
{
    temp = top;
    printf("Address of head is: %p\n", &top);
    while (temp != NULL) {
        printf("Address of node: %p\n", temp);
        printf("Data at node: %d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;
    top = NULL;

    while (1) {
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    push();
                    break;
                }
            case 2:
                {
                    pop();
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
