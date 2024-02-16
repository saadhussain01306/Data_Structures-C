#include<stdio.h>
int main()
{
    int a=22;
    int *p=&a;
    printf("%u\n",p);
    p++;
    printf("%u\n",p++);
}
