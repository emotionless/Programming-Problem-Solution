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
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("D-small-attempt0.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 100000000
#define PI acos(-1.0)
#define piii pair<int, pii>

using namespace std;

///******* Template ********///

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)

#define MX 10000000000000000ll
#define lim 50010      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************




const int maxnodes = 50009;

int nodes = maxnodes, src, dest;
long long dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge
{
    int to, rev;
    long long  f, cap;
};

vector<Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, long long  cap)
{
    Edge a = {t, g[t].size(), 0, cap};
    Edge b = {s, g[s].size(), 0, 0};
    g[s].push_back(a);
    g[t].push_back(b);
}

bool dinic_bfs()
{
    fill(dist, dist + nodes, -1);
    dist[src] = 0;
    int qt = 0;
    q[qt++] = src;
    for (int qh = 0; qh < qt; qh++)
    {
        int u = q[qh];
        for (int j = 0; j < (int) g[u].size(); j++)
        {
            Edge &e = g[u][j];
            int v = e.to;
            if (dist[v] < 0 && e.f < e.cap)
            {
                dist[v] = dist[u] + 1;
                q[qt++] = v;
            }
        }
    }
    return dist[dest] >= 0;
}

long long  dinic_dfs(int u, long long f)
{
    if (u == dest)
        return f;
    for (long long  &i = work[u]; i < (int) g[u].size(); i++)
    {
        Edge &e = g[u][i];
        if (e.cap <= e.f) continue;
        int v = e.to;
        if (dist[v] == dist[u] + 1)
        {
            long long  df = dinic_dfs(v, min(f, e.cap - e.f));
            if (df > 0)
            {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

long long  maxFlow(int _src, int _dest)
{
    src = _src;
    dest = _dest;
    long long  result = 0;
    while (dinic_bfs())
    {
        fill(work, work + nodes, 0);
        while (long long  delta = dinic_dfs(src, INT_MAX))
            result += delta;
    }
    return result;
}

struct Z
{
    int fst, snd;
    Z(){}
    Z(int _, int __)
    {
        fst = _;
        snd = __;
    }
    bool operator<(const Z& A) const
    {
        return fst > A.fst;
    }
};


vector<pii> V[MAX];

// dijkstra

int cost2[MAX];
bool vis[MAX];

int DIJKSTRA2(int n)
{
    clr(vis, false);
    priority_queue<Z>PQ;

    PQ.push(Z(0, n));

    while(!PQ.empty())
    {
        Z top = PQ.top();
        PQ.pop();

        int cn = top.snd;
        int cc = top.fst;
        if(vis[cn]) continue;
        vis[cn] = 1;
        cost2[cn] = cc;

        int sz = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int adjn = V[cn][i].xx;
            int adjc = V[cn][i].yy + cc;
            if(!vis[adjn])
                PQ.push(Z(adjc, adjn));
        }

    }
    return cost2[1];
}


int cost1[MAX];




int DIJKSTRA(int n)
{
    clr(vis, false);
    priority_queue<Z>PQ;

    PQ.push(Z(0, 1));

    while(!PQ.empty())
    {
        Z top = PQ.top();
        PQ.pop();

        int cn = top.snd;
        int cc = top.fst;
        if(vis[cn]) continue;
        vis[cn] = 1;
        cost1[cn] = cc;

        int sz = V[cn].size();
//        cout<<sz<<endl;
        for(int i = 0; i < sz; i++)
        {
            int adjn = V[cn][i].xx;
            int adjc = V[cn][i].yy + cc;
            if(!vis[adjn])
                PQ.push(Z(adjc, adjn));
        }
    }
    return cost1[n];
}

pair< pii, int> take[MAX];

int main()
{
    int n = 3;
    int m, u, v, cases = 1;
    int w;
    int t;
    s1(t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        int st, ed;
        st = 1, ed = n;

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            take[i].xx.xx = u;
            take[i].xx.yy = v;
            take[i].yy = w;
            V[u].pb(mp(v, w));
            V[v].pb(mp(u, w));
//            addEdge(u, v, w);
        }

        clr(cost1, 62);
        clr(cost2, 62);

        int c1 = DIJKSTRA(n);
        int c2 = DIJKSTRA2(n);
        if(c1 < c2) assert(0);


        for(int i = 0; i <= n; i++) V[i].clear();


        for(int i = 0; i < m; i++)
        {
            u = take[i].xx.xx;
            v = take[i].xx.yy;
            w = take[i].yy;

            if((cost1[u] + cost2[v] + w) == c1 || (cost1[v] + cost2[u] + w) == c1 )
            {
            }
            else
            {
                if(u > v) swap(u, v);
                addEdge(u, v, take[i].yy);
                addEdge(v, u, take[i].yy);
                V[u].pb( mp(v, w) );
                V[v].pb( mp(u, w) );
            }
        }

        clr(cost1, 62);
        int cst = DIJKSTRA(n);

        printf("Case %d: ", cases++);
        int flow =  maxFlow(st, ed) ;

        if(cst >= 1e8)
            printf("-1 -1\n");
        else
            printf("%d %d\n", cst, flow);

        for(int i = 0; i < maxnodes; i++)
        {
            g[i].clear();
            if(i <=n) V[i].clear();
        }
    }
    return 0;
}
