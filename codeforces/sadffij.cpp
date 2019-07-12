#include <bits/stdc++.h>

#define mp make_pair
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
#define max4(aa, bb, cc, fk) max(max(aa, fk), max(bb, cc))
#define _min(aa, bb) (aa = min(aa, bb))
#define min2(aa, bb) min(aa, bb)
#define min3(aa, bb, cc) min(aa, min(bb, cc))
#define min4(aa, bb, cc, dd) min(min(aa, dd), min(bb, cc))


///******* File *********///

#define WRITE freopen("output02_alter.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("input02.txt","r",stdin)

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
#define PI acos(-1.0)
#define piii pair<int, pii>
#define CLR(aa, nnn) for(int ii = 0; ii <= nnn; ii++) {aa[ii].clear();}

using namespace std;


#define T(a)            cerr << #a << ": " << a << endl;
#define TT(a,b)         cerr << #a << ": " << a << " | " << #b << ": " << b << endl;
#define TTT(a,b,c)      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << endl;
#define TTTT(a,b,c,d)   cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;



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
    T ans = 0;
    a%=m, b%=m;
    while(b)
    {
        if(b&1) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1;
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

#define INF 10000000000000000ll
#define MX (lim*4 + 10)
#define lim 100000    /// 10^5


///***** Template ends here *****///
///********************* Code starts here ****************************

struct Z
{
    int x, y, ind;
    Z(){}
    Z(int _, int __, int ___)
    {
        x = _;
        y = __;
        ind = ___;
    }
    bool operator<(const Z& A) const
    {
        return (y*A.x) < (A.y*x);
    }
}arr[MAX];

int seg[8*MAX];

void update(int ind, int st, int ed, int pos, int v)
{
    if(st == ed)
    {
        seg[ind]+=v;
        return;
    }
    int mid = (st + ed)/2;
    if(pos <= mid)
        update(ind*2, st, mid, pos, v);
    else
        update(ind*2+1, mid+1, ed, pos, v);

    seg[ind] = seg[ind*2] + seg[ind*2+1];

    return;
}


int query(int ind, int st, int ed, int l, int r)
{
    if(r < l) return 0;
    if(st == l && ed == r) return seg[ind];
    int mid = (st + ed)/2;
    if(r <= mid)
        return query(ind*2, st, mid, l, r);
    else if(l > mid)
        return query(ind*2+1, mid+1, ed, l, r);
    else
        return query(ind*2, st, mid, l, mid) + query(ind*2+1, mid+1, ed, mid+1, r);
}

int res[MAX];

int main()
{
    int k;
    int t, i, j;
    int n;

    cin>>n;

    for(i = 0; i < n; i++)
    {
        cin>>arr[i].x>>arr[i].y;
        arr[i].ind = i;
    }
    sort(arr, arr + n);

    for(i = 0; i < n; i++)
    {
        int x = arr[i].x;
        int y = arr[i].y;
        int ind = arr[i].ind;
        //cout<<x<<" "<<y<<" "<<ind<<endl;

        res[ind] = query(1, 1, 100000, 1, x-1);
        update(1, 1, 100000, x, 1);
    }

    for(i = 0; i < n; i++)
        cout<<res[i]<<endl;











    return 0;
}


/*


3
2 1
3 2
2 3

*/
