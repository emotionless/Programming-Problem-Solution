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
#define p1(a) printf("%d ", a)
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
#define lim 1000000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

int arr[MAX];

pii take[MAX];
vi V[MAX];
vector< pii> G[MAX];
vi vec[MAX];

int cost[MAX];

void DFS(int u, int c)
{
    if(cost[u] < c)
        cost[u] = c;
    else
        return;
    int sz = G[u].size();
    for(int i = 0; i < sz; i++)
        DFS(G[u][i].xx, cost[u]+1 + G[u][i].yy);
    return;
}

pii store[MAX];
int len[MAX];
int id;

int DFS_FOR_LEN(int u)
{
    if(len[u]) return len[u];
    len[u] = 1;

    int sz = G[u].size();
    int ret = 0;
    for(int i = 0; i < sz; i++)
        ret = max(ret,  DFS_FOR_LEN(G[u][i].xx) );
    store[id++] = mp(1+ret, u);
//    cout<<u<<" "<<1+ret<<endl;
    return len[u] = 1 + ret;
}


int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    int n, u, v, m;
    int c;
//    cin>>n>>m;
    s2(n, m);
    int ind = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            s1(c);
            V[i].pb(c);
            arr[ind++] = c;
        }
    }
    sort(arr, arr + ind);
    k = 0;
    map<int, int>M;
    for(i = 0; i < ind; i++)
    {
        if(arr[i] != arr[i+1])
        {
            M[arr[i]] = (++k);
        }
    }

    /// by row
    for(i = 0; i < n; i++)
    {
        ind = 0;
        for(j = 0; j < m; j++)
        {
            take[ind++] = mp(M[ V[i][j] ], i*m+j);
            vec[ M[V[i][j] ] ].pb(i*m+j);
//            cout<<  M[ V[i][j] ] <<" "<<i*m+j<<endl;
//            cout<<i*n+j<<endl;
        }
        sort(take, take + ind);
//        cout<<"FOr: "<<i<<endl;
        for(j = 1; j < m; j++)
        {
            if(take[j].xx != take[j-1].xx)
                G[ take[j-1].yy ].pb( mp(take[j].yy, 0 ));
            else
                G[ take[j-1].yy ].pb( mp(take[j].yy, -1 ));
//                cout<<take[j-1].yy<<" "<<take[j].yy<<endl;
        }
    }

    /// by column
    for(i = 0; i < m; i++)
    {
        ind = 0;
        for(j = 0; j < n; j++)
        {
            take[ind++] = mp(M[ V[j][i] ], j*m+i);
        }
        sort(take, take + ind);
        for(j = 1; j < n; j++)
        {
            if(take[j].xx != take[j-1].xx)
                G[ take[j-1].yy ].pb( mp(take[j].yy, 0 ));
            else
                G[ take[j-1].yy ].pb( mp(take[j].yy, -1 ));
        }
    }

    for(i = 0; i < n*m; i++)
        DFS_FOR_LEN(i);
    sort(store, store + id);
    for(i = id - 1; i >= 0; i--)
    {
        DFS(store[i].yy, 1);
    }

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            p1(cost[ i*m+j ]);
        printf("\n");
    }




    return 0;
}
/*

5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 100


*/
