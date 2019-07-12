#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 4294967296
#define MX 100009
#define mp make_pair

using namespace std;

struct matrix
{
    LL mat[55][55];
} ans, base;
LL C[55][55];

LL init()
{
    for(int i=0;i<=50;i++)
    {
        C[i][0]=1;
        C[i][i]=1;
        C[i][1]=i;
    }
    for(int i=2;i<=50;i++)
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
}


matrix multiply(matrix A, matrix B)
{
    matrix C;
    int i , j, k;
    for(i = 0; i < 55; i++)
    {
        for(j = 0; j < 55; j++)
        {
            for(k = 0; k < 55; k++)
                C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % MOD;
        }
    }
return C;
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

void solve(LL n, int K)
{
    memset(ans.mat, 0, sizeof ans.mat);
    memset(base.mat, 0, sizeof base.mat);
    int i, j, k;
    LL nn = n;
    base.mat[0][0] = 1;
    base.mat[1][0] = 0;
    for(i = 1; i <= K; i++)
        base.mat[0][i] = base.mat[1][i] = C[K][i - 1];

    for(i = 2; i <= K; i++)
    {
        int ed = K - i - 1;
        for(j = i; j <= ed; j++)
        {
            base.mat[i][j] = C[K - i - 1][j - i];
        }
    }

    for(i = 0; i <= K; i++)
        ans.mat[i][i] = 1;

    while(n)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }
    memset(base.mat, 0, sizeof base.mat);

    for(i = 0; i <= K; i++)
    base.mat[i][0] = bigmod(nn, K - i, MOD);
    ans = multiply(ans, base);
    cout<<ans.mat[K-1][0]<<endl;
    return;
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    init();
    LL n;
    int m;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;
        solve(n, m);
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
