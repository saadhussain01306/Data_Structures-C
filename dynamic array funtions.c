//array operations

#include<stdio.h>
#include<stdlib.h>

int i,j;
void read(int *p,int *size){
    if(*size<=0){
        printf("Operations cannot be performed\n");
        exit(0);
    }
    
    else{
        printf("Enter the element one by one\n");
        for(i=0;i<(*size);i++){
            scanf("%d",(p+i));
        }
    }
}

void display(int *p,int *size){
    if(size<=0){
        printf("Operations acnnot be performed\n");
    }
    
    else{
        printf("The enter elements of the array are\n");
        for(i=0;i<*size;i++){
            printf("%d\t",*(p+i));
        }
    }
}

void insertByPos(int *p,int *size){
    int value,pos;
    printf("Enter the element to be inserted\n");
    scanf("%d",&value);
    printf("Enter the position whre the element is to be inserted\n");
    scanf("%d",&pos);
    *size=*size+1;
    
    p=(int *)realloc(p,(*size)*sizeof(int));
    for(i=*size;i>=pos-1;i--){
        *(p+i+1)=*(p+i);
    }
    *(p+pos-1)=value;
    printf("The updated array is \n");
    display(p,size);
    printf("\n");
    
}

void deleteAtPos(int *p,int *size){
    int pos;
    printf("Enter the position at which ther elemnet is to be deleted\n");
    scanf("%d",&pos);
    for(i=pos-1;i<*size;i++){
        *(p+i)=*(p+i+1);
    }
    *size=*size-1;
    printf("The updated array is \n");
    display(p,size);
    printf("\n");
}

void insertByKey(int *p,int *size){
    int key;
    printf("Enter the key element to be inserted\n");
    scanf("%d",&key);
    
    p=(int *)realloc(p,(*size+1)*sizeof(int));
    *(p+*size)=key;
    *size=*size+1;
    printf("The updated array is \n");
    display(p,size);
    printf("\n");
}

void deleteByKey(int *p,int *size){
    int key;
    printf("Enter the key\n");
    scanf("%d",&key);
    int pos=1,flag=0;
    for(i=0;i<*size;i++){
        if(*(p+i)==key){
            flag=1;
            break;
        }
        pos+=1;
    }
    if(flag=0){
        printf("The key is not prsent in the array \n");
        
    }
    else{
        *size=*size-1;
        for(i=pos-1;i<*size;i++){
            *(p+i)=*(p+i+1);
        }
        printf("The updated array is \n");
        display(p,size);
    }
    
    
      printf("\n\n");
    
}

void insertSort(int *p,int *size){
    printf("The current staus of the array\n");
    display(p,size);
    int key,temp;
    printf("Enter the element to be inserted \n");
    scanf("%d",&key);
    
    p=(int *)realloc(p,(*size+1)*sizeof(int));
    *(p+*size)=key;
    *size=*size+1;
    for(i=0;i<*size;i++){
        for(j=0;j<*size-i-1;j++){
            if(*(p+j)>*(p+j+1)){
                temp=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=temp;
            }
        }
    }
    printf("The updated array is .\n");
    display(p,size);
      printf("\n\n");
    
}

void searchByKey(int *p,int *size){
    int key,pos=1,flag=0;
    
    printf("Enter the elemnet to be serached \n");
    scanf("%d",&key);
    for(i=0;i<*size;i++){
        if(*(p+i)==key){
            flag=1;
            break;
        }
        pos+=1;
    }
   if(flag==1){
       printf("The element is found at position %d\n",pos);
       display(p,size);
   }
   else{
       printf("Element not found\n");
   }
   
   printf("\n\n");
   
}

void searchByPos(int *p,int *size){
    int pos;
    printf("Enter the position \n");
    scanf("%d",&pos);
    if(pos>*size){
        printf("The position is invalid\n");
    }
    else{
        printf("The element at the position %d is %d",pos,*(p+pos-1));
        printf("\n\n");
    }
}

void reverse(int *p,int *size){
 int *q;
 q=(int *)malloc(*size*(sizeof(int)));
    for(i=0;i<*size;i++){
        *(q+i)=*(p+*size-i-1);
    }
    for(i=0;i<*size;i++){
        *(p+i)=*(q+i);
    }
    display(p,size);
}

void main(){
    int *p,*size;
    int s,choice;
    printf("Enter the size of the array for which memeory has ro be allocated dynamically\n");
    scanf("%d",&s);
    p=(int*)malloc(sizeof(int)*s);
    size=&s;
    read(p,size);
    display(p,size);
    while(1){
        printf("\n1.Insert by position\n2.Delete by position\n3.Insert by key\n4.Delete by key\n5.Insert By Order\n6.Search by key\n7.Search By position\n8.Reverse the array\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:insertByPos(p,size);
                    break;
            case 2:deleteAtPos(p,size);
                        break;
                        
            case 3:insertByKey(p,size);
                        break;
                        
            case 4:deleteByKey(p,size);
                        break;
                        
            case 5:insertSort(p,size);
                        break;
                        
            case 6:searchByKey(p,size);
                   break;
                   
            case 7:searchByPos(p,size);
                        break;
                        
            case 8:reverse(p,size);
                        break;
            case 9:exit(0);
            
            default:printf("Inavalid choice\n");
                    break;
        }
        
    
    }
        
}


