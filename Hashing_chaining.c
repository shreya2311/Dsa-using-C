#include<stdio.h>
#include<stdlib.h>
#define size 10
struct list
{
    int data;
    struct list* next;
};
struct list* arr[size]={NULL};
struct list* nn(int data)
{
    struct list* p=(struct list*)malloc(sizeof(struct list));
    p->data=data;
    p->next=NULL;
    return p;
}
void insertAtSortedPosition(int data)
{
    struct list* ptr,*ptr1=arr[data%10],*ptr2=NULL;
    ptr=nn(data);
    while(ptr!=NULL && ptr1->data<ptr->data)
    {
        ptr2=ptr1;
        ptr1=ptr1->next;
    }
    ptr->next=ptr1;
    if(ptr1!=arr[data%10])
        ptr2->next=ptr;
    else
        arr[data%10]=ptr;
}
void search(int data)
{
    struct list* ptr=arr[data%10];
    while(ptr)
    {
        if(ptr->data==data)
            return 1;
        if(ptr->data>data)
            return -1;
        ptr=ptr->next;
    }
    return -1;
}
int main()
{
    
    insertAtSortedPosition();
    search(int x);    
}