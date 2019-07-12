/***************************************************************
 *                                                             *
 *             ==>>JU_Bottom_Up                                *
 ***************************************************************/
#include<bits/stdc++.h>
#define PI acos(-1.0)
#define nl puts("")
#define SZ(x) x.size()
#define pb(x) push_back(x)
#define X first
#define Y second
#define pii pair<int,int>
#define pll pair<ul,ul>
#define mpr(a,b) make_pair(a,b)
#define S(a) scanf("%d",&a)
#define P(a) printf("%d",a)
#define SL(a) scanf("%lld",&a)
#define S2(a,b) scanf("%d%d",&a,&b)
#define all(v) v.begin(),v.end()
#define clr(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define fr(i,a,n) for(i=a;i<=n;i++)
#define rf(i,n,a) for(i=n;i>=a;i--)
#define MXE(x) *max_element(all(x))
#define MNE(x) *min_element(all(x))
#define LB(v,k) lower_bound(v.begin(),v.end(),k)
#define _cin ios_base::sync_with_stdio(0),cin.tie(0)
#define ct(x) cerr<<__LINE__<< ":: "<<#x<<"= "<<x<<endl
#define fi(it,n) for(__typeof(n.begin()) it=n.begin();it!=n.end();it++)
using namespace std;
typedef long long ll;
/// if(q1<=l && r<=q2)
/// atoi( str.c_str() ); // char string to int
/// sprintf(str,"%d",num);// num to char string
///int month[]={-1,31,28,31,30,31,30,31,31,30,31,30,31}; //Not Leap Yr
///int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Dir
///int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Dir
///int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight
/************************************************************************
 * /////////////////////////////////////////////////////////////////////*
 ************************************************************************/
/// dgt   01234567
#define MX 10009

vector<int>V[MX];
vector<int>G[MX];

int dp[MX];

void reconstruct(int st)
{
    int i, j, k;
    queue<int>Q;
    Q.push(st);


    bool vis[MX];
    memset(vis, false, sizeof vis);


    while(!Q.empty())
    {
        int cn = Q.front();
        Q.pop();

        if(vis[cn]) continue;

        vis[cn] = true;
        int sz = V[cn].size();
        for(i = 0; i < sz; i++)
        {
            int adjn = V[cn][i];
            if(!vis[adjn])
            {
                G[cn].pb(adjn);
                Q.push(adjn);
            }
        }
    }
}

set<int> next1(int u)
{
    queue<int>Q;
    set<int>S;
    S.clear();
    for(int i = 0; i < G[u].size(); i++)
    {
        Q.push(G[u][i]);
    }
    while(!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        for(int i = 0; i < G[top].size(); i++)
            S.insert(G[top][i]);
    }
    return S;
}

struct Z
{
    int node, t;
};

int fst, snd;

set<int> next2(int u)
{
    queue<Z>Q;
    set<int>S;
    Z tmp;
    tmp.node = u;
    tmp.t = 0;
    S.clear();
    Q.push(tmp);

    bool vis[MX];
    memset(vis, false, sizeof vis);

    while(!Q.empty())
    {
        Z top = Q.front();
        Q.pop();

        int cn = top.node;
        int ct = top.t;
        if(vis[cn]) continue;
        if(ct == 4)
        {
            S.insert(cn);
            continue;
        }

        vis[cn] = true;

        for(int i = 0; i < G[cn].size(); i++)
        {
            int adjn = G[cn][i];
            if(!vis[adjn])
            {
                tmp.node = adjn;
                tmp.t = ct + 1;
                Q.push(tmp);
            }
        }
    }
    return S;
}





int solve(int src)
{
    if(G[src].size() == 0) return 0;
    int &ret = dp[src];
    if(ret != -1) return ret;

    set<int>S = next1(src);
    int a = fst;
    for(set<int>:: iterator it = S.begin(); it != S.end(); it++)
    {
        int top = (*it);
        a += solve(top);
    }
    set<int>S2 = next2(src);
    int b = snd;
    for(set<int>:: iterator it = S2.begin(); it != S2.end(); it++)
    {
        int top = (*it);
        b += solve(top);
    }
    return ret = min(a, b);
}


int deg[MX];

int main()
{
    int i ,j, k;
    int n, a, b;


    while(cin>>n>>fst>>snd && (n || fst || snd))
    {
        memset(deg, 0, sizeof deg);
        for(i = 0; i <= n; i++)
        {
            G[i].clear();
            V[i].clear();
        }
        int u, v;
        for(i = 1; i < n; i++)
        {
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
            V[u].pb(v);
            V[v].pb(u);
        }
        int st = 0;
        for(int i = 1; i <= n; i++)
        {
            if(deg[i] == 1)
                st = i;
        }
        reconstruct(st);

        memset(dp, -1, sizeof dp);

        int res = solve(st);
        cout<<res<<endl;
    }
    return 0;
}

/*
5 50 50
1 2
2 3
3 4
4 5

*/
