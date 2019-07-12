#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 22222;
int low[MAXN],dfn[MAXN],ind[MAXN],outd[MAXN],belong[MAXN],t,n,m,deep,scc;
vector<int> g[MAXN];
stack<int> s;
void init()
{
    memset(dfn,-1,sizeof(dfn));
    memset(ind,0,sizeof(ind));
    memset(outd,0,sizeof(outd));
    memset(belong,-1,sizeof(belong));
    scc = deep = 0;
    for(int i=0; i<MAXN; i++)g[i].clear();
    while(!s.empty())s.pop();
}
void tarjan(int u)
{
    low[u] = dfn[u] = deep++;
    s.push(u);
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(dfn[v]==-1)
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(belong[v]==-1)
        {
            low[u] = min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u])
    {
        int v;
        do
        {
            v = s.top();
            s.pop();
            belong[v]=scc;
        }
        while(v!=u);
      //  cout<<scc<<" "<<u<<endl;
        scc++;
    }
}
void DFS(int u)
{
    dfn[u] = 1;
    for(int i=0; i<(int)g[u].size(); i++)
    {
        int v = g[u][i];
        if(belong[u]!=belong[v])
        {
            outd[belong[u]]++;
            ind[belong[v]]++;
        }
        if(!dfn[v])
        {
            DFS(v);
        }
    }
}
int solve()
{
    if(scc==1)return 0;
    int maxi=0,maxo=0;
    for(int i=0; i<scc; i++)
    {
        if(!outd[i])maxo++;
        if(!ind[i])maxi++;
        //cout<<i<<" "<<outd[i]<<" "<<ind[i]<<endl;
    }
    //cout<<maxo<<" "<<maxi<<endl;
    return max(maxi,maxo);
}
int main()
{
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        scanf("%d%d",&n,&m);
        init();
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a--,b--;
            g[a].push_back(b);
        }
        for(int i=0; i<n; i++)if(dfn[i]==-1)tarjan(i);
        memset(dfn,0,sizeof(dfn));
        //for(int i=0;i<n;i++)cout<<belong[i]<<endl;
        for(int i=0; i<n; i++)if(!dfn[i])DFS(i);
        printf("Case %d: %d\n",cas,solve());
    }
    return 0;
}
