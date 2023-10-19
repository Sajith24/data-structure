#include<stdio.h>
void main()
{
int i,n,a[50],key,f=0;
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
