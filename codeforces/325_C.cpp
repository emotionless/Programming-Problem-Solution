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
#define MAX 200009
#define INF 100000000

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


ll arr1[MAX];
ll arr2[MAX];
ll arr3[MAX];

int main()
{
//    READ;
//    WRITE;
//    use_cin;
    ll i,  j,k, u, v;
    string str2, str1;
    ll len, n;
    cin>>n;
    ll a, b, c;
    ll pre = 0;
    ll d = 0;
    vector<ll>ans;
    for(i = 0;i < n; i++)
    {
        cin>>arr1[i]>>arr2[i]>>arr3[i];
    }

    for(i = 0;i < n; i++)
    {
        c = arr3[i];
        if(c < 0)
        {
            for(j = i + 1; j < n; j++)
                arr3[j] -= arr2[i];
        }
        else
        {
            ans.pb(i);
            ll tmp = arr1[i];
            for(j = i + 1; j < n; j++){
                arr3[j] -= tmp;
                tmp--;
                if(tmp == 0) break;
            }
        }
    }
    ll sz = ans.size();
    cout<<sz<<endl;
    for(i = 0;i < sz; i++)
        cout<<ans[i]+1<<" ";







    return 0;
}
/*



5 30 50
1 2
2 3
3 4
4 5


9 20 30
1 2
2 3
3 4
4 5
4 8
5 6
5 7
8 9


6 100 500
1 3
2 3
3 4
4 5
4 6



*/
