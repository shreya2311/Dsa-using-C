#include<stdio.h>

char* str[]="a+b-(c*d)";

void reverseString(char* st)
{
    unsigned long l=strlen(st);
    for(i=0;i<l/2;i++)
    {
        ch=st[i];
        st[i]=st[l-i-1];
        st[l-i-1]=ch;                         /* in c we can reverse string using strrev() in dev c++*/
    }
}