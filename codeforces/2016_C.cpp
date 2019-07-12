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
#define pll pair<ll, ll>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1ll<<b))
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
#define eps 1e-12
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 1000000000000000000ll
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

#define MX 10000000000000000ll
#define lim 200000      /// 10^5
#define M 1007


///***** Template ends here *****///
///********************* Code starts here ****************************

int loss[MAX];
int dv[MAX];
int n;
int solve(ll num)
{
    int i;
    ll cn = num;
    for(i = n-1; i >= 0; i--)
    {
        cn -= loss[i];
        if(cn < 1900 && dv[i] == 2) continue;
        if(cn >= 1900 && dv[i] == 1) continue;

        if(dv[i] == 1) return 1;
        else return -1;

    }
    return 0;
}


int main()
{
    int  e, i, u, v, w, ind;
    int cases = 1;
    int a, b,j,  c,  d, t, q, x, y;
    string str;

    s1(n);
    for(i = 0; i < n; i++)
        s2(loss[i], dv[i]);

    ll st = -1000000000, ed = 1000000000, mid;
    ll res = st - 1;

    while(st <= ed)
    {
        mid = (st + ed)/2;
        int get = solve(mid);
//        cout<<mid<<" "<<get<<endl;
        if(get == 0)
        {
            res = max(res, mid);
            st = mid + 1;
        }
        else if(get == -1)
        {
            ed = mid - 1;
        }
        else
            st = mid + 1;
    }
    if(res == -1000000001)
        printf("Impossible\n");
    else if(res == 1000000000)
        printf("Infinity\n");
    else
        printf("%lld\n", res);










    return 0;
}
/*


6 5
6 30 105 42 35 70
1 2
1 3
2 4
2 5
3 6
4 6
5 6
1 1
1 6
6 1

*/

