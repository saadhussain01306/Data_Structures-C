#include <stdio.h>

int main()
{
    int n,i,sum=0;
    printf("enter the number whose table is to be prtinted\n");
    scanf("%d",&n);
    printf("the table is\n");
    for(i=1;i<=10;i++)
    {
        
        printf("%d\n",(n*i));
    }
    return 0;
}
