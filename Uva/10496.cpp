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
#define check(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))



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
    int x, y;
} V[12];
int dp[12][2<<12];
int num;
int solve(int ind, int mask)
{
    if(mask==((1<<(num+1))-1))
    {
        return abs(V[ind].x-V[0].x) + abs(V[ind].y - V[0]. y);
    }
    int &ret=dp[ind][mask];
    if(ret!=-1) return ret;

    ret=1000000;

    for(int i=0; i<=num; i++)
    {
        if(check(mask, i)==0  && i!=ind)
        {
            ret=min(ret, solve(i, set_bit(mask, i))+abs(V[ind].x-V[i].x) + abs(V[ind].y - V[i].y));
        }
    }
    return ret;
}


int main()
{
    int i,j,k;
    int cases=1;

    int n, x, y;
    int t;
    cin>>t;
    while(t--)
    {

        cin>>x>>y;

        cin>>V[0].x>>V[0].y;

        cin>>num;
        for(i=1; i<=num; i++)
        {
            cin>>V[i].x>>V[i].y;
        }
        for(i=0; i<12; i++)
            memset(dp[i], -1, sizeof dp[i]);
        int res=solve(0, 1);
        cout<<"The shortest path has length "<<res<<endl;
    }
    return 0;
}
