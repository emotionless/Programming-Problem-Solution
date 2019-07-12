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
#define pcs(a) printf("Tour %d: ",a)
#define dbg(x) cout<<#x<<" : "<<x<<endl

template <class T> inline T bigmod(T p,T e,T M){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;} return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}  // M is prime
template <class T> inline T bpow(T p,T e){ll ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p);p = (p * p);} return (T)ret;}

int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int toLlint(string s) { long long int sm; stringstream ss(s); ss>>sm; return sm;}

///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction
///const double eps=1e-6;

/*****************************************************************/
///////////////////////   GET SET GO    ///////////////////////////
/*****************************************************************/

#define M 1000
#define MD 10000


int n,m,a[105],rs;
bool p[105][105],r[105][105],vs[105];
vector<int> al[105], wl[105];

bool dp(int i,int u)
{
    if(i==m)
    {
        if(u==n-1)
            return 1;
        return 0;
    }

    if(p[i][u]==1)
        return r[i][u];
    p[i][u]=1;
    r[i][u]=0;

    int ln=al[u].size();
    for(int k=0;k<ln;k++)
    {
        if(a[i]==wl[u][k])
        {
            if(dp(i+1,al[u][k])==1)
            {
                r[i][u]=1;
            }
        }
    }


    if(vs[u]==0&&r[i][u]==1)
    {
        rs++;
        vs[u]=1;
    }

    return r[i][u];
}

int main()
{
    int cs=1,t,i,j,k;


    while(sc2(n,m)==2&&(n||m))
    {
        while(m--){
            sc3(i,j,k);
            al[i].pb(j);
            al[j].pb(i);

            wl[i].pb(k);
            wl[j].pb(k);
        }

        sc(m);
        f(i,m)
        {
            sc(a[i]);
        }

        mem(vs);
        mem(p);
        rs=0;
        if(dp(0,0))
            rs++;
        pcs(cs++);
        printf("%d\n",rs);


        f(i,n)
            al[i].clear(),wl[i].clear();

    }

    return 0;
}



