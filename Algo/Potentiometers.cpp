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

long sum[4*200001];


void INSERT(int ind, int st, int ed, int poss, int val)
{
    if(st==poss && ed==poss)
    {
        sum[ind]=val;
        return;
    }
    int mid=(st+ed)/2;
    if(poss<=mid)
    {
        INSERT(ind*2, st, mid, poss, val);
    }
    else
    {
        INSERT(ind*2+1, mid+1, ed, poss, val);
    }
    sum[ind]=sum[ind*2]+sum[ind*2+1];
}

long QUERY(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
    {
        return sum[ind];
    }
    int mid=(st+ed)/2;
    if(ul<=mid)
    {
        QUERY(ind*2, st, mid, ll,ul);
    }
    else if(ll>mid)
    {
        QUERY(ind*2+1,mid+1,ed,ll,ul);
    }
    else
    {
        return QUERY(ind*2,st, mid,ll,mid)+ QUERY(ind*2+1, mid+1, ed, mid+1, ul);
    }
}




int main()
{
    int i,j,k;
    int n,num,poss,ll,ul,cases=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%d",&num);
            INSERT(1,1,n,i,num);
        }
        string str;
        if(cases)
            printf("\n");
        printf("Case %d:\n",++cases);
        while(cin>>str)
        {
            if(str=="END") break;
            if(str=="S")
            {
                scanf("%d %d",&poss, &num);
                INSERT(1,1,n,poss,num);
            }
            else
            {
                scanf("%d %d",&ll,&ul);
                printf("%ld\n",QUERY(1,1,n,ll,ul));
            }
        }

        clr(sum,0);
    }
    return 0;
}
