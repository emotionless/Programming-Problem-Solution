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
    int n,cases=0,t;
    char str[10];
    si(t);
    while(t--)
    {
        scanf("%s",str);
        int l=strlen(str);
        int a=0,b=0;
        char first[10];

        sscanf(str,"%d%s",&a,first);

        bool fnd=true;

        for(int i=0; i<l; i++)
        {
            if(isdigit(str[i]) && fnd) continue;
            fnd=false;

            if(isdigit(str[i]))
            {
                b=str[i]-'0';
                fnd=true;
                break;
            }
        }

        int  res=a*50;
        res+=(b*5);
        // cout<<"\ntortal res : "<<res<<endl;

        printf("Case %d: ",++cases);

        cout<<res/100;

        res=res%100;



        if(res)
        {
            if ( res % 10 == 0 ) printf (".%d", res / 10);
            else printf (".%d", res);
        }
        cout<<endl;
    }
    return 0;
}
