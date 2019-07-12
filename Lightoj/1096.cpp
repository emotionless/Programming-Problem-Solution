#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100009
#define mp make_pair

using namespace std;
int m;
struct matrix
{
    int mat[4][4];
} base, ans;


matrix multiply(matrix A, matrix B)
{
    matrix C;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            C.mat[i][j] = 0;
            for(int k = 0; k < 4; k++)
            {
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])) % 10007;
            }
        }
    }
    return C;
}


int solve(int a, int b, int c, int n)
{
    memset(base.mat, 0, sizeof base.mat);
    memset(ans.mat, 0, sizeof ans.mat);
    base.mat[0][0] = a;
    base.mat[0][1] = 0;
    base.mat[0][2] = b;
    base.mat[0][3] = c;

    base.mat[1][0] = 1;
    base.mat[1][1] = 0;
    base.mat[1][2] = 0;
    base.mat[1][3] = 0;

    base.mat[2][0] = 0;
    base.mat[2][1] = 1;
    base.mat[2][2] = 0;
    base.mat[2][3] = 0;

    base.mat[3][0] = 0;
    base.mat[3][1] = 0;
    base.mat[3][2] = 0;
    base.mat[3][3] = 1;


    ans.mat[0][0] = ans.mat[1][1] = ans.mat[2][2] = ans.mat[3][3] = 1;

    while(n)
    {
        if(n&1) ans = multiply(ans, base);
        base = multiply(base, base);
        n = n / 2;
    }
    memset(base.mat, 0, sizeof base.mat);

    base.mat[0][0] = 0;
    base.mat[1][0] = 0;
    base.mat[2][0] = 0;
    base.mat[3][0] = 1;

    ans = multiply(ans, base);
    return ans.mat[2][0] % 10007;
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    int n, m;
    scanf("%d", &t);
    int a, b, c;
    while(t--)
    {
        cin>>n>>a>>b>>c;
        printf("Case %d: ", cases++);
        cout<<solve(a, b, c, n)<<endl;
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
