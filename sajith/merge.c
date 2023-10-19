#include<stdio.h>
void main()
{
int i,n,m,a[30],b[30],c[100],j,k;
printf("enter range:");
scanf("%d",&n);
printf("enter elements:");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
printf("enter range:");
scanf("%d",&m);
printf("enter elements:");
for(j=0;j<m;j++)
{
scanf("%d",&b[j]);
}
i=0;
j=0;
while(i<n&&j<m)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;

}
else
{
c[k]=b[j];
j++;
}
k++;

}
if(i>=n)
{
while(j<m)
{
c[k]=b[j];
j++;
k++;
}}
if(j>=m)
{
while(i<n)
{c[k]=a[i];
i++;
k++;
}}

printf("merged:");
for(i=0;i<m+n;i++)
{
printf("%d",c[i]);
}
}
