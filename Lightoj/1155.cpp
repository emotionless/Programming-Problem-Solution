#include <algorithm>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <iostream>

#define INF 100000

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



int main()
{
    int n = 3;
    int m, u, v, i, num;
    int w;
    int t, cases = 1;
    cin>>t;
    while(t--)
    {
        scanf("%d %d", &n, &m);
        int src = 1, sink = n;
        for(i = 2; i < n; i++)
        {
            cin>>num;
            addEdge(i, i + 50, num);

        }
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            if(u > v) swap(u, v);
            if(u == 1)
            {
                addEdge(u, v, w);
                addEdge(v + 50, u, w);
            }
            else if(v == n)
            {
                addEdge(v, u, w);
                addEdge(u + 50, v, w);
            }
            else
            {
                addEdge(u + 50, v, w);
                addEdge(v + 50, u, w);
            }
        }
        printf("Case %d: ", cases++);
        cout << maxFlow(src, sink) << endl;

        for(i = 0; i < 103; i++)
            g[i].clear();
    }
}

/*

1
9 5
46 307 78 140 789 892 364
2 7 394
2 3 337
1 3 673
6 8 840
2 9 497


*/
