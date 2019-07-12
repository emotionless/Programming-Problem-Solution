#include<bits/stdc++.h>
#define LL long long

using namespace std;

int dp[1005][2];
int arr[1005],n;

int solve(int ind, int is)
{

    if(ind>=n) return 0;
    if(ind==n-1 && is==1) return 0;

    if(dp[ind][is]!=-1) return dp[ind][is];

    int tmp=max(solve(ind+2, is)+arr[ind], solve(ind+1, is));
    return dp[ind][is]=tmp;
}


int main()
{
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>arr[i];

        memset(dp,-1,sizeof dp);

        int res=solve(0,1);

        memset(dp,-1,sizeof dp);

        int tmp=solve(1, 0);
        printf("Case %d: %d\n", cases++, max(res,tmp));
    }
    return 0;
}
