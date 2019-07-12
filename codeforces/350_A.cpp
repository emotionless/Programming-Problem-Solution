#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

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
//#define check_bit(a, b) (a&(1<<b))
//#define set_bit(a, b) (a|(1<<b))
//#define total_bit(a) __builtin_popcount(a)
//
//#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
//#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
//#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)

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

using namespace std;

///******* Template ********///
//
//template <class T> inline T bigmod(T p,T e,T M)
//{
//    if(e==0)return 1;
//    if(e%2==0)
//    {
//        T t=bigmod(p,e/2,M);
//        return (t*t)%M;
//    }
//    return (bigmod(p,e-1,M)*p)%M;
//}
//template <class T> inline T gcd(T a,T b)
//{
//    if(b==0)return a;
//    return gcd(b,a%b);
//}
//template <class T> inline T modinverse(T a,T M)
//{
//    return bigmod(a,M-2,M);
//}
//
///**
//return (a * b) % m;
//where a, b, m <= 10^18
//**/
//template <class T> inline T multimod(T a, T b, T m)
//{
//    T ans = 0ll;
//    a%=m, b%=m;
//    while(b)
//    {
//        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
//        b >>= 1ll;
//        a = (m - a)>a?a+a:a+a-m;
//    }
//    return (T)ans;
//}
//
//
/////****** fast scan ends here ***********///
//
////int dr[] = {-1, 0, 1, 0};
////int dc[] = {0, 1, 0, -1}; /// 4 sides
////int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides
//
//#define LEN(a) strlen(a)
//
//#define MX 1000000000000000000ll
#define lim 1000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

vector<int>V[MAX];

bool vis[MAX];
int lvl[MAX];
int par[MAX];
int deg[MAX];

void DFS(int u, int p, int pre)
{
    if(vis[u])
    {
        assert(0);
        return;
    }
    vis[u] = 1;
    par[u] = p;
    lvl[u] = pre;
    for(int i = 0; i < V[u].size(); i++)
        DFS(V[u][i], p,  pre+1);
}

int out[MAX];

int main()
{
    int i, j, k;
    int n, num, m, q;
    int t, nT, v, u;
    s1(t);
    while(t--)
    {
        s1(n);
        clr(par, 0);
        clr(vis, 0);
        clr(lvl, 0);
        clr(deg, 0);
        clr(out, 0);

        for(i = 1; i < n; i++)
        {
            s2(u, v);
            V[u].pb(v);
            deg[v]++;
            out[u]++;
        }
        int a = 0;
        for(i = 1; i <= n ; i++)
        {
            if(deg[i] == 0)
            {
                DFS(i, i, 1);
                a++;
                if(a > 1)
                    assert(0);
            }
        }
        if(a == 0)
            assert(0);

        s1(q);
        for(i = 1; i <= q; i++)
        {
            s2(u, v);
            if(lvl[u] != lvl[v])
                    printf("%d", lvl[u] < lvl[v]?u:v);
            else
                printf("-1");
//            if(i != q)
                printf(" ");
        }
//        printf("\n");

        for(i = 1; i <= MAX; i++)
            V[i].clear();
    }




    return 0;
}


/*


2
table_a
3 3
id_a a1 a2
1 2 3
2 4 5
3 6 7
table_b
3 3
id_b b1 b2
1 2 9
2 10 5
3 12 7
1
SELECT * FROM table_a JOIN table_b ON table_a.a1 = table_b.b1
SELECT * FROM table_a ta JOIN table_b tb ON ta.a2 = tb.b2
SELECT ta.a1, ta.a2, tb.b1 FROM table_a ta JOIN table_b tb ON ta.a2 = tb.b2


*/
