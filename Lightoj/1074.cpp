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
#define MX 211
#define MAX 8000*21
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
vector<int>conn[201];



bool BellmanFord(int src)
{
    int i, j, k;
    for(i = 1; i <= n; i++)
        dis[i] = MAX;
    dis[src] = 0;
    for(i = 1; i <= n; i++)
    {
        for(j = 0; j < e; j++)
        {
            if(dis[V[j].u] + V[j]. w < dis[V[j].v])
                dis[V[j].v] = dis[V[j].u] + V[j].w;
        }
    }
    return 0;
}

int val[MX];

bool vis[MX];
void DFS(int src)
{
    if(vis[src]) return;
    vis[src] = true;
    for(int i = 0; i < conn[src].size(); i++)
    {
        if(!vis[conn[src][i]])
            DFS(conn[src][i]);
    }
}

int main()
{
    int i,j,k;
    int cases=1;
    int u, v, w, t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i = 1; i <= n; i++)
        {
            cin>>val[i];
        }
        cin>>e;
        for(i = 0; i < e; i++)
        {
            cin>>u>>v;
            conn[u].PB(v);
            V.PB(Z(u, v, (val[v] - val[u])*(val[v] - val[u])*(val[v] - val[u])));
        }
        BellmanFord(1);
        DFS(1);
        printf("Case %d:\n", cases++);
        int op;
        cin>>op;
        while(op--)
        {
            cin>>i;
            // if(ok)
            //     cout<<"?"<<endl;
            // else
            {
                if(dis[i] < 3 || dis[i] == MAX || (!vis[i]))
                    cout<<"?"<<endl;
                else
                    cout<<dis[i]<<endl;
            }
        }
        V.clear();
        memset(val, 0, sizeof val);
        memset(vis, 0, sizeof vis);
        for(i=0; i< 201; i++)
            conn[i].clear();
    }
    return 0;
}
/*

5 9
0 1 6
0 3 7
2 1 -2
1 2 5
1 3 8
1 4 -4
3 4 9
3 2 -3
4 2 7



*/
