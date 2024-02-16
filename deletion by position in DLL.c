#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
    
};

void printList(struct node *head);
struct node *deletePos(struct node *head,int index);

int main(){
    int index;
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
    printf("enter the position at which element is to be deleted\n");
    scanf("%d",&index);
    printf("the list after deletion is \n");
    head=deletePos(head,index);
    printList(head);
}

void printList(struct node *head){
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

struct node *deletePos(struct node *head,int index){
    struct node *ptr=head;
    struct node *temp;
    while(index>1){
        ptr=ptr->next;
        index--;
        
    }
    temp=ptr->prev;
    temp->next=ptr->next;
    ptr->next->prev=temp;
    free(ptr);
    ptr=NULL;
    return head;
    
}
