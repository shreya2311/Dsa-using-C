d = -1;
for(i=0;i<n-1;i++)
{
    if(A[i] == A[i+1] && D != A[i])
    {
        printf(A[i]);                                                      /* Time complexity = O(n) */
        d = A[i];
    }
}
/* if in the same ques. we want to print the number of occurences of duplicate element the use the below code */
for(i=0;i<n-1;i++)
{
    if(A[i] == A[i+1])
    {
        j=i+2;
        while(A[i]==A[j])
            j++;                                                          /* Time Complexity = O(n) */
            printf("%d,%d",A[i],j-i);
        i=j;
    }
}
/* using Hash Table is both applicable on sorted and unsorted array */
for(i=0;i<=max-min;i++)
    H[A[i]-min]++;
for(i=0;i<=max-min;i++)
{
    if(H[i]>1)
    {
        printf("%d,%d",i+min,H[i]);
    }
}
