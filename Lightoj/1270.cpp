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
#define lim 100      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

string mat[101];
string str[101];

ull dp[101][11][1<<8][2];
//map< pair< int, pii> , ull>M;
int n, m;

ull solve(int ind, int r, int cur, bool is)
{
    if(ind == m) return 1ll;
    ull &ret = dp[ind][r][cur][is];
    if(ret != -1ll) return ret;
    ret = 0ll;
    if(r == n)
        return ret = solve(ind + 1, 0, cur, 0);
    int i = r;
    //for(i = 0; i < n; i++)
    if(mat[i][ind] == '#' || check_bit(cur, i))
    {
        int tmp = cur;
        if(is)
            tmp |= (1<<i);
        else
            tmp &= ~(1 << i);
        return ret = solve(ind, r+1, tmp, 0);
    }
    else if(!check_bit(cur, i) && mat[i][ind] == '.')
    {
        // vertical
        if(i+1 < n && !check_bit(cur, i+1) && mat[i+1][ind] == '.')
        {
            int tmp = cur;
            if(is)
            tmp |= (1 << i);
            tmp &= ~(1 << (i+1));
            ret += solve(ind, i+2, tmp, 0);
        }
        // horizontal
        if(ind + 1 < m && mat[i][ind+1] == '.' && !is)
        {
            int tmp = cur;
            tmp = set_bit(tmp, i);
            ret += solve(ind, i+1, tmp, 0);
        }
        // blank top right
        if(i+1 < n && ind+1 < m && !check_bit(cur, i+1) && mat[i+1][ind] == '.' && mat[i+1][ind+1] == '.')
        {
            int tmp = cur;
            if(is)
                tmp |= (1<<i);
            tmp |= (1<<(i+1));
            ret += solve(ind, i+2, tmp, 0);
        }
        // blank bottom right
        if(i+1 < n && ind+1 < m && !check_bit(cur, i+1) && !is && mat[i+1][ind] == '.' && mat[i][ind+1] == '.')
        {
            int tmp = cur;
            tmp ^= (1<<i);
            ret += solve(ind, i+2, tmp, 0);
        }
        // blank top left
        if(i-1 >= 0 && ind+1 < m && !check_bit(cur, i-1) && !is && mat[i-1][ind+1] == '.' && mat[i][ind+1] == '.')
        {
            int tmp = cur;
            tmp ^= (1<<(i-1));
            tmp ^= (1<<(i));
            ret += solve(ind, i + 1, tmp, 0);
        }
        // blank bottom left
        if(ind + 1 < m && i+1 < n && !is && mat[i][ind+1] == '.' && mat[i+1][ind+1] == '.')
        {
            int tmp = cur;
            tmp ^= (1<<i);
//            deb;
            ret += solve(ind, i+1, tmp, 1);
        }
    }

//    cout<<ind<<" "<<r<<" "<<cur<<" "<<ret<<endl;


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
        for(i = 0; i < n; i++)
        {
            cin>>mat[i];
            str[i] = mat[i];
        }

        if(m < n)
        {
            for(i = 0; i < m; i++)
            {
                mat[i] = "";
                for(j = n-1; j >= 0; j--)
                    mat[i]+=str[j][i];
            }
            swap(n, m);
        }

//        M.clear();
        clr(dp, -1ll);
        ull res = solve(0, 0, 0, 0);
        printf("Case %d: %llu\n", cases++, res);
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






*/
