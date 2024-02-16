#include<stdio.h>
#include<math.h>
void root(float n);
int main()
{
    int n;
    printf("enter the number whose root is to be calculated\n");
    scanf("%d",&n);
    root(n);
}

void root(float y)
{
    printf("the root is %f\n",sqrt(y));
}
