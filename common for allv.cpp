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
#define MAX 5000001

using namespace std;
void sieve();
bool is[MAX];
int phi[MAX];
long ans[MAX];

int main()
{
    int a,i,b,t;
    sieve();
    ans[1]=0;
    for(i=2; i<MAX; i++)
    {
        ans[i]=ans[i-1]+(phi[i]*phi[i]);
    }
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %ld\n",i,ans[b]-ans[a-1]);
    }
    return 0;
}

void sieve()
{
    int i,j;
    int sq=sqrt(MAX);
    for(i=1; i<MAX; i++)
        phi[i]=i;
    for(i=2; i<MAX; i+=2)
        phi[i]=phi[i]/2;
    for(i=3; i<=sq; i+=2)
    {
        if(is[i]==false)
        {
            for(j=i; j<MAX; j+=i)
            {
                phi[j]*=(i-1);
                phi[j]=phi[j]/i;
                    is[j]=true;
            }
        }
    }
}
