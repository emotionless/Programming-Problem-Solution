#include<bits/stdc++.h>
#define LL long long

using namespace std;
int price[105], weight[105];
int n;
int dp[105][10005];

int solve(int ind, int w)
{
    if(ind>=n) return 0;

    if(dp[ind][w]!=-1) return dp[ind][w];

    int a=0,b=0, c=0;
    if(w-weight[ind]>=0)
        a= solve(ind, w-weight[ind])+price[ind];
    if(w-weight[ind+1]>=0)
        b=solve(ind+1, w-weight[ind+1])+price[ind+1];
    c=solve(ind+1, w);
    return dp[ind][w]=max(a, max(b,c));
}



int main()
{
    int i, cases=1, need,w,t;

    cin>>t;
    while(t--)
    {
        cin>>n>>w;
        int sum=0;

        memset(price, 0, sizeof price);
        memset(weight, 0, sizeof weight);
        for(i=0; i<n; i++)
        {
            cin>>price[i]>>need>>weight[i];
            sum+=(need*weight[i]);
        }
        memset(dp, -1, sizeof dp);
        printf("Case %d: ",cases++);
        if(sum>w)
        {
            printf("Impossible\n");;
            continue;
        }


        int res=solve(0, w-sum);
        printf("%d\n", res);
    }

    return 0;
}
