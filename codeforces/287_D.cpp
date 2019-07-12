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
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 2000


using namespace std;
int n, mod;
int K;
LL dp[1009][1009][2];
LL mul[MAX];
LL solve(int ind, int rem,  bool is)
{
    if(ind == n)
    {
        if(is) return 1ll;
        return 0ll;
    }
    LL &ret = dp[ind][rem][is];
    if(ret != -1ll) return ret;
    ret = 0ll;
    for(int i = (ind == n - 1)?1:0; i <= 9; i++)
    {
        int r = (rem + (mul[ind] * i)%K) % K;
        ret = (ret + solve(ind + 1, r, is || (r==0 && i))) % mod;
    }
    return ret;
}

int main()
{
    int tc,cs=1,i,j,k;
    cin>>n>>K>>mod;
    mul[0] = 1ll%K;
    for(i = 1; i <= MAX; i++)
    {
        mul[i] = (mul[i - 1] * 10ll) % K;
    }

    memset(dp, -1ll, sizeof dp);
    cout<<solve(0, 0, 0) <<endl;








    return 0;
}

/*

5 3 1103


*/
