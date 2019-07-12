#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<stack>
#include<utility>
#include<iomanip>
#include<complex>
#include <bits/stdc++.h>

#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define PS(s) printf(s)

#define S2(a,b) scanf("%d%d",&a,&b)
#define S3(a,b,c) scanf("%d%d%d",&a,&b,&c)

#define SLL(a) scanf("%lld",&a)
#define PLL(a) printf("%lld",a)
#define SLL2(a,b) scanf("%lld%lld",&a,&b)
#define SLL3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)

#define PCASE() printf("Case %d: ",kk++)
#define PCASENL() printf("Case %d:\n",kk++)
#define NL PS("\n")

#define rep(i,a,b) for(int i=a;i<=b;i++)
//#define rev(i,a,b) for(int i=a;i>=b;i--)
#define SZ(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define REV(a) reverse(all(a))
#define countbit(x) __builtin_popcount(x)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define PI (2.0*acos(0.0))
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define in(a,x,y) (a>=x && a<=y)
#define eq(a,b) (fabs(a-b)<eps)
#define less(a,b) (a+eps<b)
#define great(a,b) (a>b+eps)
#define xx first
#define yy second
#define root 1


#define MAX(a) *max_element(all(a))
#define MIN(a) *min_element(all(a))

using namespace std;
int ts,kk=1;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;

template< class T > inline T _abs(T a)
{
    return (a<0?-a:a);
}
template< class T > inline T _sq(T a)
{
    return a * a;
}
template< class T > inline T _sqrt(T a)
{
    return (T) sqrt( (double) a);
}
template< class T, class X > inline T _pow(T a,X y)
{
    T z=1;
    rep(i,1,y)
    {
        z*=a;
    }
    return z;
}
template< class T > inline T _gcd(T a,T b)
{
    a=_abs(a);
    b=_abs(b);
    if(!b) return a;
    return _gcd(b,a%b);
}
template< class T > inline T _lcm(T a,T b)
{
    a=_abs(a);
    b=_abs(b);
    return (a/_gcd(a,b))*b;
}

template< class T > inline T _extended(T a,T b,T &x,T &y)
{
    a=_abs(a);
    b=_abs(b);
    T g,x1,y1;
    if(!b)
    {
        x=1;
        y=0;
        g=a;
        return g;
    }
    g=_extended(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}

template< class T, class X > inline bool getbit(T a, X i)
{
    T t=1;
    return ((a&(t<<i))>0);
}
template< class T, class X > inline T setbit(T a, X i)
{
    T t=1;
    return (a|(t<<i));
}
template< class T, class X > inline T resetbit(T a, X i)
{
    T t=1;
    return (a&(~(t<<i)));
}
template< class T, class X > inline T togglebit(T a, X i)
{
    T t=1;
    return (a^(t<<i));
}

///       //CONSTANT//        ///
///  power     0123456789     ///
#define MAX  (  1000000    + 3  )
#define MOD    1000000009
#define inf    2000000000

#define LOGMX  19
#define eps 1e-9
///===========================///

template< class T,class X > inline T _bigmod(T n,X m)
{
    ull ret=1, a = n%MOD ;
    while(m)
    {
        if(m&1)ret=(ret*a)%MOD;
        m>>=1;
        a=(a*a)%MOD;
    }
    ret%=MOD;
    return (T)ret;
}
template< class T > inline T _modinv(T n)
{
    return _bigmod(n,MOD-2);
}

///===============///
///End of template///
///===============///

typedef complex < double > base ;

void fft ( vector < base > & a, bool invert )
{
    int n = ( int ) a. size ( ) ;

    for ( int i = 1 , j = 0 ; i < n ; ++ i )
    {
        int bit = n >> 1 ;
        for ( ; j >= bit ; bit >>= 1 )
            j -= bit ;
        j += bit ;
        if ( i < j )
            swap ( a [ i ] , a [ j ] ) ;
    }

    for ( int len = 2 ; len <= n ; len <<= 1 )
    {
        double ang = 2 * PI / len * ( invert ? - 1 : 1 ) ;
        base wlen ( cos ( ang ) , sin ( ang ) ) ;
        for ( int i = 0 ; i < n ; i += len )
        {
            base w ( 1 ) ;
            for ( int j = 0 ; j < len / 2 ; ++ j )
            {
                base u = a [ i + j ] ,  v = a [ i + j + len / 2 ] * w ;
                a [ i + j ] = u + v ;
                a [ i + j + len / 2 ] = u - v ;
                w *= wlen ;
            }
        }
    }
    if ( invert )
        for ( int i = 0 ; i < n ; ++ i )
            a [ i ] /= n ;
}

int multiply ( const vector < int > & a, const vector < int > & b) {
	vector < base > fa ( a. begin ( ) , a. end ( ) ) ,  fb ( b. begin ( ) , b. end ( ) ) ;
	size_t n = 1 ;
	while ( n < max ( a. size ( ) , b. size ( ) ) )  n <<= 1 ;


	n <<= 1 ;


	fa. resize ( n ) ,  fb. resize ( n ) ;

	fft ( fa, false ) ,  fft ( fb, false ) ;
	for ( size_t i = 0 ; i < n ; ++ i )
		fa [ i ] *= fb [ i ] ;
	fft ( fa, true ) ;

    int ret=0;

	for ( size_t i = 0 ; i < n ; ++ i )
    {
        int x=(int) ( fa [ i ] . real ( ) + 0.5 );

        if(x>0) ret++;
    }

    return ret;
}

bool vis[20000010];
ll arr[1000001];
    map<ll, bool>M;
int main()
{
    int i, j, k;
    int n;
    scanf("%d", &n);
    if(n <= 2000)
    {
        ll a;
        arr[0] = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%lld", &a);
            arr[i] = a;
        }


        ll cnt = 0;
        for(i = 1; i <= n; i++)
        {
            ll s = 0ll;
            for(j = i; j <= n; j++)
            {
                s += arr[j];
                if(M.find(s) == M.end())
                {
                    M[s] = 1;
                    cnt++;
                }
            }
        }
        printf("%lld\n", cnt - 1ll);
        return 0;
    }
    arr[0] = 0;
    int tmp;
    int sum = 0ll;
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &tmp);
        arr[i] = tmp;
        sum += tmp;
    }


    if(n <= 20000)
    {
        int cnt = 0;
        for(i = 1; i <= n; i++)
        {
            int s = 0ll;
            for(j = i; j <= n; j++)
            {
                s += arr[j];
                if(!vis[s]) cnt++;
                vis[s] = 1;
            }
        }
        printf("%lld\n", cnt-1ll);
        return 0;
    }
    if(sum >= 700000)
        assert(0);
    vi a(2*sum + 1, 0), b(2*sum + 1, 0);
    a[sum] = b[sum] = 1;
    for(i = 1; i<= n; i++)
    {
        arr[i] += arr[i - 1];
        a[sum - arr[i]] = b[ sum + arr[i] ] = 1;
    }
    ll ans = multiply(a, b);
    printf("%lld\n", ans/2ll - 1ll);

    return 0;
}
