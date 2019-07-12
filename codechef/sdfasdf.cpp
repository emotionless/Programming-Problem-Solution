#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0; i--)
#define LL long long
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define vi vector<int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 100009



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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

vector<int>V[MAX];
bool vis[MAX];
bool visited[MAX];
int cost[MAX];
int store[2*MAX];
int asz;

void DFS(int u)
{
    if(u == 1) return;
//    if(vis[u]) return;
    cost[u]++;
    vis[u] = 1;
    store[asz++] = u;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        DFS(V[u][i]);
    }
    return;
}

LL DFS1(int u)
{
    if(visited[u]) return 0;
    visited[u] = 1;
    int ret = 1;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int ad = V[u][i];
        if(cost[ad] == cost[u] && cost[u])
            ret += DFS1(V[u][i]);
    }
    return ret;
}

bool taken[MAX];

LL totalNode(int u)
{
    if(taken[u]) return 0;
    taken[u] = 1;
    int cnt = 1;
    int sz = V[u].size();
    for(int i = 0;i < sz; i++)
    {
        cnt += totalNode(V[u][i]);
    }
return cnt;
}


int main()
{
//    READ;
//    WRITE;

    int i, j, k;
    LL n, m;
    int u, v;
    scanf("%lld %lld", &n, &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        V[u].pb(v);
    }
    int sz = V[1].size();
    for(i = 0; i < sz; i++)
    {
        asz = 0;
        DFS(V[1][i]);
        for(j = 0; j < asz; j++)
            vis[ store[j] ] = 0;
//    cout<<V[1][i]<<endl;
//    for(j = 1; j <= n; j++)
//        cout<<j<<" "<<cost[j]<<endl;

    }
    LL get, res = 0ll;
    for(i = 2; i <= n; i++)
    {
        if(visited[i]) continue;
        get = DFS1(i);
        res += (get * (get - 1))/2ll;
//        cout<<i<<" "<<get<<endl;
    }
    LL tn = totalNode(1ll);
    LL rest = n - tn;
    LL total_con = ((n - 1)*(n))/2ll;
    n = tn;
    LL tot = ((n - 1)*(n))/2ll;
    LL bad = total_con - tot;
    printf("%lld\n", total_con - res - bad);



    return 0;
}

/*

1
cchheeff
5
0 1 0
0 2 1
7 5 2
0 7 0
1 1 2

2 1
2 1



10 11
1 2
1 3
2 4
3 4
4 5
5 6
6 7
7 8
6 9
9 10
3 9


5 4
1 2
1 3
1 4
1 5

3 4
1 2
1 4
2 3
3 4



7 9
1 2
1 3
2 3
3 4
2 4
4 5
6 2
6 7
7 5

*/
