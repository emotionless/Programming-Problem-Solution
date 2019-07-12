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
#define PII pair<int, int>
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


/// shaheen
#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define inf 100000000
#define INF 100000000

#define MOD 1000000007
#define MAX 100009





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




LL  n,m;


/// MIN COST MAX FLOW

#define maxn 310
#define maxe 202020

struct  MinCostMaxFlow
{
    struct node
    {
        LL  from,to,next,cap;
        LL  cst;
    }
    edge[maxe];

    LL   head[maxn];
    LL   q[maxn],front,rear,avail,vn;
    LL   in[maxn],pre[maxn];
    LL   cost[maxn];
    bool vis[maxn];

    void init(LL  maxnode)
    {
        avail=0;
        vn=maxnode;
        memset(head,-1,sizeof(head));
    }

    void insert(LL  from,LL  to,LL  cap,LL  cst)
    {
        edge[avail].from=from;
        edge[avail].to=to;
        edge[avail].cap=cap;
        edge[avail].cst=cst;
        edge[avail].next=head[from];
        head[from]=avail++;

        edge[avail].from=to;
        edge[avail].to=from;
        edge[avail].cap=0;
        edge[avail].cst=-cst;
        edge[avail].next=head[to];
        head[to]=avail++;
    }

    bool spfa(LL  src,LL  des)
    {
        for(LL  i=0; i<=vn; i++) cost[i]=INT_MAX;

        memset(vis,0,sizeof(vis));
        memset(in,0,sizeof(in));

        cost[src]=0;
        pre[src]=-1;

        front=0,rear=1;
        q[front]=src;

        vis[src]=true;
        in[src]++;

        while(front!=rear)
        {
            LL  u=q[front++],v;
            front%=maxn;
            vis[u]=false;
            for(LL  i=head[u]; i!=-1; i=edge[i].next)
            {
                v=edge[i].to;
                if(edge[i].cap>0&&cost[v]>cost[u]+edge[i].cst)
                {
                    cost[v]=cost[u]+edge[i].cst;
                    pre[v]=i;
                    if(!vis[v])
                    {
                        q[rear++]=v;
                        rear%=maxn;
                        vis[v]=true;
                        in[v]++;
                        if(in[v]>vn) return false;
                    }
                }
            }
        }

        if(cost[des]<INT_MAX) return true;
        else return false;
    }


    pair<LL ,LL > mincostmaxflow(LL  src,LL  des)
    {
        LL  mincost=0,i,j,maxflow=0;

        while( spfa(src,des) )
        {
            LL  flow=INT_MAX;

            for(i=pre[des]; i!=-1; i=pre[edge[i].from])
            {
                flow=min(flow,edge[i].cap);
            }

            maxflow+=flow;

            for(i=pre[des]; i!=-1; i=pre[edge[i].from])
            {
                edge[i].cap-=flow;
                edge[i^1].cap+=flow;
            }

            mincost+=cost[des]*flow;
        }
        return make_pair(mincost,maxflow);
    }

} MCMF;

LL  arr[100];
LL  num[100];


int main()
{
    LL  i, j, k;
    LL  tc,cases = 1;
    cin>>tc;
    LL  cp, u, v, cst;
    LL  p;
    LL  g;
    while(tc--)
    {
        cin>>n>>k>>g;
        LL  st = 0, ed = 2*n + 1;
        for(i = 1; i <= n; i++)
            cin>>arr[i];
        MCMF.init(ed);
        for(i = 1; i <= n; i++)
        {
            cin>>num[i];
            for(j = 1;  j <= n; j++)
            {
                if(arr[j] >= num[i]) continue;
                LL need = ((num[i] - arr[j]) - k);
                need = need * need;
                need = min(need, (LL)g);
                MCMF.insert(i, j + n, 1, (LL )need);
            }
            MCMF.insert(st, i, 1, 0);
        }
        for(i = 1; i <= n; i++)
            MCMF.insert(i + n, ed, 1, 0);
        PII res = MCMF.mincostmaxflow(st, ed);
        LL fst = res.xx;
        if(res.yy < n)
        {
            printf("Case %lld: impossible\n", cases++);
            continue;
        }


        MCMF.init(ed);
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= n; j++)
            {
                if(arr[j] >= num[i]) continue;
                LL need = ((num[i] - arr[j]) - k);
                need = need * need;
                need = min(need, (LL)g);
                MCMF.insert(i, j + n, 1, -(LL )need);
            }
            MCMF.insert(st, i, 1, 0);
        }
        for(i = 1; i <= n; i++)
            MCMF.insert(i + n, ed, 1, 0);


        PII res1 = MCMF.mincostmaxflow(st, ed);

        printf("Case %lld: %lld %lld\n", cases++, fst, -res1.xx);
    }

    return 0;
}
/*

2
3 7 11
8 9 10
9 11 20
2 10 10
1 11
2 12

*/
