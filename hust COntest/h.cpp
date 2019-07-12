#include<bits/stdc++.h>

#define LL long long
#define pb push_back
#define MOD 1000000007
#define MX 1000

using namespace std;
vector<int>V[MX+10];
int indx;
int t[MX+10];

int cost[1010][1010];
int parent[1010];
bool act[1010];
bool BFS(int s, int tt)
{
    bool vis[1001];
    memset(vis, false, sizeof vis);

    queue<int>Q;

    vis[s]=true;
    Q.push(s);

    while(!Q.empty())
    {
        int cn=Q.front();
        Q.pop();

        int sz=V[cn].size();

        for(int i=0; i<sz; i++)
        {
            int adjn=V[cn][i];
            if(vis[adjn]==false && cost[cn][adjn]>0 && act[adjn]==false)
            {
                Q.push(adjn);
                parent[adjn]=cn;
                vis[adjn]=cn;
            }
        }
    }
    return vis[tt];
}



LL max_flow(int st, int ed)
{

    LL res=0;
    memset(parent, -1, sizeof parent);
    memset(act, false, sizeof act);

    /*
            for(int i=0;i<ed;i++)
            {
                if(V[i].size())
                {
                    cout<<i<<" ";
                    for(int j=0;j<V[i].size();j++)
                    cout<<V[i][j]<<" ";
                }
                cout<<endl;
            }
            */

    for(int i=0; i<1001; i++)
        for(int j=0; j<1001; j++)
            cost[i][j]=1;

    while(BFS(st,ed)==true)
    {
        int path_flow=1, u,v;
        for(v=ed; v!=st; v=parent[v])
        {
            u=parent[v];
            if(v!=ed)
            act[v]=true;
            cost[u][v]=0;
        }
        res+=path_flow;
    }
    return res;

}
int dir[MX+10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    indx=1;
    bool say=true;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i]>>dir[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(dir[i]==1)
        {
            V[0].pb(i);
            for(int j=i-1; j>=1; j--)
            {
                if(dir[j]==0)
                {
                    if(t[i]<=t[j]+b)V[i].pb(j);
                    else if(t[i]>=t[j]+a) V[i].pb(j);
                }
            }
        }
        else V[i].pb(n+1);
    }
    LL res=max_flow(0,n+1);
    if(res==n/2)
    {
        cout<<"No reason"<<endl;

        for(int i=1; i<=n; i++)
        {
            if(dir[i]==0) cout<<t[parent[i]]<<" "<<t[i]<<endl;
        }
    }
    else
        cout<<"Liar"<<endl;
    return 0;
}
