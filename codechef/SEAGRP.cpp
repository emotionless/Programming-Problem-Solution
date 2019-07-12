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
#define MX 5000+7
#define MOD 1000000007
#define N 1000007
#define PB push_back


using namespace std;

LL fact[MX];

void init()
{
    int i = 0;
    fact[0] = 1;

    for(i = 1; i <= MX; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
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

LL calc(int n, int r)
{
    int up = n + r - 1;
    int down = r;

    return (fact[up] * modinverse( (fact[down] * fact[n - 1]) % MOD , MOD)) % MOD;
}



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

     int n, q,m;
    init();

    int t, u, v, l, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &n, &m, &l, &r);
        LL res = 0;
        for(int d = l; d <= r; d++)
        {
            int up = m/d;
            int down = n;
            LL a = calc(down, up);
            res = (res + a) % MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}

/*

2
5 5 5 5

*/
