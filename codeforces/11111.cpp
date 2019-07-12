#include <bits/stdc++.h>
char text[1000010];
char par[1000010];
int ff[1000010];
int freq,tc,casen;
void genff()
{
    int l=strlen(par),j=0;
    ff[0]=0;
    for(int i=1; i<l; i++)
    {
        while(j>0&&par[i]!=par[j])j=ff[j-1];

        ff[i]= ((par[i]==par[j])?ff[j++]+1:0);

    }
}


void kmp()
{
    freq=0;
    genff();
    int l=strlen(text);
    int l2=strlen(par),j=0;
    for(int i=0; i<l; i++)
    {
        while(j>0&&text[i]!=par[j])j=ff[j-1];
        if(text[i]==par[j])j++;
        if(j==l2)
        {
            j=ff[j-1];
            freq++;
        }
    }
}


main()
{
    scanf("%d",&tc);
    casen=1;
    while(tc--)
    {
        memset(ff, 0, sizeof ff);
        memset(par, '\0', sizeof par);
        memset(text, '\0', sizeof text);
        scanf("%s %s",text,par);
        kmp();
        printf("Case %d: %d\n",casen++,freq);
    }
}
/*

3
bbbbababababbbabbaabbabbaabaabbabbaaababaaaabaabbbbabaaacbcacbbbbbabbaaaaaacbaaacaaabaabbcccbbccbabbbcbcbcbacbcbcccbaaabcaaabbbcccbbccbabbbcbcbcbacbcbcccbaaabcaa
bab
cbcacbbbbbabbaaaaaacbaaacaaabaa
aaac




*/
