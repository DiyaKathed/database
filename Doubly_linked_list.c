#include<stdio.h>
#include<stdlib.h>
#define size 5

struct node
{
    int data;
    struct node *next;
    struct node *prev;
    };
    struct node *head, *newnode, *temp, *prev, *prevnode;
    
void insert_start()
{
    newnode = malloc(sizeof(struct node));
       
    printf("Enter the data for newnode: ");
    scanf("%d", &(newnode->data));  
    if(head == NULL)
    {
        head = newnode;
        newnode -> prev = head;
        newnode -> next = NULL;
        }
        else
        {
            newnode -> next = head;
            head -> prev = newnode;
            head = newnode;
            newnode -> prev = NULL;
            }
}

void insert_last()
{
    newnode = malloc(sizeof(struct node));
       
    printf("Enter the data for newnode: ");
    scanf("%d", &(newnode->data)); 
    if(head == NULL)
    {
        head = newnode;
        newnode -> prev = NULL;        
        newnode -> next = NULL;
    }
    else
    {
        temp = head;
        while(temp -> next!= NULL)
        {
            temp = temp -> next;
        }
            newnode -> next = NULL;
            temp -> next = newnode;
            newnode -> prev = temp;
     }
}

void insert_at_position()
{
    int i=1,pos,count = 0;
    printf("Enter the position after which newnode is to be inserted:");
    scanf("%d",&pos);
    
    newnode = malloc(sizeof(struct node));
    printf("Enter the data for newnode: ");
    scanf("%d", &(newnode->data)); 
    
    if(head == NULL)
    {
        head = newnode;
        newnode -> next = NULL;
        newnode -> prev = NULL;
        }
        else{
                temp = head;
                while(temp != NULL)
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
                    i = 1;
                    temp = head;
                    while(i<pos-1)
                    {
                        temp = temp -> next;
                        i++;
                    }
                    newnode -> next = temp -> next;
                    temp -> next -> prev = newnode;
                    temp -> next = newnode;
                    newnode -> prev = temp;
               }
           }
}
    
void delete_first()
{    
    if(head == NULL)
    {
        printf("Empty DLL");
        }
        else if(head -> next == NULL)
        {
            temp = head;
            head = NULL;
            free(temp);
            }
        else
        {
            temp = head;
            head = head -> next;
            temp -> prev = NULL;
            temp -> next = NULL;
            free(temp);
            }
}

void delete_last()
{
    temp = head;
    while(temp -> next != NULL)
    {
        prevnode = temp;
        temp = temp -> next;
        }
        if(head == NULL) 
        {
            printf("Empty SLL");
        }
        else if(temp == head)
        {
            head = NULL;
            free(temp);
        }
        else
        {
            prevnode -> next = NULL;
            temp -> prev = NULL;
            temp -> next = NULL;
            free(temp);
        }
 }
 
void delete_at_position()
{
    int pos, i = 1, count = 0;
    printf("Enter the position to delete node: ");
    scanf("%d", &pos);
    temp = head;
    while (temp -> next != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
    }
    else if(pos == 1)
    {
        delete_first( );
    }
    else if(pos == count)
    {
        delete_last();
    }
    else
    {
        temp = head;

        while (i < pos)
        {
            prevnode = temp;
            temp = temp->next;
            i++;
        } 
        prevnode -> next = temp -> next;
        temp -> next -> prev = prevnode;
        temp -> prev = NULL;
        temp -> next = NULL;
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
        printf("Address of prevnode :%p\n",&(temp -> prev));
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

