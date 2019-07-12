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

long sum[4*100001];
long add[4*100001];

void BUILD(int ind, int st, int ed)
{
    if(st==ed)
    {
        sum[ind]=0;
        return;
    }
    sum[ind]=0;
    int mid=(st+ed)/2;
    BUILD(ind*2,st,mid);
    BUILD(ind*2+1,mid+1,ed);
}

void UPDATE(int ind, int st, int ed, int ll, int ul, int val)
{
    if(st==ll && ed==ul)
    {
        add[ind]+=val;
        sum[ind]+=(val*(ul-ll+1));
        return;
    }
    sum[ind]+=((ul-ll+1)*val);
    int mid=(st+ed)/2;
    if(ul<=mid)
    {
        UPDATE(ind*2, st, mid,ll,ul,val);
    }
    else if(ll>mid)
    {
        UPDATE(ind*2+1, mid+1, ed, ll, ul, val);
    }
    else
    {
        UPDATE(ind*2,st, mid, ll,mid,val);
        UPDATE(ind*2+1,mid+1, ed, mid+1,ul,val);
    }
}

long QUERYY(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
    {
        return sum[ind];
    }

    long val=(add[ind]*(ul-ll+1));
    int mid=(st+ed)/2;
    if(ul<=mid)
    {
        return val+QUERYY(ind*2, st, mid, ll, ul);
    }
    else if(ll>mid)
    {
        return val+QUERYY(ind*2+1, mid+1, ed, ll, ul);
    }
    else
    {
        return val+QUERYY(ind*2, st, mid, ll, mid)+ QUERYY(ind*2+1, mid+1, ed, mid+1, ul);
    }
}


int main()
{
    int i,j,k;
    int n,q,op,ll,ul,val,t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        BUILD(1,1,n);
        printf("Case %d:\n",++cases);
        for(i=1; i<=q; i++)
        {
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%d %d %d",&ll,&ul,&val);
                UPDATE(1,1,n,ll+1,ul+1,val);
            }
            else
            {
                scanf("%d %d",&ll,&ul);
                printf("%ld\n",QUERYY(1,1,n,ll+1,ul+1));
            }
        }
        clr(add,0);
        clr(sum,0);
    }
    return 0;
}
