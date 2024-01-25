#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* link;
};

struct node* start = NULL;

// Function to create list with n nodes
void createList() {
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\nEnter number to be inserted : ");
            scanf("%d", &data);
            start->info = data;
            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to be inserted : ");
                scanf("%d", &data);
                newnode->info = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    } else
        printf("\nThe list is already created\n");
}

// Function to see the list\traverse the linked list
void traverse() {
    struct node* temp;
    // List is empty
    if (start == NULL)
        printf("\nList is empty\n");
    // Else print the LL
    else {
        temp = start;
        printf("the linked list is\n");
        while (temp != NULL) {
            printf("%d\n", temp->info);
            temp = temp->link;
        }
    }
}

// Function to insert at the front
void insertAtFront() {
    int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    temp->info = data;
    // Pointer of temp will be
    // assigned to start
    temp->link = start;
    start = temp;
    traverse();
}

// Function to insert at the rear of the linked list
void insertAtEnd() {
    int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
    // Enter the number
    printf("\nEnter number to be inserted : ");
    scanf("%d", &data);
    // Changes links
    temp->link = 0;
    temp->info = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
    traverse();
}

// Function to insert at any specified  position in the linked list
void insertAtPosition() {
    struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
    // Enter the position and data
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
    // Change Links
    temp = start;
    newnode->info = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
    traverse();
}

// Function to delete from the front of the linked list
void deleteFirst() {
    struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
    }
    traverse();
}

// Function to delete from the rear of the linked list
void deleteEnd() {
    struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
    traverse();
}

// Function to delete from any specified of the linked list
void deletePosition() {
    struct node *temp, *position;
    int i = 1, pos;
    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");
    // Otherwise
    else {
        printf("\nEnter index : ");
        // Position to be deleted
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
        // Change Links
        position = temp->link;
        temp->link = position->link;
        // Free memory
        free(position);
    }
    traverse();
}

// Function to create an ordered list in a single linked list
void sort() {
    struct node* current = start;
    struct node* index = NULL;
    int temp;
    // If LL is empty
    if (start == NULL) {
        return;
    }
    // Else
    else {
        // Traverse the LL
        while (current != NULL) {
            index = current->link;
            // Traverse the LL nestedly
            // and find the minimum
            // element
            while (index != NULL) {
                // Swap with it the value
                // at current
                if (current->info > index->info) {
                    temp = current->info;
                    current->info = index->info;
                    index->info = temp;
                }
                index = index->link;
            }
            // Update the current
            current = current->link;
        }
    }
    traverse();
}

// Function to reverse the linked list
void reverse() {
    struct node *t1, *t2, *temp;
    t1 = t2 = NULL;
    // If LL is empty
    if (start == NULL)
        printf("List is empty\n");
    // Else
    else {
        // Traverse the LL
        while (start != NULL) {
            // reversing of points
            t2 = start->link;
            start->link = t1;
            t1 = start;
            start = t2;
        }
        start = t1;
        // New head Node
        temp = start;
        printf("Reversed linked list is : ");
        // Print the LL
        while (temp != NULL) {
            printf("%d\n", temp->info);
            temp = temp->link;
        }
    }
}

// Search by key
void searchByKey() {
    struct node* ptr;
    int item, i = 0, flag;
    ptr = start;
    if (ptr == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter item which you want to search?\n");
        scanf("%d", &item);
        while (ptr != NULL) {
            flag = 1;
            if (ptr->info == item) {
                printf("item found at location %d \n", i + 1);
                flag = 0;
            } else {
                flag = 1;
            }
            i++;
            ptr = ptr->link;
        }
        if (flag == 1) {
            printf("Item not found\n");
        }
    }
}

// Delete by key
void deleteByKey() {
    int key;
    printf("Enter the key to be deleted\n");
    scanf("%d", &key);
    struct node *prev, *cur;

    /* Check if head node contains key */
    while (start != NULL && start->info == key) {
        // Get reference of head node
        prev = start;

        // Adjust head node link
        start = start->link;

        // Delete prev since it contains reference to head node
        free(prev);

        // No need to delete further
        return;
    }

    prev = NULL;
    cur = start;

    /* For each node in the list */
    while (cur != NULL) {
        // Current node contains key
        if (cur->info == key) {
            // Adjust links for previous node
            if (prev != NULL)
                prev->link = cur->link;

            // Delete current node
            free(cur);

            // No need to delete further
            return;
        }

        prev = cur;
        cur = cur->link;
    }
}

int main() {
    int choice;
    while (1) {
        printf("1.create a list\n");
        printf("2.to see the list/traverse\n");
        printf("3.insert at the front\n");
        printf("4.insert at the end\n");
        printf("5.insert at particular position\n");
        printf("6.delete at the front\n");
        printf("7.delete at the end\n");
        printf("8.delete at particular position\n");
        printf("9.delete by key\n");
        printf("10.search by key\n");
        printf("11.create an ordered list\n");
        printf("12.reverse a list\n");
        printf("13.Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                traverse();
                break;
            case 3:
                insertAtFront();
                break;
            case 4:
                insertAtEnd();
                break;
            case 5:
                insertAtPosition();
                break;
            case 6:
                deleteFirst();
                break;
            case 7:
                deleteEnd();
                break;
            case 8:
                deletePosition();
                break;
            case 9:
                deleteByKey();
                break;
            case 10:
                searchByKey();
                break;
            case 11:
                sort();
                break;
            case 12:
                reverse();
                break;
            case 13:
                exit(0);
                break;
        }
    }
    return 0;
}
