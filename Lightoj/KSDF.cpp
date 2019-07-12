#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <utility>
#include <ctime>
#include <climits>

using namespace std;

typedef long long LL;
#define MP make_pair
typedef pair<int, int> PII;

const int V = 10024;
const int E = 20086;
struct Graph {
    int head[V], cur[E], nxt[E], ne;
    void init() {
        ne = 0, memset(head, -1, sizeof(head));
    }
    void addEdge(int u, int v) {
        cur[ne] = v, nxt[ne] = head[u];
        head[u] = ne++;
    }
}g1, g2;

int dfn[V], low[V], bel[V];
int sta[V], top, idx, bcnt;
bool ins[V];
void init() {
    top = -1, idx = 0, bcnt = 0;
    memset(dfn, 0, sizeof(dfn));
    memset(ins, false, sizeof(ins));
}
void trajan(int u) {
    dfn[u] = low[u] = ++idx;
    ins[sta[++top]=u] = true;
    for (int i = g1.head[u]; i != -1; i = g1.nxt[i]) {
        int v = g1.cur[i];
        if (!dfn[v]) {
            trajan(v);
            low[u] = min(low[u], low[v]);
        } else if (ins[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        ++bcnt;
        do {
            int v = sta[top--];
            ins[v] = false;
            bel[v] = bcnt;
        } while (sta[top+1] != u);
    }
}
bool dist[V], g[V][V];
int q[V], st, ed;
void spfa(int src, int n) {
    memset(dist, false, sizeof(dist));
    st = ed = 0; q[ed++] = src;
    dist[src] = true;
    while (st != ed) {
        int u = q[st++];
        if (st == V) st = 0;
        for (int i = g2.head[u]; i != -1; i = g2.nxt[i]) {
            int v = g2.cur[i];
            if (!dist[v]) {
                dist[v] = true;
                q[ed++] = v;
                if (ed == V) ed = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        g[src][i] = dist[i];
    }
    g[src][src] = false;
}
/*int pre[V];
bool vist[V];
bool dfs(int u) {
    for (int i = 1; i <= bcnt; ++i) {
        if (g[u][i] && !vist[i]) {
            vist[i] = true;
            if (pre[i] == 0 || dfs(pre[i])) {
                pre[i] = u;
                return true;
            }
        }
    }
    return false;
}*/
const int INF = 0x3f3f3f3f;
int Mx[V], My[V];
int dx[V], dy[V], dis;
bool vist[V];
bool searchP() {
    queue<int> Q;
    dis = INF;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for (int i = 1; i <= bcnt; ++i) {
        if (Mx[i] == -1) {
            Q.push(i); dx[i] = 0;
        }
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (dx[u] > dis) break;
        for (int v = 1; v <= bcnt; ++v) {
            if (g[u][v] && dy[v] == -1) {
                dy[v] = dx[u] + 1;
                if (My[v] == -1) dis = dy[v];
                else {
                    dx[My[v]] = dy[v] + 1;
                    Q.push(My[v]);
                }
            }
        }
    }
    return dis != INF;
}
bool dfs(int u) {
    for (int v = 1; v <= bcnt; ++v) {
        if (!vist[v] && g[u][v] && dy[v] == dx[u] + 1) {
            vist[v] = true;
            if (My[v] != -1 && dy[v] == dis) continue;
            if (My[v] == -1 || dfs(My[v])) {
                My[v] = u, Mx[u] = v;
                return true;
            }
        }
    }
    return false;
}
int solved(int mm) {
    int n = mm, m, u, v;
    //scanf("%d %d", &n, &m);
    g1.init(), g2.init(), init();
//    for (int i = 0; i < m; ++i) {
//        scanf("%d %d", &u, &v);
//        g1.addEdge(u, v);
//    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) trajan(i);
    }
    for (int u = 1; u <= n; ++u) {
        for (int i = g1.head[u]; i != -1; i = g1.nxt[i]) {
            int v = g1.cur[i];
            if (bel[v] != bel[u]) {
                g2.addEdge(bel[u], bel[v]);
            }
        }
    }
    for (int i = 1; i <= bcnt; ++i) {
        spfa(i, bcnt);
    }
    int ans = 0;
    memset(Mx, -1, sizeof(Mx));
    memset(My, -1, sizeof(My));
    while (searchP()) {
        memset(vist, false, bcnt + 1);
        for (int i = 1; i <= bcnt; ++i) {
            if (Mx[i] == -1 && dfs(i)) ++ans;
        }
    }
    return  bcnt - ans;
}

vector< pair<int, int > >vec[10009];


int main()
{
    int cs = 1, i, j, k;
    int mm, u, v, w, nn, tt;
    int cases = 1;
    int
    while(cin>>nn>>mm>>tt && (nn || mm || tt))
    {
        for(i = 0; i <= nn; i++)
        {
            vec[i].clear();
        }
        for(i = 1; i <= mm; i++)
        {
            cin>>u>>v;
            vec[u].push_back(make_pair(v, i));
            vec[v].push_back(make_pair(u, i));
        }

        for(i = 1; i <= nn; i++)
        {
            int sz = vec[i].size();
            for(j = 0; j < sz; j++)
            {
                for(k = j + 1; k < sz; k++)
                {
                    g1.addEdge(vec[i][j].second,vec[i][k].second);
                    g1.addEdge(vec[i][k].second,vec[i][j].second);
                    cout<<vec[i][j].second<<" "<<vec[i][k].second<<endl;
                }
            }
            if(sz == 1)
                cnt++;
        }
        int res = solved(mm) - cnt;
        cout<<res<<endl;

    }
    return 0;
}



/*



8 7 2
1 3
2 3
3 4
4 5
4 6
6 7
6 8


*/
