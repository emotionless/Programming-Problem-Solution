#include<bits/stdc++.h>

using namespace std;


#define MAX  100009

int Stack[MAX], top;
int Index[MAX], Lowlink[MAX], Onstack[MAX];
int idx, components;
vector< int > G[MAX];
bool ok;
bool vis[MAX];
int have;
vector<int>V[MAX];
bool taken[MAX];
int comp[MAX];

void DFS(int u)
{
    if(vis[u]) return;
    vis[u] = true;
    have++;
    if(taken[comp[u]]) ok = true;
    for(int i = 0; i < V[u].size(); i++)
    {
        if(!vis[V[u][i]])
            DFS(V[u][i]);
    }
}

vector<int>sc[MAX];
void tarjan(int u)
{
    int v, i, sz = G[u].size();
    Index[u] = Lowlink[u] = idx++;
    Stack[top++] = u;
    Onstack[u] = 1;
    for(i = 0; i < sz; i++)
    {
        v = G[u][i];
        if(Index[v]==-1)
        {
            tarjan(v);
            Lowlink[u] = min(Lowlink[u], Lowlink[v]);
        }
        else if(Onstack[v]) Lowlink[u] = min(Lowlink[u], Index[v]);
    }
    if(Lowlink[u] == Index[u])
    {
        components++;
        int cnt = 0;
        do
        {
            cnt++;
            v = Stack[--top];
            Onstack[v] = 0;
            comp[v] = components;
        }
        while(u != v);
        if(cnt > 1)
        {
            taken[components] = true;
        }

    }
}
int cost[MAX];
int tot;


int res;
vector<int> st;
void findSCC(int n)
{
    components = top = idx = 0;
    memset(Index, -1, sizeof Index);
    memset(Onstack, 0, sizeof Onstack);
    memset(Lowlink, 0x3f, sizeof Lowlink);

    for(int i = 0; i < st.size(); i++)
    {
        have = 0;
        if(Index[st[i]]==-1)
        tarjan(st[i]);
    }

}
bool is[MAX];
int in[MAX];
int out[MAX];
int main()
{
    int n, e, i, u, v;
    scanf("%d",&n);
    scanf("%d", &e);
    for(i = 0; i < e; i++)
    {
        scanf("%d %d", &u, &v);
        G[u].push_back(v);
        V[u].push_back(v);
        V[v].push_back(u);
        is[u] = is[v] = true;
        out[u]++;
        in[v]++;
    }
    for(i = 1; i <= n; i++)
    {
        if(out[i])
        {
            st.push_back(i);
        }
    }
    findSCC(n);
    for(i = 1; i <= n; i++)
    {
        if(is[i] && !vis[i])
        {
            ok = false;
            have = 0;
            DFS(i);
            if(ok)
                res += have;
            else
                res += (have - 1);
//            cout<<i<<" "<<res<<endl;
        }
    }
    cout<<res<<endl;




    return 0;
}

/*


8 12
6 1
7 5
2 5
4 1
6 3
4 3
5 7
1 3
5 2
2 7
4 6
7 2




*/
