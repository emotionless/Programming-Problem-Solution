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
#define sp printf(" ")
#define nl printf("\n")
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 1000000000
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

//#define mmx 10000000000000000ll
#define lim 300      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************


int cost[MAX][MAX];
int par[MAX];
int st, ed, f;
vector<int>adj[MAX];

void augment(int v, int mmn)
{
    if(v == st)
    {
        f = mmn;
        return;
    }
    else if(par[v] != -1)
    {
        int u = par[v];
        augment(u, min(mmn, cost[u][v]));
        cost[u][v] -= f, cost[v][u] += f;
    }
}


int maxflow(int st, int ed)
{
    int ret = 0;
    while(true)
    {
        for(int i = 0; i < MAX; i++)
            par[i] = -1;
        par[st] = 0;
        queue<int>Q;
        Q.push(st);
        while(!Q.empty())
        {
            int top = Q.front();
            Q.pop();

            if(top == ed) break;
            for(int i = 0; i < adj[top].size(); i++)
            {
                int v = adj[top][i];
                if(cost[top][v] > 0 && par[v] == -1)
                {
                    Q.push(v);
                    par[v] = top;
                }
            }
        }
        f = -1;
        augment(ed, INF);
        if(f==-1) break;

        ret += f;
    }
    return ret;
}

int uuu[100000];
int vvv[100000];
int mmn[100000];
int mmx[100000];

int main()
{
    //freopen("inp.txt", "r", stdin);
    int k,j,  i;
    int a, t, b,n, c,m, cases = 1;
    s1(t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        st = 0, ed = n+1;
        int mini = 0;
        int tt = 0;
        for(i = 0; i  < m; i++)
        {
            s2(uuu[i], vvv[i]);
            s2(mmn[i], mmx[i]);

            if(uuu[i] == 1 && vvv[i] == n)
                tt = mmn[i];

            adj[uuu[i]].pb(vvv[i]);
            adj[vvv[i]].pb(uuu[i]);

            cost[ uuu[i] ][ vvv[i] ] += mmx[i] - mmn[i];
            cost[ vvv[i] ][ uuu[i] ] = 0;

            adj[ st ].pb( vvv[i] );
            cost[ st ][ vvv[i] ] += mmn[i];

            adj[ uuu[i] ].pb( ed );
            cost[ uuu[i] ][ ed ] += mmn[i];
            mini += mmn[i];
        }
        adj[ n ].pb(1);
        cost[ n ][1] = INF;

        int res = maxflow(st, ed);
        printf("Case %d: ", cases++);
        if(res != mini)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
            for(i = 0; i < m; i++)
            {
                int uu = uuu[i];
                int vv = vvv[i];
                if(uu == 1 && vv == n)
                printf("%d\n", tt);
                else
                printf("%d\n", cost[vv][uu]+mmn[i]);
            }
        }
        for(i = 0; i < MAX; i++)
        {
            adj[i].clear();
            for(j = 0; j < MAX; j++)
                cost[i][j] = 0;
        }
    }

    return 0;
}

/*

3

4 5
1 2 3 5
1 3 2 10
3 2 2 5
3 4 2 3
2 4 6 10

4 5
1 2 3 4
1 3 2 3
3 2 2 5
3 4 2 3
2 4 4 10

3 1
1 2 1 1

*/
