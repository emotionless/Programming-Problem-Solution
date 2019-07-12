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

int t;

double dp[1<<16];
int xx[17];
int yy[17];

double dist(int a, int b)
{
    return sqrt(((xx[a]-xx[b])*(xx[a]-xx[b]))+ ((yy[a]-yy[b])*(yy[a]-yy[b])));
}

double solve(int mask)
{
    if(mask==(1<<t)-1) return 0.0;
    double &ret=dp[mask];
    if(ret!=-1.0) return ret;
    ret=100000.0;
    for(int i=0; i<t; i++)
    {
        if(check_bit(mask, i)==0)
        {
            int tmp=set_bit(mask,i);
            for(int j=i+1; j<t; j++)
            {
                if(check_bit(tmp, j)==0)
                    ret=min(ret, solve(set_bit(tmp, j))+dist(i,j));
            }
            break;
        }
    }
    return ret;
}



int main()
{
    int i,j,k;
    int cases=1;

    while(s(t) && t)
    {
        t=t*2;
        char str[1001];

        for(i=0; i<t; i++)
        {
            scanf("%s", str);
            s(xx[i]);
            s(yy[i]);
        }

        for(i=0; i<(1<<16); i++)
            dp[i]=-1.0;

        double res=solve(0);
        printf("Case %d: %.2lf\n", cases++, res);
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
