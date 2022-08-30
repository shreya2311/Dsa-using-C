/* this approach is only for +ve numbers */
diff=A[0]-0;
for(i=1;i<n;i++)
{
    if(A[i]-i != diff)
    {
        printf("%d",diff+i);
        break;
    }
}