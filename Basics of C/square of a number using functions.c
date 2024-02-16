#include<stdio.h>
#include<math.h>

void square(int n);
int main()
{
    int n;
    printf("enter the number whose root is to be calculated\n");
    scanf("%d",&n);
    square(n);
    
}
void square(int y){
    int q;
    q=pow(y,2);
    printf("squre of the number is =%d\n",q);
}
