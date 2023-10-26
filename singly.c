#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
int data;
struct node*next;
};


struct node*head=NULL;
void insertfirst()
{
struct node*newnode;
newnode=(struct node*)malloc(sizeof(struct node*));
if(newnode==NULL)
printf("\n no space");
else
{
printf("\n enter the element to be inserted :");
scanf("%d",&newnode->data);
newnode->next=NULL;
if(head==NULL)
head=newnode;
else
{
newnode->next=head;
head=newnode;
}
printf("\n %d inserted into the list", newnode->data);
}
}
void insertlast()
{
struct node*temp,*newnode;
newnode=(struct node*)malloc(sizeof(struct node*));
newnode->next=NULL;
temp=head;
if(newnode==NULL)
printf("\n no space");
else
{
while(temp->next!=NULL)
temp=temp->next;
printf("\n enter the element to be inserted :");
scanf("%d",&newnode->data);
temp->next=newnode;
printf("\n %d inserted into the list", newnode->data);
}}
void insertlocation()
{
int key;
struct node*temp,*newnode;
newnode=(struct node*)malloc(sizeof(struct node*));
newnode->next=NULL;
printf("\nvalue inserted in newnode:");
scanf("%d",&key);
temp=head;
while(temp->data!=key)
{
temp=temp->next;
if(temp==NULL)
break;
}
if(temp==NULL)
{
printf("\nthe %d value not exist",key);
return;
}
if(temp->data==key)
{
if(newnode==NULL)
printf("no space");
else
{
printf("\nenter the element to be inserted:");
scanf("%d",&newnode->data);
newnode->next=temp->next;
temp->next=newnode;
printf("\n%d inserted after %d",newnode->data,key);
}}}
void deletefirst()
{
struct node*temp;
temp=head;
head=temp->next;
printf("\n%d deleted",temp->data);
free(temp);
}
void deletelast()
{
struct node*temp,*prevnode;
temp=head;
while(temp->next!=0)
{
prevnode=temp;
temp=temp->next;
}
prevnode->next=0;
printf("%d deleted",temp->data);
free(temp);
}
void deletelocation()
{
struct node*temp,*prevnode;
int key;
printf("\nenter the value o be deleted:");
scanf("%d",&key);
temp=head;
while(temp->data!=key)
{
prevnode=temp;
temp=temp->next;
if(temp==NULL)
break;
}
if(temp==NULL)
{
printf("\nthe %d value not exist",key);
return;
}
if(temp->data==key)
{printf("%d deleted",temp->data);
if(temp==head)
{
prevnode=head;
head=temp->next;
free(prevnode);
}
else
{
prevnode->next=temp->next;
free(temp);
}}}
void search()
{
struct node*temp;
int key,pos=0;
temp=head;
printf("\n enter the element to be searched:");
scanf("%d",&key);
while(temp->data!=key)
{
temp=temp->next;
pos++;
if(temp==NULL)
break;
}
if(temp==NULL)
{
printf("\n the %d value not exist",key);
return;
}
if(temp->data==key)
{
printf("\n %d value available in location %d",key,pos+1);
}
}
void display()
{
//p-temporary pointer
struct node*p;
if(head==NULL)
printf("list is empty");
else
{
printf("\n element in linked list are:");
p=head;
while(p!=NULL)
{
printf("\t%d",p->data);
p=p->next;
}}}

void main()
{
int choice;
printf("\n SINGLY LINKED LIST");
printf("\n ******************* \n");
do
{
printf("\n\n 1.insertfirst \n2.insertlast \n3.insert specific \n4.deletefirst \n5.delete last \n6.delete specific \n7.search \n8.display \n9.exit");
printf("\n\nenter the choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
{
insertfirst();
break;
}
case 2:
{
insertlast();
break;
}
case 3:
{
insertlocation();
break;
}
case 4:
{
deletefirst();
break;
}
case 5:
{
deletelast();
break;
}
case 6:
{
deletelocation();
break;
}
case 7:
{
search();
break;
}
case 8:
{
display();
break;
}
case 9:
{
printf("exit");
break;
}
default:
{
printf("\n invalid choice");
}}}
while(choice!=9);
return;
}
























