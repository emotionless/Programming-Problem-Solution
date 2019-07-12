#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXN1 = 50009;
const int MAXN2 = 50009;
const int MAXM = 150009;

int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];

void init(int _n1, int _n2)
{
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + MAXN1, -1);
}

void addEdge(int u, int v)
{
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
}

void bfs()
{
    fill(dist, dist + MAXN1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u)
    {
        if (!used[u])
        {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++)
    {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prev[e])
        {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0)
            {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}

bool dfs(int u1)
{
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prev[e])
    {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2))
        {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}

int maxMatching()
{
    fill(used, used + MAXN1, false);
    fill(matching, matching + MAXN1, -1);
    for (int res = 0;;)
    {
        bfs();
        fill(vis, vis + MAXN1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}


int A[101];
int B[101];
int main()
{
    int e, u, v;
    int tc, cases = 1;
    cin>>tc;
    while(tc--)
    {
        cin>>n1;
        int t = n1;
        for(int i = 0; i < t; i++)
        {
            cin>>A[i];
        }
        cin>>n2;
        t = n2;
        for(int i = 0; i < n2; i++)
        {
            cin>>B[i];
        }
        init(n1, n2);

        for(int i = 0; i < n1; i++)
        {
            for(int j = 0; j < n2; j++)
            {
                if(B[j] % A[i] == 0)
                    addEdge(i, j);
            }
        }

        printf("Case %d: %d\n", cases++, maxMatching());
    }
}
