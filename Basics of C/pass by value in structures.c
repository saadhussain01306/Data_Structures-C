#include<stdio.h>



struct student{
         int roll;
         char name[20];
         float cgpa;
     };
     void printdata(struct student s1);

 int main(){
    
     struct student s1={303,"atif",9.9};
     printdata(s1);
 }
 void printdata(struct student x){
     printf("student name is =%s\n",x.name);
     printf("student roll number is =%d\n",x.roll);
     printf("student cgpa =%f\n",x.cgpa);
     
 }
