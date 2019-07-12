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
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX 100009

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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


#define MX 1000000000000000000ll
///***** Template ends here *****///
///********************* Code starts here ****************************

bool arr[MAX];
vi V[MAX];
map<pii, int>M;
int mx;
int out[MAX];
int solve(int cn, int pre, int pr)
{
    if(arr[cn])
        pre += arr[cn];
    else
        pre = 0;
    if(pre > mx) return 0;
    pii p= mp(cn, pre);
    if(M.find(p) != M.end())
        return M[p];
    int ret = 0;
    int sz = V[cn].size();
    bool ok = 0;
    for(int i = 0; i < sz; i++)
    {
        if(V[cn][i] != pr)
        {
            ok = 1;
            ret += solve(V[cn][i], pre,cn);
        }
    }
    if(!ok) ret = 1;
//    cout<<cn<<" "<<ret<<endl;
    return M[p] = ret;
}



int main()
{
//    READ;
//    WRITE;
//    use_cin;


    int i,  j,k;
    int n, m, q;
    cin>>n>>mx;
    for(i = 1; i <= n; i++)
        cin>>arr[i];
    int u, v;
    for(i = 0; i < n - 1; i++)
    {
        cin>>u>>v;
        V[u].pb(v);
        V[v].pb(u);
    }
    int res = solve(1, 0, 0);
    cout<<res<<endl;














    return 0;
}
/*

7 1
1 1 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7


2 1
0 0
1 2

*/