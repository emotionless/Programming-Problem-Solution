#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a, b) for(i = a; i < b; i++)
#define frr(i,a) for(i = a - 1; i >= 0; i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1LL<<b))
#define set_bit(a, b) (a|(1LL<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 300005
#define MAXLG 20
#define INF 1000000000000000000ll


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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************
struct Z
{
    ll val, h;
};

Z seg[4*MAX];

ll P[MAX];
ll A[MAX];
ll H[MAX];

void insert(int ind, int st, int ed, int pos, ll pre_val, ll cur_val)
{
    if(st == ed)
    {
        seg[ind].val = pre_val;
        seg[ind].h = cur_val;
        return;
    }
    int mid = (st + ed)/2;
    if(pos <= mid)
        insert(ind * 2, st, mid, pos, pre_val, cur_val);
    else
        insert(ind * 2 + 1, mid + 1, ed, pos, pre_val, cur_val);
}


ll query(int ind, int st, int ed, int l, int r, ll h)
{
    if(l > r) return INF;
    if(st == ed)
    {
        if(seg[ind].h == 0ll) return INF;
        return seg[ind].val + seg[ind].h*seg[ind].h + h*h - 2ll*seg[ind].h*h;
    }
    int mid = (st + ed)/2;
    ll ret = 0;
    if(r <= mid)
        ret = query(ind * 2, st, mid, l, r, h);
    else if(l > mid)
        ret = query(ind * 2 + 1, mid + 1, ed, l, r, h);
    else
        ret = min ( query(ind * 2, st, mid, l, mid, h), query(ind * 2 + 1, mid + 1, ed, mid + 1, r, h) );
//    cout<<ind<<" "<<st<<" "<<ed<<" "<<l<<" "<<r<<" "<<h<<" "<<ret<<endl;
return ret;
}




int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    int n, m;
    int num;
    int t;

    s1(n);
    for(i = 1; i <= n; i++)
        scanf("%lld", &P[i]);
    for(i = 1; i <= n; i++)
        scanf("%lld", &A[i]);
    for(i = 1; i <= n; i++)
        scanf("%lld", &H[i]);
    ll ans = 0;
    insert(1, 1, n, 1, A[i], H[1]);
    for(i = 2; i <= n; i++)
    {
        ll cur_ind = P[i];
        ll get = query(1, 1, n, 1, cur_ind - 1, H[i]) + A[i];
        insert(1, 1, n, cur_ind, get, H[i]);
        if(cur_ind == n)
            ans = get;
//
//        cout<<i<<" "<<cur_ind<<" "<<get<<endl;
//
//        cout<<"Tree is here\n";
//        for(j = 1; j <= 9; j++)
//            cout<<"For "<<j<<" "<<seg[j].val<<" "<<seg[j].h<<endl;
//        cin.get();

    }

    printf("%lld\n", ans);

    return 0;
}

/*


5
1 4 3 2 5
0 -1 -3 0 0
1 2 3 4 5



*/
