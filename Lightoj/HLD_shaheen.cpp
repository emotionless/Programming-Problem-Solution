/***************** HLD ***********************/

/**
(2 <= n <= 30000)
initially there are ginie[i] number of genies in i'th node (tree)
1) 0 i j, it means that you have to find the total number of genies in the nodes that occur in path from node i to j (0 <= i, j < n).
2) 1 i v, it means that number of genies in node i is changed to v (0 <= i < n, 0 <= v <= 1000).
**/
#include<bits/stdc++.h>

#define mp make_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0; i--)
#define LL long long
#define ll long long int
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("semipal.out","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("semipal.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define sp printf(" ")
#define nl printf("\n")
#define eps 1e-9
#define deb cerr<<"I am here"<<endl
#define MAX (lim+7)
#define INF 1000000000000000ll
#define PI acos(-1.0)
#define piii pair<int, pii>

using namespace std;

#define I(X) scanf("%d", &(X))
#define II(X, Y) scanf("%d%d", &(X), &(Y))
#define III(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define rep(i,a,b) for(int i=a;i<=b;i++)

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


const int maxn=30007;

int chainNo;
int chainPos[maxn];
int chainHead[maxn];
int chainId[maxn];
int chainSize[maxn];
int ssize[maxn];
int schild[maxn];
int level[maxn];

vector<int>adj[maxn];

int par[maxn];

int n;

int ginie[maxn];
int tree[maxn];

void Bupdate(int idx,int val)
{
    while(idx<=n) tree[idx]+=val ,  idx += (idx & -idx);
}

int Bquery(int idx)
{
    int sum=0;  while(idx) sum+=tree[idx] , idx-=(idx & -idx);  return sum;
}


int rangeSum(int x,int y)
{
    if(x>y) swap(x,y);
    int ret = Bquery(y)-Bquery(x-1);
    return ret;
}

void DFS(int u,int papa,int lev)
{
      par[u] = papa;
    level[u] = lev;
    ssize[u] = 1;
   schild[u] = -1;

    int mx = -1;

    for(int i=0;i<adj[u].size();i++)
    {
        int v = adj[u][i];

        if(v!=papa)
        {
            DFS(v,u,lev+1);
            ssize[u]+=ssize[v];
            if(mx<ssize[v])
            {
                mx = ssize[v];
                schild[u] = v;
            }
        }
    }
}

int ptr;

void HLD(int u)
{
    if( chainHead[chainNo]==-1 )
        chainHead[chainNo]=u;

    chainId[u]=chainNo;
    chainPos[u]=++ptr;

    if(schild[u]!=-1)
    {
        HLD(schild[u]);

        for(int i=0; i<adj[u].size(); i++)
        {
            int v = adj[u][i];

            if( v!=schild[u] && v!=par[u] )
            {
                chainNo++;
                HLD(v);
            }
        }
    }
}

int LCA(int u,int v)
{
    int uhead,vhead,uchain,vchain;
    while(true)
    {
        uchain = chainId[u];
        vchain = chainId[v];

        uhead  = chainHead[uchain];
        vhead  = chainHead[vchain];

        if(uchain==vchain)  return (level[u]<level[v]?u:v);
        else if( level[uhead]<level[vhead] ) v = par[ vhead ];
        else u = par[ uhead ];
    }
}

int query_up(int papa,int u)
{
     int uchain,pchain=chainId[papa],ret=0;
     int uhead;

     while(true)
     {
         uchain = chainId[u];

         if(uchain==pchain)
         {
             ret += rangeSum( chainPos[u],chainPos[papa] );
             break;
         }

         uhead = chainHead[uchain];

         ret += rangeSum( chainPos[uhead] , chainPos[u] );
         u = par[uhead];
     }

     return ret;
}

int query(int u,int v)
{
    int lca = LCA(u,v);
    int ret =  query_up(lca,u)+query_up(lca,v)-ginie[lca];
    return ret;
}

void init()
{
    rep(i,0,n)
    {
        adj[i].clear();
        chainHead[i] = -1;
        tree[i] = 0;
        ssize[i]=0;
    }

    chainNo = 1;
    ptr=0;
}

int main()
{
    int tc,cas=1;
    int u,v,x,y,c,q;
    I(tc);
    while(tc--)
    {
         I(n);
         init();
         rep(i,1,n) I(ginie[i]);
         rep(i,1,n-1)
         {
             II(u,v);
             u++;v++;
             adj[u].push_back(v);
             adj[v].push_back(u);
         }
         DFS(1,-1,1);
         HLD(1);
         rep(i,1,n) Bupdate( chainPos[i] , ginie[i] );
         I(q);
         printf("Case %d:\n",cas++);
         rep(i,1,q)
         {
             III(c,x,y);
             x++; y++;
             if(c==0) printf("%d\n",query(x,y));
             else
             {
                 Bupdate(chainPos[x],-ginie[x]);
                 ginie[x]=y-1;
                 Bupdate(chainPos[x], ginie[x]);
             }
         }
    }
    return 0;

}
