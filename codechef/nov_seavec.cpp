#include<bits/stdc++.h>

#define LL long long

using namespace std;
int n,m;
int res[10001];
LL dp[1001][1001];
LL arr[1001][1001];

LL solve(int pre, int ind, LL have[])
{
    if(ind>n) return LONG_MAX;

    if(dp[pre][ind]!=-1) return dp[pre][ind];

    LL ret1=solve(pre, ind+1, have);      // jodi na nei

    LL temp[m];

    bool p=true;

    for(int i=1; i<=m; i++)
    {
        LL dif=have[i]-arr[ind][i];
        if(dif<0)
        {
            p=0;
            break;
        }
        temp[i]=dif;
    }

    LL ret2=LONG_MAX;
    res[ind]=0;
    if(p)
    {
        ret2=solve(ind, ind+1, temp);
        if(ret2<ret1)
            res[ind]=ind+1;
    }
    dp[pre][ind]=min(ret1, ret2);
    cout<<pre<<" "<<ind<<" "<< dp[pre][ind]<<endl;
    return dp[pre][ind];
}




int main()
{
    int i,j,l,k;
    int t;
    LL final[10001];
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d %d", &n, &m);
        cout<<n<<" "<<m<<endl;

        memset(dp,-1, sizeof dp);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
                scanf("%lld", &arr[i][j]);
        }
        for(i=1; i<=m; i++)
            scanf("%lld", &final[i]);

        LL ret=solve(0, 1, final);
        cout<<ret<<endl;
    }

    return 0;
}
