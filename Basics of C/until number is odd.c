#include<stdio.h>
int main()
{
    int n ;
    for(;;)
    {
        printf("enter number\n");
        scanf("%d",&n);
       
       
        if(n%2!=0)
        {
            break;
        }
         printf("%d\n",n);
    }
    printf("u have entered an odd number\n");
}
