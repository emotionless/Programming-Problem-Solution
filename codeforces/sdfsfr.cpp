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

#define WRITE freopen("semipal.out","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("semipal.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define sp printf(" ")
#define nl printf("\n")
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MAX (lim+7)
#define INF 1000000000000000ll
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


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)
#define ull unsigned long long

#define MX 10000000000000ll
#define MOD 1000000007
#define lim 5000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

struct Z
{
    ll amnt, cst, tm;
    Z() {}
    Z(ll _, ll __, ll ___)
    {
        amnt = _;
        cst = __;
        tm = ___;
    }
    bool operator <(const Z& A) const
    {
        return tm < A.tm;
    }
};


vi V[MAX];


ll amount[MAX];
ll cost[MAX];
bool vis[MAX];
vector<Z> vec;

pair<ll,ll> take[MAX];

int sz;
bool check(ll tm, ll amnt, ll cst)
{
    int ind = 0;
    for(int i = 0; i < vec.size() && vec[i].tm <= tm; i++)
    {
        take[ind++] = mp(vec[i].cst, vec[i].amnt);
    }
    sort(take, take + ind);

    for(int i = 0; i < ind; i++)
    {
        ll mn = min(take[i].yy, amnt);
        if(cst < (mn*take[i].xx)) return false;
        amnt -= mn;
        cst -= mn*take[i].xx;
        if(amnt == 0) return true;
    }
    return false;
}

bool ace[MAX];
vector<ll> store[MAX];

int BFS(int u, ll amnt, ll cst)
{
    queue<pii>Q;
    Q.push(mp(u, 0));
    vec.clear();
    clr(vis, false);

    while(!Q.empty())
    {
        pii top = Q.front();
        Q.pop();

        int cn = top.xx;
        int cc = top.yy;

        if(vis[cn]) continue;
        vis[cn] = 1;
        if(amount[cn])
        {
            for(int i = 0; i < store[cn].size(); i+=2)
                vec.pb(Z(store[cn][i], store[cn][i+1], (ll)cc));
        }

        int sz = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int adjn = V[cn][i];
            if(!vis[adjn])
            {
                int adjc = cc + 1;
                Q.push(mp(adjn, adjc));
            }
        }
    }

    int st = 0, ed = 10000, ans = -1;
    int mid;
    vsort(vec);
    sz = vec.size();
    while(st <= ed)
    {
        mid = (st + ed)/2;
        if(check(mid, amnt, cst))
        {
            ans = mid;
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }

    return ans;
}


int main()
{
//    freopen("inp.txt", "r", stdin);
    int j,  i;

    int q, n, k, m, num, f, p;
    int t, u, v;
    s2(n, m);
    for(i = 0; i < m; i++)
    {
        s2(u, v);
        V[u].pb(v);
        V[v].pb(u);
    }
    int w;
    s1(w);
    for(i = 0; i < w; i++)
    {
        s1(num);
        ace[num] = 1;
        int tmp;
        s1(tmp);
        store[num].pb(tmp);
        s1(tmp);
        store[num].pb(tmp);
    }
    s1(q);
    int  amnt, cst;
    while(q--)
    {
        s3(p, amnt, cst);
        int ans = BFS(p, (ll)amnt, (ll)cst);
        printf("%d\n", ans);
    }




    return 0;
}

/*


1
ABC
ABC


*/
