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
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}


using namespace std;
#define MX 1000001


void numberOfDivisors();

void sieve();


bool is[MX];
int divisor[MX];
vector<int>prime;

int main()
{
    int i,j,k;
    int n;
    sieve();
    numberOfDivisors();
}

void numberOfDivisors()
{
    divisor[1]=1;
    divisor[2]=2;
    divisor[3]=2;
    int res=1;
    for(int i=4; i<MX; i++)
    {
        double sqd=sqrt(i);
        int sq=sqrt(i);
        int j=0;
        for(j=0; prime[j]<=sq; j++)
        {
            int cnt=0;
            while(sq%prime[j]==0)
            {
                sq/=prime[j];
                cnt++;
            }
            res=res*(cnt+1);
        }
        if(sq==sqd) res--;
        divisor[i]=res;
    }
}

void sieve()
{
    int i,j;
    for(i=4; i<MX; i+=2)
        is[i]=true;
   // prime.PB(2);
    int sq=sqrt(MX);
    for(i=3; i<sq; i+=2)
    {
        if(is[i]==false)
        {
       //     prime.PB(i);
            for(j=i+i; j<MX; j+=i)
                is[j]=true;
        }
    }
    for(i=2;i<MX;i++)
    {
        if(!is[i])
        prime.PB(i);
    }
}
