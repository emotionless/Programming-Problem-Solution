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
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<LL, LL>
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


#define MOD 1000007

#define MAX 10009
#define MAXLG 20
#define inf 100000

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
int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************

int Stack[MAX], top;
int Index[MAX], Lowlink[MAX], Onstack[MAX];
int Component[MAX], Outdeg[MAX];
int idx, components;
vector< int > G[MAX];


int take[MAX];
bool cango[MAX];

bool vis[MAX][2];
bool finish[MAX][2];

void BFS(int u)
{
    queue<pii>Q;
    Q.push(mp(u, 0));
    memset(vis, false, sizeof vis);
    while(!Q.empty())
    {
        pii top = Q.front();
        Q.pop();

        int cn = top.xx;
        int cc = top.yy;
        if(vis[cn][cc]) continue;
        vis[cn][cc] = 1;
        finish[cn][cc] = 1;
        int sz = G[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int v = G[cn][i];
            if(cango[v])
                Q.push(mp(v, cc^1));
        }
    }
    return;
}


void tarjan(int u, int p)
{
    int v, i, sz = G[u].size();
    Index[u] = Lowlink[u] = (++idx);
    Stack[top++] = u;
    Onstack[u] = 1;
    for(i = 0; i < sz; i++)
    {
        v = G[u][i];
        if(v == p) continue;
        if(Index[v] == -1)
        {
            tarjan(v, u);
            Lowlink[u] = min(Lowlink[u], Lowlink[v]);
        }
        else if(Onstack[v]) Lowlink[u] = min(Lowlink[u], Index[v]);
    }
    int ind = 0;
    if(Lowlink[u] == Index[u])
    {
        components++;
//        cout<<"For "<<components<<endl;
        do
        {
            v = Stack[--top];
            Onstack[v] = 0;
            cango[v] = 1;
            take[ind++] = v;
//            cout<<v<<endl;
        }
        while(u != v);
        BFS(u);
        for(i = 0; i < ind; i++)
            cango[ take[i] ] = 0;
    }
    return;
}



void findSCC(int n)
{
    components = top = idx = 0;
    memset(Index, -1, sizeof Index);
    memset(Onstack, 0, sizeof Onstack);
    memset(Lowlink, 0x3f, sizeof Lowlink);

    for(int i = 0; i < n; i++) if(Index[i]==-1)
        {
//            cout<<"Go "<<i<<endl;
            tarjan(i, -1);
        }
}



int main()
{
//    READ;
//    WRITE;
//    use_cin;
    int i, j, type;
    int  a, b, t, cases = 1;
    scanf("%d", &t);
    int m;
    int u, v, w, n;
    while(t--)
    {
        clr(finish, false);

        scanf("%d %d", &n, &m);
        for(i = 0; i <= n; i++)
        {
            G[i].clear();
            cango[i] = 0;
        }

        idx = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            G[u].pb(v);
            G[v].pb(u);
        }
        findSCC(n);
        int cnt = 0;
        for(i = 0; i < n; i++)
        {
            if(finish[i][0] == 1 && finish[i][1] == 1)
                cnt++;
        }
        printf("Case %d: %d\n", cases++, cnt);
    }

    return 0;
}

/*


7 7
1 2
2 3
3 1
2 4
4 5
5 6
6 4

1
9 10
0 1
1 2
2 3
3 4
4 5
5 6
6 0
0 8
8 7
0 7


*/
