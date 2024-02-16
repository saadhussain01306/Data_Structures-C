#include<stdio.h>
struct student{
    char name[10];
    int roll;
    float cgpa;
};

void addinfo(struct student *ptr);
void printinfo(struct student *ptr);



int main(){
    struct student s[6];
    struct student *ptr;
    printf("enter the 3 student information\n");
    addinfo(&s[0]);
    printinfo(&s[0]);
}
void addinfo(struct student *ptr)

{
     int i;
    for(i=0;i<3;i++)
    {
        printf("enter the inforamtion of the student %d\n",(i+1));
        printf("enter the name of the student:");
        scanf("%s",ptr->name);
        printf("Enter the roll number of the student:");
        scanf("%d",&ptr->roll);
        printf("enter the student CGPA :");
        scanf("%f",&ptr->cgpa);
        ptr++;
    }
}

void printinfo(struct student *ptr)
{
    int i;
    for(i=0;i<3;i++)
    {
        printf(" \ninforamtion of the student %d\n",(i+1));
        printf(" \nname of the student:");
        printf("%s",ptr->name);
        printf(" \nroll number of the student:");
        printf("%d",ptr->roll);
        printf(" \nthe student CGPA :");
        printf("%f",ptr->cgpa);
        ptr++;
    }
    
}
