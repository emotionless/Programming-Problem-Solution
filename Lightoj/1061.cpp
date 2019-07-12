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


///***** Template ends here *****///
///********************* Code starts here ****************************

char ch[10];
int x[10], y[10];
int pos[10];
int tc;

int dp[10][1<<10];
int vis[10][1<<10];

int dist(int r1, int c1, int r2, int c2)
{
    if(r1 == r2 && c1 == c2) return 0;

    if(r1 == r2 || c1 == c2) return 1;
    if(abs(r1 - r2) == abs(c1 - c2)) return 1;
    return 2;
}


int solve(int i, int mask)
{
    if(i == 8) return 0;
    int &ret = dp[i][mask];
    if(vis[i][mask] == tc) return ret;
    ret = MAX;
    vis[i][mask] = tc;

    for(int j = 0; j < 8; j++)
    {
        if(!check_bit(mask, j))
        {
            ret = min(ret,   solve(i + 1, set_bit(mask, j)) + dist(x[i], y[i], j, pos[j]) );
        }
    }
    return ret;
}





bool check(int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        if(pos[i] == c || abs(r - i) == abs(c - pos[i])) return false;
    }
    return true;
}


int BACKTRACK(int r)
{
    if(r == 8)
    {
        tc++;
        int ret = solve(0, 0);
        return ret;
    }
    int mn = MAX;
    for(int i = 0; i < 8; i++)
    {
        if(check(r, i))
        {
            pos[r] = i;
            mn = min(mn,  BACKTRACK(r + 1) );
        }
    }
    return mn;
}

int main()
{
    int i, j, k;
    string str, inp;
    int t, n;
    int cases = 1;
    int num, m;
    int a, b, c;
    scanf("%d", &t);
    while(t--)
    {
        k = 0;
        for(i = 0; i < 8; i++)
        {
            scanf(" %s", ch);
            for(j = 0; j < 8; j++)
            {
                if(ch[j] == 'q')
                    x[k] = i, y[k++] = j;
            }
        }

        int ans = BACKTRACK(0);
        printf("Case %d: %d\n", cases++, ans);
    }
    return 0;
}

/*

1
16
1 2 1
1 5 1
1 6 1
6 7 1
6 8 1
2 4 1
4 9 1
2 3 1
3 12 1
3 10 1
3 11 1
10 16 1
11 13 1
13 14 1
13 15 1

QUERY 9 13




*/
