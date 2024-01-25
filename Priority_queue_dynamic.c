//priority queue dynanmic

#include<stdio.h>
#include<stdlib.h>

struct q{
    int *a;
    int f,r,n;
    
};
int i;
void display(struct q *q){
    if(q->f > q->r){
        printf("queue is empty\n");
        
    }
    else{
        printf("The queue is \n");
        for(i=q->f;i<=q->r;i++){
            printf("%d\t",q->a[i]);
        }
    }
}

void create(struct q*q){
   
    printf("enter the size of the queue\n");
    scanf("%d",&q->n);
    q->a=(int*)malloc(q->n*sizeof(struct q));
     q->r=-1;
    q->f=0;
}

void insert(struct q *q,int k){
    int i;
    if(q->r==(q->n)-1 && q->f==0){
        printf("The queue is full insertion not possible\n");
    }
    
    else{
        for(i=q->r;i>=(q->f);i--){
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
    }
}

void delete(struct q *q){
   
    if(q->f>q->r){
        printf("the queue is empty\n");
        
    }
    
    else{
        q->f++;
        printf("deletion done!!\n");
        display(q);
    }
}



void main(){
    struct q *q;
    q=(struct q*)malloc(sizeof(struct q));
    create(q);
    
    int k,ch;
    while(1){
        printf("1.Insertion\n2.Deletion\n3.Display\n4.exit\n");
        printf("entet your choice\n");
        scanf("%d",&ch);
        
        switch(ch){
            case 1:printf("enter the element to be inserted\n");
            scanf("%d",&k);
            insert(q,k);
            break;
            
            case 2: delete(q);
            break;
            
            case 3:display(q);
            break;
            
            case 4: exit(0);
            break;
            
            default:printf("Invalid choice\n");
            break;
        }
    }
    
    
    
}
