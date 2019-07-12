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
#define MX 120001
#define PB push_back



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
struct Z
{
    int u, v, w;
    Z(int _, int __, int ___)
    {
        u = _;
        v = __;
        w = ___;
    }
};
vector<Z> V;
int n, e;
int  dis[MX];



bool BellmanFord(int src)
{
    int i, j, k;
    for(i = 0; i < n; i++)
        dis[i] = INT_MAX;
    dis[src] = 0;
    for(i = 0; i < n - 1; i++)
    {
        cout<<i+1<<" step: ";
        for(j = 0; j < e; j++)
        {
            if(dis[V[j].u] + V[j]. w < dis[V[j].v])
                dis[V[j].v] = dis[V[j].u] + V[j].w;
        }
        for( j = 0; j < n; j++)
            cout<<dis[j]<<" ";
        cout<<endl;
    }
    cout<<endl;

    for(j = 0; j < e; j++)
    {
        if(dis[V[j].u] + V[j]. w < dis[V[j].v])
            return 1;  // I mean '1' is there is a negative circle.
    }


}


int main()
{
    int i,j,k;
    int cases=1;
    int u, v, w;
    cin>>n>>e;
    for(i = 0; i < e; i++)
    {
        cin>>u>>v>>w;
        V.PB(Z(u, v, w));
    }
    BellmanFord(0);

    return 0;
}
/*

-30 -10 5 2147483617
-60 -40 -25 -25
-90 -70 -55 -55
-120 -100 -85 -85



*/
