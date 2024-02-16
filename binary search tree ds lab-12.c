//binarey search tree


#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* rlink;
    struct node* llink;
};

void ord(struct node *r,int ch){
    if(r==NULL){
        return ;
    }
    if(r->llink==NULL && r->rlink==NULL){
        printf("%d\t",r->data);
        return ;
    }
    switch(ch){
        case 1:ord(r->llink,1);
             printf("%d\t",r->data);
             ord(r->rlink,1);
             break;
        case 2:printf("%d\t",r->data);
               ord(r->llink,2);
               ord(r->rlink,2);
               break;
        case 3:ord(r->llink,3);
               ord(r->rlink,3);
               printf("%d\t",r->data);
               break;
    }
}

void insert(struct node *r,int k){
    if(k<r->data && r->llink==NULL){
        struct node*t;
        t=(struct node*)malloc(sizeof(struct node));
        t->data=k;
        t->rlink=NULL;
        t->llink=NULL;
        r->llink=t;
        return;
    }
    if(k>r->data && r->rlink==NULL){
        struct node*t;
        t=(struct node*)malloc(sizeof(struct node));
        t->data=k;
        t->rlink=NULL;
        t->llink=NULL;
        r->rlink=t;
        return;
    }
    if(k<r->data){
        insert(r->llink,k);
    }
    if(k>r->data){
        insert(r->rlink,k);
    }
}

void main(){
    int choice,k;
    struct node *r;
    r=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value of root node\n");
    scanf("%d",&r->data);
    printf("1.Build tree\n2.Inorder traversal\n3.Preorder traversal\n4.postorder traversal\n5.exit\n");
    while(1){
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("enter the value to be inserted \n");
            scanf("%d",&k);
            insert(r,k);
            break;
            
            case 2:printf("Inorder is\n");
            ord(r,1);
            break;
            
            case 3:printf("preorder is\n");
            ord(r,2);
            break;
            
            case 4:printf("postorder is \n");
            ord(r,3);
            break;
            
            case 5:exit(0);
            
            default:printf("enter your choice\n");
            break;
            
        }
    }
}
