#include<bits/stdc++.h>
#define ll long long int
#define dd double
/**Define file I/O **/
#define f_input freopen("input.txt","r",stdin)
#define f_output freopen("output.txt","w",stdout)
/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
/**Define function and object**/
#define SQR(x) ((x)*(x))
#define DIS(a,b,c,d) sqrt(SQR(a-c)+SQR(b-d))
/**Define constant value**/
#define ERR 1e-9
#define pi  (2.0*acos(0.0))//3.141592653589793
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define nln printf("\n") ///newline
#define Case printf("Case %d:",++cno) ///print case
#define space printf(" ") ///print space
#define tc int t,cno=0;scanf("%d",&t); ///input test case
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
/**Define input**/
/** priority_queue<int,vector<int>, prioritycom > pq **/
/**  set<int>::iterator it **/
using namespace std;
/**Typedef**/
const int INF=0x7FFFFFFF;
/**Template & structure**/
struct prioritycom
{
    bool operator()(const int& l, const int& r)
    {
        return l < r;
    }
};/// priority queue compare function
template<typename T>T lcm(T a, T b)
{
    return a / __gcd(a,b) * b;
}
template <class T> inline T bigmod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1)
            ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class string> ll strton(string s)
{
    ll won;    /// convert string to number
    stringstream ss;
    ss<<s;
    ss>>won;
    return won;
}
template <class T> string ntostr(T n)
{
    stringstream ss;    /// convert a number to string
    ss << n;
    return ss.str();
}
template<class T> inline T mod(T n,T m)
{
    return (n%m+m)%m;   ///For Positive Negative No.
}
template<class T> bool isprime(T n)
{
    if(n%2==0)
    {
        if(n==2)
            return true;
        else
            return false;
    }
    T m=sqrt(n);
    for(T i=3; i<=m; i+=2)
    {
        if(n%i==0)
            return false;
    }
    return true;
}
bool isvowel(char ch)
{
    ch=toupper(ch);
    if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E')
        return true;
    return false;
}
dd triangle_area1(dd a, dd b, dd c)
{
    dd s=(a+b+c)*0.5;    ///with s
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
dd triangle_area2(dd x1,dd y1, dd x2, dd y2, dd x3, dd y3)
{
    return 0.5*abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3);   ///with points.must be in anticlockwise
}
dd circle_area(dd r,dd theta)
{
    return (theta*pi*r*r)/(2*pi);   ///area of circle sector with center angle theta.theta needs to be radian.
}
dd quad_area(dd x1,dd y1, dd x2, dd y2, dd x3, dd y3, dd x4, dd y4)
{
    return 0.5*abs(x1*y2+x2*y3+x3*y4+x4*y1-x2*y1-x3*y2-x4*y3-x1*y4);   ///with points.must be in anticlockwise
}
dd cosangle(dd a,dd b, dd c)
{
    return acos((dd)(b*b+c*c-a*a)/(dd)(2*b*c));   ///calculate angle from three sides of a triangle. returns angle in radian
}
///void stow(string s){stringstream ss(s);string x;while(ss>>x){cout<<x<<endl;}} sentence to word
ll Set(ll N,ll pos)
{
    return N=N | (1ll<<pos);
}
ll reset(ll N,ll pos)
{
    return N= N & ~(1ll<<pos);
}
bool check(ll N,ll pos)
{
    return (bool)(N & (1ll<<pos));
}
#define M 1000000007
#define MX 100005
/**ll dx8[]={-1,-1,-1,0,0,1,1,1};
ll dy8[]={-1,0,1,-1,1,-1,0,1};
ll dx4[]={-1,0,1,0};
ll dy4[]={0,1,0,-1};**/
/******************************End******************************/
ll inf=999999999999999999;
ll dp[1005][10];
ll vis[10],c[1005],n;
string s[1005];
ll f(ll i,ll msk)
{
    if(msk==7)
    {
        return 0;
    }
    if(i>n)
    {
        if(msk==7)
            return 0;
        return inf;
    }
    if(dp[i][msk]!=-1)
        return dp[i][msk];
    ll r=0;
    dp[i][msk] = inf;
    r=f(i+1,msk);
    int tmp = msk;
    for(ll j=0; j<(ll)s[i].length(); j++)
    {
        ll d=s[i][j]-'A';
        tmp=Set(tmp,d);
    }
    r=min(r,c[i]+f(i+1,tmp));
//    cout<<i<<" "<<msk<<" "<<r<<endl;
    return dp[i][msk]=r;

}
int main()
{
    scanf("%lld",&n);
    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&c[i]);
        cin>>s[i];
        ll m=s[i].length();
        for(ll j=0; j<m; j++)
        {
            vis[s[i][j]-'A']++;
        }
    }
    for(ll i=0; i<3; i++)
    {
        if(!vis[i])
        {
            cout<<"-1";
            return 0;
        }
    }
    mem(dp,-1);
    ll ans=f(1,0);
    printf("%lld\n",ans);
}

/*


8
1 CB
4 AC
4 BA
6 CB
1 BA
5 BA
6 CA
2 CA


*/
