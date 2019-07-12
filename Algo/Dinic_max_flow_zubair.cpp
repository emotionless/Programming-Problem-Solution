#include <bits/stdc++.h>

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 60006;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], from[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], nxt[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n)
{
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(int u, int v, int c)
{
    to[nEdge] = v, from[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, nxt[nEdge] = fin[u], fin[u] = nEdge;
    nEdge++;
    to[nEdge] = u, from[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, nxt[nEdge] = fin[v], fin[v] = nEdge;
    nEdge++;
}

bool bfs()
{
    int st, en, i, u, v;
    SET(dist);
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
    return dist[snk]!=-1;
}

int dfs(int u, int fl)
{
    if(u==snk) return fl;
    for(int &e=pro[u], v, df; e>=0; e=nxt[e])
    {
        v = to[e];
        if(flow[e] < cap[e] && dist[v]==dist[u]+1)
        {
            df = dfs(v, min(cap[e]-flow[e], fl));
            if(df>0)
            {
                flow[e] += df;
                flow[e^1] -= df;
                return df;
            }
        }
    }
    return 0;
}

i64 dinitz()
{
    i64 ret = 0;
    int df;
    while(bfs())
    {
        for(int i=1; i<=nNode; i++) pro[i] = fin[i];
        while(true)
        {
            df = dfs(src, INF);
            if(df) ret += (i64)df;
            else break;
        }
    }
    return ret;
}


int w;

int a[205];
int b[205];


int main()
{
    int n, e, u, v, c, m, i, cases = 1;
    scanf("%d %d", &n, &m);
    init(n + 1, n + 2, n + 3);

    int st = n + 1;
    int ed = n + 2;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    int tmp;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        if(tmp == 1)
        {

            add(st, i, a[i]);
            add(i, ed, INF);


        }
        else if(tmp == 0)
        {
            add(st, i, a[i]);
            add(i, ed, b[i]);
        }
        else
        {
            add(st, i, INF);
            add(i, ed, b[i]);
        }
    }

    for(i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }

    int res = dinitz();
    printf("Case %d: %d\n", cases++, res);

    return 0;
}


/*

3 15
3 3 4
2 1 2
1 3
1 3
1 3
1 3
3 1 2 3
2 2 3
2 1 3
1 2
1 2
2 1 2
2 1 3
2 1 2
1 1
3 1 2 3





*/
