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

int m;

bool cmp(LL a, LL b)
{
    if(a%m != b%m)
        return a%m<b%m;
    LL A=abs(a);
    LL B=abs(b);
    if(A%2==1 && B%2==1) return a>b;
    if(A%2==0 && B%2==0) return a<b;
    if(A%2==0 && B%2==1) return false;
    if(A%2==1 && B%2==0) return true;
    return false;
}


int main()
{
    int i,j,k;
    int n;
    LL list[10010];
    while(scanf("%d %d",&n,&m)==2 && (n || m))
    {

        for(i=0; i<n; i++)
        {
            scanf("%lld",&list[i]);
        }
        sort(list,list+n,cmp);
        printf("%d %d\n",n,m);
        for(i=0; i<n; i++)
        {
            printf("%lld\n",list[i]);
        }
    }
    printf("%d %d\n",n,m);
    return 0;
}
