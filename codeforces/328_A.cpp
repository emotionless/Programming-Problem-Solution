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
#define MAX 1000009
#define INF 100000000

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


#define MX 1000000000000000000ll
///***** Template ends here *****///
///********************* Code starts here ****************************

int arr[MAX];

string str[10];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int t;
    int num, cases = 1;
    ll n, a, b;
    cin>>n>>a>>b;
    if(a >= n && b>= n)
    {
        cout<<1<<"/"<<1<<endl;
        return 0;
    }
    double sq = sqrt(n);
    if((double)a > sq && (double)b>sq)
    {
        ll p = min(a, b) - 1ll;
        p = min(p, n);
        ll q = n;
        ll g = __gcd(p, q);
        cout<<p/g<<"/";
        cout<<q/g<<endl;


        return 0;
    }
    ll gg = __gcd(a, b);
    ll lcm = (a*b)/gg;

    ll tot = n/lcm;
    tot--;
    ll xtra = 0ll;
    if((tot * gg + min(a, b) - 1ll ) < n)
        tot++;
    else
    {
        xtra = min(a, b);
    }
    tot = (tot)*min(a, b);
    tot += min(min(a, b) - 1ll, n);
    tot += xtra;
//    cout<<tot<<" "<<n<<endl;

    ll g = gcd(tot, n);
    cout<<tot/g<<"/";
    cout<<n/g<<endl;








    return 0;
}

/*


........
......W.
........
........
........
........
......B.
........


*/
