#include<stdio.h>
struct class{
    char name[20];
    int roll;
    
};
int main(){
 struct class s1={"hello",23};
 struct class *ptr=&s1;
 
printf(" the name\n and roll no\n");
printf("%s \n %d",ptr->name,ptr->roll);

 
 
}
