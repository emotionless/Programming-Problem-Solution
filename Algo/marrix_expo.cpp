/*
********************­********************­**
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon *********** ********************­********************­**
***** Sorry for bad written code **********
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>

#define MD 1000000007
#define LL long long
#define N 5

using namespace std;

struct matrix
{
    LL mat[N][N];
} ans, base;

LL A0, AX, AY, B0, BX, BY;

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
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j]) % MD) % MD;
            }
            //cout<<i<<" "<<j<<" "<<C.mat[i][j]<<endl;
        }
    }
    return C;
}
int c;

LL solve(LL n)
{
    memset(base.mat, 0, sizeof base.mat);
    memset(ans.mat, 0, sizeof ans.mat);

    base.mat[0][0] = 1;

    base.mat[0][1] = (AX * BX) % MD;
    base.mat[1][1] = (AX * BX) % MD;

    base.mat[0][2] = (AX * BY) % MD;
    base.mat[1][2] = (AX * BY) % MD;
    base.mat[2][2] = (AX) % MD;

    base.mat[0][3] = (BX * AY) % MD;
    base.mat[1][3] = (BX * AY) % MD;
    base.mat[3][3] = (BX) % MD;

    base.mat[0][4] = (AY * BY) % MD;
    base.mat[1][4] = (AY * BY) % MD;
    base.mat[2][4] = (AY) % MD;
    base.mat[3][4] = (BY) % MD;
    base.mat[4][4] = 1;



    for(int i = 0; i < N; i++)
        ans.mat[i][i] = 1;

    while(n)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }

    memset(base.mat, 0, sizeof base.mat);

    base.mat[0][0] = (A0 * B0) % MD;
    base.mat[1][0] = (A0 * B0) %MD;
    base.mat[2][0] = A0 % MD;
    base.mat[3][0] = B0 % MD;
    base.mat[4][0] = 1;

    ans = multiply(ans, base);

    return ans.mat[0][0] % MD;
}



int main()
{

    LL n;

    while(cin>>n)
    {

        cin>>A0>>AX>>AY;
        cin>>B0>>BX>>BY;
        if(n == 0)
        {
            cout<<0<<endl;
            continue;
        }
        AX = AX % MD;
        BX = BX % MD;
        AY = AY % MD;
        BY = BY % MD;
        A0 = A0 % MD;
        B0 = B0 % MD;

        LL res = solve(n - 1);

        cout<<res<<endl;
    }


    return 0;
}
