/********** Centroid Decomposition **************/

/**
initially node 1 is painted red.The distance between two tree nodes v and u is the number of edges in the shortest path between v and u.
1. paint a specified blue node in red;
2. calculate which red node is the closest to the given one and print the shortest distance to the closest red node.
**/
vi V[MAX], G[MAX];
int SZ[MAX], lvl[MAX], dist[30][MAX], tot, par[MAX];

void DFS(int u, int p)
{
    tot++;
    SZ[u] = 1;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(lvl[v] || v == p) continue;
        DFS(v, u);
        SZ[u] += SZ[v];
    }
}

int get_centroid(int u, int p)
{
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(v == p || lvl[v]) continue;
        if(SZ[v] > tot/2) return get_centroid(v, u);
    }
    return u;
}

void calculate_distance(int u, int p, int cst, int stp)
{
    dist[stp][u] = cst;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(lvl[v] || p == v) continue;
        calculate_distance(v, u, cst + 1, stp);
    }
}

void decompose(int u, int p, int stp)
{
    tot = 0;
    DFS(u, p);
    int center = get_centroid(u, p);
    calculate_distance(center, -1, 0, stp);
    lvl[center] = stp;
    par[center] = p;
    int sz = V[center].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[center][i];
        if(lvl[v]) continue;
        decompose(v, center, stp + 1);
    }
}

int res[MAX];
void update(int u)
{
    int v = u, l = lvl[u];
    while(v != -1)
    {
        res[v] = min(res[v], dist[l][u]);
        l--;
        v = par[v];
    }
}

int query(int u)
{
    int v = u, l = lvl[u], mn = INT_MAX;
    while(v != -1)
    {
        mn = min(res[v] + dist[l][u], mn);
        l--;
        v = par[v];
    }
    return mn;
}

int main()
{
    int j,  i, a, t, n, b, u, k, v, cases = 1, m, op, num;
    s2(n, m);
    for(i = 1; i < n; i++)
    {
        s2(u, v);
        V[u].pb(v);
        V[v].pb(u);
    }
    decompose(1, -1, 1);
    clr(res, 50);
    update(1);
    while(m--)
    {
        s2(op, num);
        if(op == 1)
            update(num);
        else
            printf("%d\n", query(num));
    }
    return 0;
}
/**
Input:
5 4
1 2
2 3
2 4
4 5
2 1
2 5
1 2
2 5
Output:
0
3
2
**/
