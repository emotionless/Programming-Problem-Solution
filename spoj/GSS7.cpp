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
    int l, r, mx;
};


int sub_size[MAX];
int par[MAX];
int level[MAX];
vector<int>V[MAX];


int DFS(int u, int pre)
{
    int cnt = 1;
    int sz = V[u].size();
    par[u] = pre;
    for(int i = 0; i < sz; i++)
    {
        int ad = V[u][i];
        if(ad != pre)
        {
            level[ad] = level[u] + 1;
            cnt += DFS(ad, u);
        }
    }
    return sub_size[u] = cnt;
}

int head[MAX];
int position[MAX];
int SZ[MAX];
int chain;
int chainOf[MAX];
int id[MAX];
int st[MAX];

vector<int>store[MAX];


void HLD(int u, int pre)
{
//    cout<<"In HLD "<<u<<" "<<pre<<endl;
    if(head[chain] == -1) head[chain] = u;
    chainOf[u] = chain;
    position[u] = SZ[chain];
    store[chain].pb(u);
    SZ[chain]++;
    int ind = -1, mx = 0;
    int sz = V[u].size();

    for(int i = 0; i < sz; i++)
    {
        int ad = V[u][i];
        if(ad == pre) continue;
        if(mx < sub_size[ad])
        {
            mx = sub_size[ad];
            ind = i;
        }
    }
    if(ind != -1)
        HLD(V[u][ind], u);

    for(int i = 0; i < sz; i++)
    {
        int ad = V[u][i];
        if(ad == pre) continue;
        if(i == ind) continue;
        chain++;
        HLD(ad, u);
    }
    return;
}

Z seg[4*MAX];

void insert(int ind, int st, int ed)
{
    if(st == ed)
    {
        seg[ind].l = id[st];
        seg[ind].r = 0;
        seg[ind].mx = id[st];
        return;
    }
    int mid = (st + ed)/2;
    insert(ind * 2, st, mid);
    insert(ind * 2 + 1,  mid + 1, ed);

    int mx = 0;
    mx = max(mx, seg[ind * 2].mx);
    mx = max(mx, seg[ind * 2 + 1].mx);
    mx = max(mx, seg[ind * 2].l + seg[ind * 2].r + seg[ind * 2 + 1].l);
    mx = max(mx, seg[ind * 2].l + seg[ind * 2].r + seg[ind * 2 + 1].l + seg[ind * 2 + 1].r);
    mx = max(mx, seg[ind * 2].r + seg[ind * 2 + 1].l + seg[ind * 2 + 1].r);
    mx = max(mx, seg[ind * 2].r + seg[ind * 2 + 1].l);
    seg[ind].mx = mx;
    seg[ind].l = seg[ind * 2].l + seg[ind * 2].r;
    seg[ind].r = seg[ind * 2 + 1].l + seg[ind * 2 + 1].r;


    return;
}

int arr[MAX];

void update(int ind, int st, int ed, int pos)
{
    if(st == pos && ed == pos)
    {
        seg[ind] = seg[ind]^1;
        return;
    }
    int mid = (st + ed)/2;
    if(pos <= mid)
        update(ind * 2, st, mid, pos);
    else
        update(ind * 2 + 1, mid + 1, ed, pos);
    seg[ind] = seg[ind * 2] + seg[ind * 2 + 1];
}


Z query(int ind, int st, int ed, int l, int r)
{
    if(st == l && ed == r)
    {
        return seg[ind];
    }
    int mid = (st + ed)/2;
    if(r <= mid)
        return query(ind * 2, st, mid, l, r);
    else if(l > mid)
        return query(ind * 2 + 1, mid + 1, ed, l, r);
    else
    {
        Z a = query(ind * 2, st, mid, l, mid);
        Z b = query(ind * 2 + 1, mid + 1, ed, mid + 1, r);
        Z c;
        int mx = 0;
        mx = max(mx, a.mx);
        mx = max(mx, b.mx);
        mx = max(mx, a.l + a.r + b.l);
        mx = max(mx, a.l + a.r + b.l + b.r);
        mx = max(mx, a.r + b.l + b.r);
        mx = max(mx, a.r + b.l);
        c.mx = mx;
        c.l = a.l + a.r;
        c.r = b.l + b.r;
        return c;
    }
}

int cur;




int LCA(int a, int b)
{
    while(head[ chainOf[a] ] != head[ chainOf[b] ])
    {
        int lbla = level[ head[chainOf[a]] ];
        int lblb = level[ head[chainOf[b]] ];
        if(lbla < lblb)
        {
            int p = st[ chainOf[a] ];
            int q = p + position[a];
            mx = max(mx, query(1, 1, n, p, q).mx);
        }


    }

}


int main()
{
//    READ;
//    WRITE;
    int i, j, k;
    string str, inp;
    int t, n;
    int cases = 1;
    int num, m;
    int a, b, c, q, v, u;
//    scanf("%d", &t);
//    while(t--)
    {
        scanf("%d", &n);
        scanf("%d", &q);
        clr(seg, 0);
        for(i = 1; i <= n; i++)
        {
            V[i].clear();

            store[i].clear();
            arr[i] = st[i] = chainOf[i] = SZ[i] = position[i] = head[i] = level[i] = sub_size[i] = 0;
            par[i] = head[i] = -1;

        }

        for(i = 1; i <= n; i++)
            V[i].clear();

        for(i = 1; i < n; i++)
        {
            scanf("%d %d", &u, &v);

            V[u].pb(v);
            V[v].pb(u);
        }
        chain = 1;
        int root = 1;
        DFS(root, -1);

        cur = 1;
        HLD(1, -1);


        for(i = 1; i <= chain; i++)
        {
            st[i] = cur;
            for(j = 0; j < SZ[i]; j++)
            {
                id[cur++] = arr[ store[i][j] ];
            }
        }


        int op;
        insert(1, 1, cur);
        while(q--)
        {
            scanf("%d %d", &op, &a);
            if(op == 1)
                printf("%d\n", LCA(1, a));
            else
            {
                int ps = st[ chainOf[a] ] + position[a];
                update(1, 1, cur, ps);
            }
        }
    }
    return 0;
}

/*

9 8
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8

1 3
0 8
1 6
1 7
0 2
1 9
0 2
1 9

*/
