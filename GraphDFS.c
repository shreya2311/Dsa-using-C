#include<stdio.h>
#include<stdlib.h>
struct list
{
    int v;
    struct list *next;
};
struct list *nn(int v)
{
    struct list *ptr;
    ptr=(struct list*)malloc(sizeof(struct list));
    ptr->v=v;
    ptr->next=NULL;
    return ptr;
}
void createGraph(int n)
{
    int i,x,j,y;
    struct list *ptr,*ptr1;
    struct list *arr[n];
    for(i=0;i<n;i++)
        arr[i]=NULL;
    for(i=0;i<n;i++)
    {
        printf("enter no. of adjacent vertices of vertex %d: ", i);
        scanf("%d",&x);
        for(j=1;j<x;j++)
        {
            printf("enter %d adjacent vertices:",j);
            scanf("%d",&y);
            ptr=nn(y);
            if(arr[i]==NULL)
                arr[i]=ptr;
            else
            {
                ptr1=arr[i];
                while(ptr1->next!=NULL)
                    ptr1=ptr1->next;
                ptr1->next=ptr;
            }

        }

    }
    for(i=0;i<n;i++)
    {
        printf("adjacent vertex of vertex %d",i);
        ptr=arr[i];
        while(ptr)
        {
            printf("\n%d",ptr->v);
            ptr=ptr->next;
        }
    }
}
int main()
{
    createGraph(5);
}
