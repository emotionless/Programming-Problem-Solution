#include <bits/stdc++.h>

/**********TYPE CASTING**********/
#define LL long long

/**********INPUT**********/
#define si(a) scanf("%d",&a)
#define MAX 10000001



using namespace std;



bool is_prime[MAX+5];
int factor[MAX+5];

bool sieve()
{
    LL i,j;
    memset(factor, 0, sizeof factor);
    int sq=sqrt(MAX);

    for(i=2; i<=sq; i++)
    {
        if(!is_prime[i])
        {
            for(j=i+i; j<=MAX; j+=i)
            {
                is_prime[j]=1;
                if(factor[j]!=-5)
                    factor[j]++;
            }

            for(j=1; j*i*i<=MAX; j++)
            {
                factor[j*i*i]=-5;
            }
        }
    }

    for(i=2; i<=MAX; i++)
    {
        if(factor[i]==0)
        {
            factor[i]=1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    LL i;
    sieve();

    long long n, res;
    int t, sq;
    si(t);
    while(t--)
    {
        scanf("%lld", &n);
        sq=sqrt(n);
        res=n;
        for(i=2; i<=sq; i++)
        {
            if(factor[i]>0)
            {
                if(factor[i]%2)
                    res=res-(n/(i*i));
                else
                    res=res+(n/(i*i));
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}

/*

14
10
100
1000
10000
100000
1000000
10000000
100000000
1000000000
10000000000


*/

