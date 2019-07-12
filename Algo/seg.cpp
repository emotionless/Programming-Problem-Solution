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

void INSERT(int ind, int st, int ed, int poss, long val, int op)
{
    if(st==poss && ed==poss)
    {
        if(op==1)
        {
            printf("%ld\n",sum[ind]);
            sum[ind]=0;
        }
        else if(op==2)
        {
            sum[ind]+=val;
        }
        else
        {
            sum[ind]=val;
        }
        return;
    }
    long mid=(st+ed)/2;
    if(poss<=mid) INSERT(ind*2, st, mid, poss, val,op);
    else INSERT(ind*2+1, mid+1, ed, poss, val,op);
    sum[ind]=sum[ind*2]+sum[ind*2+1];
}

long query_MAX(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
        return sum[ind];
    int mid=(st+ed)/2;
    if(ul<=mid)
        return query_MAX(ind*2,st,mid,ll,ul);
    else if(ll>mid)
        return query_MAX(ind*2+1, mid+1, ed, ll, ul);
    else
        return query_MAX(ind*2, st, mid, ll, mid) + query_MAX(ind*2+1, mid+1, ed, mid+1, ul);
}
int main()
{
    int i,j,k,n,q,t,cases=0,num,ll,ul;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        for(i=0; i<4*100001; i++)
            sum[i]=-1;
        for(i=1; i<=n; i++)
        {
            scanf("%ld",&num);
            INSERT(1,1,n,i,num,3);
        }
        printf("Case %d:\n",++cases);
        for(i=1; i<=q; i++)
        {
            int poss,op;
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d",&poss);
                INSERT(1,1,n,poss+1,0,1);
            }
            else if(op==2)
            {
                scanf("%d %ld",&poss,&num);
                INSERT(1,1,n,poss+1,num,2);
            }
            else
            {
                scanf("%d %d",&ll,&ul);
                printf("%ld\n",query_MAX(1,1,n,ll+1,ul+1));
            }
        }
    }
    return 0;
}
