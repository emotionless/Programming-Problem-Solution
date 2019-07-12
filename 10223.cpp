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

LL fact[40];
int main()
{
    int i,j,k;
    LL n;
    fact[0] = 1;
    for(i = 0; i < 21; i++){
        fact[i + 1] = (fact[i] * ((2 * (2 * i +  1))) / (i + 2));
    }

    while(scanf("%lld",&n)==1)
    {
        for(i=1; i<21; i++)
        {
            if(fact[i] == n)
            {
                printf("%d\n",i);
                break;
            }
        }
    }

    return 0;
}

