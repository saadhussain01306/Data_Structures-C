#include<stdio.h>
void calculateprice(float value);
int main()
{
    float value=122.45;
    calculateprice(value);
    printf("the value is=%f\n",value);
    
}

void calculateprice(float value)
{
    value=value+(0.18*value);
    printf("the final value is =%f\n",value);
}
