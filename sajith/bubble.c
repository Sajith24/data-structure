#include<stdio.h>
void main()
{
int a[50],i,n,j,temp;
printf("enter range:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<n-1;i++)
{
for(j=0;j<n-1-i;j++)
{
if(a[j]>a[j+1])
{
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}}}
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}}
