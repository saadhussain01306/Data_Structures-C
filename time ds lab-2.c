#include<stdio.h>
#include<stdlib.h>

typedef struct Time{
    int second;
    int minute;
    int hour;
}time;

time * read(time *p){
    printf("Enter the hours: ");
    scanf("%d",&p->hour);
     printf("\n");
    printf("Enter the minutes: ");
    scanf("%d",&p->minute);
     printf("\n");
    printf("Enter the seconds: ");
    scanf("%d",&p->second);
     printf("\n");
    
    if(p->hour>23 ||  p->hour<0 || p->minute>59 || p->minute<0 || p->second>59 || p->second<0){
        printf("Enter the valid time\n");
        
    }
    else{
        return p;
        
    }
    
}

void display(time *p){
    printf("THE time is : %d:%d:%d\n",(p->hour),(p->minute),(p->second));
}

time * update(time *p){
    p->second+=1;
    if(p->second>59){
        p->second=00;
        p->minute+=1;
    }
    if(p->minute>59){
        p->minute=00;
        p->hour+=1;
    }
    if(p->hour>23){
        p->hour=00;
    }
    
    return p;
}

void addTime(time one ,time two){
    printf("Enter the time u need to add\n");
    printf("enter Time-1 hour:-");
    scanf("%d",&one.hour);
    printf("\n");
    printf("enter Time-1 minute:-");
    scanf("%d",&one.minute);
     printf("\n");
    printf("enter Time-1 seconds:-");
    scanf("%d",&one.second);
     printf("\n\n");
     
     printf("enter Time-2 hour:-");
    scanf("%d",&two.hour);
    printf("\n");
    printf("enter Time-2 minute:-");
    scanf("%d",&two.minute);
     printf("\n");
    printf("enter Time-2 seconds:-");
    scanf("%d",&two.second);
     printf("\n\n");
     
    time add;int day = 0;
add.second = one.second + two.second;
add.minute = one.minute + two.minute;
add.hour = one.hour + two.hour;
if(add.second > 59)
{
add.minute += (add.second/60);
add.second = (add.second%60);
}
if(add.minute > 59)
{
add.hour += (add.minute/60);
add.minute = (add.minute%60);
}
if(add.hour > 23)
{
day += (add.hour/24);
add.hour = (add.hour%24);
}
printf("\nResultant time after adding the above inputted two times is...\n");
printf("\n%d Days:%d hours: %d minutes:%d seconds\n",day,add.hour,add.minute,add.second);
     
     
     
     
    
}



int main()
{
    printf("Hello\n");
    time *q;
    q=(time *)malloc(sizeof(time));
    time T1;
    time T2;
    int choice;
    
    while(1)
    {
    printf("Enter choice:\n");
    printf("1.Read\n2.update\n3.display\n4.Add\n5.exit\n");
    scanf("%d",&choice);
    
    switch(choice){
        case 1: q=read(q);
               display(q);
               break;
                
                case 2: q=update(q);
                        display(q);
                        break;
                        
                        case 3: display(q);
                                break;
                                case 4: addTime(T1,T2);
                                       
                                        break;
                                        case 5:exit(0);
                                        break;
                                        
                                        default:printf("Bhai menu theek se padh\n");
                                        break;
                                        
                                        
    }
    
    
    
    }
}
