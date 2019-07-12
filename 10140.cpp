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
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) mix(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define L long
#define I int
#define vi vector<int>
#define nl() printf("\n")
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MAX 1000003

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






bool is_prime[MAX];

vi prime;

bool sieve()
{
    long i,j;
    prime.PB(2);
    is_prime[1]=1;
    is_prime[2]=0;
    for(i=4; i<MAX; i+=2)
        is_prime[i]=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(i=3;i<=MAX;i+=2)
    {
        if(!is_prime[i])
        prime.PB(i);
    }

}
/*

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

bool check(L n)
{
    if(n<=1000003)
        return is_prime[n];
    else
    {
        L sq=sqrt(n);
        if(n%2==0) return 1;
        int sz=prime.size();
        for(I i=0; prime[i] <=sq && i<sz; i++)
            if(n%prime[i]==0)
                return 1;

        return 0;
    }
}

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    sieve();

    L i,j,k;
    L n,low,upp;
    while(scanf("%ld %ld",&low,&upp)==2)
    {
        L pre=0,mn=1000000,mx=0,low_a=0,low_b,upp_a,upp_b;
        if(low<=2)
        {
            pre=2;
            low=3;
        }
        else if(low%2==0) low++;
        for(i=low;i<=upp;i+=2)
        {
            if(!check(i))
            {
                if(!pre)
                    pre=i;
                else
                {
                    L dis=i-pre;
                    if(dis<mn)
                    {
                        low_a=pre;
                        low_b=i;
                        mn=dis;
                    }
                    if(dis>mx)
                    {
                        upp_a=pre;
                        upp_b=i;
                        mx=dis;
                    }
                    pre=i;
                }

            }
        }
        if(low_a==0)
            cout<<"There are no adjacent primes."<<endl;
        else
            printf("%ld,%ld are closest, %ld,%ld are most distant.\n",low_a,low_b,upp_a,upp_b);
    }
    return 0;
}
