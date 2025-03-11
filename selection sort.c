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

                    for(i = 0; i < n; i++)
                    {
                        printf("Enter array value at position %d: ", i);
                        scanf("%d", &a[i]);
                    }

                    for(i = 0; i < n-1; i++) 
                    {
                        for(j = i+1; j < n ; j++) 
                        {
                            if(a[i] > a[j])
                            {
                                temp = a[i];
                                a[i] = a[j];
                                a[j] = temp;
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
                    int n, i, j, temp;

                    printf("Enter the string: ");
                    scanf("%s", str);

                    n = strlen(str);

                    for (i = 0; i < n - 1; i++) {
                        for (j = i + 1; j < n; j++) {
                            if (str[i] > str[j]) {
                                temp = str[i];
                                str[i] = str[j];
                                str[j] = temp;
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
