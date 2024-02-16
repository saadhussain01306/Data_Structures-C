#include<stdio.h>
int main()
{
    int n,value,i,pos,a[20];
    printf("enter the n value\n");
    scanf("%d",&n);
    printf("enter the arry elements \n");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the position at which the elemnt is inserte\n");
    scanf("%d",&pos);
    printf("enter the element to be inserted\n");
    scanf("%d",&value);
    for(i=n-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=value;
    printf("insertewd array is\n");
    for(i=0;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
}
