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
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************
int n, m;
char str[10][22];
int kase;
int dp[9][22][1<<9][1<<9][2];

int solve(int ind, int r, int mask, int bit, bool is)
{
//    cout<<"******** "<<ind<<" "<<r<<" "<<mask<<" "<<bit<<" "<<is<<" "<<is2<<endl;
    if(ind == m) return 1;
    int &ret = dp[r][ind][mask][bit][is];
    if(ret != -1) return ret;
    ret = 0;
    if(r == n) return ret = solve(ind + 1, 0, mask, bit, 0);
    if(str[r][ind] == '#' || check_bit(mask, r))
    {
        int tmp  = mask;
        int tmp2 = bit;
        tmp &= ~(1<<r);
        if(check_bit(bit, r)){
            tmp |= (1<<r);
            tmp2 &= ~(1<<r);
        }
        if(is)
            tmp2 |= (1<<r);
        ret = (ret + solve(ind, r+1, tmp, tmp2, 0)) % MOD;
    }

    if(!check_bit(mask, r))
    {
//        cout<<"here "<<ind<<" "<<r<<" "<<mask<<" "<<bit<<" "<<is<<" "<<is2<<endl;
        // for L shape
        if(r + 2 < n && ind + 1 < m && !check_bit(mask, r+1) && !check_bit(mask, r+2) && !check_bit(bit, r+2) && str[r+1][ind]=='.' && str[r+2][ind]=='.' && str[r+2][ind+1]=='.')
        {
//            cout <<"Fuck herer: "<<ind<<" "<<r<<" "<<mask<<" "<<bit<<" "<<is<<" "<<is2<<endl;
            int tmp = mask;
            int tmp2 = bit;
            if(check_bit(bit, r))
            {
                tmp |= (1<<r);
                tmp2 &= ~(1<<r);
            }
            if(check_bit(bit, r+1))
            {
                tmp |= (1<<(r+1));
                tmp2 &= ~(1<<(r+1));
            }
            tmp |= (1<<(r+2));
            if(is)
                tmp2 |= (1<<r);

            ret = (ret + solve(ind, r + 3, tmp, tmp2, 0)) % MOD;
        }
        //       .
        // for ... shape
        if(!is && ind + 2 < m && r-1 >= 0 && !check_bit(bit, r-1)&& !check_bit(bit, r) && str[r][ind+1]=='.' && str[r][ind+2]=='.' && str[r-1][ind+2]=='.')
        {
            int tmp = mask;
            tmp |= (1<<r);
            int tmp2 = bit;
            tmp2 |= (1<<(r-1));
            tmp2 |= (1<<(r));
            ret = (ret + solve(ind, r + 1, tmp, tmp2, 0)) % MOD;
        }

        //    ..
        // for . shape
        //     .
        if(r+2 < n && ind + 1 < m && !check_bit(bit, r) && !check_bit(bit, r+1) && !check_bit(bit, r+2) && str[r][ind+1]=='.' && str[r+1][ind+1]=='.' && str[r+2][ind+1]=='.')
        {
            int tmp = mask;
            tmp |= (1<<r);
            int tmp2 = bit;
            if(is)
                tmp2 |= (1<<r);
            tmp2 |= 1<<(r+1);
            tmp2 |= 1<<(r+2);
            ret = (ret + solve(ind, r + 1, tmp, tmp2, 0)) % MOD;
        }

        // for ... shape
        //     .

        if(r+1 < n && ind + 2 < m && !is && !check_bit(mask, r+1) && !check_bit(bit, r) && str[r][ind+1]=='.' && str[r][ind+2] == '.' && str[r+1][ind]== '.')
        {
            int tmp = mask;
            tmp |= (1<<r);
            int tmp2 = bit;
            tmp2 |= (1<<r);
            ret = (ret + solve(ind, r + 2, tmp, tmp2, 0)) % MOD;
        }

        //     .
        // for . shape
        //    ..

//        cout<<"now for here: "<<is<<" "<<is2<<" "<<ind<<" "<<r<<" "<<n<<" "<<m<<" "<<mask<<" "<<str[r][ind+1]<<" df "<<str[r-1][ind]<<" df "<<str[r-2][ind]<<" sdf"<<endl;

        if( r-2 >= 0 && ind+1 < m && !check_bit(bit, r) && !check_bit(mask, r-1) && !check_bit(mask, r-2) && str[r][ind+1] == '.' && str[r-1][ind+1]=='.' && str[r-2][ind+1]=='.')
        {
//            cout<<"gece"<<endl;
            int tmp = mask;
            tmp |= (1<<r);
            tmp |= (1<<(r-1));
            tmp |= (1<<(r-2));

            int tmp2 = bit;
            if(is)
                tmp2 |= (1<<r);

            ret = (ret + solve(ind, r+1, tmp, tmp2, 0)) % MOD;
        }

        // for ... shape
        //       .
        if(!is && r+1 < n && ind+2 < m && !check_bit(bit, r) && !check_bit(bit, r+1) && str[r][ind+1] == '.' && str[r][ind+2]=='.' && str[r+1][ind+2] == '.')
        {
            int tmp = mask;
            tmp |= (1<<r);
            int tmp2 = bit;
            tmp2 |= (1<<r);
            ret = (ret + solve(ind, r+1, tmp, tmp2, 1)) % MOD;
        }

        // for .. shape
        //     .
        //     .
//        cout<<"print "<<is<<" "<<" "<<r<<" "<<n<<" "<<m<<" "<<mask<<" "<<str[r][ind+1]<<" df "<<str[r+1][ind]<<" df "<<str[r+2][ind]<<" sdf"<<endl;
        if(r+2 < n && ind+1 < m && !check_bit(mask, r+1) && !check_bit(mask, r+2) && !check_bit(bit, r) && str[r][ind+1] =='.' && str[r+1][ind]=='.' && str[r+2][ind]=='.')
        {
//            cout<<"sdf"<<endl;
            int tmp = mask;
            tmp |= (1<<r);
            int tmp2 = bit;
            if(is)
                tmp2 |= (1<<r);
            ret = (ret + solve(ind, r + 3, tmp, tmp2, 0)) % MOD;
        }
        //      .
        // for  ... shape
        if(r+1 < n && ind + 2 < m && !check_bit(mask, r+1) && !check_bit(bit, r+1) && str[r+1][ind]=='.' && str[r+1][ind+1]=='.' && str[r+1][ind+2]=='.')
        {
            int tmp = mask;
            int tmp2 = bit;
            if(check_bit(bit, r)){
                tmp |= (1<<r);
                tmp2 &= ~(1<<r);
            }
            if(is)
                tmp2 |= (1<<(r));

            tmp |= (1<<(r+1));
            tmp2 |= (1<<(r+1));
            ret = (ret + solve(ind, r+2, tmp, tmp2, 0)) % MOD;
        }
    }
//    cout<<"return: "<<ind<<" "<<r<<" "<<mask<<" "<<bit<<" "<<is<<" "<<" "<<ret<<endl;
    return ret;
}

string mat[MAX];

int main()
{
//    use_cin;
//    WRITE;
//    READ;

    int i, j, k;
    int t;
    s1(t);
    char ch;
    while(t--)
    {
        s2(n, m);
        for(j = 0; j < n; j++)
        {
            cin>>mat[j];
        }
        int a = n;
        int b = m;
        a = 0;
        for(j = 0; j < m; j++)
        {
            b = 0;
            for(i = n-1; i >= 0; i--)
            {
                str[a][b] = mat[i][j];
                b++;
            }
            a++;
        }
        swap(n, m);

//        kase++;
        clr(dp, -1);
        int res = solve(0, 0, 0, 0, 0);
        cout<<res<<endl;

    }




    return 0;
}

/*

2
3 3
...
.#.
...

*/
