/** divide and conquer optimization **/
/**
It eliminate complexity O(n^2*K) to O(n*log(n)*K)
it is possible when A[i][j] ≤ A[i][j+1]
formula:
dp[i][j]=min(dp[i−1][k]+C[k+1][j])
         k<j
where i is the number of grouping
**/
ll arr[MAX];
ll sum[MAX];
ll dp[809][MAX];

ll cost(int st, int ed)
{
    ll mul = ed - st + 1;
    return (sum[ed] - sum[st-1])*mul;
}
void solve(int k, int st, int ed, int l, int r)
{
    if(st > ed) return;
    int mid = (st + ed) >> 1;
    ll &ret = dp[k][mid];
    ret = INF;
    int ind, i;
    for(i = l; i <= min(mid, r); i++)
    {
        ll tmp = dp[k-1][i] + cost(i+1, mid);
        if(tmp < ret)
        {
            ret = tmp;
            ind = i;
        }
    }
    solve(k, st, mid-1, l, ind);
    solve(k, mid+1, ed, ind, r);
    return;
}
int main()
{
    // n = array size, m = number of grouping
    cin>>n>>m;
    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    for(i = 1; i <= n; i++)
        dp[1][i] = sum[i] * (ll)i;

    for(i = 2; i <= m; i++)
        solve(i, 1, n, 1, n);

    cout<< dp[m][n] <<endl;
    return 0;
}
/**
6 3
11
11
11
24
26
100
Output: 299
**/
