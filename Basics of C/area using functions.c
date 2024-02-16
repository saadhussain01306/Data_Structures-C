#include<stdio.h>
float circle(float a);
float rectangle(float b,float c);
float square(float d);
int main()
{
    float a,b,c,d;
    printf("enter the radius of the circle\n");
    scanf("%f",&a);
    printf("the area of the circle is =%f\n",circle(a));
    printf("enter the sides of the rectangle\n");
    scanf("%f%f",&b,&c);
    printf("the area of the rectangle is =%f\n",rectangle(b,c));
    printf("entewr the sides of the square\n");
    scanf("%f",&d);
    printf("area of the squre is =%f\n",square(d));
    
    
}

float circle(float a){
    return (3.14*a*a);
}

float rectangle(float b,float c){
    return (b*c);
}

float square(float d){
    return (d*d);
}
