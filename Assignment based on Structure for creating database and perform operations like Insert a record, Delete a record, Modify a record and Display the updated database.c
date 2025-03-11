#include <stdio.h>
#include <string.h>

struct Student {  // Structure
    char name[20];
    int roll_no;
};

int main() {
    int i, c, n;
    struct Student a[10];

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);
    printf("\nEnter student details:\n");

    // Input student details
    for(i = 0; i < n; i++) {
        printf("Enter student %d details:\n", i + 1);
        printf("Enter name of student: ");
        scanf("%s", a[i].name);
        printf("Enter roll no of student: ");
        scanf("%d", &a[i].roll_no);
    }

    // Menu loop
    while(1) {
        printf("\n1. Insertion\n2. Deletion\n3. Updation\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        
        switch(c) {
            case 1: {  // Insertion
                int p;
                printf("Enter position (0 to %d) you want to insert: ", n);
                scanf("%d", &p);

                if(p < 0 || p > n) {
                    printf("Invalid position!\n");
                    break;
                }

                // Shift elements to the right
                for(i = n; i > p; i--) {
                    strcpy(a[i].name, a[i - 1].name);
                    a[i].roll_no = a[i - 1].roll_no;
                }

                // Input new student details
                printf("Enter new student details:\n");
                printf("Enter new name: ");
                scanf("%s", a[p].name);
                printf("Enter new roll no: ");
                scanf("%d", &a[p].roll_no);

                n++;  // Increase the student count

                printf("\nStudent details after insertion:\n");
                for(i = 0; i < n; i++) {
                    printf("Student %d: Name: %s, Roll No: %d\n", i + 1, a[i].name, a[i].roll_no);
                }
                break;
            }
            case 2: {  // Deletion
                int b;
                printf("Enter position (0 to %d) you want to delete: ", n - 1);
                scanf("%d", &b);

                if(b < 0 || b >= n) {
                    printf("Invalid position!\n");
                    break;
                }

                // Shift elements to the left
                for(i = b; i < n - 1; i++) {
                    strcpy(a[i].name, a[i + 1].name);
                    a[i].roll_no = a[i + 1].roll_no;
                }

                n--;  // Decrease the student count

                printf("\nStudent details after deletion:\n");
                for(i = 0; i < n; i++) {
                    printf("Student %d: Name: %s, Roll No: %d\n", i + 1, a[i].name, a[i].roll_no);
                }
                break;
            }
            case 3: {  // Updation
                int pos;
                printf("Enter position (0 to %d) of student you want to update: ", n);
                scanf("%d", &pos);

                if(pos < 0 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                pos--;  // Adjust for zero-indexed array
                printf("Enter new name: ");
                scanf("%s", a[pos].name);
                printf("Enter new roll no: ");
                scanf("%d", &a[pos].roll_no);

                printf("\nStudent details after update:\n");
                for(i = 0; i < n; i++) {
                    printf("Student %d: Name: %s, Roll No: %d\n", i + 1, a[i].name, a[i].roll_no);
                }
                break;
            }
            case 4: {  // Display
                printf("\nDisplaying all student details:\n");
                for(i = 0; i < n; i++) {
                    printf("Student %d: Name: %s, Roll No: %d\n", i + 1, a[i].name, a[i].roll_no);
                }
                break;
            }
            case 5: {  // Exit
                printf("Exiting program...\n");
                return 0;
            }
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
