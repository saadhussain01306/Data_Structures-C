#include<stdio.h>
int main()
{
    int i,fact=1,n;
    printf("enter the number whose factorial is to be calculated\n");
    scanf("%d",&n);
    printf("factorial is:");
    for(i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    printf("%d",fact);
}
