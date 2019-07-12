#include<bits/stdc++.h>

#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX  1009
#define mp make_pair

using namespace std;

#define MAX 100001
#define NIL 0
#define INF (1<<28)


vector<int>G[MX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs()
{
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++)
    {
        if(match[i]==NIL)
        {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        if(u!=NIL)
        {
            len = G[u].size();
            for(i=0; i<len; i++)
            {
                v = G[u][i];
                if(dist[match[v]]==INF)
                {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u)
{
    int i, v, len;
    if(u!=NIL)
    {
        len = G[u].size();
        for(i=0; i<len; i++)
        {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1)
            {
                if(dfs(match[v]))
                {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp()
{
    int matching = 0, i;
    memset(match, 0, sizeof match);
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}


vector<int>V[MX];

int ind[MX], low[MX], Stack[MX], val[MX];
bool isStack[MX];

int comp, id, top;
bool taken[MX][MX];
void tarjan(int u)
{
    ind[u] = low[u] = (++id);
    Stack[top++] = u;
    isStack[u] = true;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(ind[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(isStack[v])
            low[u] = min(low[u], ind[v]);
    }
    int v;
    if(ind[u] == low[u])
    {
        comp++;
        do
        {
            v = Stack[--top];
            isStack[v] = false;
            val[v] = comp;

        }
        while(v != u);
    }
}

bool visited[MX];
vector<int>GR[MX];
void connect(int u)
{
    memset(visited, false, sizeof visited);
    queue<int>Q;
    Q.push(u);

    while(!Q.empty())
    {
        int cn = Q.front();
        Q.pop();
        if(visited[cn]) continue;
        visited[cn] = true;
        int sz = GR[cn].size();

        for(int i = 0; i < sz; i++)
        {
            int v = GR[cn][i];
            if(!visited[v])
                Q.push(v);
        }
    }
    visited[u] = false;
    for(int i = 1; i <= comp; i++)
        if(visited[i])
        {
           // taken[u][i] = true;
            G[u].PB(i + comp);
            //cout<<u<<" "<<i<<endl;
        }
}

int main()
{

    int i, j, k, u, v;
    int t, cases = 1;
    s1(t);
    while(t--)
    {

        s2(n, m);
        for(i = 0; i <= n; i++)
        {
            V[i].clear();
            G[i].clear();
            GR[i].clear();
            val[i] = -1;
//            matchR[i] = -1;
            isStack[i] = false;
            ind[i] = -1;
        }
        vector< pair<int, int> >edge;
        edge.clear();
        for(i = 0; i < m; i++)
        {
            s2(u, v);
            V[u].PB(v);
            edge.PB(make_pair(u, v));
        }


        comp = 0;
        id = 0, top = 0;
        for(i = 1; i <= n; i++)
        {
            if(ind[i] == -1)
            {
                tarjan(i);
            }
        }
        memset(taken, false, sizeof taken);
        n  = comp;
        for(i = 0; i < m; i++)
        {
            u = val[edge[i].first];
            v = val[edge[i].second];
            if(u != v)
            {
                GR[u].PB(v);

                //cout<<u<<" "<<v<<endl;
            }
        }
        for(i = 1; i <= comp; i++)
        {
            connect(i);
        }
        n = comp;
        int res = hopcroft_karp();
        printf("Case %d: %d\n", cases++, comp - res);
    }
    return 0;
}

/*

1
1 0
1



*/


/*


*/
