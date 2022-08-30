/* for unsorted array find duplicate elements without using hashing */
for(i=0;i<n-1;i++)
{
    count=1;
    if(A[i]!=-1)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i] == A[j])
            {                                                      /* TimeComplexity = O(n^2) */
                count++;
                A[j]=-1;
            }
        }
        if(count>1)
        {
            printf(A[i],count);
        }
    }
}