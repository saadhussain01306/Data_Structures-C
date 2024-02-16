#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *createList(struct node *tail);
void printList(struct node*tail);

int main(){
   struct node *tail;
   tail=createList(tail);
   
   printList(tail);
   
   int choice;
   
}
    
struct node *createList(struct node *tail){
    struct node *temp;
    
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=35;
    temp->next=NULL;
    
    struct node *temp2;
    
    temp2=(struct node *)malloc(sizeof(struct node));
    temp2->data=35;
    temp2->next=NULL;
    temp->next=temp2;
    
    
    tail=(struct node *)malloc(sizeof(struct node));
    tail->data=35;
    tail->next=NULL;
    temp2->next=tail;
    
    tail->next=temp;
    
    return tail;
    
}

void printList(struct node*tail){
    struct node *p=tail->next;
    printf("The list is\n");
    do{
        printf("%d\n",p->data);
        p=p->next;  
    }while (p!=tail->next);
    
}
