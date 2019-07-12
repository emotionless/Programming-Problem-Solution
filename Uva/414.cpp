#include<stdlib.h>
#include<string.h>
#include <stdio.h>

int main()
{
    int t,i,j,count,max,sum;
    char c;
    while(scanf("%d", &t)==1)
    {
        if(!t)break;

        int num[t];
        j=0;
        while(t--)
        {
            i=0;
            count=0;
            while(i<=25)
            {
                scanf("%c", &c);
                if(c=='X')count++;
                i++;
            }

            num[j++]=count;

        }
        max=sum=0;
        for(i=0; i<j; i++)
            if(max<num[i])
                max=num[i];
        for(i=0; i<j; i++)
            if(num[i]<max)
                sum+=max-num[i];

        printf("%d\n",sum);

    }
    return 0;
}
