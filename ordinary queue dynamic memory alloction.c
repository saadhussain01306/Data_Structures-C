#include<stdio.h>
#include<stdlib.h>

struct q{
    int f,r,size,*a;
};

void create(struct q *q){
    printf("Enter the size of the queue\n");
    scanf("%d",&q->size);
    q->a=(int *)malloc((q->size)*sizeof(int));
    q->r=-1;q->f=0;
}
void display(struct q *q){
    if(q->f>q->r){
        printf("the queue is empty\n");
        
    }
    else{
        printf("queue = ");
        for(int i=q->f;i<=q->r;i++){
            printf("%d\t",q->a[i]);
        }
        
    }
}
void insert(struct q *q,int k){
    if(q->r==(q->r)-1){
        printf("The queue is full\n");
        printf("allocating memeory dynamically\n");
        q->a=realloc(q->a,2*(q->size)*sizeof(int));
        q->r=q->size-1;
        q->size=2*q->size;
        
    }
    
   
        q->a[++q->r]=k;
    
}
void delete(struct q *q){
    if(q->f >q->r){
        printf("The queue is empty\n");
    }
    else{
        printf("the deleted element is %d",q->a[q->f]);
        q->f++;
    }
}

int main(){
    struct q *q;int k,ch;
    q=(struct q *)malloc(sizeof(struct q));
    create(q);
    while(1){
       printf("\n1.insertion \n2.deletion\n3.display\n4.exit\n");
        printf("enter the choice\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element to be inserted \n");
            scanf("%d",&k);
            insert(q,k);
            break;
            case 2: delete(q);
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
