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
#define INF 1000000
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
#define lim 100      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

vector<pii> V[MAX];

vi G[MAX];
vi C[MAX];
int dp[MAX][MAX];

void DFS(int u, int p)
{

    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i].xx;
        int w = V[u][i].yy;
        if(p == v) continue;
        G[u].pb(v);
        C[u].pb(w);
        DFS(v, u);
    }
    return;
}

int K;

int solve(int p, int pos, int cst)
{
    int sz = G[p].size();
    if(pos >= sz || sz == 0)
    {
        if(cst >= 0)
            return 0;
        return INF;
    }

    int v = G[p][pos];
    int w = C[p][pos];
    int &ret = dp[v][cst];
    if(ret != -1) return ret;
    ret = INF;

    ret = min(ret, 1 + solve(p, pos + 1, cst) + solve(v, 0, K) );
    if(p)
    {
        int rest = cst - w;
        for(int i = 0; i <= rest; i++)
        {
            ret = min(ret, solve(p, pos+1, i) + solve(v, 0, rest - i) );
        }
    }
    return ret;
}


int main()
{
//    use_cin;
//    WRITE;
//    READ;
//freopen("inp.txt", "r", stdin);

    int j, k, i;
    int t, a, b,  m, cases = 1;
    int u, v, n, w;

    s1(t);
    while(t--)
    {
        s2(n, K);
        for(i = 1; i < n; i++)
        {
            s3(u, v, w);
            V[u].pb(mp(v, w));

            V[v].pb(mp(u, w));
        }
        G[0].pb(1);
        C[0].pb(0);
        DFS(1, -1);

        clr(dp, -1);

        int res = solve(0, 0, K);
        printf("Case %d: %d\n", cases++, res);

        for(i = 0; i < MAX; i++)
        {
            V[i].clear();
            C[i].clear();
            G[i].clear();
        }


    }




    return 0;
}

/*




*/

