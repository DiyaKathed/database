#include<stdio.h>
int main()
{
  int a[10];
  int i,key,n;
  printf("Enter size of array:");
  scanf("%d",&n);
  for(i = 0; i < n; i++)
  {
      printf("Enter array value at position %d: ", i);
      scanf("%d", &a[i]);
      }
       printf("Enter key to search:");
       scanf("%d", &key);
      
      for (i=0; i<n ;i++)
      {
          if(key==a[i])
          { 
               printf("Key found at position %d\n",i);
               break;
           }
       }
   return 0;
   }

