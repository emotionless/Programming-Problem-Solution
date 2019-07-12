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
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 100000000
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
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************
int dp[1005][1005];
char A[1005], argdp[1005][1005];
void print(int l, int r)
{
    if(l > r)   return;
    if(l == r)
    {
        putchar(A[l]);
        return;
    }
    if(argdp[l][r] == 1)
    {
        putchar(A[l]);
        print(l+1, r-1);
        putchar(A[r]);
    }
    else if(argdp[l][r] == 2)
    {
        putchar(A[l]);
        print(l+1, r);
        putchar(A[l]);
    }
    else
    {
        putchar(A[r]);
        print(l, r-1);
        putchar(A[r]);
    }
}
void sol(char *A)
{
    int i, j, Alen;
    Alen = strlen(A);
    for(i = 0; i < Alen; i++)
        dp[i][i] = 0, dp[i+1][i] = 0;
    for(i = 1; i <= Alen; i++)
    {
        for(j = 0; j+i < Alen; j++)
        {
            if(A[j] == A[j+i])
            {
                dp[j][j+i] = dp[j+1][j+i-1];
                argdp[j][j+i] = 1;
            }
            else
            {
                if(dp[j+1][j+i] <= dp[j][j+i-1])
                {
                    dp[j][j+i] = dp[j+1][j+i]+1;
                    argdp[j][j+i] = 2;
                }
                else
                {
                    dp[j][j+i] = dp[j][j+i-1]+1;
                    argdp[j][j+i] = 3;
                }
            }
        }
    }
    printf("%d\n", dp[0][Alen-1]);
}

char str[MAX];

int main()
{
    int i, j, k;
    int t, cases = 1;
    s1(t);
    while(t--)
    {
        scanf(" %s", str);
        printf("Case %d: ", cases++);
        sol(str);
    }



    return 0;
}
/*




*/

