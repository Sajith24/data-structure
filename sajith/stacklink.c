#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node* next;
};

struct node* top=NULL;

void push(int data)
{
struct node* newnode = (struct node*)malloc(sizeof(struct node));
newnode->data = data;
newnode->next = top;
top = newnode;
printf("\n %d Pushed to the stack",data);
}

int pop()
{
if(top==NULL)
{
printf("\n Stack is empty");
return -1;
}
struct node* temp = top;
int popped = temp->data;
top = top->next;
free(temp);
return popped;
}


void display()
{
struct node* current = top;
if(current == NULL)
{
printf("\n Stack is empty");
return;
}
printf("Stack:");
while(current != NULL)
{
printf("%d",current->data);
current = current->next;
}
printf("\n");
}

int main()
{
int choice,data;
while(1)
{
printf("\nSTACK OPERATIONS:");
printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
printf("\n Enter Your Choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
       printf("Enter data to push");
       scanf("%d",&data);
       push(data);
       break;
case 2:
       printf("%d Popped from Stack\n",pop());
       break;
case 3:
       display();
       break;
case 4:
	exit(0);

default:printf("INVALID CHOICE:");
}
}
}
