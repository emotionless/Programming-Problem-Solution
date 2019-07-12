#include <algorithm>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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
    Edge a = {t, g[t].size(), 0, cap};  //front-edge
    Edge b = {s, g[s].size(), 0, 0};    // back-edge
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
                save[u]
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
int main()
{
    int n ;
    int m, u, v;
    long long w;
    scanf("%d %d", &n, &m);
    int i, t, num, st = 0, ed = n + m + 1;
    for(i = 1; i <= n; i++)
    {
        cin>>num;
        addEdge(i + n, ed, num);
     //   cout<<i<<" "<<endl;
    }

    for( i = 1; i <= m;  i++)
    {
        cin>>t;
        while(t--)
        {
            cin>>num;
            addEdge(i, num + n, 1);
        }
        addEdge(0, i, 1);
    }
    cout << maxFlow(st, ed) << endl;


return 0;
}
