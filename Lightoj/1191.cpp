#include <stdio.h>
#include <bits/stdc++.h>
#define LL long long

using namespace std;


LL dp[51][51][51];
int K;
LL solve(int ind, int m)
{
    if(m < 0 || ind < 0) return 0;
    if(ind == 0)
    {
        if(m == 0) return 1;
        return 0;
    }
    LL &ret = dp[ind][m][K];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 1; i <= K && (ind - i) >= 0; i++)
        ret += solve(ind - i, m - 1);
    return ret;
}

int main()
{
    int t, cases=1, i, j, m, n;
    scanf("%d", &t);
    int M, N;
    memset(dp, -1, sizeof dp);
    while(t--)
    {
        scanf("%d %d %d",&N,&K,&M);
        swap(K, M);
        printf("Case %d: %lld\n",cases++, solve(N, M));
    }
    return 0;
}
