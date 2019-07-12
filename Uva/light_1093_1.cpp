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
#define loop(n) for(int o=1;o<=n;o++)

using namespace std;

long mn[4*100001];
long mx[4*100001];

void INSERT(int ind, int st, int ed, int poss, long val)
{
    if(st==poss && ed==poss)
    {
        mn[ind]=mx[ind]=val;
        return;
    }
    long mid=(st+ed)/2;
    if(poss<=mid)
        INSERT(ind*2, st, mid, poss, val);
    else
        INSERT(ind*2+1, mid+1, ed, poss, val);

    mn[ind]=min(mn[ind], min(mn[ind*2],mn[ind*2+1]));
    mx[ind]=max(mx[ind], max(mx[ind*2],mx[ind*2+1]));
}

long query_MAX(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
    {
        return mx[ind];
    }
    int mid=(st+ed)/2;
    if(ul<=mid)
    {
        return query_MAX(ind*2,st,mid,ll,ul);
    }
    else if(ll>mid)
    {
        return query_MAX(ind*2+1, mid+1, ed, ll, ul);
    }
    else
    {
        return max(query_MAX(ind*2, st, mid, ll, mid), query_MAX(ind*2+1, mid+1, ed, mid+1, ul));
    }
}

long query_MIN(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
    {
        return mn[ind];
    }
    int mid=(st+ed)/2;
    if(ul<=mid)
    {
        return query_MIN(ind*2,st,mid,ll,ul);
    }
    else if(ll>mid)
    {
        return query_MIN(ind*2+1, mid+1, ed, ll, ul);
    }
    else
    {
        return min(query_MIN(ind*2, st, mid, ll, mid), query_MIN(ind*2+1, mid+1, ed, mid+1, ul));
    }
}


int main()
{
    int i,j,k;
    int n,d,t,cases=0;
    long num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&d);
        for(i=0; i<4*100001; i++)
        {
            mx[i]=-1;
            mn[i]=INT_MAX;
        }
        for(i=1; i<=n; i++)
        {
            scanf("%ld",&num);
            INSERT(1,1,n,i,num);
        }
        long res=0;
        for(i=1; i<=(n-d+1); i++)
        {
            int ll=i;
            int ul=i+d-1;
            long a=query_MAX(1,1,n,ll,ul);
            long b=query_MIN(1,1,n,ll,ul);
            res=max(a-b,res);
        }
        printf("Case %d: %ld\n",++cases,res);
    }
return 0;
}
