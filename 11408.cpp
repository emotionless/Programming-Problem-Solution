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
#define MAX 5000005

using namespace std;

void sieve();

bool is[MAX];
int de[MAX],res[MAX];


int main()
{
    sieve();
    int n,m;
    while(scanf("%d",&m)==1 && m)
    {
        scanf("%d",&n);
        printf("%d\n",res[n]-res[m-1]);
    }
    return 0;
}

void sieve()
{
    int i,j,k;
    clr(is,true);
    is[0]=is[1]=false;
    for(i=4; i<MAX; i+=2)
        is[i]=false;

    int s=sqrt(MAX);
    for(i=3; i<=s; i+=2)
    {
        if(is[i])
        {
            for(j=i+i; j<MAX; j+=i)
                is[j]=false;
        }
    }
    for(i=2; i<MAX; i++)
        de[i]=0;

    for(i=2; i<MAX; i++)
    {
        if(is[i])
        {
            for(j=i; j<MAX; j+=i)
                de[j]+=i;
        }
    }
    k=0;
    for(i=2; i<MAX; i++)
    {
        if(is[de[i]])
        {
            res[i]=(++k);
        }
        else
            res[i]=k;
    }
}
