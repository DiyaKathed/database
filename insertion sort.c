#include<stdio.h>
int main()
{
  int a[10];
  int i,j,k,n,temp;
  printf("Enter size of array:");
  scanf("%d",&n);
  for(i = 0; i < n; i++)
  {
      printf("Enter array value at position %d: ", i);
      scanf("%d", &a[i]);
      }
      for(i = 1; i < n; i++)
      {     
           for(j = 0; j < i; j++)
           {
                 if(a[j] > a[i])
                 {
                  temp = a[i];
                  for(k=i; k > j ; k--)
                  {
                     a[k]=a[k-1];
                  } 
                   a[j]= temp;
                 }
          }
      }
      
       printf("Array after sorting: ");
       for(i = 0; i < n; i++) 
       {
           printf("%d ", a[i]);
       }
       printf("\n");

       return 0;
}
  