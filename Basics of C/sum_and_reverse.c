#include <stdio.h>

int main()
{
    int n,i,j,sum=0;
    printf("enter the number of terms\n");
    scanf("%d",&n);
    printf("reverse is\n");
    
    for(j=n;j>=1;j--)
    {
        sum=sum+j;
        printf("%d\n",j);
    }
    printf("sum=%d\n",sum);
    
    
    
    
}
