#include<stdio.h>
#define n 4
int A[n];
void insert(int i,int j,int ele)
{
    if(i==j)
        A[i]=ele;
}
int get(int i,int j)
{
    if(i==j)
        return A[i];
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
            if(i==j)
                printf("%d ",A[i]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    insert(0,0,4);
    insert(1,1,3);
    insert(2,2,5);
    insert(3,3,2);
    printf("%d\n",get(1,1));
    printf("%d\n",get(2,2));
    display();
}