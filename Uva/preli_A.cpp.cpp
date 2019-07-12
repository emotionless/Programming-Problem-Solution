#include<bits/stdc++.h>
#define PI acos(-1)
#define LL long long
#define check_mask(a,b) (a&(1<<b))
#define set_mask(a,b) (a|(1<<b))

using namespace std;
int c[11],n, w[11];
int dp[11][(1<<19)+10];
bool arr[11][11];

int solve(int ind, int mask)
{
    // cout<<ind<<" "<<mask<<endl;
    int a=check_mask(mask, ind)?1:0;
    int b=check_mask(mask, ind+10)?1:0;
    if(a+b>=w[ind]) return 0;
    if(dp[ind][mask]!=-1) return dp[ind][mask];

    int ret=0;
    // cout<<ind<<" "<<mask<<endl;

    if(a)
    {
        mask=set_mask(mask,ind+10);
    }
    else
    {
        mask=set_mask(mask, ind);
        ret+=c[ind];
    }

    int mx=0;

    for(int i=0; i<n; i++)
    {
        if(arr[ind][i] && i!=ind)
        {
            mx=max(mx, solve(i,mask));
        }
    }
    ret+=mx;
    cout<<ind<<" "<<mask<<" "<<ret<<endl;
    return dp[ind][mask]=ret;
}



int main()
{
    int i,j,k;
    int t, cases=1,m;

    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
            cin>>w[i];

        for(i=0; i<n; i++)
            cin>>c[i];

        memset(arr, false, sizeof arr);
        int u,v;
        for(i=0; i<m; i++)
        {
            cin>>u>>v;
            u--;
            v--;
            arr[u][v]=true;
            arr[v][u]=true;
        }

        memset(dp, -1, sizeof dp);
        int mx=0;
        for(i=0; i<n; i++)
        {
            //  cout<<i<<endl;
            memset(dp, -1, sizeof dp);
            mx=max(mx,solve(i, 0));
        }
        cout<<mx<<endl;
    }

    return 0;
}


/*

1
2 2
1 1
1 1
1 2
2 1

1
3 2
1 1 2
1 1 1
1 2
2 3


1
3 1
1 1 1
1 1 2
1 2

1
6 5
1 2 2 1 2 2
1 1 1 1 1 1
1 2
2 6
2 3
3 4
4 5



1
10 9
1 2 2 2 2 2 2 2 2 2
1 1 1 1 1 1 1 1 1 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10


*/

