//#include<bits/stdc++.h>
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

#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))
#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define pb push_back

#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)|(b))
#define XOR(a,b) ((a) ^ (b))
#define xx first
#define yy second
#define mp make_pair
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))

#define LB(a,x) (lower_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which does not compare less than val.
#define UB(a,x) (upper_bound(all(a),x)-a.begin()) //  first element in the range [first,last) which compares greater than val.
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define left nokol_left
#define right nokol_right
#define countbit(x) __builtin_popcountll((ll)x)
#define PQ priority_queue
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<class T>T __sqr(const T x)
{
    return x*x;
}
template< class T, class X > inline T __pow(T a,X y)
{
    T z=1;
    rep(i,1,y)
    {
        z*=a;
    }
    return z;
}
template< class T > inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);
    if(!b) return a;
    return __gcd(b,a%b);
}
template< class T > inline T lcm(T a,T b)
{
    a=abs(a);
    b=abs(b);
    return (a/__gcd(a,b))*b;
}
inline bool ispow2(int x)
{
    return (x!=0 && (x&(x-1))==0);
}
template<class T>void UpdateMin(T &x,T y)
{
    if(y<x)
    {
        x=y;
    }
}
template<class T>void UpdateMax(T &x,T y)
{
    if(x<y)
    {
        x=y;
    }
}
template<class T,class X, class Y > inline T bigmod(T n,X m,Y mod)
{
    ull ret=1, a = n%mod ;
    while(m)
    {
        if(m&1)ret=(ret*a)%mod;
        m>>=1;
        a=(a*a)%mod;
    }
    ret%=mod;
    return (T)ret;
}
template<class T, class Y > inline T modinv(T n,Y mod)
{
    return bigmod(n,mod-2,mod);
}

template<class T,class X> int gtbit(T s,X i)
{
    return (s >> i) & 1;
}
template<class T,class X> T onbit(T s, X i)
{
    return s | (T(1) << i);
}
template<class T,class X> T offbit(T s, X i)
{
    return s & (~(T(1) << i));
}
template<class T> inline void read(T &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}

void extended_euclid(ll a,ll b,ll &x,ll &y)
{
    if(!b)
    {
        x = 1 , y = 0  ;
        return ;
    }
    ll xx,yy;
    extended_euclid(b,a%b,xx,yy);
    x = yy;
    y = xx - (a/b)*yy;
}
pair<ll, pair<ll, ll> > extendedEuclid(ll a, ll b)
{
    ll x = 1, y = 0;
    ll xLast = 0, yLast = 1;
    ll q, r, m, n;
    while(a != 0)
    {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

const ll mod[]  = {1000000007,1000000009,1000000021,1000000033,1000000097,1000000093,1000000097,1000000103};
const ll base[] = {1000003,1000033,1000037,1000039,1000081,1000099,1000117,1000121};

#define pi acos(-1.0)
#define eps  1e-12
#define MX   (lmt + 20 )
#define inf  1000000000
#define MOD  1000000007LL
//---------->0123456789123465789
#define lmt  1000009

struct DT
{

    int x ,pnt , tp , id;

    DT() {}
    DT(int x,int pnt,int tp,int id): x(x) , pnt(pnt) , tp(tp) , id(id) {}

    bool operator<(const DT &b) const
    {
        if(x==b.x)
        {
            if(pnt==b.pnt)
            {
                return tp < b.tp;
            }
            return pnt < b.pnt;
        }
        return x < b.x;
    }

} d1[MX] ,d2[MX];

stack<int>st1,st2;
int bad[25005];

int main()
{
    int n , x1 , x2 , y1 , y2;
    scanf("%d",&n);
    {
        memset(bad, false, sizeof bad);
        int c1 = 0 , c2 = 0;
        rep(i,1,n)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            d1[c1]   = DT(x1,y1,-1,i);
            d1[c1+1] = DT(x1,y2,+1,i);
            c1 += 2;

            if(x1!=x2)
            {
                d1[c1] = DT(x2,y1,-1,i);
                d1[c1+1] = DT(x2,y2,+1,i);
                c1 += 2;
            }

            d2[c2]   = DT(y1,x1,-1,i);
            d2[c2+1] = DT(y1,x2,+1,i);
            c2 += 2;

            if(y1!=y2)
            {
                d2[c2] = DT(y2,x1,-1,i);
                d2[c2+1] = DT(y2,x2,+1,i);
                c2 += 2;
            }

        }

        sort(d1,d1 + c1);
        sort(d2,d2 + c2);

        rep(i,0,c1-1)
        {

            if(i&&d1[i].x!=d1[i-1].x)
            {
                while(!st1.empty()) st1.pop();
            }

            if(d1[i].tp==-1)
            {
                st1.push(d1[i].id);
            }
            else
            {
                if(st1.size()==1) st1.pop();
                else
                {
                    while(!st1.empty())
                    {
                        bad[ st1.top() ] = 1;
                        st1.pop();
                    }
                }
            }
        }

        rep(i,0,c2-1)
        {

            if(i&&d2[i].x!=d2[i-1].x)
            {
                while(!st2.empty()) st2.pop();
            }

            if(d2[i].tp==-1)
            {
                st2.push(d2[i].id);
            }
            else
            {
                if(st2.size()==1) st2.pop();
                else
                {
                    while(!st2.empty())
                    {
                        bad[ st2.top() ] = 1;
                        st2.pop();
                    }
                }
            }
        }

        int tot = 0;
        rep(i,1,n)
        {
            if(!bad[i]) tot++;
        }

        printf("%d\n",tot);
    }
    return 0;

}
