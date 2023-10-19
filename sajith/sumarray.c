#include<stdio.h>
void main()
{
int a[5],i,n,sum=0;
printf("enter the range:");
scanf("%d",&n);
printf("enter the elements:");
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
for(i=0;i<5;i++)
{
sum=sum+a[i];
}
printf("%d",sum);
}
