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

#define WRITE freopen("perechi3.out","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("perechi3.in","r",stdin)

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
#define lim 3000000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

map< vi, pair<ll, ll> >dp;
ll p[20];
void power()
{
    p[0] = 1ll;
    for(int i = 1; i <= 18; i++)
        p[i] = (p[i-1]*10ll)%MOD;
}

int sum;

pair<ll, ll> solve(vi a)
{
    int s = 0;
    for(int i = 0; i < 10; i++){
        s += a[i];
    }

    if(s == 0)
    {
        return mp(0ll, 1ll);
    }
    if(dp.find(a) != dp.end())
        return dp[a];
    ll res = 0ll;
    ll ways = 0ll;

    for(int i = 0; i < 10; i++)
    {
        if(s == sum && i == 0) continue;
        if(!a[i]) continue;
        vi tmp = a;
        tmp[i] --;
        pair<ll,ll> x = solve(tmp);
        res = (res + x.xx) % MOD;
        res = (res + (x.yy*p[s-1]*i)%MOD)%MOD;
        ways = (ways + x.yy)%MOD;
    }
    return dp[a] = mp(res, ways);
}

int cnt[10];

int main()
{
//    use_cin;
//    WRITE;
//    READ;

    int n;
    int t;
    int i, j, k;
    power();
    cin>>n;
    for(i = 1; i <= n; i++)
    {
        int tmp = i;
        while(tmp)
        {
            cnt[tmp%10]++;
            tmp /= 10;
        }
    }
    vi a;
    for(i = 0; i < 10; i++)
    {
        a.pb(cnt[i]);
        sum += cnt[i];
    }
    cout<<solve(a).xx<<endl;

    return 0;
}


/*
10


3
4 9 2
3 0 7
8 1 6


*/
