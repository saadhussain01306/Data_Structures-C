#include<stdio.h>
#include<stdlib.h>
struct q{
    int f,r,n,*a;
};


void create(struct q *q){
    printf("enter the size of the queue\n");
    scanf("%d",&q->n);
    q->a=(int *)malloc(sizeof(int)*q->n);
    q->r=-1;q->f=0;
}

void display(struct q *q){
    if(q->f>q->r){
        printf("the queue is empty\n");
    }
    else{
        printf("The queueelemts are\n");
        for(int i=q->f;i<=q->r;i++){
            printf("%d\t",q->a[i]);
        }
    }
}

struct q* insert(struct q *q,int k){
    if(q->r==q->n-1){
        printf("The queue ie full allocating memory dynalically\n");
        int *t=(int *)realloc(q->a,2*(q->n)*sizeof(int));
        q->a=t;
        q->n=2*q->n;
    }
    int i;
    
    for( i=q->r;i>=q->f;i--){
        if(q->a[i]>k){
            q->a[i+1]=q->a[i];
        }
        else{
            break;
        }
    }
    
    if(q->r==-1){
        q->a[++q->r]=k;
       
    }
    else{
        q->a[i+1]=k;
        q->r++;
       
    }
     return q;
    
}

struct q * delete(struct q *q){
    if(q->f>q->r){
        printf("The queue ie empty\n");
    }
    else{
        printf("The deleted element is %d\n",q->a[q->f]);
        q->f++;
        return q;
    }
}


void main(){
    struct q *q;
    q=(struct q*)malloc(sizeof(struct q));
    create(q);
    int choice,data;
    while(1){
        printf("\n1.Insert\n2.Delete\n3.Dispaly\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter elemnt\n");
                   scanf("%d",&data);
                q=insert(q,data);
                display(q);
                break;
            case 2:q=delete(q);
                  display(q);
                break;
                
            case 3:
                  display(q);
                break; 
                
            case 4:exit(0);
            
            default:printf("Invalid choice\n");
            break;
        }
    }
}
