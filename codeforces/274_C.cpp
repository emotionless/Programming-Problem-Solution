#include <bits/stdc++.h>

#define LL long long
#define MX 2009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>
#define ll long long
#define MOD  1000000007ll
#define check(aa , bb) (aa & (1<<bb))
#define PB push_back

#define PI 3.14159265358979323846264338328

using namespace std;

LL dp[5001][5001];

    int n,k, m;
    LL a, b;
LL solve(int ind, int stp)
{
    if(stp == k) return 1l;
    LL &ret = dp[ind][stp];
    if(ret != -1) return ret;
    ret = 0;
    int tot = b - ind - 1;
    int nxt = ind - 1;
    for(int i = 1; i <= tot * 2 + 1; i++)
    {
        if(b - i == ind) continue;
        if(b - i == 0) break;
        ret = (ret + solve(b - i, stp + 1)) % MOD;
    }
return ret;
}

int main()
{
    int i, j;
    cin>>n>>a>>b>>k;
    memset(dp, -1, sizeof dp);
    LL res = solve(a, 0);
    cout<<res<<endl;

    return 0;
}

/*

5 3 1 1

*/
