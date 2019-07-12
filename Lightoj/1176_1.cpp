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
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 100009
#define MX 200
#define INF 100000



using namespace std;
///******* Template ********///


template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}


///***** Template ends here *****///
///********************* Code starts here ****************************




vector<int>V[MX];
int cost[MX][MX];



bool BFS(int s, int t, int parent[])
{
    bool vis[MX];

    memset(vis, false, sizeof vis);
    memset(parent, -1, sizeof parent);

    queue<int>Q;

    vis[s]=true;
    Q.push(s);
    while(!Q.empty())
    {
        int cn=Q.front();
        Q.pop();

        int sz=V[cn].size();
        for(int i=0; i<sz; i++)
        {
            int adjn=V[cn][i];

            if(vis[adjn]==false && cost[cn][adjn]>0)
            {
                Q.push(adjn);
                parent[adjn]=cn;
                vis[adjn]=true;
            }
        }
    }
    return vis[t];
}



int max_flow(int st, int ed)
{
    int parent[MX];
    int res=0;

    while(BFS(st,ed, parent)==true)
    {
        int path_flow=INT_MAX, u,v;


        for(v=ed; v!=st; v=parent[v])
        {
            u=parent[v];
            path_flow=min(path_flow, cost[u][v]);
        }

        for(v=ed; v!=st; v=parent[v])
        {
            u=parent[v];

            cost[u][v]-=path_flow;
            cost[v][u]+=path_flow;
        }
        res+=path_flow;
    }
    return res;

}




int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    string str, inp;
    int t, n;

    map<string, int>M;
    M["XXL"] = 101;
    M["XL"] = 102;
    M["L"] = 103;
    M["M"] = 104;
    M["S"] = 105;
    M["XS"] = 106;
    int cases = 1;

    int num, m;
    int a, b, c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        clr(cost, 0);
        int st = 0, ed = 110;
        for(i = 0; i < MX; i++)
            V[i].clear();
        for(i = 1; i <= m; i++)
        {
            cin>>str;
            int to = M[str];
            V[i + m].pb(to);
            V[to].pb(i + m);
            cost[i + m][to] = INF;

            cin>>str;
            to = M[str];
            V[i + m].pb(to);
            V[to].pb(i + m);
            cost[i + m][to] = INF;
        }

        for(i = 1; i <= m; i++)
        {
            V[st].pb(i);
            V[i + m].pb(st);
            cost[st][i] = INF;
            cost[i + m][st] = INF;
        }

        for(i = 101; i <= 106; i++)
        {
            V[i].pb(ed);
            V[ed].pb(i);
            cost[i][ed] = n;
        }
        for(i = 1; i <= m; i++)
        {
            V[i].pb(i + m);
            V[i + m].pb(i);
            cost[i][i + m] = 1;
        }
        int get = max_flow(st, ed);
        if(get == m)
            printf("Case %d: YES\n", cases++);
        else
            printf("Case %d: NO\n", cases++, get);
    }




    return 0;
}

/*

10 5
4 4 5 8 8

1 2 3 4
1 4 3 2
2 4 3 1

*/
