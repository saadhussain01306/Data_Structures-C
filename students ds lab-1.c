#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[10];
    int reg_no;
    int marks[3];
    float avg;
};



void read(struct student *p,int n){
    for(int i=0;i<n;i++){
        printf("Enter the details of the student %d\n",(i+1));
        printf("Enter the name of the student: ");
        scanf("%s",(p+i)->name);
        printf("\nenter the Reg_No of the student: ");
        scanf("%d",&(p+i)->reg_no);
        for(int j=0;j<3;j++){
        printf("\nEnter the marks in test-%d:",(j+1));
        scanf("%d",&(p+i)->marks[j]);
        
        }
        printf("\n\n");
        
    }
}

void avg(struct student *p,int n){
   int i,j,k,temp,sum[n];
    
   for(int i=0;i<n;i++){
       for(j=0;j<3;j++){
           for(k=0;k<(3-j-1);k++){
               if((p+i)->marks[j]>(p+i)->marks[j+1]){
                   temp=(p+i)->marks[j];
                   (p+i)->marks[j]=(p+i)->marks[j+1];
                   (p+i)->marks[j+1]=temp;
               }
           }
       }
   }
   
   for(i=0;i<n;i++){
       sum[i]=(p+i)->marks[1]+(p+i)->marks[2];
       printf("Average of the two best marks of student %d is %f\n",(i+1),(float)(sum[i]/2.0));
   }
    
}
void display(struct student *p,int n)
{
for(int i=0; i<n; i++)
{
printf("\nDetails for student %d",i+1);
printf("\nName:\t"); printf("%s",(p+i)->name);
printf("\nRoll no:\t"); printf("%d",(p+i)->reg_no);
for(int j=0; j<3; j++)
{
printf("\nMarks in test %d:\t",j+1);
printf("%d",(p+i)->marks[j]);
}
printf("\n\n");
}
}

int main(){
    int n;
   
    printf("Enter the number of students whose inforamtion is to be displayed\n");
    scanf("%d",&n);
     struct student *p;
    p=(struct student *)malloc(n*sizeof(struct student));
    
    read(p,n);
    display(p,n);
    avg(p,n);
}
