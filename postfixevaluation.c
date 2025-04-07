#include<stdio.h>
#include<ctype.h>
int top=-1,i,item,op1,op2,size=10,stack[10],value;
char ch;


void push(int item)
{

if(top==size-1)
{
printf("Stack is Overflow\n");
}
else
{
top+=1;
stack[top]=item;
}
}

int pop()
{
	if(top<0)
	{
	printf("\nStack is empty\n");
	}
	else
	{
	item=stack[top];
	top-=1;
	
	return item;
	}
}
int evalpostfix(char pf[])
{
	for(i=0;pf[i]!=')';i++)
	{
	   ch=pf[i];
	   if(isdigit(ch))
	   {
	   push (ch-'0');
	   }
	   else if(ch=='+'|| ch=='-'|| ch=='*'||ch=='/')
	   {
	   	op1=pop();
	   	op2=pop();
	   	switch(ch)
	   	{
	   	case '*':
	   	{
	   		value=op2*op1;
	   		break;
	   		}
	   	case '/':
	   	{
	   		value=op2/op1;
	   		break;
	   		}	
	   	case '+':
	   	{
	   		value=op2+op1;
	   	
	   		break;
	   		}
	   		
	   	case '-':
	   	{
	   		value=op2-op1;
	   		break;
	   	}
	   	default:
	   	printf("INVALID CHOICE\n");
	   	break;
	   	}
	   	push(value);
	   }
	  
	}
	 printf("Result is  %d \n",pop());
}


int main()
{
char pf[size];
     printf("consider only +,-,*,/\n");
     printf("Enter postfix expression and press')' for end of expression:");

     for(i=0;i<=size-1;i++)
     {
	scanf("%c",&pf[i]);
	if(pf[i]==')')
	{
	break;
	}
     } 
	evalpostfix(pf);
     
     return 0;
}
                 
