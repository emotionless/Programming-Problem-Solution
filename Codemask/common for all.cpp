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


///***** Template ends here *****///
///********************* Code starts here ****************************



bool check(int y)
{
    if(y%100==0)
    {
        if(y%400==0) return true;
        return false;
    }
    if(y%4==0) return true;
    return false;
}

char mon[][20] = { "Baishakh", "Jaishtha", "Ashar", "Sraban", "Bhadra", "Ashwin", "Kartik" ,"Agrahayan", "Poush", "Magh", "Falgun", "Chaitra" };

int main()
{
//    READ;
//    WRITE;
    int a, b;
    int e, i, u, v, k, n, m, d, y, cases = 1;
    int t;
    s1(t);
    while(t--)
    {
        scanf("%d %d %d", &d, &m, &y);
        int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        int bangla[] = {0, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30, 30};

        if(check(y))
            arr[2]++, bangla[11]++;


        int day = 0;
        for(i = 1; i < m; i++)
        {
            day += arr[i];
        }
        day += d;

        bool cros = 0;
        int bd = 17, bm = 9, by = y - 594;
        for(i = 1; i <= day; i++)
        {
            bd++;
            if(bd > bangla[bm])
            {
                bd = 1;
                bm++;
                if(bm > 12)
                    bm = 1, by++;
            }
        }
        printf("Case %d: %d, %s, %d\n", cases++, bd, mon[bm-1], by);

    }
    return 0;
}
/*

10
1 9 2016
Case 1: 17, Bhadra, 1423
14 4 2016
Case 2: 1, Baishakh, 1423
13 4 2016
Case 3: 30, Chaitra, 1422
31 12 2016
Case 4: 17, Poush, 1423
29 2 2016
Case 5: 17, Falgun, 1422



*/
