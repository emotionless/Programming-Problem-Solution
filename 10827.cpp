#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#define LL long long
#define MX 120001
#define s(a) scanf("%d", &a)



using namespace std;

/*

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


int dp[151][151];
int mat[151][151];

int main()
{
    int i,j,k;
    int cases=1;
    int n, t;
    s(t);
    while(t--)
    {
        s(n);

        memset(dp, 0, sizeof dp);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                s(mat[i][j]);
                mat[i+n][j]=mat[i][j+n]=mat[i+n][j+n]=mat[i][j];

            }
        }

        for(i=1; i<=(n*2); i++)
        {
            for(j=1; j<=(n*2); j++)
            {
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i][j];
            }
        }
        int res=0;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                for(k=0; k<n; k++)
                {
                    for(int l=0; l<n; l++)
                    {
                        int sum=dp[i+k][j+l]-dp[i+k][j-1]-dp[i-1][j+l]+dp[i-1][j-1];
                        res=max(sum, res);
                    }
                }
            }
        }
        cout<<res<<endl;

    }
    return 0;
}
