#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <locale>
#include <vector>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <sstream>
#include <utility>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <algorithm>
#include <functional>

#define xx first
#define yy second
#define LL long long
#define inf 100000000
#define pb push_back
#define all(v) v.begin(),v.end()
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define pii pair<int,int>
#define MOD 1000000007
#define EPS 1e-16
#define MP make_pair
#define MX 100000

using namespace std;

struct segmentTree
{
    LL tot,sum,lazy;

    segmentTree()
    {
        tot=sum=lazy=0;
    }
};

segmentTree seg[8*MX+10];
LL ar[MX+10];

void build(int indx,int st,int ed)
{
    if(st==ed)
    {
        seg[indx].tot=(LL)st*100ll;
        seg[indx].sum=100ll;
        seg[indx].lazy=0ll;
        return;
    }
    int mid=(st+ed)/2,L=indx*2,R=L+1;
    build(L,st,mid);
    build(R,mid+1,ed);
    seg[indx].tot=seg[L].tot+seg[R].tot;
    seg[indx].sum=seg[L].sum+seg[R].sum;
}
void lazy(int indx,int L,int R,int st,int mid,int ed)
{

    seg[L].lazy+=seg[indx].lazy;
    seg[R].lazy+=seg[indx].lazy;

    seg[L].sum+=(seg[indx].lazy*(LL)(mid-st+1));
    seg[R].sum+=(seg[indx].lazy*(LL)(ed-mid));
    seg[L].tot+=(seg[indx].lazy*(ar[mid]-ar[st-1]));
    seg[R].tot+=(seg[indx].lazy*(ar[ed]-ar[mid]));
    seg[indx].lazy=0;

}
void update(int indx,int st,int ed,int s,int e,LL v)
{

    if(s==st && e==ed)
    {
        seg[indx].tot+=(v*(ar[ed]-ar[st-1]));
        seg[indx].sum+=(v*(LL)(ed-st+1));
        seg[indx].lazy+=v;
        return;
    }

    int mid=(st+ed)/2,L=indx*2,R=L+1;

    if(seg[indx].lazy!=0) lazy(indx,L,R,st,mid,ed);

    if(e<=mid) update(L,st,mid,s,e,v);
    else if(s>mid) update(R,mid+1,ed,s,e,v);
    else
    {
        update(L,st,mid,s,mid,v);
        update(R,mid+1,ed,mid+1,e,v);
    }
    seg[indx].tot=seg[L].tot+seg[R].tot;
    seg[indx].sum=seg[L].sum+seg[R].sum;

}

pair<LL,LL>query(int indx,int st,int ed,int s,int e)
{
    int mid=(st+ed)/2,L=indx*2,R=L+1;

    if(seg[indx].lazy!=0) lazy(indx,L,R,st,mid,ed);

    if(s==st && e==ed) return MP(seg[indx].tot,seg[indx].sum);
    pair<LL,LL>ret=MP(0,0);

    if(e<=mid) ret=query(L,st,mid,s,e);
    else if(s>mid) ret=query(R,mid+1,ed,s,e);
    else
    {
        pair<LL,LL>X=query(L,st,mid,s,mid);
        pair<LL,LL>Y=query(R,mid+1,ed,mid+1,e);
        ret=MP(X.xx+Y.xx,X.yy+Y.yy);
    }
    return ret;
}

int main()
{
    ar[1]=1ll;
    for(int i=2; i<=100000; i++) ar[i]=ar[i-1]+i;
    int test;
    scanf("%d",&test);
    for(int kase=1; kase<=test; kase++)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        build(1,1,n);
        printf("Case %d:\n",kase);
        char s[11];
        for(int i=0; i<q; i++)
        {
            scanf("%s",s);
            if(s[0]=='q')
            {
                int l,r;
                scanf("%d%d",&l,&r);
                if(l>r) swap(l,r);
                pair<LL,LL>get=query(1,1,n,l,r);
                LL res=get.xx-get.yy*(LL)(l-1);
                printf("%lld\n",res);
            }
            else
            {
                int l,r,v;
                scanf("%d%d%d",&l,&r,&v);
                if(l>r) swap(l,r);
                update(1,1,n,l,r,v);
            }
        }
        memset(seg,0,sizeof seg);
    }
    return 0;
}
