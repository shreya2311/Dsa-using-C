#include<stdio.h>
#define n 5
int A[(n*(n+1))/2];
void insert(int i,int j,int ele)
{
    if(i>=j)
        A[(i*(i+1))/2+j]=ele;
}
int get(int i,int j)
{
    if(i>=j)
        return A[(i*(i+1))/2+j];
    else
        return 0;
}
void display()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",get(i,j));
        }
        printf("\n");
    }
}
int main()
{
    insert(0,0,1);
    insert(1,0,2);
    insert(1,1,3);
    insert(2,0,1);
    insert(2,1,2);
    insert(2,2,3);
    insert(3,0,4);
    insert(3,1,5);
    insert(3,2,6);
    insert(3,3,7);
    insert(4,0,2);
    insert(4,1,3);
    insert(4,2,4);
    insert(4,3,5);
    insert(4,4,6);
    display();
}