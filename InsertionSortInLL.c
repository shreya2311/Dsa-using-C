#include<stdio.h>
#include<stdlib.h>
struct student
{
    int data;
    struct student* next;
};
struct student* nn(int data)
{
    struct student* p=(struct student*)malloc(sizeof(struct student));
    p->data=data;
    p->next=NULL;
    return p;
}
struct student* add(struct student* ptr,int data)
{
    struct student* p1;
    p1=nn(data);
    if(ptr!=NULL)
    {
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=p1;
    }
    return p1;
}
void display(struct student* ptr)
{
    if(ptr==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d", ptr->data);
            ptr=ptr->next;
        }
    }
}
struct student* InsertAtSorted(struct student* ptr,struct student* ptr1)
{
    struct student* ptr4;
    if(ptr==NULL||ptr->data>ptr1->data)
    {
        ptr1->next=ptr;
        return ptr1;
    }
    else
    {
        ptr4=ptr;
        while(ptr4->next!=NULL&&ptr4->next->data<ptr1->data)
            ptr4=ptr4->next;
        ptr1->next=ptr4->next;
        ptr4->next=ptr1;
    }
    return ptr;

}
struct student* insertionSort(struct student* ptr2)
{
    struct student* ptr3,*start1=NULL;
    while(ptr2!=NULL)
    {
        ptr3=ptr2->next;
        start1=InsertAtSorted(start1,ptr2);
        ptr2=ptr3;
    }
    return start1;
}
int main()
{
    struct student* start=NULL,*start1=NULL;
    start=add(start,100);
    add(start,80);
    add(start,85);
    add(start,82);
    add(start,70);
    add(start,75);
    start1=add(start1,10);
    add(start1,20);
    start1->next->next=start->next->next->next;
    display(start);
    printf(" \
    
    ");
    start=insertionSort(start);
    display(start);
}


