/* in least comparision find min. & max. element*/
min=max=A[0];
for(i=1;i<n;i++)                                                        /* Best Case-> n-1 when array is in descending order */
{
    if(A[i]<min)                                                       
        min=A[i];                                                       /* Worst Case-> 2*n-1 When array is in ascending order */
    else if(A[i]>max)
        max=A[i];
}