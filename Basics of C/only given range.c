#include<stdio.h>
int main()
{
    int i,n1,n2;
    do{
    printf("enter your range in which you have to print the numbers\n");
    scanf("%d%d",&n1,&n2);
    }while(n1>=n2);
    
    printf("printing numbers except the odd numbers are\n");
    
    
    for(i=n1;i<=n2;i++){
        if(i%2!=0)
        {
            continue;
        }
        else{
            printf("%d\n",i);
        }

    }
}


// output:-
// enter your range in which you have to print the numbers
// 5
// 12
// printing numbers except the odd numbers are
// 6
// 8
// 10
// 12
