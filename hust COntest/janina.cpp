/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad written code **********
*/
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
#define ll long long
#define MX 50009
#define MAXN 50009
#define MOD 1000000000+7
#define PB push_back
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define mp make_pair

using namespace std;
int n;
struct Z
{
    int u, v;
    LL w;
    Z(int a, int b, LL c)
    {
        u = a;
        v = b;
        w = c;
    }
};

bool operator < (Z A, Z B)
{
    return A.w > B.w;
}


vector< int > adj[MAXN+1];
int root;
char flag[MAXN+1];
int L[MAXN+1];
int father[MAXN+1];
int A[MAXN+1][100+1];

void dfs(int cur)
{
    flag[cur] = true;
    int i;
    for(int i = 0; i < adj[cur].size(); i++)
    {
        if(!flag[adj[cur][i]])
        {
            father[adj[cur][i]] = cur;
            L[adj[cur][i]] = L[cur] + 1;
            dfs(adj[cur][i]);
        }
    }
}

LL cost[MX];
LL res[MX][20];
void pre_process()
{
    int i,j;
    for(i = 1; i <= n; i++)
        for(j = 0; (1<<j) <= n; j++)
            A[i][j] = -1;
    for(i = 1; i <= n; i++)
    {
        A[i][0] = father[i];
        res[i][0] = cost[i];
    }
    for(j = 1; (1<<j) <= n; j++)
        for(i = 1; i <= n; i++)
            if(A[i][j-1] != -1)
            {
                A[i][j] = A[A[i][j-1]][j-1];
                res[i][j] = max(res[i][j - 1], res[A[i][j-1]][j-1]);
            }
}


int getLCA(int p, int q)
{
    int i,log;
    if(L[p] < L[q]) swap(p,q);
    for(log=1; (1<<log)<=L[p]; log++);
    log--;
    LL ret = 0;
    for(i=log; i>=0; i--)
        if(L[p] - (1<<i) >= L[q])
        {

            ret = max(ret, res[p][i]);
            p = A[p][i];
        }
    if(p == q) return ret;
    for(i=log; i>=0; i--)
    {
        if(A[p][i] != -1 && A[p][i] != A[q][i])
        {
            ret = max(ret, res[p][i]);
            ret = max(ret, res[q][i]);
            p = A[p][i];
            q = A[q][i];
        }
    }
    ret = max(ret, cost[p]);
    ret = max(ret, cost[q]);
    return ret;
}


int par[MX];
int ranking[MX];
int find(int x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y)
{
    if(ranking[x] > ranking[y])
        par[y] = x;
    else
    {
        par[x] = y;
        if(ranking[x] == ranking[y])
            ranking[x]++;
    }
}



struct ZZ
{
    int node;
    LL cost;
};

map <pair<int, int> , LL>M;
void BFS(int src)
{
    queue<ZZ>Q;
    ZZ tmp;
    tmp.node = src;
    tmp.cost = 0;
    bool is[MX];
    memset(is, false, sizeof is);
    Q.push(tmp);

    while(!Q.empty())
    {
        ZZ top = Q.front();
        Q.pop();


        int cn = top.node;
        LL cc = top.cost;
        if(is[cn]) continue;
        cost[cn] = cc;
        is[cn] = true;

        for(int i = 0; i < adj[cn].size(); i++)
        {
            int an = adj[cn][i];
            if(is[an]) continue;

            tmp.node = an;
            tmp.cost =  M[mp(cn, an)];
            Q.push(tmp);
        }
    }
}


int  main()
{

    int i, j, k;
    int m;
    int cases = 0;
    int tc;
    while(cin>>n>>m)
    {
        int u, v;
        LL w;
        priority_queue <Z> PQ;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v>>w;
            PQ.push(Z(u, v, w));
        }

        for(i = 0; i <= n; i++)
        {
            par[i] = i;
            ranking[i] = 0;
        }
        while(!PQ.empty())
        {
            Z tmp = PQ.top();
            PQ.pop();
            int x = tmp.u;
            int y = tmp.v;
            LL cc = tmp.w;

            int px = find(x);
            int py = find(y);
            if(px != py)
            {
                Union(px, py);
                adj[x].PB(y);
                adj[y].PB(x);

                pair<int, int> PP = mp(x, y);
                M[PP] = cc;

                PP = mp(y, x);
                M[PP] = cc;
            }
        }
        root = 1;
        BFS(1);
        father[root] = -1;
        L[root] = 0;

        dfs(root);
        pre_process();

        int q;
        cin>>q;
        int t, s;
        if(cases) cout<<endl;
        cases++;
        while(q--)
        {
            cin>>s>>t;
            cout<<getLCA(s, t)<<endl;
        }
       // cout<<endl;

        M.clear();

        for(i = 0; i <= n; i++)
        {
            cost[i] = 0;
            flag[i] = false;
            adj[i].clear();
            L[i] = 0;
        }
    }

    return 0;
}
