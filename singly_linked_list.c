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

void insert_at_position()
{
    int i=1,pos,count = 0;
    printf("Enter the position after which newnode is to be inserted");
    scanf("%d",&pos);
    temp = head;
    while(temp -> next != NULL)
    {
        temp = temp -> next;
        count++;
        }
        if(pos<1 || pos>count)
        {
            printf("Invalid position");
            }
            else
            {
                newnode = malloc(sizeof(struct node));
                printf("Enter the data for newnode: ");
                scanf("%d", &(newnode->data)); 
                temp = head;
                while(i<pos-1)
                {
                    temp = temp -> next;
                    i++;
                    }
                    newnode -> next = temp -> next;
                    temp -> next = newnode;
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
        printf("Empty SLL");
        }
        else
        {
             temp = head;
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
                       prevnode -> next = NULL;
                       free(temp);
                       }
         }
 }
 
void delete_at_position()
{
    int pos, i = 1, count = 0;
    printf("Enter the position to delete node: ");
    scanf("%d", &pos);
    temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
    }
    else
    {
        temp = head;

        if (pos == 1)
        {
            head = temp->next;  
            free(temp);         
            printf("Node deleted at position %d\n", pos);
            return;
        }

        
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }

        prevnode = temp;
        temp = temp->next;  
        prevnode -> next = temp -> next;

        free(temp);

        printf("Node deleted at position %d\n", pos);
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
        printf("1. Insert at start\n2. Insert at end\n3. Insert at a position\n4. Delete first node\n5. Delete last node\n6. Delete at position\n7. Display\n8. Exit\n");
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
                    insert_at_position();
                    break;
                }
            case 4:
                {
                    delete_first();
                    break;
                }
            case 5:
                {
                    delete_last();
                    break;
                }
            case 6:
                {
                    delete_at_position();
                    break;
                }
            case 7:
                {
                    display();
                    break;
                }
            case 8:
                {
                    return 0;
                }
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

