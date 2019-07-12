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
#define MX 410
#define mp make_pair
#define INF 1000000

using namespace std;


int st, ed;
int par[MX];

vector<int> adj[MX];
int cost[MX][MX];
int f;


int augment(int v, int mn)
{
    //cout<<v<<endl;
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
        queue<int>Q;
        Q.push(st);
        for(int i = 0; i < MX; i++) par[i] = -1;
        par[st] = 0;
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            int sz = adj[u].size();
            if(u == ed) break;
            //cout<<endl<<u<<" can: "<<endl;

            for(int i = 0; i < sz; i++)
            {
                int v = adj[u][i];
                if(cost[u][v] > 0 && par[v] == -1)
                {
                    par[v] = u;
                    Q.push(v);
                    //cout<<v<<endl;
                }
            }
        }
        f = 0;
        augment(ed, INF);
        if(f == 0)
            break;
        ret += f;
    }
return ret;
}




int main()
{
    int i, j, k;
    int t, cases = 1;
    int u, v;


    int n, m;
    //scanf("%d", &t);
    //while(t--)
    {
        scanf("%d %d", &n, &m);
        int src = 1;
        st = n*2 + 1;
        ed = n * 2 + 2;

        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            adj[u].PB(n + v);
            adj[n + v].PB(u);
            cost[u][n + v] = INF;

            adj[v].PB(n + u);
            adj[n + u].PB(v);
            cost[v][n + u] = INF;
        }
        for(i = 1; i <= n; i++)
        {
            adj[st].PB(i);
            cost[st][i] = 1;
            adj[i + n].PB(ed);
            cost[i + n][ed] = 1;
        }
        int flow = maxflow(st, ed);
        printf("%d\n",n - flow);

        for(int i = 0; i <= 2*n + 5; i++)
        {
            adj[i].clear();
        }
        clr(cost, 0);
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
