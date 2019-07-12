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
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define MX 120001



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
struct Z
{
    int val;
    string str;
    bool operator > (Z &a)
    {
        if (val != a.val)
            return val > a.val;
        return str < a.str;
    }
} dp[1001][1001];

int main()
{
    int i,j,k;
    int cases=1;
    string str;
    while(cin>>str)
    {

        int len=str.length();

        for(i=len-1; i>=0; i--)
        {
            for(j=i; j<len; j++)
            {
                if(str[i]==str[j])
                {
                    if(i==j)
                    {
                        dp[i][j].val=1;
                        dp[i][j].str=str[i];
                    }
                    else
                    {
                        dp[i][j].val=dp[i+1][j-1].val+2;
                        dp[i][j].str=str[i]+dp[i+1][j-1].str+str[j];
                    }
                }
                else
                {
                    if(dp[i+1][j].val>dp[i][j-1].val)
                    {
                        dp[i][j].val=dp[i+1][j].val;
                        dp[i][j].str=dp[i+1][j].str;
                    }
                    else if(dp[i+1][j].val<dp[i][j-1].val)
                    {
                        dp[i][j].val=dp[i][j-1].val;
                        dp[i][j].str=dp[i][j-1].str;
                    }
                    else
                    {
                        dp[i][j].val=dp[i+1][j].val;
                        dp[i][j].str=min(dp[i+1][j].str, dp[i][j-1].str);
                    }
                }
            }
        }

        cout<<dp[0][len-1].str<<endl;
        for(i=0; i<=len; i++)
        {
            for(j=0; j<=len; j++)
            {
                dp[i][j].val=0;
                dp[i][j].str="";
            }
        }
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