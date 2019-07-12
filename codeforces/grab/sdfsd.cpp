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
#define lim 200000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************
int a, l;
char str[100];

ll dp[55][10][10][10][55];

ll solve(int ind, int pre1, int pre2, int pre3, int rest)
{
//    cout<<ind<<" "<<pre1<<" "<<pre2<<" "<<pre3<<" "<<rest<<endl;
    if(rest < 0) return 0ll;
    if(ind == l){
            return 1ll;
    }
    ll &ret = dp[ind][pre1][pre2][pre3][rest];
    if(ret != -1ll) return ret;
    ret = 0ll;
    for(int i = 1; i <= a; i++)
    {
        if(i == 1)
        {
            for(int j = 0; j < 2; j++)
            {
//                if(ind == 1 && pre1 == 0 && pre2 == 1 && rest == 1)
//                {
////                    cout<<"********* "<<(rest - (str[ind]-'a'+1)!=i)<<endl;
//                }
                if(check_bit(pre1, j) == 0)
                {
//                    cout<<"wesdr "<<ind+1<<" "<<set_bit(pre1, j)<<" "<<pre2<<" "<<pre3<<" "<<rest - check_bit(pre1, j)<<endl;
                    ret = (ret +  solve(ind + 1, set_bit(pre1, j), pre2, pre3, (rest - ((str[ind]-'a'+1)!=i)) ))%MOD;
                    break;
                }
            }
        }
        if(i == 2)
        {

            for(int j = 0; j < 2; j++)
            {
                if(check_bit(pre2, j) == 0)
                {
                    ret = (ret +  solve(ind + 1, pre1, set_bit(pre2, j), pre3, (rest - ((str[ind]-'a'+1)!=i)) ))%MOD;
                    break;
                }
            }
        }
        if(i == 3)
        {

            for(int j = 0; j < 2; j++)
            {
                if(check_bit(pre3, j) == 0)
                {
                    ret = (ret +  solve(ind + 1, pre1, pre2, set_bit(pre3, j), (rest - ((str[ind]-'a'+1)!=i)) ))%MOD;
                    break;
                }
            }
        }
    }
//    cout<<ind<<" "<<pre1<<" "<<pre2<<" "<<pre3<<" "<<rest<<" "<<ret<<endl;
    return ret;
}

int main()
{
    int i,  j;
    int N, n=0, t;
    int m, cases = 1, k;
    s1(t);
    while(t--)
    {
        s2(a, k);
        scanf("%s", str);
        l = strlen(str);
        memset(dp, -1ll, sizeof dp);
        ll res = solve(0, 0, 0,0, k);
        printf("%lld\n", res%MOD);
    }


    return 0;
}
/*

1
3 50
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa

650536459


2
1 0
a
2 0
ba



1
3 12
abcabcabcabc

1
3 1
aba


*/
