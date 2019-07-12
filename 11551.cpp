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
ll mod;
struct matrix
{
    ll mat[60][60];
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

ll arr[60];

void solve(ll n, ll r)
{
    memset(ans.mat, 0, sizeof ans.mat);
    memset(base.mat, 0, sizeof base.mat);
    N = n;
    n = r;

    for(int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);
    int x;
    int ind;
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        while(x--)
        {
            scanf("%d", &ind);
            base.mat[i][ind] = 1;
        }
    }

    for(int i = 0; i < N; i++)
        ans.mat[i][i] = 1;


    while(n>0)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }
    memset(base.mat, 0, sizeof base.mat);

    for(int i = 0; i < N; i++)
    {
        ll res = 0ll;
        for(int j = 0; j < N; j++)
        {
            res = (res + (arr[j]*ans.mat[i][j])%mod) % mod;
        }
        printf("%lld", res);
        if(i == (N-1))
            printf("\n");
        else
            printf(" ");
    }
    return;
}


int main()
{
    int i, j, k;
    int t, cases = 0;
    ll n, m, r;
    scanf("%d", &t);
    mod = 1000;
    while(t--)
    {
        scanf("%lld %lld", &n, &r);
        solve(n, r);
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
