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
#define MX 100009
#define mp make_pair
#define INF 100000

using namespace std;

string mat[23];
int id;
int num;

map < pair<int, int>, int > M;
int n, m;
int getId(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(mat[x][y] != '*') return 0;
    pair<int, int>p = MP(x, y);

    if(!M[p]) M[p] = (++id);
    return M[p];
}

// flow is here

int src, sink, nNode, nEdge;
int flow[MX], cap[MX], to[MX], from[MX], nxt[MX], fin[MX];
int dist[MX], Q[MX], pro[MX];


inline void init(int _src, int _sink, int __node)
{
    src = _src;
    sink = _sink;
    nNode = __node;
    nEdge = 0;
    clr(fin, -1);
}

inline void add(int u, int v, int c)
{
    to[nEdge] = v, from[nEdge] = u, flow[nEdge] = 0, cap[nEdge] = c, nxt[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, from[nEdge] = v, flow[nEdge] = 0, cap[nEdge] = c, nxt[nEdge] = fin[v], fin[v] = nEdge++;
}



bool bfs()
{
    int st, en, i, u, v;
    clr(dist, -1);
    dist[src] = st = en = 0;
    Q[en++] = src;

    while(st < en)
    {
        u = Q[st++];
        for(i=fin[u]; i>=0; i=nxt[i])
        {
            v = to[i];

            if(flow[i] < cap[i] && dist[v]==-1)
            {
                dist[v] = dist[u]+1;
                Q[en++] = v;
            }
        }
    }
    return dist[sink]!=-1;
}


int dfs(int u, int f1)
{
    if(u == sink) return f1;
    for(int &e = pro[u], v, df; e >= 0; e = nxt[e])
    {
        v = to[e];
        if(flow[e] < cap[e] && dist[v] == dist[u] + 1)
        {
            df = dfs(v, min(cap[e] - flow[e], f1));
            if(df > 0)
            {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}




int dinitz()
{
    int ret = 0;
    int df = 0;

    while(bfs())
    {
        for(int i = 1; i <= num; i++) pro[i] = fin[i];
        while(true)
        {
            df = dfs(src, INF);
            if(df) ret += df;
            else
                break;
        }
    }
    return ret;
}

#include <algorithm>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


string mat[23];
int id;
int num;

map < pair<int, int>, int > M;
int n, m;
int getId(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(mat[x][y] != '*') return 0;
    pair<int, int>p = make_pair(x, y);

    if(!M[p]) M[p] = (++id);
    return M[p];
}




//  flow is here


const int maxnodes = 5009;
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
    Edge b = {s, g[s].size(), 0, cap};
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

int lft[23][23];
int dr[] = {0, -1, 0, 1, 0};
int dc[] = {0, 0, 1, 0, -1};

int main()
{
    int i, j, k;
    int t, cases = 1;
    cin>>n>>m;

    for(i = 0; i < n; i++)
        cin>>mat[i];

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(mat[i][j] == '*')
                lft[i][j] = (++num);
        }
    }
    int st = 801, ed = 802;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(lft[i][j])
            {
                for(k = 0; k < 5; k++)
                {
                    int x = i + dr[k];
                    int y = j + dc[k];
                    int get = getId(x, y);
                    if(get)
                    {
                        addEdge(lft[i][j], get + num, 1);
                    }
                }
                addEdge(st, lft[i][j], 2);
            }
        }
    }

    for(i = num + 1; i <= num + id; i++)
        addEdge(i, ed, 1);
    cout<<maxFlow(st, ed)<<endl;
    int cnt = 0;
    for(i = 0; i < g[st].size(); i++)
    {
        cout<<g[st][i].f<<endl;
    }








    return 0;
}


/*

3 4
**oo
**oo
*oo*

*/
