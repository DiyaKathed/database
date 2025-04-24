#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head, *newnode, *temp, *prevnode;
int ch;
void insert_start()
{
    newnode = malloc(sizeof(struct node));
       
    printf("Enter the data for newnode: ");
    scanf("%d", &(newnode->data));  

    newnode->next = head;
    head = newnode;
}

void insert_last()
{
    newnode = malloc(sizeof(struct node));
       
    printf("Enter the data for newnode: ");
    scanf("%d", &(newnode->data)); 
    if(head == NULL)
    {
        head = newnode;
        newnode -> next = NULL;
    }
    else
    {
        temp = head;
        while(temp -> next!= NULL)
        {
            temp = temp -> next;
        }
            temp -> next = newnode;
            newnode -> next = NULL;
     }
}

void delete_first()
{    
    if(head == NULL)
    {
        printf("Empty SLL");
        }
        else
        {
            temp = head;
            head = head -> next;
            temp -> next = NULL;
            free(temp);
            }
}

void delete_last()
{
    if(head == NULL) 
    {
        temp = NULL;
        while(temp -> next != NULL)
        {
           prevnode = temp;
           temp = temp -> next;
           }
           if(head == temp)
           {
               head = NULL;
               free(temp);
               }
               else
               {
                   prevnode = NULL;
                   free(temp);
                   }
         }
 }
    
void display()
{
    int num = 0;
    temp = head;
    printf("Address of head is: %p\n", &head);
    while (temp != NULL) {
        printf("Address of node: %p\n", temp);
        printf("Data at node: %d\n", temp->data);
        temp = temp->next;
        num++;
    }
    printf("%d Node\n",num); 
}

int main() {
    int choice;
    head = NULL;

    while (1) {
        printf("1. Insert at start\n2. Insert at end\n3. Delete firt node\n4. Delete last node\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    insert_start();
                    break;
                }
            case 2:
                {
                    insert_last();
                    break;
                }
            case 3:
                {
                    delete_first();
                    break;
                }
            case 4:
                {
                    delete_last();
                    break;
                }
            case 5:
                {
                    display();
                    break;
                }
            case 6:
                {
                    return 0;
                }
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

