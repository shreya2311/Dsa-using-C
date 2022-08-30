#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    int age;
    struct student* next;
};
struct student* start=NULL;
struct student* nn(int rno, int ag)
{
    struct student* p=(struct student*)malloc(sizeof(struct student));
    p->rollno=rno;
    p->age=ag;
    p->next=NULL;
    return p;
}
void add()
{
    int rollno,age;
    struct student* p1,* ptr;
    printf("\n enter rollno:");
    scanf("%d", &rollno);
    printf("\n enter age:");
    scanf("%d", &age);
    p1=nn(rollno, age);
    if(start==NULL)
    {
        start=p1;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=p1;
    }
}
void display()
{
    struct student* ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("\n%d-->%d", ptr->rollno, ptr->age);
            ptr=ptr->next;
        }
    }
}
int count(struct student* ptr)
{
    int c=0;
    while(ptr!=NULL)
    {
        c++;
        ptr=ptr->next;
    }
    return c;
}
void deleteNodes(struct student* ptr)
{
    int c=0,b=0;
    int number,n;
    struct student* ptr1;
    ptr=start;
    printf("\nenter no. of nodes to be deleted:");
    scanf("\n%d",&number);
    n=count(start);
    while(number>c)
    {
        start=start->next;
        c++;
        while(number-2>b)
        {
            ptr1=ptr->next;
            ptr=ptr->next;
            free(ptr);
        }
    }
}
int main()
{
    add();
    add();
    add();
    add();
    add();
    add();
    add();
    add();
    deleteNodes(start);
    display();
    count(start);
    return 0;
}