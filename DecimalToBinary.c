#include<stdio.h>
int stack[100],top=-1;
void push(int rem)
{
if(top>100){
printf("stack is overflow\n");
}
stack[++top]=rem;
}

int pop()
{
if(top<0){
printf("stack underflow");
return -1;
}
return stack[top--];
}

int main()
{
int num,rem;
printf("enter a number to convert it into binary: ");
scanf("%d",&num);
while(num>0)
{
int rem=num%2;
push(rem);
num/=2;
}
printf("Binary number is:");
while(top>=0)
{
printf("%d",pop());
}
printf("\n");
return 0;
}
