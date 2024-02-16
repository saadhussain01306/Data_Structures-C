#include<stdio.h>


struct bank {
    char author[20];
    int pages;
    float price;
    
};

int main()
{
    struct bank book[2];
    int i;
    for(i=0;i<2;i++){
    printf("enter the %d book details\n",(i+1));
    printf("enter the author\n");
    scanf("%s",book[i].author);
    printf("enter the pages");
    scanf("%d",&book[i].pages);
    printf("enter the price\n");
    scanf("%f",&book[i].price);
    }
    
    printf("\n");
    for(i=0;i<2;i++){
    printf("enter the %d book details\n",(i+1));
    printf(" the author\n");
    printf("%s",book[i].author);
    printf(" the pages");
   printf("%d",book[i].pages);
    printf(" the price\n");
    printf("%f",book[i].price);
    }
    
    
    
}
