#include <stdio.h>

int main()
{
    int i,n,pos,a[20];
    printf("enter the n value\n");
    scanf("%d",&n);
    printf("enter the arry elments one by one\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the value at which element is to be deleted");
    scanf("%d",&pos);
    if(pos>=n+1)
    {
        printf("insertiuon is not possible\n");
    }
    
    else if(pos==n)
    {
        for(i=pos-1;i<=n-1;i++){
            a[i]=a[i+1];
        }
    }
    
    
    else{
    for(i=pos-1;i<n-1;i++){
        a[i]=a[i+1];
    }
    }
    printf("new array is\n");
    for(i=0;i<n-1;i++){
        printf("%d\t",a[i]);
    }
    
}
