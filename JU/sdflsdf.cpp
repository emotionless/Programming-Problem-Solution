#include<bits/stdc++.h>

#define eps 1e-8
#define xx first
#define yy second
#define LL long long
#define inf INT_MAX/3
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define pll pair<LL,LL>
#define MOD 1000000007
#define MP make_pair
#define MX 100005

using namespace std;
LL ncr[105][MX];
LL ar[MX];
LL dp[105][MX];


void NCR()
{
    ncr[0][0]=1ll;
    for(int i=1; i<=100000; i++) ncr[0][i]=1ll;
    for(int i=1; i<=100; i++)
    {
        ncr[i][0]=1ll;
        for(int j=1; j<=100000; j++)
        {
            ncr[i][j]=(ncr[i][j-1]+ncr[i-1][j])%MOD;
        }
    }
}

int main()
{
    int n,m;
    NCR();
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d",&ar[i]);
    }

    for(int i=0; i<m; i++)
    {
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        dp[k][l]++;
        dp[k][l]%=MOD;
        for(int j=0; j<=k; j++)
        {
            dp[j][r+1]=(dp[j][r+1]-ncr[k-j][r-l])%MOD;


            dp[j][r+1]=(dp[j][r+1]+MOD)%MOD;
        }
    }
    for(int i=100; i>=0; i--)
    {
        for(int j=1; j<=n; j++)
        {
            dp[i][j]=(dp[i][j]+dp[i+1][j]+dp[i][j-1])%MOD;
            if(dp[i][j]<0ll) dp[i][j]+=MOD;
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=1; i<=n; i++)
    {
        printf("%I64d ",(dp[0][i]+ar[i])%MOD);
    }
    puts("");
    return 0;
}
/*
5 5
1 2 8 6 3
5 5 4
1 5 5
1 1 4
5 5 0
2 3 0
*/

