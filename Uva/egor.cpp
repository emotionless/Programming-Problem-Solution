/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://shygypsy.com/tools/
 * LICENSE:
 *      http://shygypsy.com/tools/LICENSE.html
 * Copyright (c) 2006
 * Contact author:
 *      abednego at gmail.c0m
 **/

/****************
 * Maximum flow * (Dinic's on an adjacency list + matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * RUNNING TIME:
 *      - O(n^3)
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission (Gives WA, but it's probably my graph building that's wrong)
 *      - Valladolid 563:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 **/

#include <string.h>
#include <stdio.h>
#include <bits/stdc++.h>

// the maximum number of vertices
#define NN 1024
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

using namespace std;

const int INF = 0x7fffffff;
const int MAXN = 5005, MAXE = 60006;

int src, snk, nNode, nEdge;
int Q[MAXN], fin[MAXN], pro[MAXN], dist[MAXN];
int flow[MAXE], cap[MAXE], next[MAXE], to[MAXE];

inline void init(int _src, int _snk, int _n)
{
    src = _src, snk = _snk, nNode = _n, nEdge = 0;
    SET(fin);
}

inline void add(int u, int v, int c)
{
    to[nEdge] = v, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[u], fin[u] = nEdge++;
    to[nEdge] = u, cap[nEdge] = c, flow[nEdge] = 0, next[nEdge] = fin[v], fin[v] = nEdge++;
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
        for(i=fin[u]; i>=0; i=next[i])
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
    int a;
    cin>>a;
    if(u==snk) return fl;
    cout<<endl<<u<<endl;
    for(int &e=pro[u], v, df; e>=0; e=next[e])
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
        int tmp;
        cin>>tmp;
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
    int n, e, u, v, c, i;

    scanf("%d %d", &n, &e);
    init(0, n + e + 1, n + e);
    //
    long long w;
    for(i = 1; i <= n; i++)
    {
        cin>>w;
        add(0, i, w);
    }
    for(i = 1; i <= e; i++)
    {
        int t;
        cin>>t;
        while(t--)
        {
            cin>>v;
            add(v, n + i, 1);
            add(n + i, n + e + 1, 1);
        }
    }
    //
    printf("%lld\n", dinitz());
    return 0;
}
