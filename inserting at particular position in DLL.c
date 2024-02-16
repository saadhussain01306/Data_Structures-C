#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
    
};

void printList(struct node *head);
struct node * insertPos(struct node *head,int index,int data);

int main(){
    int data,index;
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=20;
    head->next=NULL;
    
    
    struct node *current1;
    current1=(struct node *)malloc(sizeof(struct node));
    current1->prev=head;
    current1->data=10;
    current1->next=NULL;
    head->next=current1;
    
     struct node *current2;
    current2=(struct node *)malloc(sizeof(struct node));
    current2->prev=current1;
    current2->data=40;
    current2->next=NULL;
     current1->next=current2;
     
     
     struct node *current3;
    current3=(struct node *)malloc(sizeof(struct node));
    current3->prev=current2;
    current3->data=90;
    current3->next=NULL;
    current2->next=current3;
    
    printf("the list is \n");
    printList(head);
    
    printf("enter the position where element is to be inserted\n");
    scanf("%d",&index);
    printf("enter th elemnt to be inserted\n");
    scanf("%d",&data);
    head=insertPos(head,index,data);
    printf("list after insertion is\n");
    printList(head);
}

void printList(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}


struct node * insertPos(struct node *head,int index,int data){
    struct node *ptr=head;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->prev=NULL;
    newnode->data=data;
    newnode->next=NULL;
    int i;
    index--;
   while(index>1){
        ptr=ptr->next;
        index--;
    }
    struct node *temp=ptr->next;
    ptr->next=newnode;
    newnode->prev=ptr;
   temp->prev=newnode;
   newnode->next=temp;
    
    return head;
    
}
