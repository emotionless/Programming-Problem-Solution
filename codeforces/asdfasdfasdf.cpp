#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll dp[4][4005];
ll n;
ll cut[4];
ll f(ll i, ll w)
{
    if(i>2)
    {
        if(w==0)
            return 0;
        return -9999999999;
    }

    if(dp[i][w]!=-1)
        return dp[i][w];
    ll r1=-9999999999,r2=-9999999999;
    if(w-cut[i]>=0)
        r1=1+f(i,w-cut[i]);
    r2=f(i+1,w);
    return dp[i][w]=max(r1,r2);
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%lld%lld%lld%lld",&n,&cut[0],&cut[1],&cut[2]);
    ll ans=f(0,n);

    printf("%lld\n",ans);
    return 0;
}
