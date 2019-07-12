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
#define PB push_back
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
#define MAX 100009


using namespace std;
int n, m, s;
struct Z
{
    int v, pre;
    LL w;
    Z() {}
    Z(int ___, int _, LL __)
    {
        pre = ___;
        v = _;
        w = __;
    }
    bool operator < (const Z& A) const
    {
        return w > A.w;
    }
};

map< pair< pair<int, int> , LL> , bool>M;
vector<Z>V[MAX];
LL dist[MAX];
LL l;

bool vis[100009];
LL cost[100009];

int DIJKSTRA()
{
    for(int i = 0; i <= n; i++)
        dist[i] = INT_MAX, vis[i] = false;

    Z tmp;
    tmp.v = s;
    tmp.pre = -1;
    tmp.w = 0;
    priority_queue<Z>PQ;
    PQ.push(tmp);
    int cnt = 0;

    while(!PQ.empty())
    {
        tmp = PQ.top();
        PQ.pop();
        int cn = tmp.v;
        int pre = tmp.pre;
        LL cc = tmp.w;
        if(vis[cn]) continue;
        vis[cn] = true;
        if(cc >= l) continue;

        dist[cn] = cc;

        int sz = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int adjn = V[cn][i].v;
            LL adjc = V[cn][i].w;
            if(adjn == pre) continue;

            if(adjc + cc == l)
            {
                pair < pair<int, int>, LL> P = mp(mp(adjn, adjn), 0ll);
                if(!M[P] && !vis[adjn] && cost[adjn] == cc + adjc)
                {
                    M[P] = true;
                    cnt++;
                }
                continue;
            }
            else if(adjc + cc > l)
            {

                LL len = l - cc;
                LL rest = adjc - len;
                if(rest + cost[adjn] >= l)
                {
                    pair < pair<int, int>, LL> P = mp(mp(cn, adjn), len);
                    if(M[P]) continue;
                    pair < pair<int, int>, LL> P1 = mp(mp(adjn, cn), rest);
                    if(!M[P1])
                        cnt++;
                    M[P1] = true;
                    M[P] = true;
                }
                continue;
            }
            if(!vis[adjn] && adjc + cc < dist[adjn])
            {
                tmp.v = adjn;
                tmp.w = cc + adjc;
                tmp.pre = cn;
                PQ.push(tmp);
            }

        }
    }
    return cnt;
}




void DIJKSTRA_first()
{
    for(int i = 0; i <= n; i++)
        cost[i] = INT_MAX, vis[i] = false;

    priority_queue<Z>PQ;
    Z tmp;
    tmp.v = s;
    tmp.w = 0;
    PQ.push(tmp);

    while(!PQ.empty())
    {
        Z top = PQ.top();
        PQ.pop();

        int cn = top.v;
        LL cc = top.w;

        if(vis[cn]) continue;
        cost[cn] = cc;
        vis[cn] = true;

        int sz = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int adjn = V[cn][i].v;
            LL adjc = V[cn][i].w + cc;
            if(!vis[adjn] && adjc < cost[adjn])
            {
                tmp.v = adjn;
                tmp.w = adjc;
                //cost[adjn] = adjc;
                PQ.push(tmp);
            }
        }
    }
}





int main()
{
    int tc,cs=1,i,j,k, v, u;
    LL w;
    cin>>n>>m>>s;
    M.clear();

    fr(i, m)
    {
        cin>>u>>v>>w;
        V[u].PB(Z(0,v, w));
        V[v].PB(Z(0,u, w));
    }

    cin>>l;
    if(l == 0)
    {
        cout<<1<<endl;
        return 0;
    }
    DIJKSTRA_first();
    int res = DIJKSTRA();
    cout<<res<<endl;

    for(i = 0; i <= n; i++)
        V[i].clear();
    return 0;
}

/*
//

6 8 3
3 1 1
3 2 1
3 4 1
3 5 1
1 2 6
4 5 6
5 6 6
3 6 1
4


*/
