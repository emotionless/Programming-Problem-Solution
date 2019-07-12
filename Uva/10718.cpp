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

using namespace std;


int main()
{
    long n,tmp,l,u;
    while(scanf("%ld %ld %ld",&n,&l,&u)==3)
    {
        int i,b=log2(n)+1;
        LL ans=0,r;
        for(i=31; i>=0; i--)
        {
            if(n&(1LL<<i))
            {
                r= ans|(1LL<<i);
                if(r<=l)
                    ans|=(1LL<<i);
            }
            else
            {
                r=ans|(1LL<<i);
                if(r<=u)
                    ans|=(1LL<<i);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
