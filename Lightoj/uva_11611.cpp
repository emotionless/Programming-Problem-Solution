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
#define MOD 50431
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
#define lim 100      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

int dp[9][20][1<<9][2];
char str[12][22];
int n, m;

int solve(int ind, int r, int mask, bool is)
{
//    cout<<ind<<" "<<r<<" "<<mask<<" "<<is<<endl;
    if(ind == m) return 1;
    int &ret = dp[r][ind][mask][is];
    if(ret != -1) return ret;
    ret = 0;
    if(r == n) return ret = solve(ind + 1, 0, mask, 0);
    if(str[r][ind] == '#' || check_bit(mask, r))
    {
        int tmp = mask;
        if(is)
            tmp |= (1<<r);
        else
            tmp &= ~(1<<r);
        return ret = solve(ind, r + 1, tmp, 0);
    }

    if(!check_bit(mask, r))
    {
        // blank top right
        if(r+1 < n && ind+1 < m &&  !check_bit(mask, r+1) && (str[r][ind] == '.' || str[r][ind] == 'R') && (str[r+1][ind] == '.' || str[r+1][ind] == 'R') && (str[r+1][ind+1] == '.' || str[r+1][ind+1] == 'R'))
        {
            int tmp = mask;
            if(is)
                tmp |= (1<<(r));
            tmp |= (1<<(r+1));
            ret = (ret + solve(ind, r + 2, tmp, 0)) % MOD;
        }
        // blank top left
        if(r-1 >= 0 && ind+1 < m && !is && !check_bit(mask, r-1) && (str[r][ind] == '.' || str[r][ind] == 'G') && (str[r-1][ind+1] == '.' || str[r-1][ind+1] == 'G') && (str[r][ind+1] == '.' || str[r][ind+1] == 'G'))
        {
            int tmp = mask;
            tmp |= (1<<(r-1));
            tmp |= (1<<r);
            ret = (ret + solve(ind, r+1, tmp, 0)) % MOD;
        }
        // blank bottom right
        if(r + 1 < n && ind + 1 < m && !is && !check_bit(mask, r+1) && (str[r][ind] == '.' || str[r][ind] == 'B') && (str[r+1][ind] == '.' || str[r+1][ind] == 'B') && (str[r][ind+1] == '.' || str[r][ind+1] == 'B'))
        {
            int tmp = mask;
            tmp |= (1<<r);
            ret = (ret + solve(ind, r + 2, tmp, 0)) % MOD;
        }
        // blank bottom left
        if(!is && r+1 < n && ind+1 < m && (str[r][ind] == '.' || str[r][ind] == 'N') && (str[r][ind+1] == '.' || str[r][ind+1] == 'N') && (str[r+1][ind+1] == '.' || str[r+1][ind+1] == 'N'))
        {
            int tmp = mask;
            tmp |= (1<<r);
            ret = (ret + solve(ind, r + 1, tmp, 1)) % MOD;
        }
        // by 2*1 tile
        if(r+1 < n && !check_bit(mask, r+1) && (str[r][ind] == '.' || str[r][ind] == 'W') && (str[r+1][ind] == '.' || str[r+1][ind] == 'W') )
        {
            int tmp = mask;
            if(is)
                tmp |= (1<<r);
            ret = (ret + solve(ind, r + 2, tmp, 0)) % MOD;
        }
        // by 1*2 tile
        if(ind + 1 < m && !is && (str[r][ind] == '.' || str[r][ind] == 'P') && (str[r][ind+1] == '.' || str[r][ind+1] == 'P'))
        {
            int tmp = mask;
            tmp |= (1<<r);
            ret = (ret + solve(ind, r + 1, tmp, 0)) % MOD;
        }
        // by 1*1 tile
        if((str[r][ind] == '.' || str[r][ind] == 'L'))
        {
            int tmp = mask;
            if(is)
                tmp |= (1<<r);
            ret = (ret + solve(ind, r + 1, tmp, 0)) % MOD;
        }
    }
//    cout<<ind<<" "<<r<<" "<<mask<<" "<<is<<" "<<ret<<endl;
    return ret;
}



int main()
{
//    use_cin;
//    WRITE;
//    READ;

    int i, j, k;
    int t, cases = 1;

    scanf("%d", &t);
    while(t--)
    {
        s2(n, m);
        for(i = 0; i < n; i++){
            scanf(" %s", str[i]);
//            puts(str[i]);
        }
        clr(dp, -1);
        int res = solve(0, 0, 0, 0);
        printf("Case %d: %d\n", cases++, res);
    }





    return 0;
}

/*

3
2 3
...
...
2 3
..#
..#
5 5
.....
.#...
.....
.....
.....


1
5 5
.....
.#...
..#..
.....
.....

out: 2635


3

3 3
...
...
...

1 4
..#.

2 2
..
N.



*/
