#include<cstdio>
#include<algorithm>
#include <bits/stdc++.h>
#include<vector>
#define re(i,a,b) for(int i=a;i<=b;++i)
#define sf scanf
#define si(a) sf("%d",&a)
#define pf printf
#define ps while(1)
#define pb push_back
#define inf 0xffffff
#define multi int T;si(T);re(t,1,T)
#define cse pf("Case %d: ",t)
#define csel pf("Case %d:\n",t)
using namespace std;
vector<int> eg[2010],wt[2010];
int d[2010],f[2010];
int mx=-1;
void dfs(int u)
{
    if(f[u])return;
    f[u]=1;
    mx=max(u,mx);
    re(k,0,int(eg[u].size())-1)dfs(eg[u][k]);
}
int main()
{
    multi
    {
        int n,m;
        si(n);
        si(m);
        fill(eg,eg+n,vector<int>());
        fill(wt,wt+n,vector<int>());
        fill(d,d+n,0);
        fill(f,f+n,0);
        mx=-1;
        re(i,1,m)
        {
            int u,v,w;
            si(u),si(v),si(w);
            eg[v].pb(u);
            wt[v].pb(w);
        }
        re(i,1,n-1)
        {
            re(j,0,n-1)
            {
                re(k,0,int(eg[j].size())-1)
                {
                    int u=j,v=eg[j][k],w=wt[j][k];
                    if(d[u]+w<d[v])d[v]=d[u]+w;
                }
            }
            cout<<"FOR "<<i<<" : "<<endl;
            for(int j = 0; j < n; j++)
                cout<<d[j]<<" ";
            cout<<endl;
        }
        re(j,0,n-1)
        {
            re(k,0,int(eg[j].size())-1)
            {
                int u=j,v=eg[j][k],w=wt[j][k];
                if(d[u]+w<d[v])dfs(u);
            }
        }
        cse;
        if(mx==-1)pf("impossible\n");
        else re(i,0,n-1)
        {
            if(f[i])
            {
                pf("%d",i);
                if(i==mx)pf("\n");
                else pf(" ");
            }
        }
    }
    return 0;
}
