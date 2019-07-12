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
#define MAX 100009
#define MAXLG 20
#define inf 100000000

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

int arr[MAX];
int n, k;
int dp[MAX];
int solve(int ind)
{
    if(ind >= n) return 0;
    int &ret = dp[ind];
    if(ret != -1) return ret;
    ret = inf;
    int nxt = upper_bound(arr, arr + n, arr[ind] + k + k) - arr;
    if(nxt - ind >= 3)
        ret = min(ret, 1 + solve(nxt) );
    if(nxt - ind >= 4)
        ret = min(ret, 1 + solve(nxt - 1));
    if(nxt - ind >= 5)
        ret = min(ret, 1 + solve(nxt - 2));

return ret;
}



int main()
{
//    READ;
//    WRITE;
    int i, j, type;
//    use_cin;
    int m, a, b, t, num, cases = 1;
    string inp;
    s1(t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(i = 0; i < n; i++)
            s1(arr[i]);
        sort(arr, arr + n);
        memset(dp, -1, sizeof dp);
        int res = solve(0);
        printf("Case %d: ", cases++);
        if(res >= inf)
            printf("-1\n");
        else
            printf("%d\n", res);
    }
    return 0;
}

/*





*/
