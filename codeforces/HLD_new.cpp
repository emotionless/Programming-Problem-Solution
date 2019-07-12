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
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define nl printf("\n")
#define sp printf(" ")
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("D-small-attempt0.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 100000000
#define PI acos(-1.0)
#define piii pair<int, pii>

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

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)

#define MX 10000000000000000ll
#define lim 400000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************


vector<int> A[MAX];

int Tot[MAX],ChainNo,Pos[MAX],now;
int Ase[MAX],St[MAX],IdNo[MAX],Par[MAX],Lev[MAX];

map< pair<int,int>,int> Rakhsi;

void Dfs(int u,int p,int L)
{
    Par[u]=p;
    Tot[u]=1;
    Lev[u]=L;

    for(int i=0; i<A[u].size(); i++)
    {
        int v=A[u][i];
        if(v==p) continue;
        Dfs(v,u,L+1);
        Tot[u]+=Tot[v];
    }
    return;
}

void Hld(int u,int p)
{
    if(St[ChainNo]==-1)
    {
        St[ChainNo]=u;
    }
    Pos[u]=++now;
    IdNo[u]=ChainNo;
    int tp=Rakhsi[ mp(u,p) ];
    Ase[u]=tp;

    int Special,mx=-1;
    for(int i=0; i<A[u].size(); i++)
    {
        int v=A[u][i];
        if(v==p) continue;
        if(mx<Tot[v])
        {
            mx=Tot[v];
            Special=v;
        }
    }
    if(mx!=-1) Hld(Special,u);
    for(int i=0; i<A[u].size(); i++)
    {
        int v=A[u][i];
        if(v==p||v==Special) continue;
        ChainNo++;
        Hld(v,u);
    }
}

int Lca(int u,int v)
{
    while(true)
    {
        int unom=IdNo[u],vnom=IdNo[v];
        int ustart=St[unom],vstart=St[vnom];

        if(unom==vnom) return (Lev[u]<Lev[v]?u:v);
        else if(Lev[ustart]<Lev[vstart]) v=Par[vstart];
        else u=Par[ustart];
    }
}

int Tree[MAX*4];

void Update(int id,int l,int r,int st,int ed)
{
    if(st<=l&&ed>=r)
    {
        Tree[id]++;
        return;
    }

    int mid=(l+r)/2;
    int lft=2*id;
    int rgt=lft+1;

    if(ed<=mid)                 Update(lft,l,mid,st,ed);
    else if(st>mid)             Update(rgt,mid+1,r,st,ed);
    else
    {
        Update(lft,l,mid,st,ed);
        Update(rgt,mid+1,r,st,ed);
    }
}

int Query(int id,int l,int r,int pos,int sum)
{
    sum+=Tree[id];
    if(l==r)
    {
        return sum;
    }

    int mid=(l+r)/2;
    int lft=2*id;
    int rgt=lft+1;

    if(pos<=mid)        return Query(lft,l,mid,pos,sum);
    else                return Query(rgt,mid+1,r,pos,sum);
}

int N;

void ClimpChainFromU(int u,int v)
{
    while(true)
    {
        int uchain=IdNo[u],vchain=IdNo[v];
        int st=St[uchain];

        if(uchain==vchain)
        {
            int stt=Pos[v]+1,ed=Pos[u];
            if(stt<=ed)
            {
                Update(1,1,N,stt,ed);
            }
            return;
        }
        int stt=Pos[st],ed=Pos[u];
        Update(1,1,N,stt,ed);
        u=Par[st];
    }
}

int Ans[MAX];

int main()
{

    int n;
    scanf("%d", &n);
    N=n;
    for(int i=1; i<=n-1; i++)
    {
        int a,b;
        scanf("%d %d", &a, &b);

        Rakhsi[ mp(a,b) ]=i;
        Rakhsi[ mp(b,a) ]=i;

        A[a].pb(b);
        A[b].pb(a);
    }

    ChainNo=1;
    for(int i=1; i<=n; i++)
    {
        St[i]=-1;
    }

    Dfs(1,0,1);
    Hld(1,0);


    int m;
    scanf("%d", &m);

    while(m--)
    {
        int a,b;
        scanf("%d %d", &a, &b);

        int lc=Lca(a,b);
        ClimpChainFromU(a,lc);
        ClimpChainFromU(b,lc);
    }

    for(int i=1; i<=n; i++)
    {
        Ans[ Ase[i] ]=Query(1,1,n,Pos[i],0);
    }

    for(int i=1; i<n; i++)
    {
        printf("%d ",Ans[i]);
    }
    printf("\n");

    return 0;
}

