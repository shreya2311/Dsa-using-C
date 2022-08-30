#include<stdio.h>
char A[]="fired";
char B[]="fried";
int H[26]={0};

for(i=0;A[i];i++)
    H[A[i]-97]++;
for(i=0;B[i],i++)
{
    if(H[B[i]-97]==0)
    {
        printf("Not Anagram");
        return;
    }
    H[B[i]-97]--;
}
for(i=0;i<26;i++)
{
    if(H[i]!=0)
    {
        printf("not anagram");
        return;
    }
}
printf("anagram");