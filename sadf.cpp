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
#define frr(i,a) for(i = a - 1; i >= 0, i--)

/// BG_PeaceMind
#define SZ(x) x.size()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define MXE(x) *max_element(all(x))
#define MNE(x) *min_element(all(x))
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)

/// sahedsohel
#define f(i,n) for(i=0;i<n;i++)
#define fl(c,i,n) for(i=c;i<n;i++)
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
#define ll long long
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
#define scl2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define nl puts("")
#define pf printf
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
    return bigmod(a,M-2,M);    // M is prime
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
#define MX 5009
#define MD 1000000000000LL
#define YES printf("success.\n")
vector<int> V;

long long val[MX];
bool is[MX];

map<int, int>M;

inline int value(int u)
{
    return M[u];
}

int sp, id;

void erase(int i)
{
    V.erase(V.begin() + i);
}

void insert(int i)
{
    V.insert(V.begin(), i);
}

void execute(string cmd, int u)
{
    if(cmd == "Add")
    {
        int v = value(u);
//        cout<<v<<endl;
        if(is[v])
        {
            pf("same priority.\n");
            return;
        }
        V.pb(u);
        is[v] = true;
        val[v] = 0;
        YES;
    }
    else if(cmd[0] == 'C' && cmd[1] == 'l')
    {
        int p = 0;
        int v = value(u);
        if(sp == u)
        {
            is[v] = false;
            sp = -1000;
            p = 1;
        }
        int i, sz = V.size();
        for(i = 0; i < sz; i++)
        {
            if(V[i] == u) break;
        }
        if(i == sz && !p)
            pf("invalid priority.\n");
        else
        {
            if(!p)
                pf("close %d with %lld.\n", u, val[v]);
//            cout<<v<<endl;
            erase(i);
            is[v] = false;
            val[v] = 0;
        }
    }

    else if(cmd[0] == 'C' && cmd[1] == 'h' && cmd[2] == 'a')
    {
        int v = value(u);
        int sz = V.size();

        if(sp > 0)
            val[val[sp]] += u;
        else
        {
            if(sz == 0) pf("empty.\n");
            else
            {
                YES;
                val[value(V[0])] += u;
            }
        }
    }
    else if(cmd == "Rotate")
    {

        int sz = V.size();
        if(u > sz || u < 1)
            pf("out of range.\n");
        else
        {
            int tmp = V[u - 1];
            erase(u - 1);
            insert(tmp);
            YES;
        }
    }
    else if(cmd == "Prior")
    {
        int sz = V.size();
        if(sz == 0)
        {
            pf("empty.\n");
        }
        else
        {
            int mx = 0, pos = -1;
            for(int i = 0; i < sz; i++)
            {
                if(V[i] > mx)
                {
                    mx = V[i];
                    pos = i;
                }
            }
            erase(pos);
            insert(mx);
            YES;
        }
    }
    else if(cmd == "Choose")
    {
        int v = value(u), i, sz = V.size();
        for(i = 0; i < sz; i++)
        {
            if(V[i] == u) break;
        }
        if(i == sz)
            pf("invalid priority.\n");
        else
        {
            erase(i);
            insert(u);
            YES;
        }
    }
    else if(cmd == "Top")
    {
        int i, sz = V.size();
        for(i = 0; i < sz; i++)
        {
            if(V[i] == u) break;
        }
        if(i == sz)
            pf("invalid priority.\n");
        else
        {
            sp = u;
            YES;
        }
    }
    else if(cmd == "Untop")
    {
        if(sp < 0)
            pf("no such person.\n");
        else
        {
            sp = -1000;
            YES;
        }
    }
}









int main()
{
    int t,cs=1,i,j,k;
    int cases = 1;
    sc1(cs);
    while(cs--)
    {
        memset(val, 0, sizeof val);
        memset(is, false, sizeof is);
        sc1(t);
        char cmd[10];
        int u;
        sp = -1000;
        V.clear();
        M.clear();

        id = 0;
        while(t--)
        {
//            cin>>cmd;
            scanf("%s", cmd);

            if(cmd[0] == 'U' || cmd[0] == 'P')
            {
                pf("Operation #%d: ", cases++);
                execute(cmd, 0);
            }
            else
            {
                scanf("%d", &u);
                pf("Operation #%d: ", cases++);
                if(!M[u])
                    M[u] = (++id);
                execute(cmd, u);
            }
            int sz = V.size();
            for(i = 0; i <sz; i++)
            {
                int v = value(V[i]);

                if(val[v])
                    pf("Bye %d: %d\n", V[i], val[v]);
            }
        }


    }
    return 0;
}


/*


18
Prior
Add 1
Chat 1
Add 2
Chat 2
Top 2
Chat 3
Untop
Chat 4
Choose 2
Chat 5
Rotate 2
Chat 4
Close 2
Add 3
Prior
Chat 2
Close 1

*/
