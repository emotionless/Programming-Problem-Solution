/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MAX 1562501
#define PB push_back
#define set_mask(a,b) (a|(1<<b))


using namespace std;
#define MOD 1000000009


int m;
LL dp[101][101];
long long save[100001];
long long num[101];
long long fact[100001];

void init()
{
    fact[0]=1LL;
    for(LL i=1; i<=100000; i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
    }
}

LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}


LL mi[100001];

LL NCR(int N, int R)
{
    if(R>N) return 0;
    if(R==0 || N==0) return 1;
    if(R==1) return N;
    return (((fact[N]*mi[N-R])%MOD)*mi[R])%MOD;
}


int main()
{
    int i,j,k,q;
    int t,n;
    init();


    for(i=0; i<=100000; i++)
        mi[i]=modinverse(fact[i],MOD);
    scanf("%d", &t);

    map< pair<LL, int>, LL>M;
    while(t--)
    {
        scanf("%d %d", &n, &q);
        for(i=0; i<n; i++)
            scanf("%lld", &save[i]);
        while(q--)
        {
            scanf("%d", &m);
            memset(num, 0, sizeof num);
            for(i=0; i<n; i++)
            {
                int tmp=(save[i]%m +m)%m;
                num[tmp]++;
            }
            memset(dp, 0, sizeof dp);
            // long long res=solve(0,0);

            dp[m][0]=1;

            for(i=m-1; i>=0; i--)
            {
                for(k=0; k<m && k<=num[i]; k++)
                {
                    for(j=0; j<m; j++)
                    {
                        int tmp=(k+i*j)%m;
                        LL sum=0;
                        for(int l=j; l<=num[i]; l+=m)
                        {
                            sum=(sum+NCR(num[i], l))%MOD;
                        }
                        LL hud=(dp[i+1][tmp]*sum)%MOD;
                        dp[i][k]=(dp[i][k]+hud)%MOD;
                    }
                }
            }
            printf("%lld\n", dp[0][0]%MOD);




            // printf("%lld\n", res);
        }
    }
    return 0;
}

/*

1
5 2
1 2 3 4 5
15
5



*/
