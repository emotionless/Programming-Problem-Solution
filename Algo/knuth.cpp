/** knuth optimization
complexity: n*m;
dp[i][j]=min{dp[i][k]+dp[k][j]}+C[i][j]
        i<j<k
and             A[i,j-1]≤A[i,j]≤A[i+1,j]
***/
const long long inf = 3000000000000000000LL;
long long dp[1002][1002], a[1002],s[1002][1002];
long long  sum[1002], pre[1001][1001];
///cost from st...ed
ll cost(int st, int ed)
{
    return pre[st][ed];
}
/// index strats from 1
///pass size of n whose have to be grouped in m group...
long long run(int n,int m)
{
    memset(dp,0xff,sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + a[i];
        int maxj = min(i, m), mk;
        long long mn = inf, tmp;
        for (int k = 0; k < i; ++k)
        {
            if (dp[k][maxj - 1] >= 0)
            {
                tmp = dp[k][maxj - 1] + cost(k+1, i);///k+1..i
                if (tmp < mn)
                {
                    mn = tmp;
                    mk = k;
                }
            }
        }
        dp[i][maxj] = mn;
        s[i][maxj] = mk;
        for (int j = maxj - 1; j >= 1; --j)
        {
            long long mn = inf;
            int mk;
            for (int k = s[i - 1][j]; k <= s[i][j + 1]; ++k)
            {
                if (dp[k][j - 1] >= 0)
                {
                    tmp = dp[k][j - 1] + cost(k+1, i);///k+1..i
                    if (tmp < mn)
                    {
                        mn = tmp;
                        mk = k;
                    }
                }
            }
            dp[i][j] = mn;
            s[i][j] = mk;
        }
    }
    return dp[n][m];
}
/*
4 1
4 5 1 2
output: 17
*/
