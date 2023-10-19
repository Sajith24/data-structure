#include<stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);
int main()
{
top=-1;
printf("enter the size:");
scanf("%d",&n);
printf("operations");
printf("\n1.PUSH \n2.POP \n3.DISPLAY \n4.EXIT");
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
printf("exit");
break;
}
default:
{
printf("\n invalid choice");
}}}
while(choice!=4);
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
