#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 2000009

#define NIL 0
#define INF (1<<28)

using namespace std;

vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

int i, u, v, len;
bool bfs()
{
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
    // match[] is assumed NIL for all vertex in G
    while(bfs())
    {
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    }
    return matching;
}

int dr[] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[] = {-1, 1, 2, 2, 1, -1, -2, -2};


//int dr[]={1,1,-1,-1,2,2,-2,-2};
//int dc[]={2,-2,2,-2,1,-1,1,-1};

int main()
{
    int u, v, k, i, j;
    int nn, mm;
//    cin>>nn>>mm;
    scanf("%d %d", &nn, &mm);

    if(nn==2||mm==2) goto jmpl;

    if(nn==1||mm==1)
    {
        printf("%d\n",nn*mm);
    }


    else if((nn*mm)%2==0) printf("%d\n",nn*mm/2);
    else printf("%d\n",(nn*mm+1)/2);
    return 0;
jmpl:
    int tot = nn * mm;
    for(i = 1; i <= nn; i++)
    {
        for(j = 1; j <= mm; j++)
        {
            for(k = 0; k < 8; k++)
            {
                int x = dr[k] + i;
                int y = dc[k] + j;
                if(x >= 1 && x <= nn && y >= 1 && y <= mm)
                {
                    int id1 = (i - 1)*mm + j;
                    int id2 = (x - 1)*mm + y;
                    G[id1].pb(tot + id2);
                    G[tot + id2].pb(id1);
                }
            }
        }
    }
//    cout<<"sdf"<<endl;
    n = tot;
    int res = hopcroft_karp();
//    cout<<n - res/2<<endl;
    printf("%d\n", n - res/2);







    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
