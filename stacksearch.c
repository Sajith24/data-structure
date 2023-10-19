#include<stdio.h>
int stack[100],choice,n,top,x,i,key,f=0,a[50];
void push(void);
void pop(void);
void display(void);
void search(void);
int main()
{
top=-1;
printf("enter the size:");
scanf("%d",&n);
printf("operations");
printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.SEARCH \n5.EXIT");
printf("\n.....................................");
do
{
printf("\n enetr the choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
push();
break;
}
case 2:
{ 
pop();
break;
}
case 3:
{
display();
break;
}
case 4:
{
search();
break;
}
case 5:
{
printf("exit");
break;
}
default:
{
printf("\n invalid choice");
}}}
while(choice!=5);
return 0;
}
void push()
{ if(top>=n-1)
{
printf("\nstack overflow");
}
else
{
printf("\nenter the value to be printed:");
scanf("%d",&x);
top++;
stack[top]=x;
}}
void pop()
{
if(top<=-1)
{
printf("\nstack underflow");
}
else
{
printf("\nthe popped element is %d",stack[top]);
top--;
}}
void display()
{
if(top>=0)
{
printf("\nelements in stack:");
for(i=top;i>=0;i--)
printf("%d",stack[i]);
printf("\nnext choice:");
}
else
{printf("\nstack is empty");
}}
void search()
{
printf("enter the range:");
scanf("%d",&n);
printf("enter the elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter key:");
scanf("%d",&key);
for(i=0;i<n;i++)
{
if(a[i]==key)
{
f=1;
break;
}}
if(f==1)
{		
printf("num is found");
}
else
{ 
printf("num is not found");
}}
































