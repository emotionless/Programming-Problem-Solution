#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 20009
#define mp make_pair

using namespace std;
int id;
int S[MX];
int ind[MX], low[MX];
bool vis[MX];
int tar[MX];
int scc;
vector<int>V[MX];
int top;
void tarjan(int u)
{
    //cout<<u<<endl;
    ind[u] = low[u] = (id++);
    vis[u] = true;
    S[top++] = (u);
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(ind[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(vis[v])
            low[u] = min(low[u], ind[v]);
    }
    int v;
    if(ind[u] == low[u])
    {
        do
        {
            v = S[--top];
            vis[v] = false;
            tar[v] = scc;
        }
        while(v != u);
        scc++;
    }
}
int out[MX];
int in[MX];
void DFS(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(tar[u] != tar[v])
        {
            out[tar[u]]++;
            in[tar[v]]++;
        }
        if(!vis[v])
            DFS(v);
    }
}



int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;
        for(i = 1; i <= n; i++)
            V[i].clear();
        clr(vis, false);
        clr(in, false);
        clr(out, false);
        clr(tar, -1);
        scc = top = id = 0;
        int u, v;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v;
            V[u].PB(v);
        }
        memset(ind, -1, sizeof ind);
        clr(low, 100000);
        for(i = 1; i <= n; i++)
        {
            if(ind[i] == -1)
                tarjan(i);
        }
        clr(vis,false);
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
                DFS(i);
        }

        int d = 0, o = 0;
        printf("Case %d: ", cases++);
        if(scc == 1)
        {
            cout<<0<<endl;
            continue;
        }
        for(i = 0; i < scc; i++)
        {
            if(!in[i]) d++;
            if(!out[i]) o++;
        }
        cout<<max(o, d)<<endl;


    }

    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
