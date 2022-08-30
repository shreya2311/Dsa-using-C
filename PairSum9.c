k=9;
for(i=0;i<n-1;i++)
{
    for(j=i+1;j<n;j++)                                                      /* T.C.- O(n^2) */
    {                                                                     
        if(A[i]+A[j]==k)
            printf("%d,%d",A[i],A[j]);
            break;
    }
}
/* Using Hash Table */
/* (7,2)and(2,7) will be considered same in this method */
/* this method is for unsorted */
k=9;
for(i=0;i<n;i++)
{
    if(A[i]<k)
    {                                                                      /* T.C. - O(n)   */
        if(H[k-A[i]]!=0)
            printf("%d,%d",A[i],k-A[i])
        H[A[i]]++;
    }
}
/* this method is for sorted */
k=9;
i=0,j=n-1;
while(j>i)
{
    if(A[i]+A[j]>k)
        j--;
    else if(A[i]+A[j]<k)                                                   /* T.C. - O(n)  */
        i++;
    else:
        printf("%d,%d",A[i],A[j])
        i++;
        j--;
}
