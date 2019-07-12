///*** sparse table for maximum int the range *****///

int dp[20][MX],n;
void Sparse()
{
    n = in<int>();

    for (int i=0;i<n;i++)  dp[0][i] = in<int>();
    for (int i=1;(1<<i) <= n;i++){
        for(int j=0;j+(1<<i)-1 < n ;j++){
            if (dp[i-1][j] > dp[i-1][j+(1<<(i-1))])   dp[i][j] = dp[i-1][j];
            else                                      dp[i][j] = dp[i-1][j+(1<<(i-1))];
        }
    }
}
int mn(int xx,int yy)
{
    int diff = 31 - __builtin_clz(yy-xx+1);

    return ( dp[diff][xx]>dp[diff][yy-(1<<diff)+1] ? dp[diff][xx]:dp[diff][yy-(1<<diff)+1] );
}
int main()
{
    Sparse();
    int x,y,xx,yy,a=7%(n-1),b=11%n,diff,m;
    S3(m,x,y);
    xx=min(x,y),yy=max(x,y);
    diff=31-__builtin_clz((yy-xx)+1);
    LL ans=mn(xx,yy);
    F(i,2,m+1)
    {
        x=(x+a);
        y=(y+b);
        if(x>=(n-1)) x-=(n-1);
        if(y>=(n))   y-=(n);
        xx=min(x,y),yy=max(x,y);
        ans+=mn(xx,yy);
        diff=31-__builtin_clz(yy-xx+1);
    }
    printf("%lld\n",ans);

    return 0;
}
