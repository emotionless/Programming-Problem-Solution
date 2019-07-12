#include<bits/stdc++.h>

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
#define nl printf("\n")
#define sp printf(" ")
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

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
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 100000000
#define PI acos(-1.0)
#define piii pair<int, pii>

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
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)

#define MX 10000000000000000ll
#define lim 1000000      /// 10^5



///***** Template ends here *****///
///********************* Code starts here ****************************


int seg[8*MAX];
pii inp[MAX];
pii arr[MAX];


void insert(int ind, int st, int ed, int pos, int val)
{
    if(st == ed)
    {
        seg[ind] += val;
        return;
    }
    int mid = (st + ed)/2;
    if(pos <= mid)
        insert(ind*2, st, mid, pos, val);
    else
        insert(ind*2+1, mid+1, ed, pos, val);

    seg[ind]  = seg[ind*2] + seg[ind*2+1];


    return;
}

int n;

int queryRight(int ind, int st, int ed, int l, int r)
{
//    cout<<ind<<" "<<st<<" "<<ed<<" "<<l<<" "<<r<<" "<<seg[ind]<<endl;
    if(!seg[ind]) return n+1;

    if(st == ed) return st;

    int mid = (st + ed)/2;
    if(r <= mid)
        return queryRight(ind*2, st, mid, l, r);
    else if(l > mid)
        return queryRight(ind*2+1, mid+1, ed, l, r);
    else
    {
        int a = queryRight(ind*2, st, mid, l, mid);
        if(a == (n+1))
            a = queryRight(ind*2+1, mid+1, ed, mid+1, r);
        return a;
    }
}




int queryLeft(int ind, int st, int ed, int l, int r)
{
    if(!seg[ind]) return 0;

    if(st == ed) return st;

    int mid = (st + ed)/2;
    if(r <= mid)
        return queryLeft(ind*2, st, mid, l, r);
    else if(l > mid)
        return queryLeft(ind*2+1, mid+1, ed, l, r);
    else
    {
        int a = queryLeft(ind*2+1, mid+1, ed, mid+1, r);
        if(!a)
            a = queryLeft(ind*2, st, mid, l, mid);
        return a;
    }
}





int main()
{
    int j, k, i;
    int t, a, b,  m, num;
    sc(n);
    for(i = 0; i < n; i++)
    {
        sc(num);
        inp[i].xx = num;
        inp[i].yy = i;

        arr[i].xx = -num;
        arr[i].yy = i;
    }
    sort(inp, inp + n);

    ll sum = 0ll;

    for(i = 0; i < n; i++)
    {
        int ind = inp[i].yy + 1;
        int val = inp[i].xx;

        int lft = queryLeft(1, 1, n, 1, ind);
        int rgt = queryRight(1, 1, n, ind, n);
        sum += (ll)(ind - lft) * (ll)(rgt - ind) * (ll)val;
        insert(1, 1, n, ind, 1);
    }

    clr(seg, 0);

    sort(arr, arr + n);

    ll now = 0ll;

    for(i = 0;  i < n; i++)
    {
        int ind = arr[i].yy + 1;
        int val = -arr[i].xx;
//        cout<<ind<<" "<<val<<endl;
        int lft = queryLeft(1, 1, n, 1, ind);
        int rgt = queryRight(1, 1, n, ind, n);
        now += (ll)(ind - lft) * (ll)(rgt - ind) * (ll)val;
        insert(1, 1, n, ind, 1);
    }
//    cout<<now<<endl;
//    cout<<now - sum<<endl;
    printf("%lld\n", now-sum);





















    return 0;
}

/*

3
1 2 3


*/
