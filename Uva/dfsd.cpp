#include <bits/stdc++.h>

using namespace std;

#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long
#define pii pair<int, int>

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

pair<int, int> pp[MAXN],jj[MAXN];

int main()
{
    int n, e, u, v, c, m, i;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        getchar();
        int st = n + m + 1;
        int ed = n + m + 2;
        init(st, ed, ed);
        int j;


        for(i = 1; i <= n; i++)
        {
            string s;
            getline(cin,s);

            for(j=0; s[j]; j++)
            {
                if(s[j]==':')s[j]=' ';
            }
            stringstream ss(s);
            int h1,m1,h2,m2;
            ss>>h1;
            ss>>m1;
            ss>>h2;
            ss>>m2;

            pp[i]=(pii(h1*60+m1,h2*60+m2));
        }
        for(i = 1; i <= m; i++)
        {
            string s;
            getline(cin,s);

            for(j=0; s[j]; j++)
            {
                if(s[j]==':')s[j]=' ';
            }
            stringstream ss(s);
            int h1,m1,h2,m2;
            ss>>h1;
            ss>>m1;
            ss>>h2;
            ss>>m2;
            jj[i]=(pii(h1*60+m1,h2*60+m2));
        }
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                if(jj[j].first >= pp[i].first && jj[j].second <= pp[i].second)
                {
                    add(i, n + j, 1);
                }
            }
        }
        for(i = 1; i <= n; i++)
            add(st, i, 1);

        for(i = n + 1; i <= n + m; i++)
            add(i, ed, 1);
        cout<<dinitz()<<endl;
    }


    return 0;
}


/*





*/
