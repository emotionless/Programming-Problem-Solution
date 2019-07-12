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
int n;
bool vis[10001];
bool taken[10001];
int com[10001];
vector<int>sortedList;
vector<int>V[1000], VR[1000];
void DFS_VISIT(int u);
void DFS()
{
    for(int i=0; i<=n; i++)
        vis[i]=false;
    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
            DFS_VISIT(i);
    }
}

void DFS_VISIT(int u)
{
    vis[u]=true;
    for(size_t i=0; i<V[u].size(); i++)
    {
        int v=V[u][i];
        if(!vis[v])
            DFS_VISIT(v);
    }
    sortedList.PB(u);
}

void DFS_R_VISIT(int u, int id)
{
    vis[u]=false;
    com[u]=id;
    for(int i=0; i<VR[u].size(); i++)
    {
        if(vis[VR[u][i]])
            DFS_R_VISIT(VR[u][i], id);
    }
}

void traverse(int u)
{
    taken[u]=true;
    cout<<u<<" ";
    for(int i=0; i<V[u].size(); i++)
    {
        if(!taken[V[u][i]] && com[V[u][i]]==com[u])
        traverse(V[u][i]);

    }
}


int main()
{
    int i,j,k;
    int cases=1;
    int m, u, v;
    cin>>n>>m;

    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        V[u].PB(v);
        VR[v].PB(u);
    }

    DFS();

    int id=0;
    int sz=sortedList.size();

    for(i=sz-1; i>=0; i--)
    {
        if(vis[i])
            DFS_R_VISIT(sortedList[i], ++id);
    }

    for(int i=1; i<=n; i++)
    {
        if(!taken[i])
        {
            traverse(i);
            cout<<endl;
        }
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
