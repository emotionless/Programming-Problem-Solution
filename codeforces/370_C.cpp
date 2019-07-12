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

using namespace std;


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)
#define MOD 1000000007

#define MX 10000000000000000ll
#define lim 30      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************
int n;
ll dp[35];

ll solve(int ind)
{
    if(ind == n) return 1;
    if(ind > n) return 0;
    ll &ret = dp[ind];
    if(ret != -1) return ret;
    ret = 0;
    ret += solve(ind + 2);
    ret += solve(ind + 1);
    ret += solve(ind + 2);
    return ret;
}

ll a[35];
int main()
{
//    use_cin;
//    WRITE;
//    READ;

    int i, j, k;
    int t, cases = 1;
    a[0] = 1;
    a[1] = 1;
    a[2] = 3;
    a[3] = 1;
    for(i = 4; i < 35; i++)
        a[i] = a[i-2] + 2*a[i-4];
    s1(t);
    while(t--)
    {
        s1(n);
        clr(dp, -1);
        ll res = solve(0);
        printf("%lld\n", (res-a[n])/2 + a[n]);
    }

    return 0;
}

/*
10


3
4 9 2
3 0 7
8 1 6

1
200
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 200

*/
