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


void print(LL n);

int main()
{
    int i,j,k;
    LL n;
    int t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        cases++;
        scanf("%lld",&n);
        printf("Case %d: ",cases);
        if(n==1)
            printf("0\n");
        else
            print(n);
    }
    return 0;
}

void print(LL n)
{
    long long num=n*(n-1);
    int d=4;
    while(num%2==0 && d!=1)
    {
        num=num/2;
        d=d/2;
    }
    if(d==1)
        printf("%lld\n",num);
    else
        printf("%lld/%d\n",num,d);
}
