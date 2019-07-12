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

int main()
{
    int i,j,k;
    int n,arr1[30],arr2[30];
    while(si(n)==1)
    {
        arr1[0]=arr2[0]=arr1[n+1]=arr2[n+1]=0;
        for(i=1; i<=n; i++)
        {
            si(arr1[i]);
        }
        for(i=1; i<=n; i++)
        {
            si(arr2[i]);
        }
        int poss=0,cnt=0;
        FOR(i,1,n)
        {
            for(j=i; j<=n; j++)
            {
                if(arr1[i]==arr2[j])
                {
                    poss=j;
                    break;
                }
            }
            for(k=poss; k>i; k--)
            {
                arr2[k]=arr2[k-1];
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
