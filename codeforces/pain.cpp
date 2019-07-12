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
#define inf (INT_MAX/10)
#define linf (LLONG_MAX/10LL)
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
#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define xx first
#define yy second
#define mxv(a) *max_element(aov(a))
#define mnv(a) *min_element(aov(a))
#define LB(a,x) (lower_bound(aov(a),x)-a.begin())
#define UB(a,x) (upper_bound(aov(a),x)-a.begin())
#define to_c_string(a) a.c_str()
#define strtoint(c) atoi(&c[0])
#define pii pair< int , int >
#define pll pair< ll , ll >
#define pcs(a) printf("Case %d: ", a)
#define nl puts("")
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
    return bigmod(a,M-2,M);
}   // M is prime}
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


///int mnth[]={-1,31,28,31,30,31,30,31,31,30,31,30,31};  //Not Leap Year
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int dx[]={-1,-1,+0,+1,+1,+0};int dy[]={-1,+1,+2,+1,-1,-2}; //Hexagonal Direction
///const double eps=1e-6;
///int dx[]={0,1,0,-1};int dy[]={1,0,-1,0}; //4 Direction

/*****************************************************************/
/// ////////////////////   GET SET GO    ////////////////////// ///
/*****************************************************************/

#define M 1000006
#define MM 100000
#define MD 1000000007LL
#define MX 2000012LL

int nx[MM][26],fl[MM],qz[MM],ch[MM],p[MM],sz;
vector< int >tr[MM];
char s[505],g[M];

void init(int x)
{
    tr[x].clear();
    qz[x]=0;
    for(int i=0; i<26; i++)nx[x][i]=-1;
}

void aho_csk()
{
    queue< int >q;
    fl[0]=0;
    q.push(0);
    int cr,c;
    while(!q.empty())
    {
        cr=q.front();
        q.pop();
        for(int i=0; i<26; i++)if(nx[cr][i]!=-1)q.push(nx[cr][i]);
        if(cr==0)continue;

        c=ch[cr];
        fl[cr]=fl[ p[cr] ];
        while(fl[cr]!=0&&nx[fl[cr]][c]==-1)fl[cr]=fl[ fl[cr] ];
        if(nx[fl[cr]][c]!=-1)
        {
            fl[cr]=nx[fl[cr]][c];
            if(fl[cr]==cr)fl[cr]=0;
        }
//        printf("%d : %d %d\n",cr,p[cr],fl[cr]);
    }
}

int rs[505];

int main()
{
    int t,i,j,k,n;
    int rt,cs=1;

    sc(t);
    while(t--)
    {
        sc(n);
        init(0);
        rt=0;
        sz=1;

        scanf(" %s",g);
        f(k,n)
        {
            rs[k]=0;
            scanf(" %s",&s);
            i=rt;
            j=0;
            while(s[j]!='\0')
            {
                if(nx[i][s[j]-'a']==-1)
                {
                    init(sz);
                    p[sz]=i;
                    ch[sz]=s[j]-'a';
                    nx[i][s[j]-'a']=sz++;
                }
                i=nx[i][s[j++]-'a'];
//                printf("%c %d\n",s[j-1],i);
            }
            tr[i].pb(k);
            qz[i]++;
        }
        aho_csk();
        i=j=0;
        while(g[j]!='\0')
        {
            while(i!=0&& nx[i][g[j]-'a']==-1 )
            {
                i=fl[i];
                for(k=0; k<qz[i]; k++)rs[ tr[i][k] ]++;
            }
            if(nx[i][g[j]-'a']!=-1)
            {
                i=nx[i][g[j]-'a'];
                for(k=0; k<qz[i]; k++)rs[ tr[i][k] ]++;
            }
            j++;
        }

        printf("Case %d:\n",cs++);
        f(k,n)printf("%d\n",rs[k]);
    }
    return 0;
}
/*
5
asdad
abcde
abc
cde
bcd
bbbc
*/
