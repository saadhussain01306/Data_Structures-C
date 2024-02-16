#include<stdio.h>
#include<stdlib.h>

struct q{
   int f,r,size,a[10];
   

};

void display(struct q *q){
    if(q->f>q->r){
        printf("queue is empty\n");
    }
    else{
        printf("Queue is : ");
        for(int i=q->f;i<=q->r;i++){
            printf("%d\t",q->a[i]);
        }
        printf("\n");
    }
}
void insert(struct q *q,int k){
    if(q->r==(q->size)-1){
        printf("the queue is full\n");
    }
    else{
       
        q->a[++q->r]=k;
    }
}

void dequeue(struct q *q){
    if(q->f>q->r){
        printf("The queue is empty\n");
    }
    else{
        printf("the deleted elemnt is =%d\n",q->a[q->f]);
        q->f++;
    }
}

int main(){
    struct q *q;
    q=(struct q*)malloc(sizeof(struct q));
    printf(":Enter the size of the queue \n");
    scanf("%d",&q->size);
    q->f=0;q->r=-1;
    
    int k,ch;
    while(1){
        printf("\n1.insertion \n2.deletion\n3.display\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element to be inserted \n");
            scanf("%d",&k);
            insert(q,k);
            break;
            case 2: dequeue(q);
            break;
            
            case 3:display(q);
            break;
            case 4:exit(0);
            break;
            
            default:printf("Enter a valid choice");
            break;
            
        }
    }
}

