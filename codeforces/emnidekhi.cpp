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
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
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


#define MOD 4294967296
#define MAX 100009
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

#define eps 1e-9
#define high 1e18

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

ll a[MAX];
ll b[MAX];

int n, now;
vector<ll>Slop, Ci;

int isBad(int l1, int l2, int l3)
{
    return 1.0*(Ci[l3]-Ci[l1])*(Slop[l1]-Slop[l2]) < 1.0*(Ci[l2]-Ci[l1])*(Slop[l1]-Slop[l3]);
}

void add(ll m, ll c)
{
    Slop.pb(m);
    Ci.pb(c);
    while(Slop.size() >= 3 && isBad(Slop.size()-3, Slop.size()-2, Slop.size()-1))
    {
        Slop.erase(Slop.end()-2);
        Ci.erase(Ci.end()-2);
    }
}

ll query(ll x)
{
    if(now >= Slop.size()) now = Slop.size()-1;
    while(now < Slop.size()-1 && (Slop[now+1]*x + Ci[now+1])<(Slop[now]*x+Ci[now] )) now++;
    return (Slop[now]*x + Ci[now]);
}



int main()
{
//    use_cin;
//    READ;
//    WRITE;
    int  t;
    int i, j, k;
    cin>>n;

    for(i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for(i = 1; i <= n; i++)
    {
        cin>>b[i];
    }
    add(b[1], 0);
    ll ans = 0;
    for(i = 2; i <= n; i++)
    {
        ans = query(a[i]);
        add(b[i], ans);
    }
    cout<<ans<<endl;


    return 0;
}

/*


3 3 5
2 8 5 3 7 6
2 1 4 3 6 5
10 9 8 7 6 5

*/
