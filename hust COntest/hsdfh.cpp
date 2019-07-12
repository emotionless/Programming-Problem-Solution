///BISMILLAHIR RAHMANIR RAHIM

/**************************************************************
 *                       NILOY-D-ROCKER                       *
 *                          JU_CSE_21                         *
 ************************************************************** */

#include <bits/stdc++.h>

#define S scanf
#define P printf

#define LL long long int
#define ULL unsigned long long int
#define D double

#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SQR(n) (n*n)
#define eps 1e-9
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)
#define MEM(a,val) memset(a,val,sizeof(a))

#define all(a) a.begin(),a.end()
#define X first
#define Y second

#define SET(a,i) memset(a,i,sizeof a)
#define open freopen("input.txt","r",stdin)
#define close freopen ("output.txt","w",stdout)

#define S1(a) scanf("%d",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define SL1(a) scanf("%lld",&a)
#define SL2(a,b) scanf("%lld%lld",&a,&b)
#define SL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

#define F(i,a,b) for(int i=a;i<b; i++)

#define CHR getchar()
#define PB(x) push_back(x)

#define PS(x) push(x)
#define sz size()
#define UB upper_bound
#define LB lower_bound
#define countbits  __builtin_popcount

#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)

#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;

// array initialization
#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pb push_back

#define NL printf("\n");
#define cp printf("here\n");

#define VI vector<int>
#define PII pair<int,int>
#define PQ priority_queue
#define MP make_pair

template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInv (T b,T m){return BigMod(b,m-2,m);}
template <typename T> LL isLeft(T a,T b,T c) { return (a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y); }
template<typename T>inline T euclide(T a,T b,T &x,T &y) {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template<typename T>inline T gcd(T a,T b){if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<typename T>inline T lcm(T a,T b) {if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

int Set(int N,int pos){ return N=N | (1<<pos);}
int Reset(int N,int pos){return N= N & ~(1<<pos);}
bool Check(int N,int pos){return (bool)(N & (1<<pos));}

           //0123456879
#define MOD  1000000007
#define MX   1000007
#define INF  INT_MAX

using namespace std;

struct edge{
    int u,v,w,id;

    edge(){}
    edge(int _,int __,int ___,int ____){
        u = _;
        v = __;
        w = ___;
        id = ____;
    }

    bool operator< (const edge& p)const{
        return w>p.w;
    }
};

VI adj[MX];
vector<edge> e[MX];
edge E[MX];
int taken[MX];
int par[MX];
int bk[MX],ds[MX];
bool vis[MX];
int node;
vector<int> needed;

void init(int n){
    for (int i=0;i<=n;i++)      par[i] = i;
}

int FindPar(int n){
    if (par[n] == n)            return n;
    else                        return par[n] = FindPar(par[n]);
}

void Dfs(int u,int p){
    cout<<u<<" "<<p<<endl;
    vis[u] = true;
    node++;

    ds[u] = bk[u] = node;

    for (int i=0;i<adj[u].size();i+=2){
        int v = adj[u][i];
        int id = adj[u][i+1];

        if (!vis[v]){
            Dfs(v,id);

            bk[u] = min( bk[v],bk[u] );

            //cout << bk[v] << " " << ds[u] << endl;

            if (bk[v] > ds[u]){
                taken[id] = 2;
            }
        }

        else if (id != p){
            bk[u] = min( bk[u], ds[v] );
        }
    }
}

void MST(int n,int l,int h){
    init(n);
    int connectNode = 1;

    for (int i=l;i<=h;i++){
        for (int j=0;j<e[i].size();j++){
            int u = FindPar(e[i][j].u), v = FindPar(e[i][j].v), w = e[i][j].w,id = e[i][j].id;

            if (u != v){
                adj[u].PB( v );
                adj[u].PB( id );

                adj[v].PB( u );
                adj[v].PB( id );

                vis[u] = vis[v] = 0;
                bk[u] = bk[v] = ds[u] = ds[v] = 0;


                needed.PB(u);
                needed.PB(v);
            }

            else taken[id] = 3;
        }

        node = 0;

        for (int j=0;j<needed.size();j++){
            if (!vis[needed[j]])
                Dfs(needed[j],-1);
        }

        for (int j=0;j<e[i].size();j++){
            int u = FindPar(e[i][j].u), v = FindPar(e[i][j].v), w = e[i][j].w,id = e[i][j].id;

            if (u != v){
                //par[u] = v;

                if (taken[ id ] < 2)        taken[ id ] = 1;
            }
        }

        for (int j=0;j<e[i].size();j++){
            int u = FindPar(e[i][j].u), v = FindPar(e[i][j].v), w = e[i][j].w,id = e[i][j].id;

            if (u != v){
                par[u] = v;

                //if (taken[ id ] < 2)        taken[ id ] = 1;
            }
        }

        for (int j=0;j<needed.size();j++)   adj[ needed[j] ].clear();
        needed.clear();
    }
}


int main()
{
    int n,m;

    S2(n,m);
    int lw = INF,hg = -1;

    for (int i=1;i<=m;i++){
        int u,v,w;

        S3(u,v,w);

        e[w].PB(edge(u,v,w,i));
        E[i] = edge(u,v,w,i);

        lw = min( lw,w );
        hg = max( hg,w );
    }

    MST(n,lw,hg);

    for (int i=1;i<=m;i++){
        if ( taken[i] == 2 )            cout << "any\n";
        else if (taken[i] == 1)         cout << "at least one\n";
        else                            cout << "none\n";
    }

return 0;
}

/*

8 8
1 2 3
2 3 1
3 4 3
2 5 1
5 6 1
3 6 1
5 7 3
6 8 3


*/
