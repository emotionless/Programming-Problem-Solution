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
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}


using namespace std;

int cnt[6*100001];
int val[6*100001];


void INSERT(int ind, int st, int ed, int poss, int v)
{
    if(st==ed)
    {
        val[ind]=v;
        cnt[ind]=1;
        return;
    }
    int mid=(st+ed)/2;
    if(poss<=mid)
        INSERT(ind*2, st, mid, poss, v);
    else
        INSERT(ind*2+1, mid+1, ed, poss, v);
    cnt[ind]++;
}

void QUERY(int ind, int st, int ed, int poss)
{
    if(cnt[ind]<poss)
    {
        //  cout<<cnt[ind]<<endl;
        printf("none\n");
        return;
    }
    if(ed==st)
    {
        printf("%d\n",val[ind]);
        cnt[ind]=0;
        return;
    }
    int mid=(st+ed)/2;
    if(cnt[ind*2]>=poss)
        QUERY(ind*2, st, mid, poss);
    else
        QUERY(ind*2+1, mid+1, ed, poss-cnt[ind*2]);
    cnt[ind]--;

}



int main()
{
    int i,j,k;
    int n,q,a,t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&q);
        clr(val,0);
        clr(cnt,0);
        for(i=1; i<=n; i++)
        {
            scanf("%d",&a);
            INSERT(1,1,n+q,i,a);
        }
        int f=n;
        char op[3];
        printf("Case %d:\n",++cases);
        for(i=1; i<=q; i++)
        {
            scanf("%s %d",&op, &a);
            f++;
            if(op[0]=='a') INSERT(1,1,n+q, f,a);
            else
                QUERY(1,1,n+q,a);
        }
    }
    return 0;
}
