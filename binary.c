#include<stdio.h>
int main()
{
int i, n, mid, a[10], key;

printf("Enter size of array:");
scanf("%d",&n);

printf("Enter array elements in sorted form\n");
for(i = 0; i < n; i++)
  {
      printf("Enter element %d: ", i);
      scanf("%d", &a[i]);
      }
       printf("Enter key to search:");
       scanf("%d", &key);
       int high=n-1;
       int low=0;
       while(low <= high)
       {
            mid=(low + high)/2;
            if(key == a[mid])
            {
                printf("Key is present at %d position\n", mid);
                break;
            }
            else if(key > a[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
       }
        
       return 0;
}
            
