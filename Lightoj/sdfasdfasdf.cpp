#include<bits/stdc++.h>

#define LL long long int


using namespace std;



///**********************************************************//


///         0123456789
#define MX  10000007
#define MOD 1000000007
#define INF (1<<28)
#define eps 1e-9
#define LL long long

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}




/// ==========================================////




LL N, K, Q;
LL a, b, c, d, e, f, p, q, r, s, t, m;
LL L1, La, Lc, Lm,D1, Da, Dc, Dm, aa, bb, tot;


int dp[25][MX],n;
void Sparse()
{
    scanf("%lld %lld %lld", &N, &K, &Q);
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &r, &s, &t, &m, &dp[0][1]);
    LL get = t;
    for (int i=2; i<=N; i++)
    {
        get = (get * t);
        if(get >= s)
            get = get%s;

        if(get <= r)
        {
            dp[0][i] = (((a * dp[0][i - 1])%m * dp[0][i - 1]) + (b*dp[0][i - 1])%m + c) % m;

            aa = (a * dp[0][i - 1]) ;
            if(aa >= m) aa = aa%m;
            aa = aa * dp[0][i - 1];

            bb = b*dp[0][i - 1];
            tot = aa + bb + c;
            if(tot >= m)
                tot = tot%m;
            dp[0][i] = tot;

        }
        else
        {
//            dp[0][i] =(((d * dp[0][i - 1])%m * dp[0][i - 1]) + (e*dp[0][i - 1])%m + f) % m;

            aa = (d * dp[0][i - 1]) ;
            if(aa >= m) aa = aa%m;
            aa = aa * dp[0][i - 1];

            bb = e*dp[0][i - 1];
            tot = aa + bb + f;
            if(tot >= m)
                tot = tot%m;
            dp[0][i] = tot;

        }
//        cout<<i<<" "<<dp[0][i]<<endl;
    }
    n = N;
    for (int i=1; (1<<i) <= n; i++)
    {
        for(int j=1; j+(1<<i)-1 <= n ; j++)
        {
            if (dp[i-1][j] < dp[i-1][j+(1<<(i-1))])   dp[i][j] = dp[i-1][j];
            else                                      dp[i][j] = dp[i-1][j+(1<<(i-1))];
        }
    }
}
LL mn(int xx,int yy)
{
    int diff = 31 - __builtin_clz(yy-xx+1);

    return ( dp[diff][xx]<dp[diff][yy-(1<<diff)+1] ? dp[diff][xx]:dp[diff][yy-(1<<diff)+1] );
}
int main()
{
    Sparse();
    LL x,y,xx,yy,diff;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &L1, &La, &Lc, &Lm, &D1, &Da, &Dc, &Dm);
    //xx=min(x,y),yy=max(x,y);
    diff=31-__builtin_clz((yy-xx)+1);
    LL L, R;
    LL ans = 0ll;
    LL ans2 = 1ll;

//    for(int i = 1;  i <= N; i++)
//        cout<<i<<" "<<dp[0][i]<<endl;
    LL a;
    for(LL i = 1; i <= Q; i++)
    {
        L1 = ((L1 * La) + Lc);
        if(L1 >= Lm)
            L1 = L1%Lm;
        D1 = ((D1 * Da) + Dc);
        if(D1 >= Dm)
            D1 = D1%Dm;
        L = L1 + 1;
        R = min(L + K - 1 + D1, N);
        xx=min(L,R),yy=max(L,R);
        a = mn(xx,yy);
        ans += a;
        ans2 = (ans2 * a);
        if(ans2>= MOD)
            ans2 = ans2%MOD;
        diff=31-__builtin_clz(yy-xx+1);
    }
    printf("%lld %lld\n",ans, ans2);

    return 0;
}

/*


10000000 2 10000000
1 1 1 1 1 1 1 1 1 100 1
1 1 1 3 1 1 1 2



*/
