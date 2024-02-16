#include<stdio.h>
float sum(float *p1,float *p2);
float product(float *p1,float *p2);
float average(float *p1,float *p2);
int main()
{
    float a , b;
    printf("enter the number 1\n");
    scanf("%f",&a);
    printf("enter thye number 2\n");
    scanf("%f",&b);
    
    printf("the sum is =%f\n",sum(&a,&b));
    printf("the product is =%f\n",product(&a,&b));
    printf("the average is =%f\n",average(&a,&b));
    
}

float sum(float *p1,float *p2){
    float i;
    i=*p1+*p2;
    return i;
}

float product(float *p1,float *p2){
    float r;
    r=(*p1)*(*p2);
    return r;
}

float average(float *p1,float *p2){
    float q;
    q=(*p1+*p2)/2;
    return q;
}
