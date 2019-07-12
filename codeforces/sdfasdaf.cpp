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
#define lim 200000    /// 10^5
#define MAXN 200009

///***** Template ends here *****///
///********************* Code starts here ****************************


vector< int > adj[MAXN+1];
int n, root;
char flag[MAXN+1];
int L[MAXN+1];
int in[MAXN+1];
int father[MAXN+1];
int A[MAXN+1][100+1];
LL INF = 10000000;

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

ll cost[MAXN];
bool vis[MAXN];

vector<ll>cst[MAXN];

void DFS(int cur, int pre, ll c)
{
    if(vis[cur]) return;
    vis[cur] = 1;
    int i;
    cost[cur] = c;
    int sz = adj[cur].size();
    for(i = 0; i < sz; i++)
        if(adj[cur][i] != pre)
            DFS(adj[cur][i], cur, c + cst[cur][i]);
}

int arr[MAXN];


int CX[MAXN];

void dekhii(int u, int c, int p)
{
    CX[u] = c;
    for(auto v:adj[u])
    {
        if(v != p)
        {
            dekhii(v, c+1, u);
        }
    }
    return;
}

int C[MAXN];

void dekhi(int u, int c, int p)
{
    C[u] = c;
    for(auto v:adj[u])
    {
        if(v != p)
        {
            dekhi(v, c+1, u);
        }
    }
    return;
}

pii take[MAX];

int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int a, b, v, u,m, q;
    int w, x;
    scanf("%d",&n);
    sc(x);
    for(i = 1; i <= n; i++) adj[i].clear(), flag[i] = false;

    for(i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    root = 1;

    father[root] = -1;
    L[root] = 0;

    dfs(root);
    pre_process();



    //DFS(root, -1, 0);
//    deb;
    dekhi(1, 0, 0);
    dekhii(x, 0, 0);

    for(i = 1; i <= n; i++)
    {
        take[i-1].xx = C[i];
        take[i-1].yy = i;
    }
    sort(take, take + n);

    reverse(take, take + n);
    int ans = 0;
    for(i = 0; i < n; i++)
    {
        int node = take[i].yy;
        int cc = take[i].xx;
        int cx = CX[ node ];
//        cout<<node<<" "<<cc<<" "<<cx<<endl;
        if(cc <= cx) continue;
        ans = max(ans, cc*2);
    }
    printf("%d\n", ans);







//
//    // query is here
//
//    while(m--)
//    {
//        scanf("%d", &q);
//        for(i = 0; i < q; i++)
//            scanf("%d", &arr[i]);
//        ll res = 0ll;
//        for(i = 0; i < q; i++)
//            for(j = i + 1; j < q; j++)
//            {
//                u = arr[i];
//                v = arr[j];
////            cout<<u<<v<<" "<<getLCA(u, v)<<endl;
//                res += cost[u] + cost[v] - 2 * cost[getLCA(u, v)];
//            }
//        printf("%lld\n", res);
//    }



    return 0;
}
/*

8 8
1 2
2 3
2 4
4 5
5 6
6 7
3 8

5 3
1 2
2 3
2 4
4 5

*/
