#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 50009
#define mp make_pair

using namespace std;
double dp[501][501];

void init()
{
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <=500; i++)
        dp[0][i] = 1;

    for(int i = 1; i < 501; i++)
    {
        for(int j = i + 1; j < 501; j++)
        {
            if((i+j)%2)
                dp[i][j] = (i*(1.0))/(i+j)*dp[i-1][j-1] + (j*1.0)/(i+j)*dp[i][j-2];
        }
    }
}


int main()
{
    int i, j, k;
    int t, r, cases = 1;
    init();

    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &r);
        printf("Case %d: %.9lf\n", cases++, dp[n][r]);

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
