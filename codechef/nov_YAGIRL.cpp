#include<bits/stdc++.h>

#define LL long long
#define MAX 1000001
#define PB(a) push_back(a)

using namespace std;





bool is_prime[MAX];
vector<int> prime;

void sieve()
{
    long i,j;
    prime.PB(2);
    int k=1;
    int sq=(sqrt(MAX));

    for(i=4; i<=MAX; i+=2)
        is_prime[i]=1;

    is_prime[1]=1;

    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime.PB(j);
        }
    }
}




vector<LL>V[1000001];
int main()
{
    FILE * fin, * fout;
    fin=fopen("input.txt","r");
    fout=fopen("output.txt","w");
    LL i,k,j;
    LL a,b;
    sieve();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld", &a, &b);
        if(a==1)
            a=2;
        int sz=prime.size();
        LL sq=sqrt(b);
        for(i=0; prime[i]<=sq && i<sz; i++)
        {
            LL p=prime[i];
            LL tmp=(ceil((double)a/p)*p);
            for(j=tmp; j<=b; j+=p)
                V[j-a].PB(p);
        }
        LL ans=0;
        for(k=0; k<=b-a; k++)
        {
            int len=V[k].size();
            if(len==0)
                ans++;
            else
            {
                LL num=a+k;
                LL mul=1;
                LL sqq=sqrt(num);
                for(i=0; i<len && V[k][i]<=sqq; i++)
                {
                    int cnt=1;
                    while(num%V[k][i]==0)
                    {
                        cnt++;
                        num=num/V[k][i];
                    }
                    mul*=cnt;
                    sqq=sqrt(num);
                }
                if(num>1) mul=mul*2;
                if(!is_prime[mul])
                    ans++;
            }
        }
        fprintf(fout, "%lld\n", ans);
        for(i=0; i<=1000000; i++)
            V[i].clear();
    }
    return 0;
}

/*

1
999999000000 1000000000000

4
100 1000
100 10000
100 100000
100 1000000

152
1230
9639
78655


*/
