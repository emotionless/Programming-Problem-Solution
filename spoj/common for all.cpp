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

#define MX 1000000000000000000ll
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

ll dp[103][1<<12][12];
int n;

int M;

ll solve(int ind, int msk, int id, int tmp)
{
//    cout<<ind<<" "<<msk<<" "<<id<<" "<<tmp<<endl;
    if(ind == 0)
    {
        return 1;
    }
//    cout<<msk<<" "<<tmp<<endl;
    ll &ret = dp[ind][msk][id];
//    if(ret!=-1ll)return ret;
    ret = 0;
//    cout<<tmp<<" "<<id<<endl;
    if(id == n)
    {
//        cout<<ind<<" "<<msk<<" "<<id<<" "<<tmp<<endl;
        return ret = solve(ind - 1, tmp, 0, 0);
    }

    if(check_bit(msk, id))
        return ret = solve(ind, msk, id+1, tmp);

    if((id + 2) <= n)
        ret = ret + solve(ind, msk, id + 2, tmp);
    if((ind - 1) > 0)
    ret = ret + solve(ind, msk, id + 1, tmp|(1<<id));
//    cout<<ind<<" "<<msk<<" "<<id<<" "<<tmp<<" "<<ret<<" "<<(tmp|(1<<id))<<endl;
    return ret;
}


int main()
{
    int i, j, k;
    int t, cases = 1;
    t = 100;
    int m;
    while(t--)
    {
        s2(n, m);
        if(n > m) swap(n, m);
        clr(dp, -1);
        ll res = solve(m, 0, 0, 0);
        printf("%lld\n", res);
    }


    return 0;
}
/*

2
5 1
1 2 3 4 5
2 5 10
1 3 2
1 4 1


*/
