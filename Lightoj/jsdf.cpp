#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int LL;

int a[70];
LL dp[70][70];

LL dfs(int len,int l,int r,bool limit,bool ok)
{
    if(l<r) return !limit||(limit&&ok);
    if(!limit&&~dp[len][l])
        return dp[len][l];
    LL ret=0;
    int mx=limit?a[l]:9;
    for(int i=0; i<=mx; i++)
    {
        if(l==len-1&&i==0)
            continue;
        int g=ok;
        if(g) g=a[r]>=i;
        else g=a[r]>i;
        ret+=dfs(len,l-1,r+1,limit&&i==mx,g);
    }
    if(!limit)
        dp[len][l]=ret;
    return ret;
}

LL gaoit(LL n)
{
    if(n<0) return 0;
    if(n==0) return 1;
    int len=0;
    while(n)
    {
        a[len++]=n%10;
        n/=10;
    }
    LL ret=1;
    for(int i=len; i>=1; i--)
        ret+=dfs(i,i-1,0,i==len,1);
    return ret;
}

int main()
{
    int T_T,cas=1;
    cin>>T_T;
    memset(dp,-1,sizeof(dp));
    while(T_T--)
    {
        LL x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        printf("Case %d: %lld\n",cas++,gaoit(y)-gaoit(x-1));
    }
    return 0;
}
