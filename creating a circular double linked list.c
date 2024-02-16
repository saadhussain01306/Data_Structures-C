#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node *next;
};
void printList(struct node *head);

int main(){
     struct node *head;
     head=(struct node *)malloc(sizeof(struct node));
     head->data=55;
     head->next=NULL;
     
     struct node *cur;
     cur=(struct node *)malloc(sizeof(struct node));
     cur->data=99;
     cur->next=NULL;
     head->next=cur;
     
      struct node *cur2;
     cur2=(struct node *)malloc(sizeof(struct node));
    cur2->data=69;
     cur2->next=NULL;
     
     cur->next=cur2;
     
      struct node *cur3;
     cur3=(struct node *)malloc(sizeof(struct node));
    cur3->data=44;
     cur3->next=head;
     cur2->next=cur3;
     
     printf("the list is \n");
     printList(head);
     
     
}


void printList(struct node *head){
    struct node *ptr=head;
     struct node *ptr2=head;
    
    do{
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=ptr2);
}
