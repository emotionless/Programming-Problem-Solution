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
#define MX 250
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


    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;
        int src = 1;
        st = 1;
        ed = n + m + 2;
        int tot = 0, cst;
        for(i = 1; i <= n; i++)
        {
            cin>>cst;
            adj[src].PB(i + 1);
            cost[src][i + 1] = cst;
            tot += cst;
        }
        for(i = 1;  i <= m; i++)
        {
            cin>>cst;
            adj[i + n + 1].PB(ed);
            cost[i + n + 1][ed] = cst;
        }
        int num;
        for(i = 1; i <= n; i++)
        {
            cin>>k;
            while(k--)
            {
                cin>>num;
                adj[i + 1].PB(num + n + 1);
                adj[num + n + 1].PB(i + 1);
                cost[i + 1][num + n + 1] = INF;
            }
        }
        int flow = maxflow(src, ed);
        printf("Case %d: ", cases++);
        cout<<tot - flow<<endl;
        for(int i = 0; i < MX; i++)
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
