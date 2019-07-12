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
#define MAX 100000001

using namespace std;

LL val[MAX];

void totient(LL n);

int main()
{
    int i,j,k;
    LL n;
    while(scanf("%lld",&n)==1 && n)
    {
        if(n==1)
            printf("0\n");
            else
        totient(n);
    }
    return 0;
}

void totient(LL n)
{
    // for(LL j=2; j<MAX; j++)
    LL m=n;
    {
        LL i=0,j=0,res=n;
        if(n%2==0)
        {
            res=res-res/2;
            while(n%2==0)
            {
                n=n/2;
            }
        }

        for(i=3; i*i<=n; i+=2)
        {
            if(n%i==0)
            {
                res=res-res/i;
                while(n%i==0)
                {
                    n=n/i;
                }
            }
        }
        if(n>1)
            res=res-res/n;
        printf("%lld\n",m-res);
        //val[j]=res;
    }
}
