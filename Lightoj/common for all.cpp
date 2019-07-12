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



///***** fast scan start here.... *****///

/// use input.grabBuffer(); for all input in the first line.

const int maxBufSize = (6000000);

struct Input
{
    int bufSize, bufEnd, bufPos;
    char buffer[maxBufSize];
    void grabBuffer()
    {
        bufSize = (maxBufSize);
        bufPos = 0;
        bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
        buffer[bufEnd] = '\0';
    }
    bool bufEof()
    {
        return bufPos == bufEnd;
    }
    int getChar()
    {
        return buffer[bufPos++];
    }
    void skipWS()
    {
        while ((buffer[bufPos] == '\n' ||
                buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
            bufPos++;
    }
    int rInt()
    {
        int n = 0, x;
        skipWS();
        bool neg=false;
        if (  ( x = getChar() )=='-'  )
        {
            neg=true;
            x=getChar();
        }

        for (; x <= '9' && x >= '0'; x = getChar())
            n = (n << 3) + (n << 1) + (x - '0');
        if ( neg )return -n;
        else return n;
    }
    inline bool isWhiteSpace(char x)
    {
        return x == ' ' || x == '\n' || x == '\t';
    }
    char rChar()
    {
        skipWS();
        return getChar();
    }
} input;



///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define pll pair<ll, ll>

#define MX 1000000000000000000ll
#define lim 30      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

int K;
pll dp[MAX][MAX][MAX][3][7];
int mxone;
bool dig[MAX];
bool ideal[MAX];

pll DFS(int ind, int one, int k, int three, int seven, bool is)
{
    if(ind == -1)
    {
        pll tmp = pll(0, 0);
        if(one <= mxone && k <= K && three==0 && seven)
        {
            tmp.xx = 1;
        }
        return tmp;
    }
    pll ret = dp[ind][one][k][three][seven];
    if(!is && ret.xx != -1ll) return ret;
    ret = pll(0, 0);
    int d, m = is?dig[ind]:1;
    pll tmp;
    tmp = pll(0, 0);
    for(d = 0; d <= m; d++)
    {
        tmp = DFS(ind - 1, one + d, k + (d^ideal[ind]), (2*three+d)%3, (2*seven+d)%7, is&&(d==m));
        ret.xx += tmp.xx;
        ret.yy += tmp.yy;
        if(d)
            ret.yy += tmp.xx*(1<<ind);
    }
    if(!is)
    dp[ind][one][k][three][seven] = ret;
//    cout<<ind<<" "<<one<<" "<<k<<" "<<three<<" "<<seven<<" "<<is<<" "<<ret.xx<<" "<<ret.yy<<endl;
    return ret;
}

ll solve(int x)
{

    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            for(int k = 0; k < MAX; k++)
            {
                for(int p = 0; p < 3; p++)
                {
                    for(int q = 0; q < 7; q++)
                    {
                        dp[i][j][k][p][q].xx = -1ll;
                        dp[i][j][k][p][q].yy = 0ll;
                    }
                }
            }
        }
    }
    int ind = 0;
    while(x)
    {
        dig[ind++] = x&1;
        x=x>>1;
    }
    int tot = 0;
    for(int i = 0; i < 32; i++)
    {
        tot += ideal[i];
    }
//    cout<<tot<<endl;
//    if(tot > K) return 0;
    return DFS(ind - 1, 0, tot, 0, 0, 1).yy;
}


int main()
{
//    READ;
//    WRITE;
    int a, b, t;
//    string str;
    int i, j,  u,s, e, idl, v, x,  cases = 1;
    s1(t);
    while(t--)
    {
        scanf("%d %d %d %d %d", &s, &e, &mxone, &idl, &K);
        for(i = 0; i < 32; i++)
        {
            ideal[i] = idl>>i&1;
//            cout<<ideal[i]<<endl;
        }
        ll ans = solve(e);
        ans = ans - solve(s-1);
        printf("Case %d: %lld\n", cases++, ans);
    }


    return 0;
}
/*


1
11 10
1 0
1 2
2 3
1 4
5 3
4 6
7 3
8 7
1 9
5 10

*/
