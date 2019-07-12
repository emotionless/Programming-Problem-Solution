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
int histogram(int n);

int num[30001];

int main()
{
    int i,j,k;
    int n,t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d",&num[i]);
        printf("Case %d: %d\n",++cases,histogram(n));
    }
    return 0;
}



int histogram(int len)
{
    int i,j,k;
    stack<int>ST;

    int area[ 30001]= {0},t;
    for(i=0; i<len; i++)
    {
        while(!ST.empty())
        {
            if(num[i]<=num[ST.top()])
                ST.pop();
            else
                break;
        }
        if(ST.empty())
            t=-1;
        else
            t=ST.top();
        area[i]=i-t-1;
        ST.push(i);
    }

    while(!ST.empty())
        ST.pop();

    // do the right here

    for(i=len-1; i>=0; i--)
    {
        while(!ST.empty())
        {
            if(num[i]<=num[ST.top()])
                ST.pop();
            else
                break;
        }
        if(ST.empty())
            t=len;
        else
            t=ST.top();
        area[i]+=(t-i-1);
        ST.push(i);
    }
    int mx=0;
    for(i=0; i<len; i++)
    {
        area[i]=num[i]*(area[i]+1);
        mx=max(mx,area[i]);
    }
    return mx;
}
