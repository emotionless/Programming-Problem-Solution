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
#define rep(i,a,b) for(i=a; i<b; i++)



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

bool mat[101][101];
int dp[101][101];



int main()
{
    int i,j,k;
    int cases=1, t;
    int n,s, x1, x2, y1, y2;
    cin>>t;
    while(t--)
    {
        cin>>n;

        cin>>s;
        memset(mat, true, sizeof mat);
        memset(dp, 0, sizeof dp);
        for(i=1; i<=n; i++)
            dp[i][0]=dp[0][i]=0;
        while(s--)
        {
            cin>>x1>>y1>>x2>>y2;
            rep(i,x1,x2+1)
            {
                rep(j,y1,y2+1)
                {
                    mat[i][j]=0;
                }
            }
        }

        rep(i, 1, n+1)
        {
            rep(j, 1, n+1)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+mat[i][j];
                //cout<<dp[i][j];
            }
            // cout<<endl;
        }
        int res=0;
        rep(i, 1, n+1)
        {
            rep(j, 1, n+1)
            {
                for(k=i; k<=n; k++)
                {
                    for(int l=j; l<=n; l++)
                    {
                        int sum=dp[k][l]+dp[i-1][j-1]-dp[k][j-1]-dp[i-1][l];
                        if(sum==(k-i+1)*(l-j+1))
                            res=max(res, sum);
                        else
                            break;
                    }
                }
            }
        }
        cout<<res<<endl;

    }

    return 0;
}
