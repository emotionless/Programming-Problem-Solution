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
#define MAX 1000001
using namespace std;

bool is_prime[MAX];

void sieve()
{
    clr(is_prime,true);
    int l=sqrt(MAX);
    for(int i=4; i<MAX; i+=2)
        is_prime[i]=false;
        is_prime[0]=is_prime[1]=false;
    for(int i=3; i<=l; i++)
    {
        if(is_prime[i])
        {
            for(long j=i*i; j<MAX; j+=i)
                is_prime[j]=false;
        }
    }
}

int val[MAX];
int occure[400];
int main()
{
    int i,j,k;
    int n;
    k=0;
    sieve();
    long l,u;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld %ld",&l,&u);
        if(l>u)
        swap(l,u);
        int pre=l;
        bool p=false;
        int mx=0,f=0,d,res;
        for(i=0; i<300; i++)
            occure[i]=0;
        bool first=false;
        for(i=l; i<=u; i++)
        {
            if(is_prime[i])
            {
                if(first)
                {
                    d=i-pre;
                    occure[d]++;
                    if(occure[d]==mx)
                    {
                        p=false;

                    }
                    else if(occure[d]>mx)
                    {
                        p=true;
                        res=d;
                        mx=occure[d];
                    }
                    pre=i;
                }
                else
                {
                    first=true;
                    pre=i;
                }
                f++;
            }
        }
        if(f<2)
            printf("No jumping champion\n");
        else if(p)
            printf("The jumping champion is %d\n",res);
        else
            printf("No jumping champion\n");
    }
    return 0;
}
