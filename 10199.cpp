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
#define FOR(aa,bb) for(aa=0; aa<bb; aa++)
#define WHITE 0
#define BLACK 1
#define PB push_back


using namespace std;
const int NIL=-1000000000;

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
int N;
int col[101];
int p[101];
int low[101];
int d[101];
int root;
set<int>res;
set<int>::iterator it;

void dfs(vector<int>g[], int u,int kfather,int deep)
{
    int i,tot;
    col[u]=1;
    d[u]=deep;
    low[u]=deep;
    tot=0;
    for(i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v!=kfather&&col[v]==1)
            low[u]=min(low[u],d[v]);
        if(!col[v])
        {
            dfs(g,v,u,deep+1);
            tot++;
            low[u]=min(low[u],low[v]);
            if((u==root&&tot>1)||(u!=root&&low[v]>=d[u]))
            {
                res.insert(u);
            }
        }
    }
    col[u]=2;
}


void DFS(vector<int>G[])
{
    for(int i=0; i<=N; i++)
    {
        col[i]=WHITE;
        p[i]=NIL;
    }
    int i;
    for(i=1; i<=N; i++)
    {
        if(col[i]==WHITE)
        {
            root=i;
            dfs(G,i, 0, 0);
        }
    }
}

int main()
{
    int i,j,k;
    int cases=1;
    string str1, str2;
    vector<int>V[101];
    vector<string>VV;
    while(cin>>N && N)
    {
        map<string, int>M;
        map<int, string>val;

        M.clear();
        val.clear();
        res.clear();
        memset(col, 0, sizeof col);
        memset(p, 0, sizeof p);
        memset(low, 0, sizeof low);
        memset(d, 0, sizeof d);

        k=0;
        FOR(i,N)
        {
            cin>>str1;
            M[str1]=(++k);
            val[k]=str1;
        }
        int m;
        cin>>m;
        FOR(i,m)
        {
            cin>>str1>>str2;
            V[M[str1]].PB(M[str2]);
            V[M[str2]].PB(M[str1]);
        }
        DFS(V);
        if(cases>1)
            cout<<endl;
        printf("City map #%d: %d camera(s) found\n", cases++, res.size());

        for(it=res.begin(); it!=res.end(); it++)
        {
            int tmp=(*it);
            VV.PB(val[tmp]);

        }
        sort(VV.begin(), VV.end());
        for(int i=0; i<VV.size(); i++)
            cout<<VV[i]<<endl;
        res.clear();
        for(i=1; i<=N; i++)
            V[i].clear();
        VV.clear();
    }
    return 0;
}
/*


6 7
4 3




*/
