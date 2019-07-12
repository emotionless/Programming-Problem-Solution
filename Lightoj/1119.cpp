#include<bits/stdc++.h>
#define LL long long
#define check_mask(a,b) (a&(1<<b))
#define set_mask(a,b) (a|(1<<b))
using namespace std;
int n;
int arr[16][16];
int dp[1000001];

int solve(int mask)
{
    if(mask>=(1<<n)-1) return 0;

    if(dp[mask]!=-1) return dp[mask];

    int mn=INT_MAX;

    for(int i=0; i<n; i++)
    {
        if(check_mask(mask,i)==0)
        {
            int w=arr[i][i];

            for(int j=0; j<n; j++)
            {
                if(i!=j && check_mask(mask, j)==0)
                    w+=arr[i][j];
            }
            mn=min(mn, w+solve(set_mask(mask, i)));
        }
    }
    return dp[mask]=mn;
}




int main()
{
    int i,j,t,cases=1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%d", &arr[i][j]);
        }
        memset(dp, -1, sizeof dp);
        int res=solve(0);
        printf("Case %d: %d\n", cases++, res);
    }
    return 0;
}

/*

2
10 10
9000 10
3
14 23 0
0 14 0
1000 9500 14


*/
