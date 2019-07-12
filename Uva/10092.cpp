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

int main()
{
    int n, e, u, v, c, m, i;
    vector<int>ans[25];

   cin>>n>>m;
    {
        init(n + m + 1, n + m + 2, n + m + 2);

        int num;
        int sum = 0;
        for(i = 1; i <= n; i++)
        {
            cin>>num;
            sum += num;
            add(n + m + 1, i, num);
        }
        for(i = 1; i <= m; i++)
        {
            int k;
            cin>>k;
            while(k--)
            {
                cin>>num;
                add(num, i + n, 1);

            }
        }
        for(i = n + 1; i <= n + m; i++)
            add(i, n + m + 2, 1);
        int res =  dinitz();
        if(res != sum)
        {
            cout<<0<<endl;
            continue;
        }
        cout<<1<<endl;
        for(i = 0; i < 25; i++)
            ans[i].clear();
        for(i = 0; i < nEdge; i++)
        {
            if(flow[i] == cap[i] && flow[i] == 1 && from[i] >= 1 && from[i] <= n + m && to[i] >= 1 && to[i] <= n + m)
            {
                ans[min(from[i], to[i])].push_back(max(from[i], to[i]) - n);
            }
        }
        for(i = 1; i <= n; i++)
        {
            for(int j = 0; j < ans[i].size(); j++)
            {
                cout<<ans[i][j];
                if(j == ans[i].size() - 1)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<" ";
                }
            }
        }
    }

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
