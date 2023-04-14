#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *rlink;
    struct node *llink;
};

void preorder(struct node *root){
    if(root==NULL) return ;
    printf("%d\t",root->data);
    preorder(root->llink);
    preorder(root->rlink);
}

void postorder(struct node *root){
    if(root==NULL) return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t",root->data);
}


void inorder(struct node *root){
    if(root==NULL) return;
    postorder(root->llink);
     printf("%d\t",root->data);
    postorder(root->rlink);
   
}

int totalnodes(struct node *root){
    if(root==NULL){
        return 0;
    }
    int l=totalnodes(root->llink);
   int r=totalnodes(root->rlink);
    return (1+r+l);
}

int height(struct node *root){
    if(root==NULL || (root->rlink==NULL && root->llink==NULL) ) return 0;
    else{
        int lh=height(root->llink);
        int rh=height(root->rlink);
        if(lh>rh){
            return (lh+1);
        }
        else{
            return(rh+1);
        }
    }

}

struct node * insert(struct node *root,int data){
    if(root==NULL){
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=data;
        newnode->rlink=newnode->llink=NULL;
        return newnode;
    }
    if(root->data==data){
        printf("The inserted element is already present..\n");
        return root;
    }
    if(root->data<data) root->rlink=insert(root->rlink,data);
    if(root->data>data) root->llink=insert(root->llink,data);
    return root;
}

struct node *search(struct node *root,int data){
    if(root==NULL){
        printf("The element is found\n");
        return NULL;
    }
    
    if(root->data==data){
        printf("node found value:%d\n",root->data);
    }
    
    if(root->data<data){
        if(root->rlink!=NULL && root->rlink->data==data) printf("element found\nThe parent node value is %d\n",root->data);
        return search(root->rlink,data);
    }
    if(root->data>data){
        if(root->llink!=NULL && root->llink->data==data) printf("element found\nThe parent node value is %d\n",root->data);
        return search(root->llink,data);
    }
}

struct node *inorderPredecessor(struct node *root){
    root=root->llink;
    while(root->rlink!=NULL){
        root=root->rlink;
    }
    return root;
}

struct node* delete(struct node *root,int data){
    if(root==NULL){
        printf("There is non elemnet to be deleted\n");
        free(root);
        return NULL;
    }
    if(root->data>data) root->llink=delete(root->llink,data);
    
    else if(root->data<data) root->rlink=delete(root->rlink,data);
    
    else{
        if(root->rlink==NULL && root->llink==NULL){
            free(root);
            root=NULL;
        }
        else if(root->rlink==NULL){
            struct node *ptr;
            ptr=root;
            root=root->rlink;
            free(ptr);
        }
        else if(root->llink=NULL){
            struct node *ptr;
            ptr=root;
            root=root->rlink;
            free(ptr);
        }
        
        else{
            struct node *ipre=inorderPredecessor(root);
            root->data=ipre->data;
            root->llink=delete(root->llink,ipre->data);
        }
    }
    return root;
    
}


void main()
{
    
    struct node* root= NULL;
    int ch,ele;
    while(1)
    {
    printf(" 1.Build tree\n 2.Search Node\n 3.Preorder traversal\n 4.Inorder Traversal\n 5.Postorder traversal\n 6.Count Nodes\n 7.Find Height\n8.Delete  \n9.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to be inserted\n");
                scanf("%d", &ele);
                root=insert(root,ele);
                break;

            case 2:
                printf("Enter element to be searched\n");
                scanf("%d", &ele);
                search(root,ele);
                break;

            case 3:
            printf("Preorder traversal is: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
            printf("Inorder traversal is: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
            printf("Postorder traversal is: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                printf("Total Number of nodes: %d\n", totalnodes(root));
                break;

            case 7:
                printf("Total Height: %d\n", height(root));
                break;
                
            case 8:printf("Enetr the node to be delted\n");
                   scanf("%d",&ele);
                   delete(root,ele);
                   break;

            case 9:
            printf("Exiting..");
            exit(0);

            default: printf("Invalid choice\n");
        }
    }
}





