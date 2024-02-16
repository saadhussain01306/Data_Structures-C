#include <stdio.h>

int main()
{
    int age=22;
    int *p=&age;
    int _age=*p;
   printf("adress of age is =%u\n",&age);//address
   printf("adress of age is =%u\n",p);//adresss using the pointer
   printf("adrees of the pointer itself is =%u\n",&p);//adresss of the pointer itself
   //different format specifiers
   printf("%d\n",age);//age has value 22
   printf("%d\n",*p);// *gives value at address p has ths address of age and * gives the value present at that address
   printf("%d\n",*(&age));// & age stores the address of age and * points at the value present at that address
   
   
    return 0;
}
