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


/// MIN COST MAX FLOW

#define maxn 200010
#define maxe 202020

struct  MinCostMaxFlow
{
    struct node
    {
        int from,to,next,cap;
        int cst;
    }
    edge[maxe];

    int  head[maxn];
    int  q[maxn],front,rear,avail,vn;
    int  in[maxn],pre[maxn];
    int  cost[maxn];
    bool vis[maxn];

    void init(int maxnode)
    {
        avail=0;
        vn=maxnode;
        memset(head,-1,sizeof(head));
    }

    void insert(int from,int to,int cap,int cst)
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

    bool spfa(int src,int des)
    {
        for(int i=0; i<=vn; i++) cost[i]=INT_MAX;

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
            int u=q[front++],v;
            front%=maxn;
            vis[u]=false;
            for(int i=head[u]; i!=-1; i=edge[i].next)
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


    pair<int,int> mincostmaxflow(int src,int des)
    {
        int mincost=0,i,j,maxflow=0;

        while( spfa(src,des) )
        {
            int flow=INT_MAX;

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
//        cout<<"here"<<endl;
        return make_pair(mincost,maxflow);
    }

} MCMF;

map<int, int>M, pos;



int main()
{
    int i, j, k;
    int tc,cases = 1;
    int n, m;
    long long c, sz;


    cin>>n;
    MCMF.init(2*n+2);
    for(i = 1; i <= n; i++)
    {
        cin>>c>>sz;
        M[sz] = c;
        pos[sz] = i;
        MCMF.insert(i+n, 2*n+2, 1, -c);
    }
    cin>>m;
    for(i = 1; i <= m; i++)
    {
        cin>>c>>sz;
        MCMF.insert(2*n+1, i, 1, 0);
        if(M.find(sz) != M.end() && M[sz] <= c){
            MCMF.insert(i, pos[sz] + n, 1, 0);
            cout<<i<<" "<<pos[sz]<<endl;
        }
        if(M.find(sz+1) != M.end() && M[sz+1] <= c){
            cout<<i<<" "<<pos[sz-1]<<endl;
            MCMF.insert(i, pos[sz+1] + n, 1, 0);
        }
    }
    pii ans = MCMF.mincostmaxflow(2*n+1, 2*n+2);
    cout<<ans.xx<<" "<<ans.yy<<endl;








    return 0;
}
/*
2
2
0 0
0 0
3
1 4 5
5 7 6
5 8 8

*/
