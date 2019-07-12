#include<bits/stdc++.h>

#define LL long long
#define N 6

using namespace std;

struct matrix
{
    LL mat[N][N];
} base, ans;
int MD;
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
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])) % MD;
            }
        }
    }
    return C;
}




void solve(int a1, int b1, int c1, int a2, int b2, int c2, int f0, int f1, int f2, int g0, int g1, int g2, LL n)
{
    memset(base.mat, 0, sizeof base.mat);
    memset(ans.mat, 0, sizeof ans.mat);

    // base is here
    base.mat[0][0] = a1;
    base.mat[0][1] = b1;
    base.mat[0][2] = 0;
    base.mat[0][3] = 0;
    base.mat[0][4] = 0;
    base.mat[0][5] = c1;

    base.mat[1][0] = 1;
    base.mat[1][1] = 0;
    base.mat[1][2] = 0;
    base.mat[1][3] = 0;
    base.mat[1][4] = 0;
    base.mat[1][5] = 0;

    base.mat[2][0] = 0;
    base.mat[2][1] = 1;
    base.mat[2][2] = 0;
    base.mat[2][3] = 0;
    base.mat[2][4] = 0;
    base.mat[2][5] = 0;

    base.mat[3][0] = 0;
    base.mat[3][1] = 0;
    base.mat[3][2] = c2;
    base.mat[3][3] = a2;
    base.mat[3][4] = b2;
    base.mat[3][5] = 0;

    base.mat[4][0] = 0;
    base.mat[4][1] = 0;
    base.mat[4][2] = 0;
    base.mat[4][3] = 1;
    base.mat[4][4] = 0;
    base.mat[4][5] = 0;

    base.mat[5][0] = 0;
    base.mat[5][1] = 0;
    base.mat[5][2] = 0;
    base.mat[5][3] = 0;
    base.mat[5][4] = 1;
    base.mat[5][5] = 0;


    ans.mat[0][0] = ans.mat[1][1] = ans.mat[2][2] =  ans.mat[3][3] = ans.mat[4][4] = ans.mat[5][5] = 1;

    while(n)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }
    memset(base.mat, 0, sizeof base.mat);

    base.mat[0][0] = f2;
    base.mat[1][0] = f1;
    base.mat[2][0] = f0;
    base.mat[3][0] = g2;
    base.mat[4][0] = g1;
    base.mat[5][0] = g0;

    ans = multiply(ans, base);
    cout<<ans.mat[2][0]%MD<<" "<<ans.mat[5][0]%MD<<endl;
    return;
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    LL n, m;
    scanf("%d", &t);
    int a, b, c;

    LL a3, a1, a2, b1, b2, b3, c1, c2, c3, f0, f1, f2, g0, g1, g2;
    while(t--)
    {
        cin>>a1>>b1>>c1;
        cin>>a2>>b2>>c2;

        cin>>f0>>f1>>f2;
        cin>>g0>>g1>>g2;
        cin>>MD;
        int q;
        cin>>q;
        printf("Case %d:\n", cases++);

        while(q--)
        {
            cin>>n;
            solve(a1, b1, c1, a2, b2, c2, f0, f1, f2, g0, g1, g2, n);
        }
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
