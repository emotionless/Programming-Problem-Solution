#include<bits/stdc++.h>

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
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(aa, bb) (aa&(1ll<<bb))
#define set_bit(aa, bb) (aa|(1ll<<bb))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);




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
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************


int is[110][51];
double dp[110][51], pr;
double solve(int c, int m)
{
    if(c == 0)
    {
        if(m == 0) return 1.0;
        return 0.0;
    }
    if(is[c][m]) return dp[c][m];
    is[c][m] = 1;
    dp[c][m] = pr * solve(c - 1, max(0, m-1)) + (1.0 - pr) * solve(c - 1, m);
    return dp[c][m];
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int i, j,k;
    int t;
    int cases = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cin>> pr;
        memset(is, 0, sizeof is);
        printf("Case %d: %.3lf\n", cases++, solve(n*2-1, n));
    }
}

/*


8
-1 2 3 -4 -5 6 7 -1


*/
