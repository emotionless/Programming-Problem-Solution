#include<bits/stdc++.h>
#define LL long long

using namespace std;
int n,m;
int dp[25][25][25][25];
int mat[25][25];

bool vis[25][25];

int solve(int r1, int c1, int r2, int c2)
{
  //  cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<endl;
    if(r1>=n || r2>=n || c1>=m || c2>=m) return 0;

    if(r1==n-1 && c1==m-1)
    {
        if(r2==n-2 && c2==m-1) return mat[n-1][m-1]+mat[r2][c2];
        else
            return -10000;
    }

    if(r2==n-1 && c2==m-1)
    {
        if(r1==n-1 && c1==m-2) return mat[n-1][m-1]+mat[r1][c1];
        else
            return -10000;
    }


    int &ret=dp[r1][c1][r2][c2];
    if(ret!=-1) return ret;

    ret=0;

    int first1=r1;
    int first2=c1+1;

    if(!vis[first1][first2])
        ret=max(ret, solve(first1, first2, r2, c2)+mat[r1][c1]);



    first1=r1+1;
    first2=c1;

    if(!vis[first1][first2])
        ret=max(ret, solve(first1, first2, r2, c2)+mat[r1][c1]);



    first1=r2;
    first2=c2+1;

    if(!vis[first1][first2])
        ret=max(ret, solve(r1, c1, first1, first2)+mat[r2][c2]);


    first1=r2+1;
    first2=c2;

  //  cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<first1<<" "<<first2<<endl;

    if(!vis[first1][first2])
        ret=max(ret, solve(r1, c1, first1, first2)+mat[r2][c2]);
    vis[r1][c1]=vis[r2][c2]=true;
    cout<<r1<<" "<<c1<<" "<<r2<<" "<<c2<<" "<<ret<<endl;
    return ret;
}


int main()
{
    int i,j,k;

    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            cin>>mat[i][j];
    }
    memset(vis, false, sizeof vis);
    memset(dp, -1, sizeof dp);
    int res=solve(1,0,0,1);
    cout<<res<<endl;

    return 0;
}


/*

3 3
1 1 1
1 0 1
1 1 1





*/
