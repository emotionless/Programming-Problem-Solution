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
int md[5];
int m;
struct matrix
{
    int mat[2][2];
} base, ans;
int a, b;
matrix multiply(matrix A, matrix B)
{
    matrix C;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            C.mat[i][j] = 0;
            for(int k = 0; k < 2; k++)
            {
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j])) % md[m];
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
    return ans.mat[1][0] % md[m];
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    md[1] = 10;
    md[2] = 100;
    md[3] = 1000;
    md[4] = 10000;

    int n;
    scanf("%d", &t);
    while(t--)
    {
        cin>>a>>b>>n>>m;
        printf("Case %d: ", cases++);
        cout<<solve(a, b, n)<<endl;
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
