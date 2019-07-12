#include<bits/stdc++.h>

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
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<LL, LL>
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


#define MOD 100000007

#define MAX 109
#define MAXLG 20
#define inf 100000

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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

vector<LL> V;

void init()
{
    for(LL x = 2; x <= 100000ll; x++)
    {
        LL cur = x;
        int cnt = 0;
        while(cur * x <= 10000000000ll)
        {
            cnt++;
            cur = cur * x;
            V.pb(cur);
        }
    }
    UNIQUE(V);
}

LL dp[20001];

LL solve(int cur)
{
    LL &ret = dp[cur];
    if(cur == 0 || cur == 1) return ret = 1ll;
    if(ret != -1ll) return ret;
    ret = 0ll;
    for(int x = 0; x < cur; x++)
    {
        int mx = max(x, cur - x - 1);
        int mn = min(x, cur - x - 1);
        ret = (ret + (solve(mx) * solve(mn)) % MOD) % MOD;
    }
    return ret;
}



int main()
{
//    READ;
//    WRITE;
    int i, j, type;
//    use_cin;
    int t, cases = 1;
    string inp;
    LL num, a, b;
    init();
    clr(dp, -1ll);
    solve(2000);
    scanf("%d", &t);
    dp[0] = 0ll;

    int u, v, w;
    while(t--)
    {
        scanf("%lld %lld", &a, &b);
        a = upper_bound(V.begin(), V.end(), a-1) - V.begin();
        b = upper_bound(V.begin(), V.end(), b) - V.begin();
        printf("Case %d: %lld\n", cases++, dp[b - a]);
    }
    return 0;
}

/*

for(i=0;i<size;i++)
    scanf("%d",&array[i]);
for(i = 0; i < size; i++
    min=array[0];
    for(i=1;i<size;i++)
    {
        if(array[i]<min)
        {
            min=array[i];
            location=i+1;

        }
    }


*/
