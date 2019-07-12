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

char str[100001];
long sum[4*100001];

void INSERT(int ind, int st, int ed)
{
    if(st==ed)
    {
        sum[ind]=str[st-1]-'0';
        return;
    }
    sum[ind]=0;
    int mid=(st+ed)/2;
    INSERT(ind*2,st,mid);
    INSERT(ind*2+1,mid+1,ed);
}

void UPDATE(int ind, int st, int ed, int ll, int ul)
{
    if(ll==st && ul==ed)
    {
        sum[ind]++;
        return;
    }
    int mid=(st+ed)/2;
    if(ul<=mid)
    {
        UPDATE(ind*2, st, mid, ll, ul);
    }
    else if(ll>mid)
    {
        UPDATE(ind*2+1,mid+1, ed, ll, ul);
    }
    else
    {
        UPDATE(ind*2, st, mid, ll, mid);
        UPDATE(ind*2+1, mid+1, ed, mid+1, ul);
    }
}

void QUERY(int ind, int v, int poss,int st, int ed)
{
    v+=sum[ind];
    if(st==poss && ed==poss)
    {
        printf("%d\n",v%2);
        return;
    }
    int mid=(st+ed)/2;
    if(poss<=mid)
    {
        QUERY(ind*2, v, poss, st, mid);
    }
    else
    {
        QUERY(ind*2+1,v,poss,mid+1, ed);
    }
}



int main()
{
    int i,j,k;
    int n,q,ll,ul;
    char op[2];
    int t,cases=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int len=strlen(str);
        INSERT(1,1,len);
       // clr(sum,0);
        scanf("%d",&q);
        printf("Case %d:\n",++cases);
        for(i=1; i<=q; i++)
        {
            scanf("%s",op);
            if(op[0]=='I')
            {
                scanf("%d %d",&ll,&ul);
                UPDATE(1,1,len,ll,ul);
            }
            else
            {
                int pos;
                scanf("%d",&pos);
                QUERY(1,0,pos,1,len);
            }
        }
        //clr(sum,0);
    }
    return 0;
}
