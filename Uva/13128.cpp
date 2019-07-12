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
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000009
#define MAX (lim+7)
#define INF 10000000000000
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
#define lim 1000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

char str[MAX];

ll dp[2][26][MAX][MAX];
int K;
int freq[26];

ll ncr[MAX][MAX];



void precal()
{
    for(int i = 0; i < MAX; i++)
    {

        for(int j = 0; j <= i; j++)
        {
            if(i == j || j == 0) ncr[i][j] = 1ll;
            else
            {
                ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1]);
                if(ncr[i][j] >= MOD)
                    ncr[i][j] -= MOD;
            }
        }
    }
}

ll d[MAX][MAX];

ll calc(int cur, int aro)
{
    if(aro == 0) return 1ll;
    if(cur == -1) return 0;
    ll &ret = d[cur][aro];
    if(ret != -1) return ret;
    ret = 0;
    ret = calc(cur-1, aro) + calc(cur, aro - 1);
    if(ret >= MOD) ret = MOD;
    return ret;
}
int vis[2][26][MAX][MAX];
int kase;
ll solve(bool is, int ind, int tot, ll way)
{
    if(ind == 26)
    {
        if(way == 1 && is) return 1ll;
        return 0ll;
    }
    ll &ret = dp[is][ind][tot][way];
    if(vis[is][ind][tot][way] == kase) return ret;
    vis[is][ind][tot][way] = kase;
    ret = 0ll;

    for(int i = 0; i <= freq[ind]; i++)
    {
        ll by = calc(tot, i);
        if(by > way) return ret;
        if(way%by != 0) continue;
        ret = ret + (solve(is || i, ind + 1, tot+i, way/by) * ncr[ freq[ind] ][ i ])%MOD;
        if(ret >= MOD)
            ret -= MOD;
    }
//    cout<<ind<<" "<<tot<<" "<<way<<" "<<ret<<endl;
    return ret;
}

int main()
{
//    use_cin;
//    WRITE;
//    READ;
    int t,  i,k, j;
    int a, c,  x, q;
    clr(d, -1);
    precal();
    while(scanf("%s", str) != EOF)
    {
        s1(K);
        int len = LEN(str);
        clr(freq, 0);
        for(i = 0; i < len; i++)
        {
            freq[ str[i]-'a' ]++;
        }
        kase++;
        ll res = solve(0, 0, 0, K);
        printf("%lld\n", res);
    }
    return 0;
}

/*



aaab
3
abcc
2



*/
