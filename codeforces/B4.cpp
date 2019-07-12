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

long long n,i;

long long  take,cnt=0;

int main()
{
    int r,c,d;
    int mat[10001];
    cin>>r>>c>>d;
    int mn=10001,mx=-1;
    long tot=r*c;
    for(i=0; i<tot; i++)
    {
        scanf("%d",&mat[i]);
        mn=min(mn,mat[i]);
        mx=max(mx,mat[i]);
    }
    if(mn==mx)
    {
        cout<<0<<endl;
    }
    else
    {
        int res=INT_MAX;
        for(i=mn; i<=mx+mx; i+=d)
        {
            int take=0;
            for(int j=0; j<tot; j++)
            {
                int tmp=abs(i-mat[j]);
                if(tmp%d)
                    break;
                take+=(tmp/d);
            }

            res=min(res,take);
        }
        if(res)
            cout<<res<<endl;
        else
            cout<<-1<<endl;
    }


    return 0;
}

/*

2 2 2
2 4
6 8

*/
