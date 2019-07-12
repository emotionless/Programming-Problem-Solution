///*************** HLD ******************///
/**
Given a tree and each path cost. Determine
the maximum cost from u to v on that path.
**/

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
#define MAX 109

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


///int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
///int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides



///***** Template ends here *****///
///********************* Code starts here ****************************

vector<pii>V[MAX];
int level[MAX];
bool vis[MAX];
int par[MAX];
int sub_size[MAX];

int DFS_FOR_CHAIN(int u, int pre, int lvl)
{
    if(vis[u]) sub_size[u];
    vis[u] = 1;
    int sz = V[u].size();
    int tot = 1;
    par[u] = pre;
    for(int i = 0; i < sz; i++)
    {
        if(V[u][i].xx != pre)
        {
            level[V[u][i].xx] = lvl + 1;
            tot += DFS_FOR_CHAIN(V[u][i].xx, u, lvl + 1);
        }
    }
    return sub_size[u] = tot;
}

int chainNo;            /// total chain
int chainPosition[MAX]; /// position of a node int the chain
int head[MAX];          /// head of the current chain
int chainSize[MAX];     /// Size of the chain
int chainInd[MAX];      /// the chain where the current node belongs to.

vector<int>vec[MAX];

void HLD_CHAIN_BUILD(int cur, int pre)
{
    if(head[chainNo] == -1) head[chainNo] = cur;
    chainInd[cur] = chainNo;
    chainPosition[cur] = chainSize[chainNo];
    chainSize[chainNo]++;
    vec[chainNo].pb(cur);

    int sz = V[cur].size();
    int ind = -1, mx = 0;
    for(int i = 0; i < sz; i++)
    {
        int adjn = V[cur][i].xx;
        if(sub_size[adjn] > mx && adjn != pre)
        {
            mx = sub_size[adjn];
            ind = i;
        }
    }
    if(ind >= 0)
        HLD_CHAIN_BUILD(V[cur][ind].xx, cur);

    for(int i = 0; i < sz; i++)
    {
        if(ind != i)
        {
            int adjn = V[cur][i].xx;
            if(adjn == pre) continue;
            chainNo++;
            HLD_CHAIN_BUILD(adjn, cur);
        }
    }
}

int st[MAX], ed[MAX], id[MAX], seg[4*MAX];
map<pii, int>M;

void insert(int ind, int st, int ed)
{
    if(st == ed)
    {
        seg[ind] = 0;
        return;
    }
    int  mid = (st + ed)/2;
    insert(ind * 2, st, mid);
    insert(ind * 2 + 1, mid + 1, ed);
    seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]);
    seg[ind] = max(seg[ind], M[mp(id[mid], id[mid + 1])]);

    return;
}


void update(int ind, int st, int ed, int pos, int val)
{
    if(st == ed)
    {
        seg[ind] = 0;
        return;
    }
    int mid = (st + ed)/2;
    if(pos <= mid)
        update(ind * 2, st, mid, pos, val);
    else
        update(ind * 2+ 1, mid + 1, ed, pos, val);
    seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]);
    seg[ind] = max(seg[ind], M[mp(id[mid], id[mid + 1])]);
}


pii save[MAX];
int nodeId[MAX];

int Query(int ind, int st, int ed, int l, int r)
{
    if(st == l &&  ed == r)
    {
        return seg[ind];
    }
    int mid = (st + ed)/2;
    if(r <= mid)
        return Query(ind*2, st, mid, l, r);
    else if(l > mid)
        return Query(ind*2 + 1, mid + 1, ed, l, r);
    else
    {
        int a = Query(ind*2, st, mid, l, mid);
        int b = Query(ind*2 + 1, mid + 1, ed, mid + 1, r);
        int ret = max(a, b);
        return max(ret, M[mp(id[mid], id[mid + 1])] );
    }
}


int main()
{
    int i, j, k, t, n, cases = 1, num, m, a, b, c, q;
    string str, inp;
    scanf("%d", &t);
    while(t--)
    {

        scanf("%d", &n);
        int u, v;
        int w;
        for(i = 1; i < n; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            V[u].pb(mp(v, w));
            V[v].pb(mp(u, w));

            M[mp(u, v)] = M[mp(v, u)] = w;
            save[i] = mp(u, v);
        }

        int root = 1;

        level[root] = 1;

        DFS_FOR_CHAIN(root, -1, 1);

        memset(head, -1, sizeof head);
        chainNo = 1;
        HLD_CHAIN_BUILD(root, -1);

        int cur = 1;
        for(i = 1; i <= chainNo; i++)
        {
            st[i] = cur;
            for(j = 0; j < vec[i].size(); j++)
            {
                id[cur++] = vec[i][j];
                nodeId[vec[i][j]] = cur-1;
            }
            ed[i] = cur - 1;
        }
        insert(1, 1, n);

        cin>>q;
        while(1)
        {
            scanf("%s", op);
            if(op[0] == 'D') break;
            scanf("%d %d", &a, &b);
            if(op[0] == 'Q')
            {
                int mx = 0;
                while(head[chainInd[a]] != head[chainInd[b]])
                {
                    int lvla = level[head[chainInd[a]]];
                    int lvlb = level[head[chainInd[b]]];
                    if(lvla > lvlb)
                    {
                        int chind = chainInd[a];
                        int from = head[chind];
                        int to = chainPosition[a];
                        mx = max(mx, Query(1, 1, n, min(nodeId[from], nodeId[a]), max(nodeId[from], nodeId[a])));
                        a = from;
                        mx = max(mx, M[mp(a, par[a])]);
                        a = par[a];

                    }
                    else
                    {
                        int chind = chainInd[b];
                        int from = head[chind];
                        int to = chainPosition[b];
                        mx = max(mx, Query(1, 1, n, min(nodeId[from], nodeId[b]), max(nodeId[from], nodeId[b])));
                        b = from;
                        mx = max(mx, M[mp(b, par[b])]);
                        b = par[b];
                    }
                }
                mx = max(mx, Query(1, 1, n, min(nodeId[b], nodeId[a]), max(nodeId[b], nodeId[a])));

                printf("%d\n",mx);
            }
            else
            {
                pii p = save[a];
                int u = p.xx;
                int v = p.yy;
                M[mp(u, v)] = M[mp(v, u)] = b;
                update(1, 1,n, a, b);
            }

        }
        chainNo = 0;
        M.clear();
        for(i = 1; i <= n; i++)
        {
            V[i].clear();
            vec[i].clear();
            nodeId[i] = 0;
            st[i] = ed[i] = ed[i] = 0;
            chainPosition[i] = 0;
            chainSize[i] = 0;
            head[i] = -1;
            chainInd[i] = -1;
            sub_size[i] = 0;
            par[i] = -1;
            vis[i] = 0;
            level[i] = -1;
        }
        memset(seg, 0, sizeof seg);
    }
    return 0;
}

/**

1
16
1 2 1
1 5 1
1 6 1
6 7 1
6 8 1
2 4 1
4 9 1
2 3 1
3 12 1
3 10 1
3 11 1
10 16 1
11 13 1
13 14 1
13 15 1

QUERY 9 13

**/
