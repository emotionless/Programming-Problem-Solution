#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#define LL long long
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define MAX (200009)
#define PB push_back
#define MOD 1000000007
#define MX 1009
#define INF INT_MAX



using namespace std;

/*

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

#define MAXX INT_MAX


#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

using namespace std;
struct Z
{
    int u, v;
    LL w;
    Z() {}
    Z(int _, int __, LL ___)
    {
        u = _;
        v = __;
        w = ___;
    }
};

vector<Z>V;
int n, m;



LL dis[MX];

bool BellmanFord()
{
    for(int i = 0; i <= n; i++)
        dis[i] = 1000000;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            dis[V[j].v] = min(dis[V[j].v],  dis[V[j].u] + V[j].w);
    }
    bool ck = true;
    for(int i = 0; i < m; i++)
    {
        if(dis[V[i].v] > dis[V[i].u] + V[i].w)
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int i,j;
    int cases=1;
    int a, b, u, v;
    LL w;
    int t;
    int P;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>P;
        V.clear();
        int I, E;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v>>I>>E;
            w = P*E - I;
            V.PB(Z(u, v, w));
        }


        printf("Case %d:", cases++);
        if(BellmanFord())
        {
            printf(" YES\n");
        }
        else
        {
            printf(" NO\n");
        }

    }

    return 0;
}
/*




*/
