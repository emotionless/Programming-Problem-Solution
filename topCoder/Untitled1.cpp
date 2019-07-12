#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#define maxim 100
#define LLD long long int
#define LLU long long unsigned
#define HD short int
#define HU short unsigned
#define ui unsigned
#define pi acos(-1.0)
#define inf (1<<29)
#define Clear(a) memset(a,0,sizeof(a))
#define SET(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define ppb pop_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define eps 1e-9
#define rep(i,init,n) for(int i=init;i<n;i++)
#define rem(i,init,n) for(int i=init;i>n;i--)
#define _abs(a) ((a)<0?(-(a)):(a))
#define area(x1,y1,x2,y2,x3,y3) ( x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2) )
#define sqr(x) ((x)*(x))
#define distSqr(x1,y1,x2,y2) ( sqr(x1-x2) + sqr(y1-y2) )
#define spDist(lat1,long1,lat2,long2,r) ( r * acos( sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1-long2) ) )
#define isEq(a,b) (fabs(a-b)<eps)
#define STR string
#define LF double
#define IT iterator
#define VI vector<int>
#define VLLD vector<LLD>
#define VS vector<STR>
#define VLF vector<LF>
#define MII map<int,int>
#define MIB map<int,bool>
#define MSI map<STR,int>
#define MSB map<STR,bool>
#define MSS map<STR,STR>
#define M2dII map<int,map<int,int> >
#define QI queue<int>
#define SI stack<int>
#define PII pair< int, int >
#define PPI pair< PII, int >
#define x first.first
#define y first.second
#define w second
#define VPII vector<PII>
#define MP make_pair

#define chk(a,k) ((bool)(a&(1<<(k))))
#define set0(a,k) (a&(~(1<<(k))))
#define set1(a,k) (a|(1<<(k)))

#define chkA(a,k) (bool)(a[(k)>>5] & (1<<((k)&31)))
#define setA0(a,k) (a[(k)>>5] &= ~(1<<((k)&31)))
#define setA1(a,k) (a[(k)>>5] |= (1<<((k)&31)))

#define SD(a) scanf("%d",&a)
#define SU(a) scanf("%u",&a)
#define SHD(a) scanf("%hd",&a)
#define SHU(a) scanf("%hu",&a)
#define SLLD(a) scanf("%lld",&a)
#define SLLU(a) scanf("%llu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)

#define foreach(i, c) for( __typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i )
#define N 505

int diru[] = {-1,-1,-1,0,0,1,1,1};
int dirv[] = {-1,0,1,-1,1,-1,0,1};

using namespace std;

vector<int>v;
int n;
bool vis[N],p[N];

void set_prime()
{
    Clear(p);
    p[1]=p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=p[37]=true;
}

void reset()
{
    Clear(vis);
    v.clear();
    v.pb(1);
}

void print()
{
    cout<<v[0];
    rep(i,1,v.size())    cout<<" "<<v[i];
    cout<<endl;
}

void call(int s)
{
    if(v.size()==n)
    {
        if(p[v[n-1]+v[0]])print();
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(p[s+i]&&!vis[i])
        {
            v.pb(i);
            vis[i]=true;
            call(i);
            v.ppb();
            vis[i]=false;
        }
    }
}
int main()
{
    set_prime();

    int CASE=0;
    bool blank=false;

    while(cin>>n)
    {
        if(blank)   cout<<endl;
        blank=true;
        reset();
        printf("Case %d:\n",++CASE);
        call(1);
    }
}
