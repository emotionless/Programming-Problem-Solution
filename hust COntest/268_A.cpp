#include <bits/stdc++.h>

#define LL long long
#define MX 100009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define pi pair<int, int>
#define ll long long
#define MOD 1000000007ll
#define check(aa , bb) (aa & (1<<bb))

#define PI 3.14159265358979323846264338328

using namespace std;

struct Z
{
    int u, v;
    int id;
    Z() {}
    Z(int _, int __, int ___)
    {
        u = _;
        v = __;
        id = ___;
    }
};


int par[MX];
int ranking[MX];

vector<Z>V[1000009];
vector<int>adj[MX];
int n, m;
bool vis[MX];
int taken[MX];
int find(int x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y)
{
    if(ranking[x] > ranking[y])
        par[y] = x;
    else
    {
        par[x] = y;
        if(ranking[x] == ranking[y])
            ranking[y]++;
    }
}


void init(){
    for(int i=0;i<=n;i++)
        par[i] = i;
}

int traverse[MX];
int mn[MX];
int node;
void DFS(int u, int par)
{
     //cout<<u<<" "<<par<<endl;
    traverse[u]= mn[u] = (++node);

    vis[u] = true;

    for(int i = 0; i < adj[u].size(); i+=2)
    {
        int v = adj[u][i];
        int id = adj[u][i + 1];
        if(!vis[v])
        {
            DFS(v, id);
            mn[u] = min(mn[u], mn[v]);

            if(mn[v] > traverse[u])
                taken[id] = 2;
        }
        else if(id != par)
            mn[u] = min(mn[u], traverse[v]);
    }
}



void MST(int low, int high)
{
    init();
    vector<int>store;

    for(int k = low; k <= high; k++)
    {
       // cout<<endl<<k<<endl;
        for(int i = 0; i < V[k].size(); i++)
        {
            int u = find(V[k][i].u);
            int v = find(V[k][i].v), id = V[k][i].id;
//            cout<<V[k][i].u<<" "<<V[k][i].v<<endl;
//            cout<<u<<" "<<v<<endl;
            if(u != v)
            {
                adj[u].PB(v);
                adj[u].PB(id);

                adj[v].PB(u);
                adj[v].PB(id);

                vis[u] = vis[v] = false;

                traverse[u] = traverse[v] = mn[u] = mn[v] = 0;

                store.PB(u);
                store.PB(v);
            }
            else{
                taken[id] = 3;
                //cout<<id<<endl;
            }
        }
        node = 0;

        for(int i = 0; i < store.size(); i++)
        {
            if(!vis[store[i]])
                DFS(store[i], -1);
        }


        for(int i = 0; i < V[k].size(); i++)
        {
            int u = find(V[k][i].u);
            int v = find(V[k][i].v);
            int id = (V[k][i].id);

            if(u != v)
            {
                if(taken[id] < 2)
                    taken[id] = 1;
            }
        }

        for(int i = 0; i < V[k].size(); i++)
        {
            int u = find(V[k][i].u);
            int v = find(V[k][i].v);
            int id = find(V[k][i].id);

            if(u != v)
            {
                Union(u, v);
            }
        }
        for(int i = 0; i < store.size(); i++)
            adj[store[i]].clear();
        store.clear();
    }

}

int main()
{
    int i, j, k;

    int t;

    cin>>n>>m;
    int u, v, w;
    int low = 10000000, high = -1;
    for(i = 1; i <= m; i++)
    {
        cin>>u>>v>>w;
        V[w].PB(Z(u, v, i));
        low = min(low, w);
        high = max(high, w);
    }
    MST(low, high);

    for(i = 1; i <= m; i++)
    {
        if(taken[i] == 1) cout<<"at least one"<<endl;
        else if(taken[i] == 2) cout<<"any"<<endl;
        else cout<<"none"<<endl;
    }


    return 0;
}

/*



3 -1
4 5
2 -1
4 3
1 -1
4 2

*/
