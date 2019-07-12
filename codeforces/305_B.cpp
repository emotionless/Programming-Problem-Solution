#include<bits/stdc++.h>

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
#define eps 1e-9


#define MOD 1000000007
#define MAX 200009



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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

LL arr[MAX];
LL ans[MAX];

int lft[MAX];
int rgt[MAX];

vector<pii>V;

int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    int cases = 1, t;
    int n;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        lft[i] = rgt[i] = i;
    }
    for(i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }

    for(i = n; i >= 1; i--)
    {
        for(j = i + 1; j <= n; j++)
        {
            if(arr[j] < arr[i])
            {
                rgt[i] = j - 1;
                break;
            }
            else
                j = rgt[j];
        }
        if(j == n + 1)
            rgt[i] = n;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = i - 1; j >= 1; j--)
        {
            if(arr[j] < arr[i])
            {
                lft[i] = j + 1;
                break;
            }
            else
                j = lft[j];
        }
        if(j == 0)
            lft[i] = 1;
    }
    V.clear();

    for(i = 1; i <= n; i++)
    {
        V.pb(mp(arr[i], i - lft[i] + rgt[i] - i + 1));
    }
    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    j = 1;
    for(i = 0; i < n; i++)
    {
        LL fst = V[i].xx;
        LL snd = V[i].yy;

        for(; j <= snd; j++)
        {
            ans[j] = fst;
        }
    }
    for(i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    puts("");










    return 0;
}

/*


5 6
......
..xx..
..x...
..xx..
.xxxx.
10
3

5 7
.....x.
.....x.
xxxx.x.
x....x.
x....x.
5
5

5
5 5 4 5 5



*/
