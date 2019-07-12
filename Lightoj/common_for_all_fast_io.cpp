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
#define MAX 20009
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

vector<int>V[MAX];
int par[MAX];
int level[MAX];
int sub_size[MAX];

int DFS(int u, int pre)
{
    int cnt = 1;
    int sz = V[u].size();
    par[u] = pre;
    for(int i = 0; i < sz;  i++)
    {
        int ad = V[u][i];
        if(ad != pre)
        {
            level[ad] = level[u] + 1;
            cnt += DFS(ad, u);
        }
    }
return sub_size[u] = cnt;
}

int chain;
int head[MAX];
int position[MAX];
int chainOf[MAX];
int SZ[MAX];

vector<int>store[MAX];


void HLD(int u, int pre)
{
    //    cout<<u<<" "<<pre<<endl;
    if(head[chain] == -1) head[chain] = u;
    chainOf[u] = chain;
    position[u] = SZ[chain];
    store[chain].pb(u);
    SZ[chain]++;
    int ind = -1, mx = 0;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int ad = V[u][i];
        if(ad == pre) continue;
        if(mx < sub_size[ad])
        {
            mx = sub_size[ad];
            ind = i;
        }
    }
    if(ind != -1)
        HLD(V[u][ind], u);
    for(int i = 0; i < sz; i++)
    {
        int ad = V[u][i];
        if(ad == pre) continue;
        if(i == ind) continue;
        chain++;
        HLD(ad, u);
    }
return;
}

int st[MAX];
int id[MAX];
int arr[MAX];

struct Z
{
    int val, lft, rgt;
};

int seg[4*MAX];

void insert(int ind, int st, int ed)
{
    if(st == ed)
    {
        seg[ind] = id[st];
        return;
    }
    int mid = (st + ed)/2;
    insert(ind * 2, st, mid);
    insert(ind * 2 + 1, mid + 1, ed);
    seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}


int query(int ind, int st, int ed, int l, int r)
{
    if(st == l && ed == r) return seg[ind];
    int mid = (st + ed)/2;
    if(r <= mid)
        return query(ind * 2, st, mid, l, r);
    else if(l > mid)
        return query(ind * 2 + 1, mid + 1, ed, l, r);
    else
        return query(ind * 2, st, mid, l, mid) + query(ind * 2 + 1, mid + 1, ed, mid + 1, ed);
}

int cur;

int LCA(int a, int b)
{
    int res = 0;
    while(head[ chainOf[a] ] != head[ chainOf[b] ])
    {
//        cout<<a<<" "<<b<<endl;
        int la = level[ head[chainOf[a] ] ];
        int lb = level[ head[ chainOf[b] ] ];
        if(la > lb)
        {
            int from = st[ chainOf[a] ];
            int to = from + position[a];
            res += query(1, 1, cur, from, to);
            a = par[ head[chainOf[a]] ];
        }
        else
        {
            int from = st[ chainOf[b] ];
            int to = from + position[b];
            res += query(1, 1, cur, from, to);
            b = par[ head[chainOf[b]] ];
        }
    }
    int aa = min( st[chainOf[a]] + position[a], st[chainOf[b]] + position[b]);
    int bb = max( st[chainOf[a]] + position[a], st[chainOf[b]] + position[b]);
    return res + query(1, 1, cur, aa, bb);
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");


    int i,j;
    int t, n,m, cases=1;
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        par[i] = -1;
        head[i] = -1;
    }

    for(i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    int u, v;
    for(i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        V[u].pb(v);
        V[v].pb(u);
    }
    chain = 1;
    int root = 1;
    DFS(root, -1);
    HLD(root, -1);


    for(i =1; i <= n; i++)
        cout<<i<<" "<<chainOf[i]<<endl;


    cur = 1;
    for(i = 1;i <= chain; i++)
    {
        st[i] = cur;
        for(j = 0; j < SZ[i]; j++)
        {
            id[ cur++ ] = arr[ store[i][j] ];
        }
    }
    insert(1, 1, cur);
    int q;
    scanf("%d", &q);
    while(q--)
    {
        scanf("%d %d", &u, &v);
        printf("%d\n", LCA(u, v));
    }

    return 0;
}

/*


4
10 20 30 40
2 1
2 4
3 2
3
2 3


*/
