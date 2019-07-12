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


#define MOD 1000000007

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

LL prime[50001];
bool is[100001];
void sieve()
{
    int i, j, k = 0;
    for(i = 2; i < 5000; i++)
    {
        if(!is[i])
        {
            prime[++k] = i;
            for(j = i + i; j < 5000; j += i)
                is[j] = 1;
        }
    }
    return;
}



LL dp[501][501];

LL pw[501][501];

void init()
{
    int i, j, k;
    dp[0][0] = 1ll;
    for(i = 1; i <= 500; i++)
        for(j = 1; j <= 500; j++)
            pw[i][j] = bigmod((LL) prime[i], (LL)(j - 1), (LL) MOD);

    for(i = 1; i <= 500; i++)
    {
        for(j = i - 1; j <= 500; j++)
        {
            for(k = 1; k <= (500 - j); k++)
            {
                dp[i][j + k] += (((dp[i - 1][j] * pw[i][k]) % MOD) * (prime[i] - 1)) % MOD;
                if(dp[i][j + k] >= MOD)
                    dp[i][j + k] -= MOD;
            }
        }
    }
}





int main()
{
//    READ;
//    WRITE;
//    use_cin;
    int i, j, type;
    sieve();
    int  a, b, t, cases = 1;
    scanf("%d", &t);
    int u, v, w, n;
    int k, p;
    init();
    while(t--)
    {
        scanf("%d %d", &k, &p);
        printf("Case %d: %lld\n", cases++, (dp[p][k] + MOD) % MOD);
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
