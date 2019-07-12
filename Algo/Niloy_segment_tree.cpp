#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<climits>
#include<cfloat>
#include<ctime>
#include<cassert>
#include<map>
#include<utility>
#include<set>
#include<iostream>
#include<memory>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<sstream>
#include<complex>
#include<stack>
#include<queue>
#include<numeric>
#include<list>
#include<iomanip>
#include<fstream>

#define MX 1000
#define inf 1E20
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define loop(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
#define rloop(i,n) for(i=n-1;i>=0;i--)
#define rloop1(i,n) for(i=n;i>=1;i--)
#define vloop(i,k,n) for(i=k;i<=n;i++)
#define rvloop(i,k,n) for(i=n;i>=k;i--)
#define si(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define sd(n) scanf("%lf",&n);
#define wi(n) while(scanf("%d",&n))
#define wd(n) while(scanf("%lf",&n))
#define wib(n) while(scanf("%d",&n) && n)
#define wdb(n) while(scanf("%lf",&n) && n)
#define ws(n) while(getline(cin,n))
#define s(k) k.size()

using namespace std;

long seg[100009];
long mx[100009];
void insert(long indx,long st,long ed,long pos,long val)
{
    if(st==ed)
    {
        seg[indx]=val;
        mx[indx]=val;
        return;
    }
    long mid=(st+ed)/2;
    if(pos<=mid) insert(indx*2,st,mid,pos,val);
    else insert(indx*2+1,mid+1,ed,pos,val);
    seg[indx]=min(seg[indx],min(seg[indx*2],seg[indx*2+1]));
    mx[indx]=max(seg[indx],max(seg[indx*2],seg[indx*2+1]));
}
long query1(long indx,long st,long ed,long ll,long ul)
{
    if(st==ll && ed==ul) return seg[indx];
    long mid=(st+ed)/2;
    if(ul<=mid) return query1(indx*2,st,mid,ll,ul);
    else if(ll>mid) return query1(indx*2+1,mid+1,ed,ll,ul);
    else return min(query1(indx*2,st,mid,ll,mid),query1(indx*2+1,mid+1,ed,mid+1,ul));
}

long query2(long indx,long st,long ed,long ll,long ul)
{
    if(st==ll && ed==ul) return mx[indx];
    long mid=(st+ed)/2;
    if(ul<=mid) return query2(indx*2,st,mid,ll,ul);
    else if(ll>mid) return query2(indx*2+1,mid+1,ed,ll,ul);
    else return max(query2(indx*2,st,mid,ll,mid),query2(indx*2+1,mid+1,ed,mid+1,ul));
}

int main()
{
    long num,i,j,ll,ul,q;
    int kase,test;
    scanf("%d",&test);
    for(kase=1;kase<=test;kase++)
    {

        for(i=1; i<100009; i++)
        {
            seg[i]=100009;
            mx[i]=-1;
        }
        scanf("%ld %ld",&num,&q);
        for(i=1;i<=num;i++)
        {
            scanf("%ld",&j);
            insert(1,1,num,i,j);
        }
        printf("Case %d: ",kase);
        long res=0;
        for(i=1;i<=(num-q+1);i++)
        {
            ll=i;
            ul=i+q-1;
            long a=query1(1,1,num,ll,ul);
            long b=query2(1,1,num,ll,ul);
            res=max(res,abs(b-a));
        }
        printf("%ld\n",res);
    }
    return 0;
}
