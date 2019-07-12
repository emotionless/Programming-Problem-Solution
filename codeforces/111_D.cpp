#include<bits/stdc++.h>

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

///***** Template ends here *****///
///********************* Code starts here ****************************

struct Z
{
    int u, v, w, ind;

    bool operator <(const Z& A) const
    {
        return w < A.w;
    }
};


int par[MAX];
int res[MAX];

int find(int u)
{
    if(par[u] == u) return u;
    return par[u] = find(par[u]);
}

vector<Z>PQ;
vector<pii>V[MAX];

int comp[MAX];
bool chk[MAX];
int st[MAX], ed[MAX];

int cnt;

void DFS(int u, int pre)
{
    st[u] = ed[u] = cnt++;
    chk[u] = true;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i].first;
        if(v == pre) continue;
        if(!chk[v])
        {
            DFS(v, u);
            ed[u] = min(ed[u], ed[v]);
            if(st[u] < ed[v])
                res[V[u][i].yy] = 2;
        }
        else
            ed[u] = min(ed[u], st[v]);
    }
}






int main()
{
    int i, j, k;
    string str;
    int t, n, m;
    cin>>n>>m;
    Z tmp;
    for(i = 0; i < m; i++)
    {
        cin>>tmp.u>>tmp.v>>tmp.w;
        tmp.ind = i;
        PQ.pb(tmp);
    }
    sort(PQ.begin(), PQ.end());

    for(i = 0; i <= m; i++)
        par[i] = i;

    for(i = 0; i < m; i++)
    {
        j = i;
        while(j < m && PQ[j].w == PQ[i].w) j++;

        for(k = i; k < j; k++)
        {
            int pu = find(PQ[k].u);
            int pv = find(PQ[k].v);
            if(pu != pv)
            {
                V[pu].pb(mp(pv, PQ[k].ind));
                V[pv].pb(mp(pu, PQ[k].ind));
                res[PQ[k].ind] = 1;
            cout<<i<<" "<<k<<" "<<PQ[k].u<<" "<<PQ[k].v<<" "<<pu<<" "<<pv<<endl;

                comp[k] = pu;
            }
        }
        for(k = i; k < j; k++)
        {
            if(!chk[comp[k]] && comp[k])
            {
                cnt = 1, DFS(comp[k], -1);
            }
        }

        for(k = i; k < j; k++)
        {
            int pu = find(PQ[k].u);
            int pv = find(PQ[k].v);
            if(pu != pv)
            {
                par[pu] = pv;
                V[pu].clear();
                V[pv].clear();
                comp[k] = 0;
                chk[pu] = chk[pv] = 0;
            }
        }
        i = j - 1;
    }

    for(i = 0; i < m; i++)
    {
        if(res[i] == 1)
            cout<<"any"<<endl;
        else if(res[i] == 2)
            cout<<"at least one"<<endl;
        else
            cout<<"none"<<endl;
    }

    return 0;
}

/*


6 1
ioi
 2


*/
