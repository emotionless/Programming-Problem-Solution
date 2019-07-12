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



using namespace std;
int mod;
struct matrix
{
    ll mat[20][20];
} base, ans;

int N;

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

ll arr[20];

ll solve(int n)
{
    memset(ans.mat, 0, sizeof ans.mat);
    memset(base.mat, 0, sizeof base.mat);

    for(int i = 0; i < N; i++)
        scanf("%lld", &base.mat[0][i]);
    for(int i = 0; i < N; i++)
        scanf("%lld", &arr[N-i-1]);

    for(int i = 0; i < N; i++)
        ans.mat[i][i] = 1;

    for(int i = 1; i < N; i++)
    {
        base.mat[i][i-1] = 1;
    }
    n = n - N;
    while(n)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }
    memset(base.mat, 0, sizeof base.mat);

    for(int i = 0; i < N; i++)
        base.mat[i][0] = arr[i];

    ans = multiply(ans, base);


    return ans.mat[0][0] % mod;
}


int main()
{
    int i, j, k;
    int t, cases = 1;

    int n, m, d;
    while(scanf("%d %d %d", &d, &n, &m) && (n+m+d))
    {
        mod = m;
        N = d;
        printf("%lld\n", solve(n) );

    }

    return 0;
}

/*

2 10 100000
1 1
1 1

*/
