#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

const int maxn = 10010;
int t, n, idx;
int dep[maxn], size[maxn];
int son[maxn], tid[maxn];
int pre[maxn], top[maxn];
bool vis[maxn];
struct Edge
{
    int u, v, w;
    Edge() {};
    Edge(int a, int b, int c)
    {
        u = a, v = b, w = c;
    }
};
vector<Edge> edge[maxn];
Edge alledge[maxn];

int Max[maxn<<2];
int val[maxn];

void find_heavy_edge(int x, int father, int depth)
{
    vis[x] = true;
    pre[x] = father;
    dep[x] = depth;
    size[x] = 1;
    son[x] = -1;
    int maxsize = 0;
    int sz = edge[x].size();
    for (int i = 0; i < sz; ++i)
    {
        int child = edge[x][i].v;
        if (!vis[child])
        {
            find_heavy_edge(child, x, depth + 1);
            size[x] += size[child];
            if (size[child] > maxsize)
            {
                maxsize = size[child];
                son[x] = child;
            }
        }
    }
}


void connect_heavy_edge(int x, int ance)
{
    vis[x] = true;
    tid[x] = ++idx;
    top[x] = ance;
    if (son[x] != -1)
    {
        connect_heavy_edge(son[x], ance);
    }
    int sz = edge[x].size();
    for (int i = 0; i < sz; ++i)
    {
        int child = edge[x][i].v;
        if (!vis[child])
        {
            connect_heavy_edge(child, child);
        }
    }
}

void build(int l, int r, int rt)
{
    if (l == r)
    {
        Max[rt] = val[l];
        return ;
    }
    int m = (l + r) >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, (rt << 1) | 1);
    Max[rt] = max(Max[rt<<1], Max[rt<<1|1]);
}

void update(int l, int r, int rt, int p, int c)
{
    if (l == r)
    {
        Max[rt] = c;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m)
    {
        update(l, m, rt << 1, p, c);
    }
    else
    {
        update(m + 1, r, (rt << 1) | 1, p, c);
    }
    Max[rt] = max(Max[rt<<1], Max[rt<<1|1]);
}

int query(int l, int r, int rt, int L, int R)
{
    if (L <= l && R >= r)
    {
        return Max[rt];
    }
    int m = (l + r) >> 1;
    int tmp = -(1 << 30);
    if (L <= m)
    {
        tmp = max(tmp, query(l, m, rt << 1, L, R));
    }
    if (R > m)
    {
        tmp = max(tmp, query(m + 1, r, (rt << 1) | 1, L, R));
    }
    return tmp;
}

void CHANGE(int x, int val)
{
    if (dep[alledge[x].u] > dep[alledge[x].v])
    {
        update(2, n, 1, tid[alledge[x].u], val);
    }
    else
    {
        update(2, n, 1, tid[alledge[x].v], val);
    }
}

int QUERY(int a, int b)
{
    int ans = -(1 << 30);
    while (top[a] != top[b])
    {
        if (dep[top[a]] < dep[top[b]])
        {
            swap(a, b);
        }
        ans = max(ans, query(2, n, 1, tid[top[a]], tid[a]));
        cout<<a<<" "<<top[a]<<" "<<tid[top[a]]<<" "<<tid[a]<<endl;
        a = pre[top[a]];
    }
    if (dep[a] > dep[b])
    {
        swap(a, b);
    }
    if (a != b)
    {
        ans = max(ans, query(2, n, 1, tid[a] + 1, tid[b]));
    }
    return ans;
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i)
        {
            edge[i].clear();
        }
        int a, b, c;
        for (int i = 1; i <= n - 1; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            alledge[i].u = a;
            alledge[i].v = b;
            alledge[i].w = c;
            edge[a].push_back(Edge(a, b, c));
            edge[b].push_back(Edge(b, a, c));
        }
        memset(vis, false, sizeof(vis));
        find_heavy_edge(1, 1, 1);
        idx = 0;
        memset(vis, false, sizeof(vis));
        connect_heavy_edge(1, 1);


        // here this is

//
//        for(int i = 1; i <= n; i++)
//            cout<<i<<" "<<top[i]<<endl;
//        int i;
//        cin>>i;



        for (int i = 1; i <= n - 1; ++i)
        {
            if (dep[alledge[i].u] > dep[alledge[i].v])
            {
                val[tid[alledge[i].u]] = alledge[i].w;
            }
            else
            {
                val[tid[alledge[i].v]] = alledge[i].w;
            }
        }
        build(2, n, 1);
        char op[10];
        while (scanf("%s", op))
        {
            if (op[0] == 'D') break;
            scanf("%d%d", &a, &b);
            if (op[0] == 'Q')
            {
                printf("%d\n", QUERY(a, b));
            }
            else
            {
                CHANGE(a, b);
            }
        }
    }
    return 0;
}

/*

1

13
1 2 1
1 3 1
2 4 1
2 5 1
5 6 1
6 7 1
6 8 1
7 9 1
9 10 1
4 11 1
11 12 1
11 13 1

*/
