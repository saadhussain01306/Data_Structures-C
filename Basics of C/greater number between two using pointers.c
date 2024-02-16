#include<stdio.h>
void greater(int*,int*,int*);
int main()
{
    int a,b,f;
    printf("enter the two values\n");
    scanf("%d%d",&a,&b);
    greater(&a,&b,&f);
    if(f==1){
        printf("a>b\n");
    }
   else if(f==2){
       printf("a=b\n");
   }
    else{
        printf("b>a\n");
    }
}
void greater(int *x,int *y,int *z)
{
if(*x>*y){
   *z=1;
}
else if(*x==*y){
    *z=2;
}

else{
    *z=3;
}
}
