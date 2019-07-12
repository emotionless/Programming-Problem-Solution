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
#define lim 200000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

struct Z

{
    int node, cost, cnt, pre;
    Z() {}
    Z(int _, int __, int ___, int ____)
    {
        node = _;
        cost = __;
        cnt = ___;
        pre = ____;
    }
    bool operator <(const Z& A) const
    {
        return cost < A.cost;
    }
};


vector<pii>V[5009];


int pre[5001][5001];

int T;
int n;



int mincost = INT_MAX, best = 0;
ll DIJKSTRA()
{
    priority_queue < Z> PQ;
    PQ.push(Z(1, T, 1, -1));


    while(!PQ.empty())
    {
        Z top = PQ.top();
        PQ.pop();

        int cn = top.node;
        int cc = top.cost;
        int cnt = top.cnt;
        int age = top.pre;

        if(pre[cn][cnt]) continue;
        pre[cn][cnt] = age;

        if(cn == n)
        {
            if(cnt > best)
            {
                best = cnt;
                mincost = cc;
            }
//            else if(cnt == best)
//            {
//                mincost = min(mincost, cc);
//            }
            continue;
        }


        int sz = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int adjn = V[cn][i].xx;
            int adjc = V[cn][i].yy;
            if(adjc <= cc)
            {
                PQ.push(Z(adjn, cc- adjc, cnt+1, cn));
            }
        }
    }
    return best;
}

int take[5009];

int mat[5001][5001];
int main()
{
    int u, v, k, i;
    int  m;
    string str;
    int w;
    s2(n, m);
    scanf("%d", &T);

    for(i = 0; i < m; i++)
    {
        s3(u, v, w);

        V[u].pb(mp(v, w));
        mat[v][u] = w;
    }
    int ans = DIJKSTRA();
    printf("%d\n", ans);
    int x = n;
    int cst = mincost;
    int ind = 0;
    take[ind++] = n;
    while(x != -1)
    {
        v = pre[x][ans];
        take[ind++] = v;
        cst += mat[x][v];
        ans--;
        x=v;
//        cout<<x<<endl;
//        cin.get();
    }
    for(i = ind - 2; i >= 0; i--)
        printf("%d ", take[i]);










    return 0;
}

/*


5 5 200
1 2 100
2 4 100
1 3 1
3 4 1
4 5 1





*/
