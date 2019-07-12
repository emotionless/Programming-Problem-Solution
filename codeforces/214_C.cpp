#include<bits/stdc++.h>
#define LL long long
#define MX 100010

using namespace std;

int a[110], b[110];
int dp[110][MX];
int n;
int solve(int ind, int sum)
{
    if(ind==n)
    {
        if(sum==MX) return 0;
        else return -MX;
    }
    if(dp[ind][sum]!=-1) return dp[ind][sum];

    int tmp=solve(ind+1, sum);
    int tmp1=solve(ind+1, sum+b[ind]);
    tmp1+=a[ind];
    return dp[ind][sum]=max(tmp, tmp1);
}



int main()
{
    int i,j,k;
    int  temp;

    cin>>n>>k;

    for(i=0; i<n; i++)
        cin>>a[i];

    for(i=0; i<n; i++)
    {
        cin>>temp;
        b[i]=a[i]-(temp*k);
    }

    memset(dp, -1, sizeof dp);

    int res=solve(0, MX);
    if(res<1)
        cout<<-1<<endl;
    else
        cout<<res<<endl;


    return 0;
}
