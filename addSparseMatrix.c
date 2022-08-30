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
    arr[0].z=num;
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
struct sparse* add(struct sparse*arr,struct sparse*arr1)
{
    struct sparse* arr2;
    int i=1,j=1,k=1;
    if(arr[0].x!=arr1[0].x||arr[0].y!=arr1[0].y)
        return NULL;
    arr2=(struct sparse*)malloc((arr[0].z+arr1[0].z+1)*sizeof(struct sparse));
    arr2[0].x=arr[0].x;
    arr2[0].y=arr[0].y;
    while(i<=arr[0].z&&j<=arr1[0].z)
    {
        if(arr[i].x<arr1[i].x)
            arr2[k++]=arr[i++];
        else if(arr[i].x<arr1[j].x)
            arr2[k++]=arr1[j++];
        else
        {
            if(arr[i].y<arr1[j].y)
                arr2[k++]=arr[i++];
            else if(arr[i].y>arr1[j].y)
                arr2[k++]=arr1[j++];
            else
            {
                arr2[k]=arr[i++];
                arr2[k++].z+=arr1[j++].z;
            }
        }
    }
    while(i<=arr[0].z)
        arr2[k++]=arr[i++];
    while(j<=arr1[0].z)
        arr2[k++]=arr1[j++];
    arr2[0].z=k-1;
    return arr2;
}
int main()
{
    struct sparse* arr,*arr1,*arr2;
    arr=create();
    arr1=create();
    printf("\n\n");
    display(arr);
    printf("\n\n");
    display(arr1);
    arr2=add(arr,arr1);
    printf("\n\n");
    display(arr2);
}