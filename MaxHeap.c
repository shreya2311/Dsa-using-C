#include<stdio.h>
void insert(int A[],int i)
{
    int t;
    t=A[i];
    while(i>0&&t>A[(i-1)/2])                                 /*  To make it min heap just change the sign i.e.t<A[(i-1)/2] */
    {
        A[i]=A[(i-1)/2];
        i=(i-1)/2;
    }
    A[i]=t;
}
void heapify(int A[], int n)
{
    int temp,i,j,x;
    for(i=(n-1)/2;i>=0;i--)
    {
        j=2*i+1;
        x=i;
        while(j<=n)                                        /* time complexity- O(n) */
        {
            if(j<n&&A[j]<A[j+1])
                j=j+1;
            if(A[i]<A[j])
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
                i=j;
                j=2*i+1;
            }
            else
            {
                break;
            }
        }
        i=x;
    }
}
void delete(int A[],int n)
{
    int temp,i,j;
    temp=A[0];
    A[0]=A[n];
    A[n]=temp;
    i=0,j=2*i+1;
    while(j<n)
    {
        if(j<n-1&&A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j])
        {
            temp=A[i];                                 /* this is the code for heap also */
            A[i]=A[j];                                 /* time complexity of heap sort = O(nlogn) */
            A[j]=temp;
            i=j;
            j=2*i+1;
        }
        else{
            break;
        }
    }
}
int main()
{
    int A[]={10,20,30,50,15,11,28,4,3,2,1,800,300,250},i;
    heapify(A,13);                              /* when we know all elements */
    for(i=1;i<=13;i++)
        insert(A,i);                           /* when we don't know all elements */
    for(i=13;i>=1;i--)
        delete(A,i);
    for(i=0;i<14;i++)
        printf("%d\n",A[i]);
}
