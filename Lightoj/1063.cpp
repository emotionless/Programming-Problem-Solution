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

using namespace std;
vector<int>V[100001];
int n;
int p[100001];
bool col[100001];
int t;
int d[100001];
int low[100001];
set<int>res;
void DFS(int u)
{
    t++;
    low[u] = d[u] = t;
    col[u] = true;      // visited
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(col[v] == 0)
        {
            p[v] = u;
            DFS(v);
            if(d[u] == 1)
            {
                if(V[u].size() >=2 && low[v] > low[u])
                    res.insert(u);
            }
            else if(low[v] >= d[u])
                res.insert(u);
            low[u] = min(low[u], low[v]);
        }
        else if(p[u] != v)
            low[u] = min(low[u], d[v]);
    }
    t = t + 1;
}

void AP()
{

    for(int i = 0; i <= n; i++)
    {
        p[i] = (-1);
        col[i] = 0;
        low[i] = 0;
    }
    t = 0;

    for(int i = 1; i <= n; i++)
    {
        if(col[i] == 0)
            DFS(i);
    }
}




int main()
{
    int i, j, k;
    int m, u, v;
    int cases = 1, t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v;
            V[u].PB(v);
            V[v].PB(u);
        }

        AP();
        int sz = res.size();
        printf("Case %d: ", cases++);
        cout<<sz<<endl;
        res.clear();
        for(int i = 0; i < 100001; i++)
            V[i].clear();
    }


    return 0;
}
