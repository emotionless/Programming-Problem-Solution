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

int GCD(int a, int b)
{
    while(1)
    {
        a=a%b;
        if(a==0)return b;
        b=b%a;
        if(b==0) return a;
    }
}

int main()
{
    int i,j,k;
    int n;
    int a[55];
    while(scanf("%d",&n)==1 && n)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        int sum=0,f;
        for(i=0; i<n-1; i++)
        {
            for(j=i+1; j<n; j++)
            {
                f=GCD(a[i],a[j]);
                if(f==1)
                {
                    sum++;
                }
            }
        }
        int c=(n*(n-1))/2;
        double res=sqrt((c*6)/(sum*1.0));
        if(sum==0)
            printf("No estimate for this data set.\n");
        else
            printf("%.6lf\n",res);
    }
    return 0;
}

