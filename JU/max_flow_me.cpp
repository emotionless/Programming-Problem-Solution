#include<bits/stdc++.h>


#define mp make_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define pii pair<int, int>#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO

#define REadj  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)



#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9


#define MOD 1000000007
#define MX 205
#define INF 1000000000

using namespace std;


int st, ed;
int par[MX];

vector<int> adj[MX];
int cost[MX][MX];
int f;


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
        queue<int>Q;
        Q.push(st);
        clr(par, -1);
//        for(int i = 0; i < MX; i++) par[i] = -1;
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


int u, v, w;

int a[205];
int b[205];

int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        s2(n, m);
        st = 0;
        ed = n + 2;
        for(i = 1;i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for(i = 1;i <= n; i++)
        {
            scanf("%d", &b[i]);
        }
        int tmp;
        for(i = 1;i <= n; i++)
        {
            s1(tmp);
            if(tmp == 1)
            {
                adj[st].pb(i);
                cost[st][i] = a[i];
                adj[i].pb(st);

                adj[i].pb(ed);
                adj[ed].pb(i);
                cost[i][ed] = INF;

            }
            else if(tmp == 0)
            {
                adj[st].pb(i);
                adj[i].pb(st);
                cost[st][i] = a[i];

                adj[i].pb(ed);
                adj[ed].pb(i);
                cost[i][ed] = b[i];
            }
            else
            {
                adj[st].pb(i);
                adj[i].pb(st);
                cost[st][i] = INF;

                adj[i].pb(ed);
                adj[ed].pb(i);
                cost[i][ed] = b[i];
            }
        }

        for(i = 1; i <= m; i++)
        {
            s3(u, v, w);
            adj[u].pb(v);
            cost[u][v] = w;

            adj[v].pb(u);
            cost[v][u] = w;
        }

        int res = maxflow(st, ed);
        printf("Case %d: %d\n", cases++, res);

        for(int i = 0; i <= n + 2; i++)
        {
            adj[i].clear();
        }
        clr(cost, 0);
    }

    return 0;
}

/*


1
4 3
5 6 7 8
8 7 6 5
-1 0 0 1
1 2 10
3 4 10
2 3 1



*/
