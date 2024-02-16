#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};


int printList(struct node *head);

int main()
{
    int count;
    struct node *head;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=20;
    head->link=NULL;
     struct node *current;
    current=(struct node *)malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    struct node *current2;
    current2=(struct node *)malloc(sizeof(struct node));
    current2->data=40;
    current2->link=NULL;
    current->link=current2;
    
    head->link=current;
    
   
    count=printList(head);
    printf("the count of the node is =%d\n",count);
    
    
    
}
 
 int printList(struct node *ptr){
     int count=0;
     while(ptr!=NULL){
         
         ptr=ptr->link;
         count++;
     }
     return count;
 }
 
