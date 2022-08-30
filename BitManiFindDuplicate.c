char A[] = "garbage";
int H =0,x=1;
for(i=0;A[i];i++)
{
    x=1;
    x=x<<A[i]-97;
    if(x&H>0)
        printf("%d",A[i]);                                 /* T.C.- O(n) */
    else
        H=H|x;
}