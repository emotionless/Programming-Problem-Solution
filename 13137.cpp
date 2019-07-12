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
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 10000000000000
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

#define MX 10000000000000000ll
#define lim 1000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************


int dp[1001][1001];
int arr[1001][1001];

int m, n;
int area[MAX];
int histogram(int r)
{
    int t;
    stack<int>ST;
    for(int i = 1; i <= m; i++)
    {
        while(!ST.empty())
        {
            if(dp[r][i] <= dp[r][ST.top()] && (arr[r][i] - arr[r][ST.top()]) == (i-ST.top()))
                ST.pop();
            else break;
        }
        if(ST.empty())
            t = 0;
        else
            t = ST.top();
        area[i] = i-t-1;
        ST.push(i);
    }

    while(!ST.empty())
    {
        ST.pop();
    }
    for(int i = m; i > 0; i--)
    {
        while(!ST.empty())
        {
            if(dp[r][i] <= dp[r][ST.top()] && (arr[r][ST.top()] - arr[r][i])== (ST.top() - i))
                ST.pop();
            else
                break;
        }
        if(ST.empty())
            t = m+1;
        else
            t = ST.top();
        area[i] += (t-i-1);
        ST.push(i);
    }
    int mx = 1;
    for(int i = 1; i <= m; i++)
    {
        int how = area[i]+1;

        int sizzz = dp[r][i];
        int tmp = (sizzz*how);
        mx = max(mx, tmp);
    }
    return mx;
}



int main()
{
//    use_cin;
//    WRITE;
//    READ;
    int t,  i,k, j;
    int a, c,  x, q;
    while(s2(n,m)==2)
    {
        for(i = 1; i <= n; i++)
        {
            for(j = 1; j <= m; j++)
            {
                s1(arr[i][j]);
                if(arr[i-1][j]+1 == arr[i][j])
                    dp[i][j] = dp[i-1][j] + 1;
                else
                    dp[i][j] = 1;
            }
        }
        int res = 0;
        for(i = 1; i <= n; i++)
        {
            int get = histogram(i);
            res = max(res, get );
        }
        printf("%d\n", res);

    }
    return 0;
}

/*

4 7
3 4 5 6 7 8 9
5 4 2 7 8 9 10
6 3 1 8 9 11 11
7 4 2 9 11 10 12


5 5
5 1 2 4 5
3 3 3 1 1
1 2 1 4 2
3 5 5 5 3
4 2 4 5 1

5 5
5 1 2 4 5
3 3 3 1 1
1 2 1 4 2
3 5 5 5 3
4 2 4 5 1

5 5
5 1 2 4 5
3 3 3 1 1
1 2 1 4 2
3 5 5 5 3
4 2 4 5 1

5 5
5 1 2 4 5
3 3 3 1 1
1 2 1 4 2
3 5 5 5 3
4 2 4 5 1

5 5
5 1 2 4 5
3 3 3 1 1
1 2 1 4 2
3 5 5 5 3
4 2 4 5 1


*/
