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
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)

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


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)


#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************



ll arr[MAX];

pair<ll, ll>seg[4*MAX];

void insert(int ind, int st, int ed, int pos, ll v)
{
    if(st == ed)
    {
        seg[ind].xx = v;
        seg[ind].yy = v;
        return;
    }
    int mid = (st + ed)/2;
    if(pos <= mid)
        insert(ind*2, st,  mid, pos, v);
    else
        insert(ind*2+1, mid + 1, ed, pos, v);
    seg[ind].xx = seg[ind*2].xx + seg[ind*2+1].xx;
    if(seg[ind*2].yy >= seg[ind*2+1].yy)
        seg[ind].xx += (ed - mid)*seg[ind*2].yy;
    else
        seg[ind].xx += (mid-st+1)*seg[ind*2+1].yy;
    seg[ind].yy = max(seg[ind*2].yy, seg[ind*2+1].yy);
}


pair<ll, ll> query(int ind, int st, int ed, int l, int r)
{
    if(st == l && ed == r) return seg[ind];
    int mid = (st + ed)/2;
    if(r <= mid)
        return query(ind*2, st, mid, l, r);
    else if(l > mid)
        return query(ind*2+1, mid+1, ed, l, r);
    else
    {
        pair<ll, ll> a = query(ind*2, st, mid, l, mid);
        pair<ll, ll> b = query(ind*2+1, mid+1,ed, mid+1, r);
        pair<ll, ll> tmp;

        tmp.xx = a.xx + b.xx;
        if(a.yy >= b.yy)
            tmp.xx += (ed - mid)*a.yy;
        else
            tmp.xx += (mid - st + 1)*b.yy;
        tmp.yy = max(a.yy, b.yy);

        return tmp;
    }
}


int main()
{
    int i, j, k;
    int num;
    int n,q;
    cin>>n>>q;

    for(i = 1; i <= n; i++)
    {
        cin>>arr[i];
        insert(1, 1, n, i, arr[i]);
    }

    int l, r;
    while(q--)
    {
        cin>>l>>r;
        ll ans = query(1, 1, n, l, r).xx;
        cout<<ans<<endl;
    }

    return 0;
}
/*

0 5 6 7 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

*/
