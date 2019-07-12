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
#define MAX 47000

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

I prime[MAX],N;


bool con[1000001];

bool check(I n)
{
    if(n<MAX)
        return !is_prime[n];
    for(I i=0; prime[i] <= n && i<N; i++)
        if(!(n%prime[i]))
            return 0;
    return 1;
}

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");


    I i,j;

    is_prime[1]=1;

    for(i=2; i<MAX; i++)
    {
        if(!is_prime[i])
        {
            prime[N++]=i;
            for(j=i+i; j<MAX; j+=(i))
                is_prime[j]=1;
        }
    }
    // L i,j,k;
    I n,low,upp;

    while(scanf("%d %d",&low,&upp)==2)
    {
        for(i=low; i<=upp; i++)
        {
            con[i-low]=1;
            if(!check(i))
                con[i-low]=0;
        }
        I la,lb,ha,hb,mx=0,mn=2e9,a=-1,b=-1;
        for(i=0; i<=upp-low; i++)
        {
            if(con[i])
            {
                a=i;
                if(b!=-1)
                {
                    if(a-b<mn)
                    {
                        mn=a-b;
                        la=b;
                        lb=a;
                    }
                    if(a-b>mx)
                    {
                        mx=a-b;
                        ha=b;
                        hb=a;
                    }
                }
                b=a;
            }
        }
        if(!mx)
            puts("There are no adjacent primes.");
        else
            printf("%ld,%ld are closest, %ld,%ld are most distant.\n",la+low,lb+low,ha+low,hb+low);
    }
    return 0;
}
