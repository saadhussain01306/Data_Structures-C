#include<stdio.h>
int main()
{
    int n;
    for(;;)
    {
        printf("enter the number:");
        scanf("%d",&n);
        if(n%7==0)
        {
            break;
        }
        printf("%d\n",n);
    }
    printf("u have entered a multiple of 7\n");
}
