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
***** Sorry for bad written code **********
*/


#include<bits/stdc++.h>

#define LL long long
#define MX 100        // 10^5 + 9
#define MOD 10000007   // 10^9 + 7
#define PB push_back
#define sc1(a) scanf("%d", &a)
#define sc1l(a) scanf("%lld", &a)
#define set_mask(a,b) (a|(1<<b))
#define check_mask(a,b) (a&(1<<b))
#define fr(i, b) for(i = 0; i < b; i++)

using namespace std;

LL dp[MX][MX];
int n, m;
LL mat[MX][MX];
LL solve(int r, int c)
{
    if(c == m)
        return mat[r][c];

    LL &ret = dp[r][c];
    if(ret != -1ll) return ret;
    ret = 0ll;
    for(int i = 1; i <= n; i++)
    {
        ret = (ret + (mat[r][c] * solve(i, c + 1)) % MOD) % MOD;
    }
//    cout<<r<<" "<<c<<" "<<ret<<endl;
    if(ret < 0)
        ret = ret + MOD;
    return ret;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");
    int i, j;
    int t;
    cin>>n>>m;

    for(i = 0; i <= n; i++)
        for(j = 0; j <= m; j++)
            mat[i][j] = 1ll;

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
            cin>>mat[i][j];
    }

    memset(dp, -1ll, sizeof dp);

    LL res = 0ll;
    res = (solve(0, 0) + MOD) % MOD;
    cout<<res<<endl;








    return 0;
}

/*

2 3
-1 -1 -1
-1 -1 -1

*/
