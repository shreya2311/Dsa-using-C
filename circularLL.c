#include<stdio.h>
#include<stdlib.h>
struct student
{
    int rollno;
    int age;
    struct student* next;
};
struct student* start=NULL;
struct student* nn(int rno,int ag)
{
    struct student* p=(struct student*)malloc(sizeof(struct student));
    p->rollno=rno;
    p->age=ag;
    p->next=NULL;
}
void add()
{
    int rollno,age;
    struct student* ptr,* p1;
    printf("\nenter age:");
    scanf("%d",&rollno);
    printf("/nenter age");
    scanf("%d",&age);
    p1=nn(rollno,age);
    if (start==NULL)
    {
        start=p1;
        start->next=start;
    }
    else
    {
        ptr=start;
        while(ptr->next!=start)
        {
            ptr=ptr->next;
        }
        ptr->next=start;
    }
}
void display()
{
    struct student* ptr;
    ptr=start;
    if (start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        do
        {
            /* code */
            printf("\n%d-->%d",ptr->rollno,ptr->age);
            ptr=ptr->next;
        }while (ptr!=start);
        
    }
}
int count(struct student* ptr)
{
    int c=0;
    if (start==NULL)
        return 0;
    else
    {
        do
        {
            /* code */
            c++;
            ptr=ptr->next;
        } while(ptr!=start);
        return c;
    }
}
int main()
{
    add();
    add();
    add();
    display();
    count(start);
    return 0;
}