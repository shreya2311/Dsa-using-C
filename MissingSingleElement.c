/* this is for -Ve elements */
diff = 0-A[0];
for(i=1;i<n;i++)
{
    if(A[i]-i != diff)
    {
        printf("%d",i-diff)
        break;
    }
}