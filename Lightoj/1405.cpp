#include <algorithm>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <iostream>

#define INF 100000

using namespace std;

const int maxnodes = 20009;

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
int n;
int m;


bool isValid(int a, int b)
{
    if(a < 0 || a >= n || b < 0 || b >= m) return false;
    return true;
}

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
int total_node;

int get(int r, int c)
{
    return r * m + c + 1;
}

string str[109];

int main()
{

    long long w;
    int i, j, k, cases = 1;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)
            cin>>str[i];
        total_node = n * m;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                for(int k = 0; k < 4; k++)
                {
                    int ax = i + dr[k];
                    int ay = j + dc[k];

                    if(isValid(ax, ay))
                    {
                        int num = get(i, j);
                        int to = get(ax, ay);
                        addEdge(num + total_node, to, INF);
                        //cout<<num + total_node<<" "<<to<<" "<<INF<<endl;
                    }
                }
                int num = get(i, j);
                addEdge(num, num + total_node, 1);
                //cout<<num<<" "<<num + total_node<<" "<<1<<endl;
            }
        }

        int st = 0;
        int ed = 2 * (n * m) + 2;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1)
                {
                    addEdge(get(i, j) + total_node, ed, INF);
                    //cout<<i <<" "<< j<<endl;
                }
            }
        }
        int cnt = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(str[i][j] == '*')
                {
                    cnt++;
                    int num = get(i, j);
                    addEdge(st, num, 1);
                }
            }
        }
        int res = maxFlow(st, ed);
        printf("Case %d: ", cases++);
        if(res == cnt)
        {
            printf("yes\n");
        }
        else
            printf("no\n");
        for(i = 0; i <= ed; i++)
            g[i].clear();
    }
    return 0;
}


/*

7 6
..*...
.*.*..
..*.*.
***..*
.....*
..**..
....*.



*/
