#include<stdio.h>
#include<math.h>
#define rep(i,a,b) for(i=a;i<=b;i++)

int main()
{
    int i,j,k,t,c,s;
    long a,b,n;
    while(scanf("%ld",&n)==1 && n)
    {
        c=1;
        s=log2(n)+1;
        b=0;
        for(i=0; i<=s; i++)
        {
            if(n&(1<<i))
            {

                if(c%2)
                {
                    b|=(1<<i);
                }
                c++;
            }
        }
        printf("%ld %ld\n",b,n-b);
    }
    return 0;
}
