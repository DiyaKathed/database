#include<stdio.h>
#include<string.h>
int main()
{
    int c;
    while(1){
        printf("\n1.Numbers.\n2.String\n3.Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        switch(c){
            case 1:{
                int n, a[10], i, j, k, temp;
                printf("Enter size of array: ");
                scanf("%d", &n);

                for(i = 0; i < n; i++) {
                    printf("Enter array value at position %d: ", i);
                    scanf("%d", &a[i]);
                }

                     for(i = 0; i < n - 1; i++) {
                        for(j = 0; j < n - i - 1; j++) {
                            if(a[j] > a[j + 1]) {
                                temp = a[j];
                                a[j] = a[j + 1];
                                a[j + 1] = temp;
                            }
                        }
                    }

                    printf("Array after sorting: ");
                    for(k = 0; k < n; k++) {
                        printf("%d ", a[k]);
                    }
                    printf("\n");
                    break;
            }
            case 2:{
                    char str[10];
                    int i, j, temp;
    
                    printf("Enter the string: ");
                    scanf("%s", str);
    
                    int n = strlen(str);

                    for(i = 0; i < n - 1; i++) {
                        for(j = 0; j < n - i - 1; j++) {
                            if(str[j] > str[j + 1]) {
                                temp = str[j];
                                str[j] = str[j + 1];
                                str[j + 1] = temp;
                            }
                        }
                    }

                    printf("String after sorting: %s", str);
                    break;
                }
            case 3:{
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
