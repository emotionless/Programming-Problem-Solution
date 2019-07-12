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

using namespace std;
void init();
int Query(int P, int a, int b, int l, int r);
struct point
{
    int start,end,num,cnt;
} p[100010];

int a[100010];
int n,T;
int rash[100010];
struct segment
{
    int num,Cnt;
} tree[1000010];


void build(int P, int l, int r)
{
    int mid=(l+r)/2;
    if(l==r)
    {
        tree[P].Cnt=p[l].cnt;
        tree[P].num=p[l].num;
        return;
    }
    build(P*2,l,mid);
    build(P*2+1,mid+1,r);
    if(tree[P*2].Cnt>tree[P*2+1].Cnt)
    {
        tree[P]=tree[P*2];
    }
    else
        tree[P]=tree[P*2+1];
}

int Solve(int x, int y)
{

    if(rash[x] == rash[y])
    {
        return y - x + 1;
    }
    else if(rash[x] + 1 == rash[y])
    {
        int l = p[ rash[x] ].end - x + 1;
        int r = y - p[ rash[y] ].start + 1;
        return l > r ? l : r;
    }
    else
    {

        int l = p[ rash[x] ].end - x + 1;
        int r = y - p[ rash[y] ].start + 1;
        int Max = l > r ? l : r;

        int ans = Query(1, rash[x] + 1, rash[y] - 1, 1, T);
        return Max > ans ? Max : ans;
    }

}

int Query(int P, int a, int b, int l, int r)
{

    if(a == l && r == b)
    {
        return tree[P].Cnt;
    }

    int mid = (l + r) / 2;
    if(b <= mid)
    {
        return Query(2*P, a, b, l, mid);
    }
    else if(mid + 1 <= a)
    {
        return Query(2*P+1, a, b, mid+1, r);
    }
    else
    {
        int x = Query(2*P, a, mid, l, mid);
        int y = Query(2*P+1, mid+1, b, mid+1, r);
        return x > y ? x : y;
    }

}
int main()
{
    int i,j,k;
    int q;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&q);
        for(i=0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        init();
        build(1,1,T);
        int x,y;
        while(q--)
        {
            scanf("%d %d",&x,&y);
            x--;
            y--;
            int res=Solve(x,y);
            printf("%d\n",res);
        }
    }
    return 0;
}

void init()
{
    T=1;
    p[1].start=0;
    p[1].end=0;
    p[1].cnt=1;
    p[1].num=a[0];
    rash[0]=1;
    int i;
    for(i=1; i<n; i++)
    {
        if(a[i]==a[i-1])
        {
            p[T].cnt++;
            p[T].end=i;
        }
        else
        {
            T++;
            p[T].start=i;
            p[T].end=i;
            p[T].cnt=1;
            p[T].num=a[i];
        }
        rash[i]=T;
    }
}
