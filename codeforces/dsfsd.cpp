#include<bits/stdc++.h>

#define mp make_pair
#define vi vector<int>
//#define xx first
//#define yy second
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


#define MX 1000000000000000000ll
#define lim 500000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

char txt1[MAX], pat1[MAX];
int F1[MAX];

void FailureFunction1()
{
    int i = 1, j = 0;
    F1[0] = 0;
    int m = strlen(pat1);
    while(i < m)
    {
        if(pat1[i] == pat1[j])
        {
            F1[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F1[j - 1];
        }
        else
        {
            F1[i] = 0;
            i++;
        }
    }
}

int store1[MAX];

int KMP1()
{
    int i = 0, j = 0;
    int cnt = 0;
    FailureFunction1();
    int n = strlen(txt1);
//    puts(txt1);
    int m = strlen(pat1);
//    puts(pat1);
    while(i < n)
    {
        if(txt1[i] == pat1[j])
        {
            if(j == m - 1)
            {
                cnt++;
                i++;
                j = F1[j];
            }
            else
            {
                i++;
                j++;
            }
            store1[i-1] = j;
        }
        else if(j > 0)
        {
            j = F1[j - 1];
        }
        else
            i++;
    }
    return cnt;
}


char txt[MAX], pat[MAX];
int F[MAX];

void FailureFunction()
{
    int i = 1, j = 0;
    F[0] = 0;
    int m = strlen(pat);
    while(i < m)
    {
        if(pat[i] == pat[j])
        {
            F[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }
}

int store[MAX];

int KMP()
{
    int i = 0, j = 0;
    int cnt = 0;
    FailureFunction();
    int n = strlen(txt);
    int m = strlen(pat);
    while(i < n)
    {
        if(txt[i] == pat[j])
        {
            if(j == m - 1)
            {
                cnt++;
                i++;
                j = F[j];
            }
            else
            {
                i++;
                j++;
            }
            store[i-1] = j;
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
            i++;
    }
    return cnt;
}


int main()
{
//    READ;
//    WRITE;
    int e, i,j,  u, m, v, k, n;
    string str;
    scanf(" %s", txt);
    scanf(" %s", pat);


    KMP();
    int len = strlen(txt);
//    for(i = 0; i < len; i++)
//        cout<<i<<" "<<store[i]<<endl;

    int len2 = strlen(pat);

    for(i  = 0; i < len; i++)
        txt1[i] = txt[i];
    for(i  = 0; i < len2; i++)
        pat1[i] = pat[i];

    reverse(txt1, txt1 + len);
    reverse(pat1, pat1 + len2);

    KMP1();

//    for(i = 0; i < len; i++)
//        cout<<i<<" "<<store1[i]<<endl;


    int cnt = 0;
    for(i = 0; i < len; i++)
    {
        int nxt = len - i - 2;
        int pre = i - 1;
        if(store[i-1]+1 == store[i]) continue;
//        cout<<store[i-1]<<" "<<store[i]<<" "<<nxt<<" "<<store1[nxt]<<endl;
        if((store[i-1]+1 != store[i] && (store[pre] + store1[nxt]) == (len2-1)))
            cnt++;
        else
        {
            int ma = store[i-1];
            int rest = len2 - ma;
            for(j = i + 1; j < i + rest; j++)
            {
//                cout<<j<< " "<<ma+(j-i-1)<<endl;
                if(txt[j] == pat[ma+(j-i-1)]);
                else
                    break;
            }
            if(j == i+rest)
                cnt++;
        }

    }
    cout<<cnt<<endl;







    return 0;
}
/*



5 1
1 2
*/
