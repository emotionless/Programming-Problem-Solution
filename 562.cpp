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
long func(long ind, long val);

long arr[101];
long mem[101][25005];
long n;

int main()
{
    long t;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld",&n);
        long sum=0;
        for(long i=0; i<n; i++)
        {
            scanf("%ld",&arr[i]);
            sum+=arr[i];
        }
        long l=sum/2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=l;j++)
            mem[i][j]=-1;
        }
        long res=func(0,l);
        printf("%ld\n",sum-2*res);
    }
return 0;
}

long func(long ind, long val)
{
    if(ind>=n) return 0;
    if(mem[ind][val]!=-1) return mem[ind][val];
    long ret=0;
    if(arr[ind]<=val)
        ret=max(func(ind+1, val-arr[ind])+arr[ind] , func(ind+1,val));
    else
        ret=func(ind+1,val);
    return ret;
}
