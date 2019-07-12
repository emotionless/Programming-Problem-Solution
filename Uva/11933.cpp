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

int main()
{
    int i,j,k,t;
    long a,b,n;
    while(scanf("%ld",&n)==1 && n)
    {
        int c=1;
        int s=log2(n)+1;
        b=0;
        for(i=0; i<=s; i++)
        {
            if(n&(1<<i))
            {

                if(c%2)
                {
                    b|=(1<<i);
                }
                c++;
            }
        }
        printf("%ld %ld\n",b,n-b);
    }
    return 0;
}
