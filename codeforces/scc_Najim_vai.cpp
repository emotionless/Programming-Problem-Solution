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
//#define MAX (lim+7)
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
#define lim 1000000      /// 10^6

///***** Template ends here *****///
///********************* Code starts here ****************************

int arr[MAX];


const int MAX = 100009;

int Stack[MAX], top;
int Index[MAX], Lowlink[MAX], Onstack[MAX];
int Component[MAX], Outdeg[MAX];
int idx, components;
vector< int > G[MAX];
vector<int>SS[MAX];

void tarjan(int u, int par)
{
    int v, i, sz = G[u].size();
    Index[u] = Lowlink[u] = idx++;
    Stack[top++] = u;
    Onstack[u] = 1;
    for(i = 0; i < sz; i++)
    {
        v = G[u][i];
        if(v == par) continue;
        if(Index[v]==-1)
        {
            tarjan(v, u);
            Lowlink[u] = min(Lowlink[u], Lowlink[v]);
        }
        else if(Onstack[v]) Lowlink[u] = min(Lowlink[u], Index[v]);
    }
    if(Lowlink[u] == Index[u])
    {
        components++;
        do
        {
            v = Stack[--top];
            Onstack[v] = 0;
            Component[v] = components;
        }
        while(u != v);
    }
}
int cost[MAX];

void findSCC(int n)
{
    components = top = idx = 0;
    memset(Index, -1, sizeof Index);
    memset(Onstack, 0, sizeof Onstack);
    memset(Lowlink, 0x3f, sizeof Lowlink);

    for(int i = 1; i <= n; i++) if(Index[i]==-1) tarjan(i, -1);
}

long long modv=1000000007;
int main()
{
    int n, e, i, u, v;
    //freopen("in.txt", "r", stdin);
    //while(scanf("%d", &n) == 1 && n) {
    scanf("%d",&n);
    scanf("%d", &e);
    //for(i = 1; i <= n; i++) G[i].clear();
    for(i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
    }
    findSCC(n);
    //memset(Outdeg, 0, sizeof Outdeg);
    int compNo=1;
    for(u = 1; u <= n; u++)
    {
        compNo=max(compNo,Component[u]);
        SS[Component[u]].push_back(cost[u]);
        //printf("%d %d\n",u,Component[u]);
    }
    cout << components<<endl;

    for(i = 1; i <= n; i++)
        cout<<i<<" "<<Component[i]<<endl;

    //}
    return 0;
}
/*
6 7
1 2
2 3
3 1
2 4
4 5
5 6
6 4

4 4
1 2
1 3
2 3
1 4


*/
