#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define ll long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100009
#define mp make_pair

#define N 2


using namespace std;
int mod;
struct matrix
{
    ll mat[N][N];
} base, ans;
int md[30];
matrix multiply(matrix A, matrix B)
{
    matrix C;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            C.mat[i][j] = 0;
            for(int k = 0; k < N; k++)
            {
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])) % mod;
            }
        }
    }
    return C;
}


ll solve(int n)
{
    memset(ans.mat, 0, sizeof ans.mat);
    memset(base.mat, 0, sizeof base.mat);
    ans.mat[0][0] = ans.mat[1][1] = 1;

    base.mat[0][0] = 1;
    base.mat[0][1] = 1;
    base.mat[1][0] = 1;
    base.mat[1][1] = 0;

    while(n)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }
    memset(base.mat, 0, sizeof base.mat);

    base.mat[0][0] = 1;
    base.mat[1][0] = 0;

    ans = multiply(ans, base);
    return ans.mat[1][0] % mod;
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    md[0] = 1;
    for(i = 1; i <= 20; i++)
        md[i] = md[i-1]*2;

    int n, m;
    while(scanf("%d %d", &n, &m)==2)
    {
        mod = md[m];
        printf("%lld\n", solve(n) );
    }

    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
