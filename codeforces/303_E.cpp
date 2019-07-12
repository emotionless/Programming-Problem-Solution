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
#define MAX 300009



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

struct Z
{
    int node, edge;
    LL w, c;
    Z(){}
    Z(int _, LL __, int ___, LL ____)
    {
        node = _;
        w = __;
        edge = ___;
        c = ____;
    }
    bool operator <(const Z& A) const
    {
        if(w == A.w)
            return c > A.c;
        return w > A.w;
    }
};

bool vis[MAX];
LL cost[MAX];
LL edgecost[MAX];

vector<Z>V[MAX];

void DIJKSTRA(int st)
{
    priority_queue<Z>PQ;
    PQ.push(Z(st, 0, 0, 0));
    clr(vis, false);
    while(!PQ.empty())
    {
        Z top = PQ.top();
        PQ.pop();

        int cn = top.node;
        LL cc = top.w;
        int edge = top.edge;
        LL c = top.c;
        if(vis[cn]) continue;

        vis[cn] = 1;

        cost[cn] = cc;
        edgecost[edge] = c;
//        cout<<cn<<" "<<edge<<" "<<cc<<endl;
        int sz = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int adn = V[cn][i].node;
            LL adc = V[cn][i].w + cc;
            int ed = V[cn][i].edge;
            if(!vis[adn]){
                PQ.push(Z(adn, adc, ed, V[cn][i].w));
//                cout<<adn<<" "<<adc<<" "<<ed<<" "<<V[cn][i].w<<endl;
            }
        }
    }
}



int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    string str, inp;
    int  m, t, n;
    int u, v;
    LL w;
    cin>>n>>m;
    for(i = 0; i < m; i++)
    {
        cin>>u>>v>>w;
        V[u].pb(Z(v, w, i, -1));
        V[v].pb(Z(u, w, i, -1));
    }
    int st;
    cin>>st;
    DIJKSTRA(st);
    LL res = 0ll;
    for(i = 0; i < m; i++)
        res += edgecost[i];
    cout<<res<<endl;

    for(i = 0;i < m; i++)
    {
        if(edgecost[i])
            cout<<i + 1<<" ";
    }



    return 0;
}

/*


8
-1 2 3 -4 -5 6 7 -1


*/
