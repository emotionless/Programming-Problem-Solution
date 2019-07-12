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
#define MAX 1000005

using namespace std;
void sieve();

bool is[MAX];
int prime[MAX];
int factor[MAX];
int m[MAX],M[MAX];

int main()
{
    int i,j,k;
    int n;
    sieve();
    while(scanf("%d",&n)==1 && n)
    {
        if(n==1)
        {
            M[1]=1;
            m[1]=1;
            printf("%8d%8d%8d\n",n,m[n],M[n]);
        }
        else
            printf("%8d%8d%8d\n",n,m[n],M[n]);
    }
    return 0;
}

void sieve()
{
    clr(is,true);
    int i,j,k;
    for(i=4; i<MAX; i+=2)
        is[i]=false;
    int top=1;
    prime[0]=2;

    // take the prime

    for(i=3; i*i<MAX; i+=2)
    {
        if(is[i])
        {
            prime[top++]=i;
            for(j=i+i; j<MAX; j+=i)
                is[j]=false;
        }
    }

    // main is here

    for(i=2; i<MAX; i++)
    {
        if(is[i])
        {
            m[i]=-1;
            continue;
        }
        int t=i;
        int high=0;
        int mk=0;
        for(j=0; j<top && prime[j]<=t; j++)
        {
            while(t%prime[j]==0)
            {
                factor[high++]=prime[j];
                t=t/prime[j];
            }
        }
        if(t>1)
            factor[high++]=t;

        for(k=1; k<high; k++)
        {
            if(factor[k]==factor[k-1])
            {
                mk=1;
                break;
            }
        }
        if(mk) continue;
        if(high%2==0) m[i]=1;
        else if(high%2==1)
            m[i]=-1;
    }
    M[1]=1;
    for(i=2; i<1000001; i++)
    {
        M[i]=M[i-1]+m[i];
    }

}
