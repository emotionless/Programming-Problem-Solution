#include<bits/stdc++.h>
using namespace std;
int sum[1005][1005];
int mat[1005][1005];
int main()
{
    int i,j,k;
    int n,m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m &&n &&m)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                cin>>mat[i][j];
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];
            }
        }
        int mx=0,adjr,adjc;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                for(k=0; k<=min(n,m); k++)
                {
                    adjr=i+k;
                    adjc=j+k;
                    int numOfOne=sum[adjr][adjc]-sum[i-1][adjc]-sum[adjr][j-1]+sum[i-1][j-1];
                    if(numOfOne==(k+1)*(k+1))
                    {
                        mx=max(mx, k+1);
                    }
                }
            }
        }
        cout<<mx<<endl;
    }
    return 0;
}
