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
#define MOD 4294967296
#define MX 100009
#define mp make_pair


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
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

using namespace std;
ll mod;
struct matrix
{
    ll mat[55][55];
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
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])) %MOD;
            }
        }
    }
    return C;
}

ll com[100][100];


ll solve(ll n, ll K)
{
    memset(ans.mat, 0, sizeof ans.mat);
    memset(base.mat, 0, sizeof base.mat);
    int i;
    for(int i = 0; i <= K; i++)
    {
        for(int j = i; j <= K; j++)
        {
            base.mat[i][j] = com[K-i][j-i];
        }
    }
    for(int i = 0; i <= K; i++)
    {
        base.mat[N-1][i] = com[K][i];
    }
    base.mat[N-1][N-1] = 1;

    for(int i = 0; i < N; i++)
        ans.mat[i][i] = 1;
    n=n-1;
    while(n>0)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }
    memset(base.mat, 0, sizeof base.mat);

    for(int i = 0; i < N; i++)
        base.mat[i][0] = 1;

    ans = multiply(ans, base);
    return ans.mat[N-1][0];
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    ll n, m, r, p, q, K;
    com[0][0] = 1;
    for(i = 1; i <= 50; i++)
    {
        com[i][0] = 1;
        for(j = 1; j <= i; j++)
        {
            com[i][j] = (com[i-1][j] + com[i-1][j-1])%MOD;
        }
    }

    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld", &n, &K);
        N = K + 2;
        printf("Case %d: %lld\n", cases++, solve(n, K));
    }

    return 0;
}

/*


2
2 1
1 2
2 0 1
1 1

2
507 692
2 0 1
1 1


*/
