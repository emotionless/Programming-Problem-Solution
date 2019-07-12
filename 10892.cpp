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
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
long arr[11000];

int divisor(long x)
{
    long n;
    long i;
    n=sqrt(x);
    int cnt=0;
    for(i=2; i<=n; i++)
    {
        if(x%i==0)
        {
            arr[++cnt]=i;
            if(x/i!=i)
                arr[++cnt]=x/i;
        }
    }
    return cnt;
}
long gcd(long a,long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

long CAR(long a, long b)
{
    return (a/gcd(a,b))*b;
}



int main()
{
    long n;
    while(scanf("%ld",&n)==1 && n)
    {
        long cnt=divisor(n);
        long cardinary=0;
        for(long i=1; i<cnt; i++)
        {
            for(long j=i+1; j<=cnt; j++)
            {
                long a=CAR(arr[i],arr[j]);
                if(a==n)
                {
                    ++cardinary;
                }
            }
        }
        if(n==1)
            printf("%ld %ld\n",n,cnt+cardinary+1);
        else
            printf("%ld %ld\n",n,cnt+cardinary+2);
    }
    return 0;
}

