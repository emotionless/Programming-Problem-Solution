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
#define eps 1e-10
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 250000
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
#define ull unsigned long long

#define MX 10000000000000000ll
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

vi V[MAX];
vi G[MAX];

int SZ[MAX];
int lvl[MAX];
int dist[30][MAX];
int tot;

void DFS(int u, int p)
{
    tot++;
    SZ[u] = 1;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(lvl[v] || v == p) continue;
        DFS(v, u);
        SZ[u] += SZ[v];
    }
}

int get_centroid(int u, int p)
{
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(v == p || lvl[v]) continue;
        if(SZ[v] > tot/2) return get_centroid(v, u);
    }
    return u;
}

void calculate_distance(int u, int p, int cst, int stp)
{
    dist[stp][u] = cst;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(lvl[v] || p == v) continue;
        calculate_distance(v, u, cst + 1, stp);
    }
}

int par[MAX];
void decompose(int u, int p, int stp)
{
    tot = 0;
    DFS(u, p);
    int center = get_centroid(u, p);

    calculate_distance(center, -1, 0, stp);

    lvl[center] = stp;
    par[center] = p;
    int sz = V[center].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[center][i];
        if(lvl[v]) continue;
        decompose(v, center, stp + 1);
    }
}

int res[MAX];
void update(int u)
{
    int v = u;
    int l = lvl[u];
    while(v != -1)
    {
        res[v] = min(res[v], dist[l][u]);
        l--;
        v = par[v];
    }
}

int query(int u)
{
    int v = u;
    int l = lvl[u];
    int mn = INT_MAX;
    while(v != -1)
    {
        mn = min(res[v] + dist[l][u], mn);
        l--;
        v = par[v];
    }
    return mn;
}

int main()
{
//    freopen("inp.txt", "r", stdin);
    int j,  i;
    int a, t, n, b, u, k, v, cases = 1, m;
    s2(n, m);
    for(i = 1; i < n; i++)
    {
        s2(u, v);
        V[u].pb(v);
        V[v].pb(u);
    }
    decompose(1, -1, 1);
    int op, num;
    clr(res, 50);
    update(1);

    while(m--)
    {
        s2(op, num);

        if(op == 1)
            update(num);
        else
            printf("%d\n", query(num));
    }

    return 0;
}

/*



4
8 2 2 1


*/
