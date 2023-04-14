#include<stdio.h>
#include<stdlib.h>

typedef struct Time{
    int minute;
    int second;
    int hour;
}time;

time* read(time *p){
    
    
    printf("Enter the hours\n");
    scanf("%d",&p->hour);
    printf("Enter the minutes\n");
    scanf("%d",&p->minute);
    printf("Enter the seconds\n");
    scanf("%d",&p->second);
    
    if(p->hour<0 || p->hour>24 || p->minute>59 || p->minute<0 ||p->second>59 ||p->second<0){
        printf("Enter a valid time\n");
    }
    
    else{
        return p;
    }
}

void display(time *p){
    printf("Hours:%d\nminutes:%d\nseconds:%d\n",p->hour,p->minute,p->second);
}

time* update(time *p){
    p->second+=1;
    
    if(p->second>59){
        p->second=00;
        p->minute+=1;
    }
    
    if(p->minute>59){
        p->minute=00;
        p->hour+=1;
    }
    if(p->hour>24){
        p->hour=00;
    }
    
    return p;
}

void addTime(time one,time two){
    printf("Enter the time you need to add\n");
    printf("Time-1\n");
    printf("Hours\n");scanf("%d",&one.hour);
    printf("Minutes\n");scanf("%d",&one.minute);
    printf("Seconds\n");scanf("%d",&one.second);
    
    printf("\n\n");
    printf("Time-2\n");
    printf("Hours\n");scanf("%d",&two.hour);
    printf("Minutes\n");scanf("%d",&two.minute);
    printf("Seconds\n");scanf("%d",&two.second);
    
    time add;int day=0;
    add.hour=one.hour+two.hour;
    add.minute=one.minute+two.minute;
    add.second=one.second+two.second;
    
    if(add.second>59){
        add.minute+=((add.second)/60);
        add.second=((add.second)%60);
    }
    if(add.minute>59){
        add.hour+=((add.minute)/60);
        add.minute=((add.minute)%60);
    }
    if(add.hour>23){
        day+=((add.hour)/24);
        add.hour=((add.hour)%24);
    }
    
    printf("The time after the adding is \n");
    printf("Day:%d\nHour:%d\nMinute:%d\n,Second:%d\n",day,add.hour,add.minute,add.second);
    
}

void main(){
    time *p;
    p=(time *)malloc(sizeof(time));
    time T1,T2;
    int choice;
    while(1){
        printf("1.Read\n2.Display\n3.Update\n4.Add two Times\n5.Exit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:p=read(p);
                   break;
            case 2:display(p);
                   break;
            case 3:p=update(p);
                   printf("The time after upadation is \n");
                   display(p);
                   break;
            case 4:addTime(T1,T2);
                   break;
            case 5:exit(0);
            
            default:printf("Enter a valid choice\n");
                    break;
        }
    }
}
