/* multiple missing elements in a sorted array*/
diff = A[i]-i;
for(i=1;i<n;i++)
{
    if(A[i]-i != diff)
    {
        while(diff<=A[i]-i)
        {
            printf("%d",i+diff);
            diff++;
        }
    }
}