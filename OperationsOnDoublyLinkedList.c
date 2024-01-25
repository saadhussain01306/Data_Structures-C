#include <stdio.h>
#include <stdlib.h>
 
// Linked List Node
struct node {
    struct node *prev;
    int info;
    struct node *next;
};
struct node* start = NULL;
 
// Function to traverse the linked list
void traverse()
{
    // List is empty
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    // Else print the Data
    struct node* temp;
    temp = start;
    printf("the linked list is\n");
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
    
}
 
// Function to insert at the front
// of the linked list
void insertAtFront()
{
    int data;
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->prev = NULL;
 
    // Pointer of temp will be
    // assigned to start
    temp->next = start;
    start = temp;
    traverse();
}
 
// Function to insert at the end of
// the linked list
void insertAtEnd()
{
    int data;
    struct node *temp, *temp2;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    temp->info = data;
    temp->next = NULL;
    temp2 = start;
 
    // If start is NULL
    if (start == NULL) {
 
        start = temp;
    }
 
    // Changes Links
    else {
        while (temp2->next != NULL)
            temp2 = temp2->next;
        temp->prev = temp2;
        temp2->next = temp;
    }
    traverse();
}
 
// Function to insert at any specified
// position in the linked list
void insertAtPosition()
{
    int data, pos, i = 1;
    struct node *temp, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->prev = NULL;
 
    // Enter the position and data
    printf("\nEnter position : ");
    scanf("%d", &pos);
     
 
    // If start==NULL,
    if (start == NULL) {
        start = newnode;
        newnode->prev = NULL;
        newnode->next = NULL;
    }
 
    // If position==1,
    else if (pos == 1) {
      // this is author method its correct but we can simply call insertAtfront() function for this special case
       /* newnode->next = start;
        newnode->next->prev = newnode;
        newnode->prev = NULL;
        start = newnode; */
      // now this is improved by Jay Ghughriwala on geeksforgeeks
      insertAtFront();
    }
 
    // Change links
    else {
      printf("\nEnter number to be inserted: ");
    scanf("%d", &data);
    newnode->info = data;
    temp = start;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        temp->next->prev = newnode;
    }
    traverse();
}
 
// Function to delete from the front
// of the linked list
void deleteFirst()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(temp);
    }
    traverse();
}
 
// Function to delete from the end
// of the linked list
void deleteEnd()
{
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    if (start->next == NULL)
        start = NULL;
    else {
        temp->prev->next = NULL;
        free(temp);
    }
    traverse();
}
 
// Function to delete from any specified
// position from the linked list
void deletePosition()
{
    int pos, i = 1;
    struct node *temp, *position;
    temp = start;
 
    // If DLL is empty
    if (start == NULL)
        printf("\nList is empty\n");
 
    // Otherwise
    else {
        // Position to be deleted
        printf("\nEnter position : ");
        scanf("%d", &pos);
 
        // If the position is the first node
        if (pos == 1) {
            deleteFirst(); // im,proved by Jay Ghughriwala on GeeksforGeeks
            if (start != NULL) {
                start->prev = NULL;
            }
            free(position);
            return;
        }
 
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        // Change Links
        position = temp->next;
        if (position->next != NULL)
            position->next->prev = temp;
        temp->next = position->next;
 
        // Free memory
        free(position);
        traverse();
    }
}
void deleteByKey() {
    int key;
    printf("enter the key  to  be deleted\n");
    scanf("%d",&key);
        struct node *ptr, *temp = start;
        if (start == NULL) {
                printf("Data unavailable\n");
                return;
        } else if (temp->info == key) {
                ptr = temp->next;
                temp->next = NULL;
                free(temp);
                start = ptr;
                
        } else {
                while (temp->next != NULL && temp->info != key) {
                        ptr = temp;
                        temp = temp->next;
                }
                if (temp->next == NULL && temp->info != key) {
                        printf("Given data unvavailable in list\n");
                        return;
                } else if (temp->next != NULL && temp->info == key) {
                        ptr->next = temp->next;
                        temp->next->prev = temp->prev;
                        temp->next = NULL;
                        temp->prev = NULL;
                        free(temp);
                        printf("Data deleted successfully\n");
                       
                } else if (temp->next == NULL && temp->info == key) {
                        ptr->next = NULL;
                        temp->next = temp->prev = NULL;
                        free(temp);
                        printf("Data deleted successfully\n");
                        
                }
        }
  }


void searchByKey(){
    struct node *temp;
    temp=start;
    int key,flag=0;
    
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    for(temp=start;temp!=NULL;temp=temp->next)
    {
        if(temp->info==key)
        {
            flag=1;
            break;
        }
    }
    
    if(flag==1)
    {
        printf("Key found\n");
        
    }
    else{
        printf("Key not found\n");
    }
    
}

void swap(struct node *a,struct node *b) 
{ 
    int temp;
     temp = a->info; 
    a->info = b->info; 
    b->info = temp; 
} 

void sort() 
{ 
    int swapped, i; 
    struct node *ptr1; 
    struct node *ptr2 = NULL; 
  
    /* Checking for empty list */
    if (start == NULL) 
        return; 
  
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != ptr2) 
        { 
            if (ptr1->info > ptr1->next->info) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        ptr2 = ptr1; 
    } 
    while (swapped); 
    traverse();
} 





void reverse()
{
    struct node* temp = NULL;
    struct node* current = start;
 
    /* swap next and prev for all nodes of
      doubly linked list */
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
 
    /* Before changing head, check for the cases like empty
       list and list with only one node */
    if (temp != NULL)
        start = temp->prev;
    
    traverse();    
}


void copy()
{
    // List is empty
    if (start == NULL) {
        printf("\nList is empty\n");
        return;
    }
    // Else print the Data
    struct node* temp;
    temp = start;
    printf("the cpoy of the linked list is\n");
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
    
}

int main()
{
    int choice;
    while(1){
        printf("\nThe choices are:\n");
        printf("1.Insert at the front\n");
        printf("2.Insert at the end\n");
        printf("3.Insert at particular position\n");
        printf("4.Delete at the front\n");
        printf("5.Delete at the rear\n");
        printf("6.Delete at particular position\n");
        printf("7.Delete by key\n");
        printf("8.Search by key\n");
        printf("9.Create an ordered list\n");
        printf("10.Reverse a list\n");
        printf("11.Creating a copy of the list\n");
        printf("12.To see the list\n");
        printf("13.Exit\n");
        
        printf("\nEnter Choice :\n");
        scanf("%d", &choice);
        
        switch (choice) {
        case 1:
            insertAtFront();
            break;
        case 2:
           insertAtEnd();
            break;
        case 3:
           insertAtPosition();
            break;
        case 4:
            deleteFirst();
            break;
        case 5:
            deleteEnd();
            break;
        case 6:
           deletePosition();
            break;
        case 7:
           deleteByKey();
            break;
            
            case 8:
            searchByKey();
            break;
            
            case 9:
            sort();
            break;
            
            case 10:
            reverse();
            break;
            
            case 11:
            copy();
            break;
            
            case 12:
            traverse();
            break;
 
        case 13:
            exit(0);
            break;
        default:
            printf("Invalid choice \n");
            break;
        
    }
 }
}
