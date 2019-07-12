#include<bits/stdc++.h>
#define LL long long

using namespace std;
int arr1[1001];
int arr2[1001];
int arr3[2002];
int dp[1001][1001];
int n,m,K;

int solve(int ind1, int ind2, int ind3)
{
    if(ind3==K)
    {
        if(ind1==n && ind2==m) return 1;
        return 0;
    }
    if(ind1==n && ind2==m) return 0;
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    int ret=0;
    if(arr3[ind3]==arr1[ind1] && arr3[ind3]==arr2[ind2])
        ret=solve(ind1+1, ind2, ind3+1)|solve(ind1, ind2+1, ind3+1);
    else if(arr3[ind3]==arr1[ind1])
        ret=solve(ind1+1, ind2, ind3+1);
    else if(arr3[ind3]==arr2[ind2])
        ret=solve(ind1, ind2+1, ind3+1);
    else
        ret=0;

    dp[ind1][ind2]=ret;
    return dp[ind1][ind2];

}




int main()
{
    int i,j;
    while(cin>>n>>m && n &&m)
    {
        for(i=0; i<n; i++)
            cin>>arr1[i];

        for(j=0; j<m; j++)
            cin>>arr2[j];

        memset(dp, -1, sizeof dp);
        K=n+m;

        for(i=0; i<K; i++)
            cin>>arr3[i];

        bool res=solve(0,0,0);

        if(res)
            cout<<"possible\n";
        else
            cout<<"not possible\n";
    }
    return 0;
}

/*


3 3
1 2 1
2 1 2
1 1 1 2 2 2


*/
