#include<bits/stdc++.h>

#define eps 1e-8
#define xx first
#define yy second
#define LL long long
#define inf 100000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MOD 1000000007
#define MP make_pair
#define MX 100005

using namespace std;

vector<int>G[MX],V[MX],hold[MX];
bool chk[MX],onstack[MX];
int st[MX],ed[MX],color[MX],deg[MX],val[MX],child[MX],sz[MX],mnval[MX];
stack<int>S;
int component,n,m,cnt;

void tarjan(int x,int p)
{
    st[x]=cnt;
    ed[x]=cnt++;
    S.push(x);
    onstack[x]=true;
    chk[x]=true;
    for(int i=0; i<G[x].size(); i++)
    {
        int adj=G[x][i];
        if(adj==p) continue;
        if(!chk[adj])
        {
            tarjan(adj,x);
            ed[x]=min(ed[x],ed[adj]);
        }
        else if(onstack[adj]) ed[x]=min(ed[x],st[adj]);
    }
    if(st[x]==ed[x])
    {
        int top;
        component++;
        mnval[component]=10000000;
        do
        {
            top=S.top();
            S.pop();
            sz[component]+=val[top];
            color[top]=component;
            if(val[top]) hold[component].pb(top);
            onstack[top]=false;
            mnval[component]=min(mnval[component],top);
        }
        while(top!=x);
        reverse(hold[component].begin(),hold[component].end());
    }
}

int dfs(int x)
{
    chk[x]=true;
    child[x]+=sz[x];
    int mx=0;
    for(int i=0; i<V[x].size(); i++)
    {
        if(!chk[V[x][i]]) mx=max(mx,dfs(V[x][i]));
        else mx=max(mx,child[V[x][i]]);
    }
    child[x]+=mx;
    return child[x];
}

vector<int>ans,pr;

void getRes(int x)
{
    if(sz[x]) ans.pb(x);
    int mx=0,nd=-1;
    for(int i=0; i<V[x].size(); i++)
    {
        int adj=V[x][i];
        if(child[adj]>mx)
        {
            mx=child[adj];
            nd=adj;
        }
    }
    if(nd!=-1) getRes(nd);
}


void printRes()
{
    vector<int>tmp;
    int mnn=10000000,pp;
    int As=ans.size();
    for(int i=0; i<As; i++)
    {
        if(mnval[ans[i]]<mnn)
        {
            mnn=mnval[i];
            pp=i;
        }
    }
    for(int i=pp; i<As; i++) tmp.pb(ans[i]);
    for(int i=0; i<pp; i++) tmp.pb(ans[i]);
    ans.clear();
    for(int i=0; i<As; i++) ans.pb(tmp[i]);

    for(int i=0; i<As; i++)
    {
        int id=ans[i];
        sort(hold[id].begin(),hold[id].end());
        for(int i=0; i<hold[id].size(); i++) pr.pb(hold[id][i]);
    }
    int prsz=pr.size();
    for(int i=0; i<prsz; i++)
    {
        if(i) printf(" ");
        printf("%d",pr[i]);
    }
    puts("");
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int kase=1; kase<=test; kase++)
    {
        int k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0; i<k; i++)
        {
            int u;
            scanf("%d",&u);
            val[u]=1;
        }
        for(int i=0; i<m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].pb(v);
        }
        for(int i=1; i<=n; i++) sort(G[i].begin(),G[i].end());

        component=0;
        cnt=1;
        for(int i=1; i<=n; i++)
        {
            if(!chk[i])
            {
                tarjan(i,-1);
            }
        }
        for(int i=1; i<=n; i++)
        {
            int sz=G[i].size();
            if(sz==0) continue;
            for(int j=0; j<sz; j++)
            {
                if(color[i]!=color[G[i][j]])
                {
                    V[color[i]].pb(color[G[i][j]]);
                    deg[color[G[i][j]]]++;
                }
            }
        }
        memset(chk,false,sizeof chk);
        int ok=0;
        for(int i=1; i<=component; i++)
        {
            if(deg[i]==0)
            {
                int get=dfs(i);
                if(get==k)
                {
                    getRes(i);
                    ok=1;
                    break;
                }
            }
        }
        if(ok) printRes();
        else puts("-1");

        memset(val,0,sizeof val);
        memset(chk,false,sizeof chk);
        memset(deg,0,sizeof deg);
        memset(sz,0,sizeof sz);
        memset(onstack,false,sizeof onstack);
        memset(child,0,sizeof child);
        ans.clear();
        pr.clear();
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            V[i].clear();
            hold[i].clear();
        }
    }
    return 0;
}

/*

4 4 3
2 3 4
1 2
2 4
4 3
3 4

*/
