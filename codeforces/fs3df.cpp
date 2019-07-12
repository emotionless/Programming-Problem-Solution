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
#define pcs(a) printf("Case #%d: \n",a)
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
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/********************************************************************************/
/* ////////////////////////////////////////////////////////////////////////////*/
/*********************************************************************************/
/// dgt   01234567891011
#define MX 1005
#define MD 1000000007LL

char a[105][105], b[105][105], sm[105][105];

int main()
{
    int t, cs = 1, i, j, k, n , m, rs;
    bool smt;

    sc(t);
    while(t--)
    {
        sc2(n, m);
        smt = 0;
        f(i, n)
        {
            f(j, n)
            {
                scanf(" %c", &a[i][j]);
                sm[j][i] = a[i][j];
            }
        }
        rs = k = 0;
        f(i, n)
        {
            f(j, n)
            {
                scanf(" %c", &b[i][j]);
//                if(i<=j){
//                if(k == 0 && b[i][j] != a[j][i])
//                {
//                    k = 1;
//                }
////                }
//                rs += (b[i][j] != a[i][j]);
            }
        }


        // sdfsd

        f(i, n)
        {
            f(j, n)
            {
                //      scanf(" %c", &b[i][j]);
//                if(i<=j){
                if(a[i][j] == b[i][j]) continue;
                if(b[i][j] == a[j][i] && b[j][i] != a[i][j])
                    k = 1;
//                }
                rs += (b[i][j] != a[i][j]);
            }
        }

        f(i, n)
        {
            f(j, n)
            {
                if(b[i][j] != b[j][i])
                {
                    smt = 1;
                    break;
                }
            }
            if(j < n)break;
        }
        if(smt == 0)
        {
            printf("Case %d: %d\n", cs++, -1);
            continue;
        }

        if(k)
        {
            printf("Case %d: %d\n", cs++, rs);
            continue;
        }


        bool ok = false;
        int val = 0;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(a[i][j] != b[i][j] && i != j)
                {
                    int tmp = b[i][j];
                    if(tmp == a[j][i])
                    {
                        if(a[j][i] != b[j][i] && b[j][i] != a[i][j])
                        {
                            ok = 1;
                        }
                        else if(b[j][i] == a[i][j])
                            val++;
                    }
                    else
                        ok = 1;
                }
            }
        }
//        if(m < 3)
//            rs = -1;
        if(val && val <= 2 && m < 3)
                printf("Case %d: %d\n", cs++, -1);

        else if(ok)
            printf("Case %d: %d\n", cs++, rs);
        else
        {
            if(val && val <= 2 && m < 3)
                printf("Case %d: %d\n", cs++, -1);
            else
                printf("Case %d: %d\n", cs++, rs + 1);
        }
    }

    return 0;
}


/*

1
3 2
1 2 2
1 2 2
1 2 2

1 2 1
1 2 2
1 2 2


1
3 2
1 1 1
2 1 1
2 1 1

1 2 2
1 1 1
1 1 1

1
3 3

1 2 1
1 1 1
1 1 1

1 1 1
2 1 1
1 2 1


1
3 2

1 2 1
1 2 1
1 2 1

1 2 1
2 2 1
1 1 1


*/
