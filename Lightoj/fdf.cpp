#include <stdio.h>
#include <math.h>


static long long int memo[55][55];
static int n;
static int k;
static int m;
int max(int a,int b)
{
    return (a<b) ? b:a;
}
int mod(int x,int y)
{
    if(x<0)
        x=x+(-x/y+1)*y;
    return x%y;
}
int min(int a,int b)
{
    return (a<b) ? a:b;
}
long long int ways( int v,int i)
{
    int j=0;
    long long int ans=0;
    if(i==k&&v==n)
        return 1;
    if(v>n||i>k)
        return 0;
    if(memo[v][i]!=-1)
        return memo[v][i];
    for(j=1; j<=m; j++)
        ans+=ways(v+j,i+1);
    return memo[v][i]=ans;
}

int main()
{
    int x,q,i,j,r,c,t;
    while(scanf("%d %d %d",&n,&k,&m)==3)
    {
        for(i=0; i<55; i++)
            for(j=0; j<55; j++)
                memo[i][j]=-1;
        printf("%lld\n",ways(0,0));
    }
    return 0;
}
