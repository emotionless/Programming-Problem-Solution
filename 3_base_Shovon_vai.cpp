#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<fstream>
#include<sstream>
#include<stack>
#include<list>
#include<deque>
#include<bitset>
#include<utility>
#include<climits>
#include<iomanip>
#include<ctime>
#include<complex>
#include<set>
using namespace std;


#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define debug(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define ll long long
#define ull unsigned long long
#define eps 1e-9
#define MOD 1000000007

//TYO conversion
template<typename T>inline string toString(T a)
{
    ostringstream os("");
    os<<a;
    return os.str();
}
template<typename T>inline ll toLong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
//MATHEMATICS
template<typename T>inline T  S(T a)
{
    return a*a;
}
template<typename T>inline T gcd(T a, T b)
{
    if (b == 0)return a;
    else return gcd(b, a % b);
}
template<typename T>inline ull bigmod(T a, T b, T m)
{
    if (b == 0)return 1;
    else if (b % 2 == 0)return S(bigmod(a, b / 2, m)) % m;
    else return (a % m*bigmod(a, b - 1, m)) % m;
}
template<typename T>inline VS parse(T str)
{
    VS res;
    string s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
template<typename T>inline ull  dist(T A,T B)
{
    ull res=(A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
    return res;
}
template<typename T>inline double cosAngle(T a,T b,T c)
{
    double res=a*a+b*b-c*c;
    res=res/(2*a*b);
    res=acos(res);
    return res;
}
template<typename T>inline T power(T base,int po)
{
    T res=1;
    if(base==0)return 0;
    FOR(i,0,po)res*=base;
    return res;
}
//BIT
template<typename T>inline bool isOn(T mask,T pos)
{
    return mask&(1<<pos);
}
template<typename T>inline int Off(T mask,T pos)
{
    return mask^(1<<pos);
}
template<typename T>inline int On(T mask,T pos)
{
    return mask|(1<<pos);
}


int n,m;
int g[20][20];
int W[20],C[20];
int dp[11][60000];
int three[15];
string make(int nn)
{
    string str;
    FOR(i,0,n)str=str+"0";
    int i=0;
    while(nn)
    {
        str[i]=('0'+ nn%3);
        nn/=3;
        i++;
    }
    //reverse(arr,arr+i);
    return str;
}

int toint(string str)
{

    int cur=0;
    for(int i=0; i<n; i++)
    {
        int x=str[i]-'0';
        cur=cur+(x)*three[i];
    }
    return cur;
}


int solve(int pos  , int mask)
{

    //cout<<pos<<" "<<mask<<" "<<n<<endl;

    if(dp[pos][mask]!=-1)return dp[pos][mask];
    int &ret=dp[pos][mask]=0;

    string str=make(mask);
    for(int i=0; i<n; i++)
    {
        if(pos==i)continue;
        if(g[pos][i]==0)continue;
        if(str[i]=='0')
        {
            str[i]='1';
            int nmask=toint(str);
            ret=max(ret,solve(i,nmask)+C[i] );
            str[i]='0';
        }
        else if(str[i]=='1' && W[i]==2)
        {
            str[i]='2';
            int nmask=toint(str);
            ret=max(ret,solve(i,nmask));
            str[i]='1';
        }
    }
    return ret;
}

int main()
{



    int i,j,k;
    int cas,ks;
    n=6;
    three[0]=1;
    FOR(i,1,11)
    {
        three[i]=3*three[i-1];
    }



    cin>>ks;

    FOR(cas,1,ks+1)
    {
        cin>>n>>m;
        FOR(i,0,n)
        {
            scanf("%d",&W[i]);
        }
        FOR(i,0,n)
        {
            scanf("%d",&C[i]);
        }
        SET(g,0);
        int x,y;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            g[x][y]=g[y][x]=1;
        }
        int res=0;
        string str="";
        FOR(i,0,n)str=str+"0";
        SET(dp,-1);
        for(i=0; i<n; i++)
        {
            str[i]='1';
            int mask_val=toint(str);
            res=max(res,solve( i, mask_val )+C[i] );
            str[i]='0';
        }
        printf("Case %d: %d\n",cas,res);
    }

}
