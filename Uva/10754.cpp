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
    ll mat[30][30];
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

    base.mat[N-1][N-1] = 1;

    for(int i = 0; i < N; i++){
        scanf("%lld", &base.mat[0][i]);
        base.mat[0][i] %= mod;
        base.mat[0][i] = (base.mat[0][i]+mod)%mod;
//        cout<<base.mat[0][i]<<endl;
    }
    for(int i = 0; i < N-1; i++){
        scanf("%lld", &arr[N-i-2]);
        arr[N-i-2] %= mod;
        arr[N-i-2] = (arr[N-i-2] + mod)%mod;
    }

    for(int i = 0; i < N; i++)
        ans.mat[i][i] = 1;

    for(int i = 1; i < N - 1; i++)
    {
        base.mat[i][i-1] = 1;
    }
    if(n < N-1)
        return arr[N-n-2];
    n = n-N + 2;
    while(n>0)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }

//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < N; j++)
//            cout<<ans.mat[i][j]<<" ";
//        cout<<endl;
//    }

    memset(base.mat, 0, sizeof base.mat);

    for(int i = 0; i < N-1; i++)
        base.mat[i][0] = arr[i];
    base.mat[N-1][0] = 1;

    ans = multiply(ans, base);
    return ans.mat[0][0] % mod;
}


int main()
{
    int i, j, k;
    int t, cases = 0;
    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &k, &m, &n);
        N = k+1;
        mod = m;
        if(cases)
            printf("\n");
        cases = 1;
        printf("%lld\n", (solve(n)%mod + mod)%mod);
    }


    return 0;
}

/*
2
2 10 10
1 1 0
1 1

1
3 100 3
1 2 3 4
1 1 1


16

2 76 0
2147483647 2147483647 -2147483648
-2147483647 -2147483648

2 76 1
2147483647 2147483647 -2147483648
-2147483647 -2147483648

2 76 2
2147483647 2147483647 -2147483648
-2147483647 -2147483648

2 76 3
2147483647 2147483647 -2147483648
-2147483647 -2147483648

2 76 4
2147483647 2147483647 -2147483648
-2147483647 -2147483648

0 88 10
2147483647

2 1000 0
1 1 0
-1 -1

2 30 1
1 1 0
-1 -1

2 54 2
1 1 0
-1 -1

2 3453 3
1 1 0
-1 -1

2 3453 4
1 1 0
-1 -1

2 45 5
1 1 0
-1 -1

2 543 6
1 1 0
-1 -1

5 85785 34385
34 -54 2332 -543 54 -555
213 23 22 333 -42

1 1 1
1 1
1

5 89485 435
345 45 454 -555 -555 -555
-234 -35 -54 -54 -54


*/
