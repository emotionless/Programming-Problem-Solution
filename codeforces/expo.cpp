///**************** Matrix expo *********************///
/**
f[0] = a;f[1] = b;
f[n] = (f[n-1] + f[n-2])%MOD;
**/

#define M 2
struct matrix
{
    int mat[M][M];
} base, ans;
matrix multiply(matrix A, matrix B)
{
    matrix C;
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            C.mat[i][j] = 0;
            for(int k = 0; k < M; k++)
            {
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])) % MOD;
            }
        }
    }
    return C;
}

int solve(int a, int b, int n)
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

    base.mat[0][0] = b;
    base.mat[1][0] = a;

    ans = multiply(ans, base);
    return ans.mat[1][0] % MOD;
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        cin>>a>>b>>n;
        printf("Case %d: ", cases++);
        cout<<solve(a, b, n)<<endl;
    }
    return 0;
}
