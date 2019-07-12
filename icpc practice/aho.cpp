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

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("D-small-attempt0.in","r",stdin)

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
#define INF 100000000
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

#define MX 10000000000000000ll
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

const int mx = 52;
struct node
{
    int nxt[mx];
    node()
    {
        memset(nxt, -1, sizeof nxt);
    }
};

node T[MAX];
 int fl[MAX], ind[2009], nw, val[MAX], ST[MAX], top;

        void init()
{
    nw = 0;
    top = 0;
    clr(T, 0);
    T[0] = node();
}




char str[MAX];
char tmp[MAX];

int getId(char c)
{
    if(c <= 'Z') return c - 'A';
    return 26 + c - 'a';
}

void Aho(char S[], int pos)
{
    int len = strlen(S);
    int p = 0;
    for(int i = 0; i < len; i++)
    {
        int id = getId(S[i]);
        if(T[p].nxt[id] == -1)
        {
            T[p].nxt[id] = (++nw);
            T[nw] = node();
        }
        p = T[p].nxt[id];
    }
    ind[pos] = p;
}

void failure()
{
    queue<int>Q;
    for(int i = 0; i < mx; i++)
    {
        if(T[0].nxt[i] != -1)
            Q.push(T[0].nxt[i]);
        else
            T[0].nxt[i] = 0;
    }
    fl[1] = 0;
    top = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ST[top++] = u;

        for(int i = 0; i < mx; i++)
        {
            int v = T[u].nxt[i];
            if(T[u].nxt[i] == -1)
            {
                T[u].nxt[i] = T[fl[u]].nxt[i];
                continue;
            }
            fl[v] = T[ fl[u] ].nxt[i];
            Q.push(v);
        }
    }
}

void Search(char tar[])
{
    int p = 0;
    int len = strlen(tar);
    for(int i = 0; i < len; i++)
    {
        int id = getId(tar[i]);
        p = T[p].nxt[id];
        val[p]++;
    }
    for(int i = top - 1; i >= 0; i--)
    {
        int id = ST[i];
        val[fl[id]] += val[id];
    }
    return;
}

int main()
{
//    use_cin;
//    WRITE;
//    READ;
//freopen("inp.txt", "r", stdin);

    int j, k, i;
    int t, a, b,  m;
    int u, v, n;
    scanf("%s", str);
    s1(n);
    nw = 0;
    init();
    for( i = 1; i <= n; i++)
    {
        scanf("%s", tmp);
        Aho(tmp, i);
    }
    failure();
    Search(str);
    for(i = 1; i <= n; i++)
    {
        if(val[ind[i]])
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}

/*




*/

