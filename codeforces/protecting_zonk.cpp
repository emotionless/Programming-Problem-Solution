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
#define MAX 10009
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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


#define MX 1000000000000000000ll
///***** Template ends here *****///
///********************* Code starts here ****************************

int C1, C2;
vi V[MAX];
vi G[MAX];
int dp[10001][6][6];


int solve(int node, int ind, int ci, int ti)
{

//    cout<<node<<" "<<ind<<" "<<type<<" "<<ci<<" "<<ti<<endl;
    int sz = G[node].size();
    /*

    ci means this ci has been already allocated....

    */

    if(ind >= sz || sz == 0) return 0;

    int v = G[node][ind];

    int &ret = dp[v][ci][ti];
    if(ret != -1) return ret;
    ret = INF;
    ret = solve(node, ind + 1,  ci, ti) + (C1 + solve(v, 0, 1, 3));
    for(int i = ci + 1; i <= ti; i++)
    {
        ret = min(ret, solve(v, 0, ci + 1, ti) );
    }
    if(ci == 3)
    {
        for(int i = ci + 1;  i<= 5; i++)
            ret = min(ret, C2 - C1 + solve(v, 0, i, 5) );
    }

    cout<<node<<" "<<ind<<" "<<ci<<" "<<ti<<" "<<ret<<endl;
    return ret;
}

bool vis[MAX];
void DFS(int u, int par)
{
    int sz = V[u].size();
    vis[u] = 1;
    for(int i = 0; i < sz; i++)
        if(V[u][i] != par)
        {
            G[u].pb(V[u][i]);
            DFS(V[u][i], u);
        }
}



int main()
{
//    READ;
//    WRITE;
//    use_cin;
    int i,  j,k, u, v;
    string str2, str1;
    int len, n;
    while(1)
    {
        s1(n);
        s1(C1);
        s1(C2);
        if(n == 0 && C1 == 0 && C2 == 0) break;

        fr(i, n - 1)
        {
            scanf("%d %d", &u, &v);
            V[u].pb(v);
            V[v].pb(u);
        }
        clr(dp, -1);
        int ans = 0;
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                DFS(i, -1);
                G[0].pb(i);
                ans += C1 + solve(0, 0, 0, 3);
                G[0].clear();
            }
        }
        printf("%d\n", ans);

        for(i = 0; i <= n; i++)
            V[i].clear(), G[i].clear(), vis[i] = 0;


    }


    return 0;
}
/*



9 30 50
1 2
2 4
2 7
1 3
3 5
3 6
4 9
1 8



5 30 50
1 2
2 3
3 4
4 5

9 20 30
1 2
2 3
3 4
4 5
4 8
5 6
5 7
8 9

6 100 500
1 3
2 3
3 4
4 5
4 6


*/
