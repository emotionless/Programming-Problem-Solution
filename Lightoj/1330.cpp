#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define pb push_back
#define MP make_pair
#define MOD 1000000007
#define MX 120
#define mp make_pair
#define INF 1000000

using namespace std;

int n, m;
int cost[MX][MX];
int par[MX];
int st, ed, f;
vector<int> adj[MX];

int row, cl, ok;

int augment(int v, int mn)
{
    if(v == st) return f = mn;
    else if(par[v] != -1)
    {
        int u = par[v];
        augment(u, min(mn, cost[u][v]));
        cost[u][v] -= f, cost[v][u] += f;
    }
}

int maxflow(int st, int ed)
{
    int ret = 0;
    while(true)
    {
        for(int i = 0; i < MX; i++)
            par[i] = -1;
        par[st] = 0;
        queue<int>Q;
        Q.push(st);

        while(!Q.empty())
        {
            int top = Q.front();
            Q.pop();
            if(top == ed) break;
            for(int i = 0; i < adj[top].size(); i++)
            {
                int v = adj[top][i];
                if(cost[top][v] > 0 && par[v] == -1)
                {
                    Q.push(v);
                    par[v] = top;
                }
            }
        }
        f = 0;
        augment(ed, INF);
        if(!f || ret > row) break;
        ret+=f;
    }
    return ret;
}




int main()
{
    int i, j, k;
    int t, cases = 1;

    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;

        for(i = 0; i < MX; i++)
        {
            adj[i].clear();
            for(j = 0; j < MX; j++)
                cost[i][j] = 0;
        }
        st = n + m + 1;
        ed = n + m + 2;
        row = 0, cl = 0, ok = 1;
        int cst = 0;
        for(i = 1; i <= n; i++)
        {
            cin>>cst;
            if(cst > m) ok = 0;
            cost[st][i] = cst;
            row += cst;
        }

        for(j = 1; j <= m; j++)
        {
            cin>>cst;
            cl += cst;
            if(cst > n) ok = 0;
            cost[j + n][ed] = cst;
        }

        for(j = 1; j <= m; j++)
        {
            adj[j + n].pb(ed);
            adj[ed].pb(j + n);
            for(i = 1; i <= n; i++)
            {
                adj[j + n].pb(i);
                cost[i][j + n] = 1;
            }
        }

        for(i = n; i >= 1; i--)
        {
            for(j = 1; j <= m; j++)
            {
                adj[i].pb(j + n);
            }
            adj[st].pb(i);
            adj[i].pb(st);
        }
        printf("Case %d:", cases++);

        if(!ok || row != cl || row > n * m)
        {
            cout<<" impossible"<<endl;
            continue;
        }

        if(maxflow(st, ed) != row)
        {
            cout<<" impossible"<<endl;
        }
        else
        {
            cout<<endl;
            for(i = 1; i <= n; i++)
            {
                for(j = 1; j <= m; j++)
                    cout<<1-cost[i][n + j];
                cout<<endl;
            }
        }
    }

    return 0;
}

/*

3 3
2 0 3
3 2 0

*/
