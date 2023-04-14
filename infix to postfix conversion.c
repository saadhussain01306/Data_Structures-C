#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    char *a;
    int top;
    int size;
};
int i,j;

int prec(char a){
    if(a=='(' || a==')') return 0;
    if(a=='^' || a=='$') return 3;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
    else return -1;
}

void push(struct stack *s,char data){
    if(s->top==s->size-1) s->a=(char *)realloc(s->a,2*(s->size)*(sizeof(char)));
    s->a[++s->top]=data;
}

char pop(struct stack *s){
    return s->a[s->top--];
    
}

void infixToPostfix(char *ex,int size,char *ans){
    struct stack *s;
    s=(struct stack *)malloc(sizeof(struct stack));
    s->a=(char *)malloc(sizeof(char)*size);
    s->top=-1;
    s->size=size;
    char a;
    for(i=0;i<size;i++){
        a=ex[i];
        if(prec(a)==-1){
           ans[j++]=a;
        }
        else if(a==')'){
            while(s->a[s->top]!='('){
                ans[j++]=pop(s);
            }
            pop(s);
        }
        else if(a=='(' || prec(a)>prec(s->a[s->top]) || s->top==-1){
            push(s,a);
        }
        else if(prec(a)==3 && prec(s->a[s->top])==3){
            push(s,a);
        }
        else{
            while(prec(a)<=prec(s->a[s->top]) && s->top!=-1){
                ans[j++]=pop(s);
            }
            push(s,a);
        }
        
    }
        
        while(s->top!=-1){
            ans[j++]=pop(s);
        }
        ans[j]='\0';
        printf("Postfix expression is %s ",ans);
    
}

void main(){
    char ans[20];
    char ex[20];
    int choice;
    while(1)
    {
        printf("\nMENU\n1.Read the expresion\n2.Convert it into postfix\n3.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("Enter the infix expression \n");
                scanf("%s",ex);
                break;
                
            case 2:infixToPostfix(ex,strlen(ex),ans);
                   break;
                   
            case 3:exit(0);
            
            default: printf("Inavlid choice\n");
                     break;
        }
    }
}

