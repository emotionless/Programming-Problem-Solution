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




int arr[1000001][15];
int cap[1000001];

int main()
{
    LL j;
    // int i;
    LL a,b;
    sieve();
    int t,k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld", &a, &b);
        if(a==1)
            a=2;
        int sz=prime.size();
        int sq=sqrt(b);
        for(int i=0; prime[i]<=sq && i<sz; i++)
        {
            int p=prime[i];
            LL tmp=(ceil((double)a/p)*p);
            for(j=tmp; j<=b; j+=p)
            {
                k=cap[j-a];
                arr[j-a][k]=p;
                cap[j-a]++;
            }
        }
        int ans=0;
        for(int k=0; k<=b-a; k++)
        {
            int len=cap[k];
            if(len==0)
                ans++;
            else
            {
                LL num=a+k;
                int mul=1;
                int sqq=sqrt(num);
                for(int i=0; i<len && arr[k][i]<=sqq; i++)
                {
                    int cnt=1;
                    while(num%arr[k][i]==0)
                    {
                        cnt++;
                        num=num/arr[k][i];
                        if(num==1) break;
                    }
                    mul*=cnt;
                    sqq=sqrt(num);
                }
                if(num>1) mul=mul*2;
                if(!is_prime[mul])
                    ans++;
            }
        }
        printf("%d\n", ans);

        memset(cap,0, sizeof cap);
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

5
1 1000000
1 1000000
1 1000000
1 1000000
1 1000000


*/
