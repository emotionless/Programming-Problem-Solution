#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100009
#define mp make_pair

using namespace std;

vector<int>V[MX], R[MX];
bool visited[MX];
vector<int>sortedNode, res;

bool is[MX];

void DFS(int src)
{
   // cout<<src<<endl;
    if(is[src]) return;
    is[src] = true;
    for(int i = 0; i < V[src].size(); i++)
        DFS(V[src][i]);
}

void dfs1 (int x)
{
    visited [x] = true;

    for ( size_t u = 0; u < V [x].size(); u++ )
    {
        if ( !visited [V [x] [u]] )
            dfs1(V [x] [u]);
    }
    sortedNode.push_back(x);
}

void dfs2 (int x, int c)
{
    visited [x] = false;

    res.PB(x);

    for ( size_t u = 0; u < R [x].size(); u++ )
    {
        if ( visited [R [x] [u]] )
            dfs2(R [x] [u], c);
    }
}


struct Z
{
    int node, cnt;
    bool operator < (const Z& A) const
    {
        return cnt < A.cnt;
    }
};

int in[MX];
bool vis[MX];
//bool Onstack[MX];
//int Lowlink[MX];
//int ind[MX];
//int Stack[MX];
//int id, top;

vector<int>st;

//
//void tarjan(int u)
//{
//    int v, i, sz = V[u].size();
//    ind[u] = Lowlink[u] = (id++);
//    Onstack[u] = 1;
//    Stack[top++] = u;
//
//    for(i = 0; i < sz; i++)
//    {
//        v = V[u][i];
//        if(ind[v] == -1)
//        {
//            tarjan(v);
//            Lowlink[u] = min(Lowlink[u], Lowlink[v]);
//        }
//        else if(Onstack[v])
//            Lowlink[u] = min(Lowlink[u], ind[v]);
//    }
//
//    if(Lowlink[u] == ind[u] && u == st)
//    {
//        do
//        {
//            v = Stack[--top];
//            is[v] = true;
//            Onstack[v] = false;
//            DFS(v);
//            cout<<v<<endl;
//        }
//        while(u != v);
//    }
//}
//
//void FINDSCC(int n)
//{
//    id = top = 0;
//    clr(ind, -1);
//    memset(Lowlink, 0x3f, sizeof Lowlink);
//    clr(Onstack, 0);
//
//    for(int i = 1; i <= n; i++)
//        if(ind[i] == -1){
//            st = i;
//            tarjan(i);
//        }
//}

void RUNDFS(int src)
{
    if(vis[src]) return;
    vis[src] = true;
    for(int i = 0; i < V[src].size(); i++)
        RUNDFS(V[src][i]);
}

int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    int u, v;
    vector<Z> vec;
    while(t--)
    {
        cin>>n>>m;
        memset(in, 0, sizeof in);
        for(i = 0; i < m; i++)
        {
            cin>>u>>v;
            V[u].PB(v);
            R[v].PB(u);
            ++in[v];
        }

        for ( int i = 1; i <= n; i++ )
        {
            if ( !visited [i] )
                dfs1 (i);
        }

        int componentId = 0;

        for ( int i = sortedNode.size() - 1; i >= 0; i-- )
        {
            if (visited [sortedNode [i]])
            {
                dfs2(sortedNode [i], ++componentId);
                if(res.size() > 1){
                    for(j = 0; j < res.size(); j++)
                    st.PB(res[j]);

                    DFS(res[0]);
                }
                res.clear();

            }
        }




        Z tmp;
        vector<Z>vec;
        for(i = 1; i <= n; i++)
        {
            if(!is[i])
            {
                tmp.node = i;
                tmp.cnt = in[i];
                vec.PB(tmp);
            }
        }
        sort(vec.begin(), vec.end());

        int sz = vec.size();
        int cnt = 0;
        //cout<<"From normal\n";
        for(i = 0; i < sz; i++)
        {
            u = vec[i].node;
            if(!vis[u])
            {
                //cout<<u<<endl;
                RUNDFS(u);
                cnt++;
            }
        }
        //cout<<"From SCC\n";

        for(i = 0; i < st.size(); i++)
        {
            if(!vis[st[i]])
            {
              //  cout<<i<<endl;
                RUNDFS(st[i]);
                cnt++;
            }
        }
        printf("Case %d: %d\n", cases++, cnt);

        vec.clear();
        clr(is, false);
        clr(vis, false);
        clr(visited, false);
        clr(in, 0);
        st.clear();
        for(i = 0; i <= n; i++)
        {
            V[i].clear();
            R[i].clear();
        }
    }

    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
