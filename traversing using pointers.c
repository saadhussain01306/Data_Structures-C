#include <stdio.h>

int main()
{
   int i,a[10],*p,n;
   p=a;
   printf("enter the n value\n");
   scanf("%d",&n);
   printf("enter the array elements \n");
   for(i=0;i<n;i++)
   {
       scanf("%d",(p+i));
   }
   printf("entered array elements are\n");
   for(i=0;i<n;i++)
   {
       printf("%d\n",*(p+i));
   }
}
