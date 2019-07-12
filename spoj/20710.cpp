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
#define MX 50009      // 10^6 + 7
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


LL T[MX];
int in[MX];
LL dp[MX];
vector<int>V[MX];

LL DFS(int src)
{
    if(dp[src] != -1) return dp[src];
    dp[src] = 0;
    for(int i = 0; i < V[src].size(); i++)
    {
        dp[src] = max(dp[src], DFS(V[src][i]));
    }
    //cout<<src<<" "<<dp[src]<<endl;
    return dp[src] = dp[src] + T[src];
}

int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int n;
    int m, u, v;
    cin>>n;
    cin>>m;
    for(i = 1; i <= n; i++)
        cin>>T[i];
    for(i = 1; i <= m; i++)
    {
        cin>>u>>v;
        V[u].PB(v);
        in[v]++;
    }
    queue<int>Q;
    for(i = 1; i <= n; i++)
    {
        if(!in[i])
        {
            Q.push(i);
        }
    }
    LL mx = 0;
    memset(dp, -1, sizeof dp);
    for(i = 1; i <= n; i++)
    {
        if(dp[i] == -1)
        {
            LL get = DFS(i);
            //cout<<i<<" "<<get<<endl;
            mx = max(mx, get);
        }
    }
    cout<<mx<<endl;

    return 0;
}
/*

2
SQ 1 0
SQ 0 0
SQ 6 0
SQ 5 0



*/
