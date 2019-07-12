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
#define MX 100000
#define LESS_MX 10000000

using namespace std;
struct Z
{
    int u, v, w;
};
vector<Z>V;
vector<int>adj[10001];
int n, m;
int val[10001];
bool vis[10001];


void DFS(int u)
{
    if(vis[u]) return;
    vis[u] = true;
    for(int i = 0; i < adj[u].size(); i++)
        if(!vis[adj[u][i]])
            DFS(adj[u][i]);
}

bool Bellman_Ford()
{
    for(int i = 0; i < n; i++)
        val[i] = 10000000;

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            val[V[j].v] = min(val[V[j].v], val[V[j].u] + V[j].w);
    }
    bool ck = false;
    for(int i = 0; i < m; i++)
    {
        if(val[V[i].v] > val[V[i].u] + V[i].w)
        {
            ck = true;
            DFS(V[i].u);
        }
    }
    return ck;
}



int main()
{
    int i, j, k;
    int t, cases = 1;
    Z tmp;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        V.clear();
        for(i = 0; i < n; i++)
            adj[i].clear();
        for(i = 0; i < m; i++)
        {
            cin>>tmp.u>>tmp.v>>tmp.w;
            swap(tmp.u, tmp.v);
            V.PB(tmp);
            adj[tmp.u].PB(tmp.v);
        }

        memset(vis, false, sizeof vis);

        bool is = Bellman_Ford();
        printf("Case %d:", cases++);
        if(!is)
            cout<<" impossible"<<endl;
        else
        {
            for(int i = 0; i < n; i++)
                if(vis[i])
                    cout<<" "<<i;
            cout<<endl;
        }
    }
    return 0;
}

