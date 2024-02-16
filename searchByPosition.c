#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void traverse(struct node *ptr);
void searchByKey(struct node *head,int key);

int main()
{
    struct node *head;
    struct node *current;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=20;
    head->link=NULL;
    
    current=(struct node *)malloc(sizeof(struct node));
    current->data=30;
    current->link=NULL;
    head->link=current;
    int key;
    traverse(head);
    printf("enter the element to be searched\n");
    scanf("%d",&key);
    searchByKey(head,key);
    
}


void traverse(struct node *ptr)
{
    while(ptr!=NULL){
    printf("the element is =%d\n",ptr->data);
    ptr=ptr->link;
      }
}

void searchByKey(struct node *head,int key){
    struct node *ptr=head;
    while(ptr!=NULL){
        if(ptr->data==key){
       printf("key is found");
       break;
        }
        ptr=ptr->link;
    }
    if(ptr==NULL){
        printf("key is not found\n");
    }
    
}
