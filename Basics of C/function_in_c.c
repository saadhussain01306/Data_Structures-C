#include<stdio.h>
void sum(int n);
int main()
{
    int n;
    printf("enter the number whose sum is to be calculated\n");
    scanf("%d",&n);
    printf("sum is\n");
    sum(n);
    
}
void sum(int n){
    int x,dsum=0;
    while(n>0)
    {
        x=n%10;
        dsum=dsum+x;
        n=n/10;
    }
    printf("%d\n",dsum);
}
