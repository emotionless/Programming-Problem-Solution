#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 100000007
#define MX 100009
#define mp make_pair

using namespace std;

LL dp[2][15007];

int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m, K;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>K>>m;
        clr(dp, 0);
        dp[0][0] = 1;
        int pre = 0, past = 1;
        for(int nn = 0; nn < n; nn++)
        {
            swap(pre, past);
            dp[pre][0] = 0;
            for(i = 1; i <= m; i++)
            {
                dp[pre][i] = (dp[pre][i - 1] + dp[past][i - 1] - ((i - K - 1)<0?0 : dp[past][i - K - 1])) % MOD;
            }
        }
        printf("Case %d: %lld\n", cases++, (dp[pre][m] + MOD) % MOD);
    }
    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
