///***** EXGCD + CRT + Knuth ******///

///EXTENDED EUCLID
LL exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0ll)
    {
        x=1ll,y=0ll;
        return a;
    }
    LL ret=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ret;
}

//CHINESE REMAINDER THEOREM
LL rem[MAX];
LL mod[MAX];

LL CRT(int n)
{
    for(int i=0; i<n; i++) rem[i]%=mod[i];
    LL ret=rem[0],LCM=mod[0];
    for(int i=1; i<n; i++)
    {
        LL x,y;
        LL gd=exgcd(mod[i],-LCM,x,y);
        LL dif=ret-rem[i];

        if(dif%gd!=0) return -1;

        LCM=LCM/gd*mod[i];
        if(LCM<0) LCM=-LCM;
        x=x*dif/gd;
        ret=(mod[i]*x+rem[i])%LCM;
        if(ret<0ll) ret+=LCM;
    }
    return ret;
}

/// Knuth
///initially s = 1, e = 1, x = 1, y = n;
int solve(int stp, int s, int e, int x, int y)
{
    if(s > e) return 0;

    int mid = (s + e)/2;
    int &ret = dp[stp][mid];
    if(dp[stp][mid] != -1) return ret;
    ret = 100000000;
    int ind = -1;
    for(int i = x; i <= min(mid, y); i++)
    {
        int tmp = dp[stp - 1][i] + mat[i + 1][mid];
        if(tmp < ret)
        {
            ret = tmp;
            ind = i;
        }
    }
    solve(stp, s, mid, x, ind);
    solve(stp, mid + 1, e, ind, y);

}
