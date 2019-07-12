/**** Lowest common ancestor, insert-> Nlog(N), query-> long(N) *****/
#include <bits/stdc++.h>

#define LL long long
#define PB push_back
#define MAXN 1000007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7

using namespace std;

vector< int > adj[MAXN+1];
int n, root;
char flag[MAXN+1];
int L[MAXN+1];
int in[MAXN+1];
int father[MAXN+1];
int A[MAXN+1][100+1];
LL INF = 10000000;

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

void pre_process()
{
    int i,j;
    for(i = 1; i <= n; i++)
        for(j = 0; (1<<j) <= n; j++)
            A[i][j] = -1;
    for(i = 1; i <= n; i++)
        A[i][0] = father[i];
    for(j = 1; (1<<j) <= n; j++)
        for(i = 1; i <= n; i++)
            if(A[i][j-1] != -1)
                A[i][j] = A[A[i][j-1]][j-1];
}


int getLCA(int p, int q)
{
    int i,log;
    if(L[p] < L[q]) swap(p,q);
    for(log=1; (1<<log)<=L[p]; log++);
    log--;
    for(i=log; i>=0; i--)
        if(L[p] - (1<<i) >= L[q])
            p = A[p][i];
    if(p == q) return p;
    for(i=log; i>=0; i--)
    {
        if(A[p][i] != -1 && A[p][i] != A[q][i])
        {
            p = A[p][i];
            q = A[q][i];
        }
    }
    return father[p];
}


int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int a, b, v, u, q;

    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(i = 1; i <= n; i++) adj[i].clear(), flag[i] = false;
        int m;
        for(i = 1; i <= n; i++)
        {
            cin>>m;
            while(m--)
            {
                cin>>v;
                in[v]++;
                adj[v].PB(i);
                adj[i].PB(v);
            }
        }

        for(i = 1; i <= n; i++)
        {
            if(in[i] == 0) root = i;
            break;
        }
        father[root] = -1;
        L[root] = 0;

        dfs(root);
        pre_process();

        // query is here
        cin>>q;
        printf("Case %d:\n", cases++);
        while(q--)
        {
            cin>>u>>v;
            printf("%d\n", getLCA(u, v));
        }

    }
    return 0;
}
