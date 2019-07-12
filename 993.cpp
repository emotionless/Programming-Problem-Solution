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
    int i,j,k;
    long n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        if(n<10)
        {
            if(n==0)
                printf("10\n");
            else
                printf("%ld\n",n);
            continue;
        }
        int d=9;
        i=0;
        int ans[100];
        while(d>1)
        {
            while(n%d==0)
            {
                n=n/d;
                ans[i++]=d;
            }
            d--;
        }
        sort(ans,ans+i);
        if(n==0)
            printf("10");
        if(n==1)
        {
            for(j=0; j<i; j++)
            {
                printf("%d",ans[j]);
            }
        }
        else
            printf("-1");
        printf("\n");
    }

    return 0;
}

