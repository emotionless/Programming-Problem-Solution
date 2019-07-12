#include<bits/stdc++.h>
#define LL long long

using namespace std;
int n,m;
int mat[105][105];
int dp[105][105][105][3];

int solve(int row, int c1, int c2, int path)
{
    if(row==n-1 && c1==m-2 && c2==m-1 && path==0) return 0;

    int &ret=dp[row][c1][c2][path];
    if(ret!=-1) return ret;
    ret=0;

    if(path==0)
    {
        if(c1+1<m && c1+1<c2) ret=max(ret, solve(row, c1+1, c2, 0)+mat[row][c1+1]);
        ret=max(ret, solve(row, c1, c2, 1));
    }
    else if(path==1)
    {
        if(c2+1<m) ret=max(ret, solve(row, c1, c2+1, 1)+ mat[row][c2+1]);
        if(c2>c1) ret=max(ret,  solve(row, c1, c2, 2));
    }
    else
    {
        if(row+1<n)
            ret=max(ret, solve(row+1, c1, c2, 0)+mat[row+1][c1]+mat[row+1][c2]);
    }
    return ret;
}


int main()
{
    int i,j,k;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        scanf("%d %d", &n, &m);

        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
                scanf("%d", &mat[i][j]);
        }
        memset(dp, -1, sizeof dp);

        int res=solve(0, 0, 0, 1)+mat[0][0];

        printf("Case %d: %d\n", cases++, res);
    }
    return 0;
}
