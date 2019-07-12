/****************************************************************************
 *                                                                          *
 *                      ==>>JU_Bottom_Up                                    *
 ****************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ul,ul>
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define MXE(x) *max_element(all(x))
#define MNE(x) *min_element(all(x))
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)

/***************************************************************************/
#define ll long long int
#define ull unsigned long long int
#define inf INT_MAX
#define linf LLONG_MAX
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define fl(c,i,n) for(i=c;i<n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define pp pop_back()
#define aov(a) a.begin(),a.end()
#define mpr make_pair
#define PI acos(-1.0)
#define xx first
#define yy second
#define mxv(a) *max_element(aov(a))
#define mnv(a) *min_element(aov(a))
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
#define to_c_string(a) a.c_str()
#define strtoint(c) atoi(&c[0])
#define pii pair<int,int>
#define pcs(a) printf("Case %d: ",a)
#define dbg(x) cout<<#x<<" : "<<x<<endl

template <class T> inline T bigmod(T p, T e, T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a, T b)
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
template <class T> inline T modinverse(T a, T M)
{
    return bigmod(a, M - 2, M);   // M is prime
}
template <class T> inline T bpow(T p, T e)
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
    ss >> sm;
    return sm;
}
int toLlint(string s)
{
    long long int sm;
    stringstream ss(s);
    ss >> sm;
    return sm;
}

/********************************************************************************/

/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/********************************************************************************/
/* ////////////////////////////////////////////////////////////////////////////*/
/*********************************************************************************/
/// dgt        01234567891011
#define MX 105
#define eps 1e-12
#define MD 1000000000007LL

double p[2505][52][52];
bool bl[2505][52][52];
int n,m;

double dp(int i,int j,int k)
{
    if(j==n && k==m) return 0.0;
    if(i==n*m) return 0.0;
    double &pr=p[i][j][k];
    if(bl[i][j][k]==true) return pr;
    bl[i][j][k]=true;
    pr=0.0;
    int nw=0;
    if((i+1)<=((j+1)*(k+1)) && j<n && k<m)
    {
        pr+=dp(i+1,j+1,k+1)+1.0;
        nw++;
    }
    if((i+1)<=((j+1)*k) && j<n )
    {
        pr+=dp(i+1,j+1,k)+1.0;
        nw++;
    }
    if((i+1)<=(j*(k+1))&&k<m)
    {
        pr+=dp(i+1,j,k+1)+1.0;
        nw++;
    }
    if((i+1)<=(j*k))
    {
        pr+=1.0*(j*k-i)*(dp(i+1,j,k)+1.0);
        nw+=(j*k-i);
    }
    if(nw) pr/=(nw*1.0);
    return pr;
}

//double rs[52][52];
//bool rsl[52][52];

int main()
{
    int cs=1,t,i,j,k;
    //mem(rsl);
    sc(t);
    while(t--)
    {
        sc2(n,m);
        mem(bl);
        double ans=dp(0,0,0);
        printf("%.12lf\n",ans+eps);
    }
    return 0;
}
