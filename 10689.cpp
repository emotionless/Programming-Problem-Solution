#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second

///***** Constant ******//
#define MX 1000007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7


using namespace std;

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
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

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}


/*

bool is_prime[MAX];
L prime[MAX];

bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/

struct matrix
{
    LL mat[2][2];
} base, ans;

int m, a, b;
int dig[5];
matrix multiply(matrix A, matrix B)
{
    matrix C;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            C.mat[i][j] = 0;
            for(int k = 0; k < 2; k++)
                C.mat[i][j] = (C.mat[i][j] + (A.mat[i][k] * B.mat[k][j]) % dig[m]) % dig[m];
        }
    }
    return C;
}

LL solve(int n)
{
    memset(ans.mat, 0, sizeof ans.mat);
    memset(base.mat, 0, sizeof base.mat);

    base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1;
    ans.mat[0][0] = ans.mat[1][1] = 1;

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
    return ans.mat[1][0] % dig[m];
}




int main()
{
    int i,j,k;
    int cases=1;
    int t, n;
    dig[1] = 10;
    dig[2] = 100;
    dig[3] = 1000;
    dig[4] = 10000;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n>>m;
        LL res = solve(n);
        cout<<res<<endl;
    }




    return 0;
}
/*

2
SQ 1 0
SQ 0 0
SQ 6 0
SQ 5 0



*/
