#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int a[20];
    int size;
};

void display(struct stack *st){
    if(st->top==-1){
        printf("Stack underflow\n");
    }
    
    else{
        printf("the stack element from the bottom is");
        for(int i=0;i<=st->top;i++){
            printf("%d\t",st->a[i]);
        }
    }
}

void push(struct stack*st,int data){
    if(st->top==(st->size)-1){
        printf("Stack overflow\n");
    }
    
    else{
        printf("The pushed elemet is %d\n",data);
        st->top++;
        st->a[st->top]=data;
        display(st);
    }
    
}

void pop(struct stack*st){
    if(st->top==-1){
        printf("stack underflow\n");
    }
    
    else{
       printf("popped elemnt is %d",st->a[st->top]);
       st->top--;
       display(st);
    }
}





void main(){
    struct stack *st;
    st=(struct stack*)malloc(sizeof(struct stack));
    st->top=-1;
    printf("Enter the size of the stack");
    scanf("%d",&st->size);
    int ch,k;
    while(1){
        printf("1.pop\n2.push\n3.display\n4.exit");
        printf("enter the choice\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:printf("enter the element to be pushed \n");
                   scanf("%d",&k);
                   push(st,k);
                   break;
                   
            case 2:pop(st);
                   break;
            case 3:display(st);
                 break;
                 
            case 4:exit(0);
            
            default:printf("Enter avalid choice");
                    break;
        }
    }
}
