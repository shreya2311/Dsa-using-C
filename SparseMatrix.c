#include<stdio.h>
#include<stdlib.h>
struct sparse
{
    int x;
    int y;
    int z;
};
struct sparse *create()
{
    int num,i;
    struct sparse* arr;
    printf("\nenter no of non-zero elements:");
    scanf("%d",&num);  
    arr=(struct sparse*)malloc((num+1)*sizeof(struct sparse));
    printf("\nenter dimension of matrix:");
    scanf("%d %d",&arr[0].x,&arr[0].y);
    arr[0].z=num;                                              //Add no. of non-zero elements to (Z,0) location
    printf("\nenter elements:");
    for(i=1;i<=num;i++)
    {
        scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].z);
    }
    return arr;
}
void display(struct sparse* arr)
{
    int i,j,k=1;
    for(i=0;i<arr[0].x;i++)
    {
        for(j=0;j<arr[0].y;j++)
        {
            if(i==arr[k].x&&j==arr[k].y)
                printf("%d ",arr[k++].z);
            else
                printf("0 ");
        }
        printf("\n ");
    }
}
int main()
{
    struct sparse* arr;
    arr=create();
    display(arr);
}
