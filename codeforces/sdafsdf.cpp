#include <bits/stdc++.h>

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
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1ll<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

///**** Max/Min********///

#define _max(aa, bb) (aa = max(aa, bb))
#define max2(aa, bb) max(aa, bb)
#define max3(aa, bb, cc) max(aa, max(bb, cc))
#define max4(aa, bb, cc, dd) max(max(aa, dd), max(bb, cc))
#define _min(aa, bb) (aa = min(aa, bb))
#define min2(aa, bb) min(aa, bb)
#define min3(aa, bb, cc) min(aa, min(bb, cc))
#define min4(aa, bb, cc, dd) min(min(aa, dd), min(bb, cc))


///******* File *********///

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
#define nl printf("\n")
#define eps 1e-18
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 1001000000000000009ll
#define PI acos(-1.0)
#define piii pair<int, pii>
#define CLR(aa, nnn) for(int ii = 0; ii <= nnn; ii++) {aa[ii].clear();}

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

void sc(int &a)
{
    scanf("%d", &a);
}

void sc(ll &a)
{
    scanf("%lld", &a);
}

void sc(double &a)
{
    scanf("%lf", &a);
}

void sc(int &a, int &b)
{
    scanf("%d %d", &a, &b);
}

void sc(ll &a, ll &b)
{
    scanf("%lld %lld", &a, &b);
}

void sc(int &a, int &b, int &c)
{
    scanf("%d %d %d", &a, &b, &c);
}


void sc(int &a, int &b, ll &c)
{
    scanf("%d %d %lld", &a, &b, &c);
}


void sc(ll &a, ll &b, ll &c)
{
    scanf("%lld %lld %lld", &a, &b, &c);
}

void sc(string &str)
{
    cin>>str;
}


void sc(char *(str))
{
    scanf(" %s", str);
}

void sc(char &c)
{
    scanf(" %c", &c);
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides

//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


#define LEN(a) strlen(a)
#define ull unsigned long long

#define nl printf("\n")

//#define MX 10000000000000000ll
#define MX (lim*4 + 10)
#define lim 100000    /// 10^5


///***** Template ends here *****///
///********************* Code starts here ****************************

struct Z
{
    int l, r, sum;
};

Z tree[60*MAX];


int weight[MAX];
int take[MAX];
vi V[MAX];
vi adj[MAX];
map<int, int>M;
int avail;
int root[MAX];


/// LCA start

int n;
char flag[MAX+1];
int L[MAX+1];
int in[MAX+1];
int father[MAX+1];
int A[MAX+1][100+1];



void dfs(int cur)
{
    flag[cur] = true;
    int i;
    for(int i = 0; i < adj[cur].size(); i++)
    {
        if(!flag[adj[cur][i]])
        {
            father[adj[cur][i]] = cur;
            L[adj[cur][i]] = L[cur] + 1;
            dfs(adj[cur][i]);
        }
    }
}

void pre_process()
{
    int i,j;
    for(i = 1; i <= n; i++)
        for(j = 0; (1<<j) <= n; j++)
            A[i][j] = -1;
    for(i = 1; i <= n; i++)
        A[i][0] = father[i];
    for(j = 1; (1<<j) <= n; j++)
        for(i = 1; i <= n; i++)
            if(A[i][j-1] != -1)
                A[i][j] = A[A[i][j-1]][j-1];
}


int getLCA(int p, int q)
{
    int i,log;
    if(L[p] < L[q]) swap(p,q);
    for(log=1; (1<<log)<=L[p]; log++);
    log--;
    for(i=log; i>=0; i--)
        if(L[p] - (1<<i) >= L[q])
            p = A[p][i];
    if(p == q) return p;
    for(i=log; i>=0; i--)
    {
        if(A[p][i] != -1 && A[p][i] != A[q][i])
        {
            p = A[p][i];
            q = A[q][i];
        }
    }
    return father[p];
}



/// LCA end




int insert(int u, int st, int ed, int pos, int val)
{
    int ind = (++avail);
    tree[ind] = tree[u];

    if(st == ed)
    {
        tree[ind].sum += val;
        tree[ind].l = tree[ind].r = 0;
        return ind;
    }
    int mid = (st + ed)/2;
    if(pos <= mid)
        tree[ind].l = insert(tree[ind].l, st, mid, pos, val);
    else
        tree[ind].r = insert(tree[ind].r, mid+1, ed, pos, val);

    tree[ind].sum = tree[tree[ind].l].sum + tree[ tree[ind].r ].sum;
    return ind;
}
int par[MAX];

void DFS(int u, int p)
{
    for(auto v : V[u])
    {
        if(v != p)
        {
            par[v] = u;
            adj[u].pb(v);
            root[v] = root[u];
            root[v] = insert(root[v], 1, n, M[ weight[v] ], 1);
            DFS(v, u);
        }
    }
}


int query(int lNode, int rNode, int lcaNode, int st, int ed, int k)
{
    cout<<lNode<<" "<<rNode<<" "<<lcaNode<<" "<<st<<" "<<ed<<" "<<k<<endl;
    if(st == ed) return st;

    int mid = (st + ed)/2;

    int cnt = tree[rNode].sum - tree[lNode].sum - tree[lcaNode].sum - tree[ par[lcaNode] ].sum;
    if(k <= cnt)
        return query(tree[lNode].l, tree[rNode].l, lcaNode, st, mid, k);
    else
        return query(tree[lNode].r, tree[rNode].r, lcaNode, st, mid, k - cnt);
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    int  q, u, v, m;

    sc(n, m);

    for(i = 1; i <= n; i++){
        sc(weight[i]);
        take[i] = weight[i];
    }
    sort(take + 1, take + 1 + n);

    for(i = 1; i <= n; i++)
    {
        M[ take[i] ] = i;
    }


    for(i = 1; i < n; i++)
    {
        sc(u, v);
        V[u].pb(v);
        V[v].pb(u);
    }
    root[1] = insert(0, 1, n, M[ weight[1] ], 1);
    DFS(1, 0);


    father[1] = -1;
    L[1] = 0;

    dfs(1);
    pre_process();

    while(m--)
    {
        sc(u, v, k);
        int lca = getLCA(u, v);

        int res = query(root[u], root[v], root[lca], 1, n, k);
        cout<<M[res]<<endl;
    }






    return 0;
}

/*





*/
