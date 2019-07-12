/****************************************************************************
 *                      ==>>JU_Bottom_Up                                    *
 *              emotionless, BG_Peacemind, sahedsohel                       *
 ****************************************************************************/
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

/// emotionless
#define pb push_back
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)

/// BG_PeaceMind
#define SZ(x) x.size()
#define pii pair<int,int>
#define pll pair<ul,ul>
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define rf(i,n,a) for(i=n;i>=a;i--)
#define MXE(x) *max_element(all(x))
#define MNE(x) *min_element(all(x))
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)

/// sahedsohel
#define fl(c,i,n) for(i=c;i<n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define mpr make_pair
#define xx first
#define yy second
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
#define to_c_string(a) a.c_str()
#define strtoint(c) atoi(&c[0])
#define dbg(x) cout<<#x<<" : "<<x<<endl

///*********Data types and MAX**********///
#define LL long long
#define ll long long int
#define ull unsigned long long int
#define inf INT_MAX
#define linf LLONG_MAX

///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

///***** Input / Output *****///
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define SL(a) scanf("%lld",&a)
#define sc1(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define nl puts("")
#define pcs(a) printf("Case %d: ",a)

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);   // M is prime
}
template <class T> inline T bpow(T p,T e)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p);
        p = (p * p);
    }
    return (T)ret;
}

int toInt(string s)
{
    int sm;
    stringstream ss(s);
    ss>>sm;
    return sm;
}
int toLlint(string s)
{
    long long int sm;
    stringstream ss(s);
    ss>>sm;
    return sm;
}

/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction
///const double eps= 1e-6;
///const double PI = 2.0*acos(0.0); // PI = acos(-1.0);

/************************************************************************/

/// dgt   01234567891011
#define MX 109
#define MD 1000000000000LL


int arr[MX];

int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    sc1(tc);
    while(tc--)
    {
        sc2(n, m);
        fr(i, n)
        sc1(arr[i]);
        int sum = 0;
        arr[n] = m;
        fr(i, n)
        {
            if(i % 2 == 0)
                sum = sum ^ (arr[i + 1] - arr[i]);
        }
        pcs(cs++);
        if(sum)
            printf("First Player\n");
        else
            printf("Second Player\n");

    }
    return 0;
}
