/***************************************
    codeforces = topcoder = sahedsohel
    IIT,Jahangirnagar University(42)
****************************************/
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

#define ll long long int
#define ull unsigned long long int
#define inf INT_MAX
#define linf LLONG_MAX
#define sc(a) scanf("%d",&a)
#define sc2(a,b) scanf("%d%d",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define fl(c,i,n) for(i=c;i<n;i++)
#define f(i,n) for(i=0;i<n;i++)
#define mem(a) memset(a,0,sizeof(a))
#define memn(a) memset(a,-1,sizeof(a))
#define pb push_back
#define pp pop_back()
#define aov(a) a.begin(),a.end()
#define mpr make_pair
#define nl printf("\n")
#define PI 2.0*acos(0.0) //#define PI acos(-1.0)
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

///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction
///const double eps=1e-6;

/*****************************************************************/
///////////////////////   GET SET GO    ///////////////////////////
/*****************************************************************/

#define M 260

int fs[M],fa[M],rnt[M],ra[M],n,m,hv,aln1,aln2;
bool bl[M];

int main ()
{
    int cs=1,t,i,j,sm,mx,p,x,q;
    sc3(hv,aln1,aln2);
    sc(n);   ///  friend   can_pay   advantage
    f(i,n)
    {
        sc2(fs[i],fa[i]);
    }
    sc(m);   ///  room     1/2  rent  advantage
    f(i,m)
    {
        sc3(j,rnt[i],ra[i]);
        bl[i]=(j==2);
    }

    mx=-1;
    p=-1;
    q=-1;

    for(i=0;i<m;i++)
    {
        if(hv>=rnt[i])
        {
            sm=ra[i]+(bl[i]==1?aln2:aln1);

            if(mx<sm)
            {
                mx=sm;
                p=i;
                q=-1;
            }
        }


        if(bl[i]==1)
        {
            x=rnt[i];
            for(j=0;j<n;j++)
            {
                if(x<=(hv * 2) && x<=(fs[j] * 2))
                {
                    sm=ra[i]+fa[j];
                    if(mx<sm)
                    {
                        mx=sm;
                        p=i;
                        q=j;
                    }
                }
            }
        }
    }
    if(mx == -1)
        printf("Forget about apartments. Live in the dormitory.");
    else if(q == -1 && p >= 0)
        printf("You should rent the apartment #%d alone.",p+1);
    else if(p >= 0 & q >= 0)
        printf("You should rent the apartment #%d with the friend #%d.",p+1,q+1);
    else
        printf("Forget about apartments. Live in the dormitory.");
    cout<<endl;
    return 0;
}
