#include<string.h>
#include<stdio.h>

#include<ctype.h>
int main()
{
    int count, i, len;
    char a[10000];
    while (gets(a))
    {
        len=strlen(a);
        count=0;
        for (i=0; i<len; i++)
        {
            if ((a[i+1]=='\0'||isspace(a[i+1])>0)||(ispunct(a[i+1])>0))
            {
                if ((isspace(a[i])==0)&&(ispunct(a[i])==0))
                {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
}
