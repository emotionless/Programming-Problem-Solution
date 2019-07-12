#include <bits/stdc++.h>

#define mp mafrom_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1ll<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

///**** Max/Min********///

#define _max(aa, bb) (aa = max(aa, bb))
#define max2(aa, bb) max(aa, bb)
#define max3(aa, bb, cc) max(aa, max(bb, cc))
#define max4(aa, bb, cc, dd) max(max(aa, dd), max(bb, cc))
#define _min(aa, bb) (aa = min(aa, bb))
#define min2(aa, bb) min(aa, bb)
#define min3(aa, bb, cc) min(aa, min(bb, cc))
#define min4(aa, bb, cc, dd) min(min(aa, dd), min(bb, cc))


///******* File *********///

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("D-small-attempt0.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define nl printf("\n")
#define eps 1e-18
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 1001000000000000009ll
#define PI acos(-1.0)
#define piii pair<int, pii>
#define CLR(aa, nnn) for(int ii = 0; ii <= nnn; ii++) {aa[ii].clear();}

using namespace std;

///******* Template ********///

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}

void sc(int &a)
{
    scanf("%d", &a);
}

void sc(ll &a)
{
    scanf("%lld", &a);
}

void sc(double &a)
{
    scanf("%lf", &a);
}

void sc(int &a, int &b)
{
    scanf("%d %d", &a, &b);
}

void sc(ll &a, ll &b)
{
    scanf("%lld %lld", &a, &b);
}

void sc(int &a, int &b, int &c)
{
    scanf("%d %d %d", &a, &b, &c);
}


void sc(int &a, int &b, ll &c)
{
    scanf("%d %d %lld", &a, &b, &c);
}


void sc(ll &a, ll &b, ll &c)
{
    scanf("%lld %lld %lld", &a, &b, &c);
}

void sc(string &str)
{
    cin>>str;
}


void sc(char *(str))
{
    scanf(" %s", str);
}

void sc(char &c)
{
    scanf(" %c", &c);
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


#define LEN(a) strlen(a)
#define ull unsigned long long

#define nl printf("\n")

//#define MX 10000000000000000ll
#define MX (lim*4 + 10)
#define lim 300000     /// 10^5


///***** Template ends here *****///
///********************* Code starts here ****************************

/// ********** Convex Hull Trick ********///

struct line
{
    long long a, b;
    double xleft;
    bool type;
    line(long long _a, long long _b)
    {
        a = _a;
        b = _b;
        type = 0;
    }
    bool operator < (const line &other) const
    {
        if(other.type)
        {
            return xleft < other.xleft;
        }
        return a > other.a;
    }
};
double meet(line x, line y)
{
    return 1.0 * (y.b - x.b) / (x.a - y.a);
}
map<pii, bool>M;
struct cht
{
    set < line > hull;
    cht()
    {
        hull.clear();
    }
    typedef set < line > :: iterator ite;
    bool hasleft(ite node)
    {
        return node != hull.begin();
    }
    bool hasright(ite node)
    {
        return node != prev(hull.end());
    }
    void updateborder(ite node)
    {
        if(hasright(node))
        {
            line temp = *next(node);
            hull.erase(temp);
            temp.xleft = meet(*node, temp);
            hull.insert(temp);
        }
        if(hasleft(node))
        {
            line temp = *node;
            temp.xleft = meet(*prev(node), temp);
            hull.erase(node);
            hull.insert(temp);
        }
        else
        {
            line temp = *node;
            hull.erase(node);
            temp.xleft = -2000000000000000000LL;
            hull.insert(temp);
        }
    }
    bool useless(line left, line middle, line right)
    {
        double x = meet(left, right);
        double y = x * middle.a + middle.b;
        double ly = left.a * x + left.b;
        return y > ly;
    }
    bool useless(ite node)
    {
        if(hasleft(node) && hasright(node))
        {
            return useless(*prev(node), *node, *next(node));
        }
        return 0;
    }
    void addline(long long m, long long c, int now)
    {
        line temp = line(m, c);
        auto it = hull.lower_bound(temp);
        if(it != hull.end() && it -> a == m)
        {
            if(it -> b > c)
            {
                hull.erase(it);
            }
            else
            {
                return;
            }
        }
        hull.insert(temp);
        it = hull.find(temp);
        if(useless(it))
        {
            hull.erase(it);
            return;
        }
        while(hasleft(it) && useless(prev(it)))
        {
            hull.erase(prev(it));
        }
        while(hasright(it) && useless(next(it)))
        {
            hull.erase(next(it));
        }
        updateborder(it);
//        printf("%d ", now);
    }
    pii getbest(long long x)
    {
        if(hull.empty())
        {
            return make_pair(0, 0);
        }
        line query(0, 0);
        query.xleft = x;
        query.type = 1;
        auto it = hull.lower_bound(query);
        it = prev(it);
        int a = (it->a);
        int b = (it->b);

//		cout<<(it->a)<<" "<<(it->b)<<endl;
//        M[mp(it->a, it->b)] = 1;
//		return it -> a * x + it -> b;
        return make_pair(a, b );
    }
};

cht Tree;
ll a[MAX], b[MAX];

int main()
{
    int i, j, k;
    int n;

    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        sc(a[i], b[i]);
        Tree.addline(-a[i], -b[i], i);
    }
    map<pii, bool>M;
    for(i = 1; i <= 100000; i++)
    {
        pii p = Tree.getbest(i);
        M[p] = 1;
    }
    for(i = 1; i <= n; i++)
    {
        if(M.find(make_pair(-a[i], -b[i])) != M.end())
            printf("%d ", i);
    }



    return 0;
}
