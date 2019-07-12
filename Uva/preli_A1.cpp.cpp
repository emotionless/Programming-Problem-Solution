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
    int a=check_mask(mask, ind)?1:0;
    int b=check_mask(mask, ind+10)?1:0;
    if(a+b>w[ind]) return 0;
    if(dp[ind][mask]!=-1) return dp[ind][mask];
    int sum=0;
    if(!(a || b))
    {
        sum=c[ind];
    }
    int ret=sum;
    int mx=0;
    if(a)
        mask=set_mask(mask, ind+10);
    else
        mask=set_mask(mask, ind);

    for(int i=1; i<=n; i++)
    {
        if(arr[ind][i]==true && ind!=i)
        {
            mx=max(mx,solve(i, mask));
        }
    }
    cout<<ind<<" "<<mask<<" "<<ret+mx<<endl;
    return dp[ind][mask]=ret+mx;
}



int main()
{
    int m,t,i, cases=1;

    cin>>t;

    while(t--)
    {
        cin>>n>>m;
        memset(arr, false, sizeof arr);
        w[n+2];

        for(i=1; i<=n; i++)
        {
            cin>>w[i];
        }
        for(i=1; i<=n; i++)
        {
            cin>>c[i];
        }

        int u,v;

        for(i=1; i<=m; i++)
        {
            cin>>u>>v;
            arr[u][v]=true;
            arr[v][u]=true;
        }
        int mx=0;
        for(i=1; i<=1; i++)
        {
            memset(dp, -1, sizeof dp);
            mx=max(mx, solve(i,0));
            // cout<<"For: "<<i<<" "<<mx<<endl;
        }
        cout<<"Case "<<cases<<": "<<mx<<endl;
        cases++;
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
5 4
1 2 2 2 2
1 1 1 1 1
1 2
2 3
3 4
4 5


*/
