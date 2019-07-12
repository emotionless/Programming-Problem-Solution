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


#define MOD 1000007

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

unsigned LL f[51][51];
unsigned LL g[51][51];

void init()
{
    f[1][1] = g[1][1] = 1;
    for(int n = 1;  n <= 50; n++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j < n; j++) f[n][i] += g[n - 1][j];
            for(int j = 1; j < i; j++) g[n][i] += f[n - 1][j];
        }
    }
}

int n, m;

LL solve()
{
    LL ans = 0;
    if(m > 1)
    {
        for(int i = 1; i < m; i++)
            ans = (ans + f[n - 1][i]);
    }
    else
    {
        if(n <= 2) ans = 1;
        else
            ans = g[n - 1][2];
    }
    return ans;
}


int main()
{
//    READ;
//    WRITE;
//    use_cin;
    int i, j, type;
    int  a, b, t, cases = 1;
    scanf("%d", &t);
    int u, v, w;
    init();
    while(t--)
    {
        scanf("%d %d", &n, &m);
        printf("Case %d: %llu\n", cases++, solve());
    }
    return 0;
}

/*


1
5
2 1
2 3
3 4
3 5


*/
