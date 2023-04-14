#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct stack1{
    char *a1;
    int top1;
    int size1;
};

struct stack2{
    char *a2;
    int top2;
    int size2;
};

int prec(char a){
    if(a=='^' || a=='$') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    else return 0;
}

void push1(struct stack1 *s1,int data1 ){
    if(s1->top1==s1->size1-1) s1->a1=(char *)realloc(s1->a1,2*s1->size1*sizeof(char));
    s1->a1[++s1->top1]=data1;
}

void push2(struct stack2 *s2,int data2 ){
    if(s2->top2==s2->size2-1) s2->a2=(char *)realloc(s2->a2,2*s2->size2*sizeof(char));
    s2->a2[++s2->top2]=data2;
}

int pop1(struct stack1 *s1){
    return s1->a1[s1->top1--];
}

int pop2(struct stack2 *s2){
    return s2->a2[s2->top2--];
}

int operate(int op1,int op2,char a){
    switch(a){
        case '+':return op1+op2;
        case '-':return op1-op2;
        case '*':return op1*op2;
        case '/':return op1/op2;
        case '^':
        case '$':return pow(op1,op2);
    }
}

void postfixEva(char *ex1,int size1){
    char a;
    int i;
    int d;
    int op1,op2;
    struct stack1 *s1;
    s1=(struct stack1 *)malloc(sizeof(struct stack1));
    s1->top1=-1;
    s1->size1=size1;
    s1->a1=(char *)malloc(sizeof(char)*size1);
    for(i=0;i<size1;i++){
        a=ex1[i];
        if(prec(a)==0){
            d=a-'0';
            push1(s1,d);
        }
        else if(prec(a)>0){
            op2=pop1(s1);
            op1=pop1(s1);
            push1(s1,operate(op1,op2,a));
        }
    }
     printf("The value of the postfix expresseion is %d ",s1->a1[s1->top1]);
}

void prefixEva(char *ex2,int size2){
    char a;
    int i;
    int d;
    int op1,op2;
    struct stack2 *s2;
    s2=(struct stack2 *)malloc(sizeof(struct stack2));
    s2->top2=-1;
    s2->size2=size2;
    s2->a2=(char *)malloc(sizeof(char)*size2);
    for(i=size2-1;i>=0;i--){
        a=ex2[i];
        if(prec(a)==0){
            d=a-'0';
            push2(s2,d);
        }
        else if(prec(a)>0){
            op1=pop2(s2);
            op2=pop2(s2);
            push2(s2,operate(op1,op2,a));
        }
    }
    
    printf("The value of the prefix expresseion is %d ",s2->a2[s2->top2]);
}

void main(){
    char ex1[20];
    char ex2[20];
    int choice;
    while(1){
        printf("\nMenu\n1.Read postfix expression\n2.Read prefix expression\n3.evaluation of postfix\n4.evaluiation of prefix\n\n5.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the postfix exprsion\n");
                  scanf("%s",ex1);
                  break;
                  
            case 2:printf("Enter the prefix exprseeion\n");
                   scanf("%s",ex2);
                   break;
                   
            case 3:postfixEva(ex1,strlen(ex1));
                    break;
                    
            case 4:prefixEva(ex2,strlen(ex2));
                   break;
                   
            case 5:exit(0);
            
            default:printf("Inavlid choice\n");
                   break;
        }
    }
}





