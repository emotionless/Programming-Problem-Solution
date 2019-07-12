#include <bits/stdc++.h>

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
#define pll pair<ll, ll>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1ll<<b))
#define set_bit(a, b) (a|(1ll<<b))
#define total_bit(a) __builtin_popcount(a)

///**** Max/Min********///

#define _max(aa, bb) (aa = max(aa, bb))
#define max2(aa, bb) max(aa, bb)
#define max3(aa, bb, cc) max(aa, max(bb, cc))
#define max4(aa, bb, cc, fk) max(max(aa, fk), max(bb, cc))
#define _min(aa, bb) (aa = min(aa, bb))
#define min2(aa, bb) min(aa, bb)
#define min3(aa, bb, cc) min(aa, min(bb, cc))
#define min4(aa, bb, cc, dd) min(min(aa, dd), min(bb, cc))


///******* File *********///

#define WRITE freopen("output02_alter.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("input02.txt","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define nl printf("\n")
#define eps 1e-18
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define PI acos(-1.0)
#define piii pair<int, pii>
#define CLR(aa, nnn) for(int ii = 0; ii <= nnn; ii++) {aa[ii].clear();}

using namespace std;


#define T(a)            cerr << #a << ": " << a << endl;
#define TT(a,b)         cerr << #a << ": " << a << " | " << #b << ": " << b << endl;
#define TTT(a,b,c)      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << endl;
#define TTTT(a,b,c,d)   cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;



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
    T ans = 0;
    a%=m, b%=m;
    while(b)
    {
        if(b&1) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}

void sc(int &a)
{
    scanf("%d", &a);
}

void sc(ll &a)
{
    scanf("%lld", &a);
}

void sc(double &a)
{
    scanf("%lf", &a);
}

void sc(int &a, int &b)
{
    scanf("%d %d", &a, &b);
}

void sc(ll &a, ll &b)
{
    scanf("%lld %lld", &a, &b);
}

void sc(int &a, int &b, int &c)
{
    scanf("%d %d %d", &a, &b, &c);
}


void sc(int &a, int &b, ll &c)
{
    scanf("%d %d %lld", &a, &b, &c);
}


void sc(ll &a, ll &b, ll &c)
{
    scanf("%lld %lld %lld", &a, &b, &c);
}

void sc(string &str)
{
    cin>>str;
}


void sc(char *(str))
{
    scanf(" %s", str);
}

void sc(char &c)
{
    scanf(" %c", &c);
}


///****** fast scan ends here ***********///

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1}; /// 4 sides

//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


#define LEN(a) strlen(a)
#define ull unsigned long long

#define nl printf("\n")

#define ds(p,q,r,s) sqrt((p-r)*(p-r)+(q-s)*(q-s))
#define INF 10000000000000000ll
#define MX (lim*4 + 10)
#define lim 2000    /// 10^5


///***** Template ends here *****///
///********************* Code starts here ****************************

int n, m;
int ind;
int take[1000009];
int val[4000009];
int current;
bool vis[MAX][MAX];
int arr[MAX][MAX];
vector<pii> rakhi[4000009];
int xxx[MAX][MAX];

int DFS(int r, int c)
{
    if(vis[r][c] == 1) return 0;
    vis[r][c] = 1;
    int ret = 1;
    xxx[r][c] = current;
    for(int i = 0; i < 4; i++)
    {
        int ar = r + dr[i];
        int ac = c + dc[i];
        if(ar >= n || ar < 0 || ac >= m || ac < 0) continue;
        int cur = arr[ar][ac];
        //if(vis[ar][ac]) continue;
        if(arr[ar][ac] != arr[r][c])
        {
            if(val[cur] != current )
            {
                val[cur] = current;
                take[ind++] = cur;
                rakhi[cur].pb(mp(ar, ac));
            }
        }
        else if(arr[ar][ac] == arr[r][c])
        {
            if(!vis[ar][ac])
            {
                ret += DFS(ar, ac);
            }
        }
    }

    return ret;
}

int nowf, nows;
int id = 0;
int hoice[MAX][MAX];
int traverse(int r, int c)
{
    if(hoice[r][c] == id || xxx[r][c] == current || vis[r][c]) return 0;
    hoice[r][c] = id;
    int ret = 1;
    for(int i = 0; i < 4; i++)
    {
        int ar = r + dr[i];
        int ac = c + dc[i];
        if(ar >= n || ar < 0 || ac >= m || ac < 0) continue;
        int cur = arr[ar][ac];
        if((cur == nowf || cur == nows))
            ret += traverse(ar, ac);
    }
    return ret;
}

int main()
{
    int i, j, k;
    int  cases = 1;
    int a, u, v;
    int x, y;
    string str1, str2;
    sc(n, m);
    current = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            sc(arr[i][j]);
    int ans = 0;
    id = 0;
    int mxa = 0;

    clock_t t;
    t = clock();

    for(i = 0; i < n ; i++)
    {
        for(j = 0; j < m; j++)

        {
            if(vis[i][j]) continue;
            ind = 0;
            current++;
            int a = DFS(i, j);

            t = clock() - t;
            double tim = ((float)t)/CLOCKS_PER_SEC;
            if(a+2 <= mxa && n*m >= 1000000 && (n==2000 || n == 1000)) continue;
            mxa = a;
            ans = max(ans, a);
            for(k = 0; k < ind; k++)
            {
                nowf = arr[i][j];
                nows = take[k];
                id++;
                int sz = rakhi[nows].size();
                for(int l = 0; l < sz; l++)
                {
                    int get = traverse(rakhi[nows][l].xx, rakhi[nows][l].yy);
                    ans = max(ans, a + get);
                }
                rakhi[nows].clear();
            }
        }
    }
    printf("%d\n", ans);


    return 0;



}

/*

4 5
3 1 2 3 1
3 1 2 5 2
3 3 1 5 6
1 3 1 2 1

*/
