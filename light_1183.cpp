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
long con[4*100001];



int GCD(long a, int b);

void PushDown(int ind, int st, int ed)
{
    if(con[ind]!=-1)
    {
        int m=(st+ed)/2;
        sum[ind*2]=(m-st+1)*con[ind];
        sum[ind*2+1]=(ed-m)*con[ind];
        con[ind*2]=con[ind*2+1]=con[ind];

        con[ind]=-1;
    }
}


void PushUp(int ind)
{
    sum[ind]=sum[ind*2]+sum[ind*2+1];
}

void UPDATE(int ind, int st, int ed, int ll, int ul, int val)
{
    if(st==ll && ul==ed)
    {
        con[ind]=val;
        sum[ind]=val*(ul-ll+1);
        return;
    }
    PushDown(ind,st,ed);
    int mid=(st+ed)/2;
    if(ul<=mid)
    {
        UPDATE(ind*2, st, mid, ll, ul, val);
    }
    else if(ll>mid)
    {
        UPDATE(ind*2+1, mid+1, ed, ll, ul, val);
    }
    else
    {
        UPDATE(ind*2, st, mid, ll, mid, val);
        UPDATE(ind*2+1, mid+1, ed, mid+1, ul, val);
    }
    PushUp(ind);
}


long QUERY(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
    {
        return sum[ind];
    }
    PushDown(ind, st,ed);
    int mid=(st+ed)/2;
    long ret=0;
    if(ul<=mid)
    {
        // cout<<"here\n";
        ret+=QUERY(ind*2, st, mid, ll, ul);
    }
    else if(ll>mid)
    {
        ret+=QUERY(ind*2+1, mid+1, ed, ll, ul);
    }
    else
    {
        ret+=(QUERY(ind*2, st, mid, ll, mid)+ QUERY(ind*2+1, mid+1, ed, mid+1, ul));
    }
    PushUp(ind);
    return ret;

}



int main()
{
    int i,j,k;
    int n,q,op,ll,ul,val,t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        clr(con,-1);
        clr(sum,0);
        printf("Case %d:\n",++cases);
        loop(q)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d %d %d",&ll,&ul,&val);
                UPDATE(1,1,n,ll+1,ul+1,val);
            }
            else
            {
                scanf("%d %d",&ll,&ul);
                long a=QUERY(1,1,n,ll+1,ul+1);
                int b=ul-ll+1;
                int gcd=GCD(a,b);
                if(gcd==b)
                    printf("%ld\n",a/gcd);
                else
                    printf("%ld/%d\n",a/gcd, b/gcd);
            }
        }
    }
    return 0;
}

int GCD(long a, int b)
{
    while(1)
    {
        a=a%b;
        if(a==0) return b;
        b=b%a;
        if(b==0) return a;
    }
}
