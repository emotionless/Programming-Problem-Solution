#include<bits/stdc++.h>

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
#define PB push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 200009


using namespace std;


/// max flow is here



const int maxnodes = 7009;

int nodes = maxnodes, src, dest;
long long dist[maxnodes], q[maxnodes], work[maxnodes];

struct Edge
{
    int to, rev;
    long long  f, cap;
};

vector<Edge> g[maxnodes];

/// Adds bidirectional edge
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
        {
            result += delta;
        }
    }
    return result;
}









/// max flow is here




bool is_prime[MAX];
LL prime[MAX];

int sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
    return k;
}


long long NOD(long long n)
{
    if(n == 1) return 0ll;
    int  i,j,k;
    LL sq=sqrt(n);
    long long res=0;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=0;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res+=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res+=1;
    return res;
}

LL arr[333];
int f[333], s[333];

vector < pair< int, int > >have[333];

int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    int tot = sieve();
    cin>>n>>m;
    LL gcd = 0;
    for(i = 1; i <= n; i++)
    {
        cin>>arr[i];
        for(j = 0; j < tot && prime[j] < arr[i]; j++)
        {
            if(arr[i] % prime[j] == 0)
            {
                int cnt = 0;
                while(arr[i] % prime[j] == 0)
                {
                    arr[i] /= prime[j];
                    cnt++;
                }
                have[i].PB(mp(prime[j], cnt));
                if(arr[i] == 1) break;
            }
        }
        if(arr[i] > 1)
            have[i].PB(mp(arr[i], 1));
    }
    int id =  0;
    map < pair<int, int > , int> M;
    int mxid = 3000;
    for(i = 1; i <= n; i++)
    {
        int s = have[i].size();
        for(j = 0; j < s; j++){
            M[mp(i, j)] = (++id);
            addEdge(id, mxid + id, have[i][j].yy);
//            cout<<id<<" "<<mxid + id<<" "<< have[i][j].yy<<endl;
        }
    }
    int st = 7007;
    int ed = 7008;

    for(k = 1; k <= m; k++)
    {
        cin>>f[k]>>s[k];
        if(f[k] % 2) swap(f[k], s[k]);

        for(i = 0; i < have[ f[k] ].size(); i++)
        {
            for(j = 0; j < have[s[k]].size(); j++)
            {
                if(have[f[k]][i].xx == have[s[k]][j].xx)
                {
//                    cout<<"sdfsdfsdf"<<endl;
                    addEdge(M[mp(f[k], i)] + mxid, M[mp(s[k], j)], have[f[k]][i].yy);
//                    cout<<M[mp(f[k], i)] <<" "<< M[mp(s[k], j)]<<" "<< have[f[k]][i].yy<<endl;

                }
            }
        }
    }

//    cout<<"Add is here\n";

    for(k = 1; k <= n; k++)
    {
        if(k%2) continue;
        int sz = have[k].size();
        for(i = 0; i < sz; i++)
        {
            addEdge(st, M[mp(k, i)], 100000);
        }
    }
    for(k = 1; k <= n; k++)
    {
        if(k%2 == 0) continue;
        int sz = have[k].size();
        for(i = 0; i < sz; i++)
        {
            addEdge(M[mp(k, i)] + mxid,  ed,  have[k][i].yy);
        }
    }



    cout<<maxFlow(st, ed)<<endl;

    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
