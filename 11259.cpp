#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second

///***** Constant ******//
#define MX 1000007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7


using namespace std;

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}


/*

bool is_prime[MAX];
L prime[MAX];

bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
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
            prime[k++]=j;
        }
    }
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/


int used[100001];
int val[100001];
int c[5];
int d[5];

int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int n;
    int q;
    for(i = 0; i < 4; i++)
        cin>>c[i];
    cin>>q;
    while(q--)
    {
        memset(val, 0, sizeof val);
        for(i = 0; i < 4; i++)
        {
            cin>>d[i];
        }
        for(i = 0; i < 4; i++)
        {
            memset(used, 0, sizeof used);
            for(j = c[i]; j <= 100000; j++)
            {
                if(used[j - c[i]] < d[i])
                {
                    used[j] = used[j - c[i]] + 1;
                    val[j]++;
                }
            }
        }
        cin>>t;
        cout<<val[t]<<endl;

    }



    return 0;
}
/*

2
SQ 1 0
SQ 0 0
SQ 6 0
SQ 5 0



*/
