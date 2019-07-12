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
#define MX 1009
#define mp make_pair

using namespace std;

int Index[MX];
int Lowlink[MX];
bool isStack[MX];
int Stack[MX];
int comp;
int id, top;
vector < int > vec[MX], V[MX];
int components[MX];
int in[MX];
int out[MX];


void tarjan(int u)
{
    Index[u] = Lowlink[u] = (id++);
    Stack[top++] = u;
    isStack[u] = true;

    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = V[u][i];
        if(Index[v] == -1)
        {
            tarjan(v);
            Lowlink[u]= min(Lowlink[u], Lowlink[v]);
        }
        else if(isStack[v])
            Lowlink[u] = min(Lowlink[u], Index[v]);
    }
    int v;
    if(Index[u] == Lowlink[u])
    {
        do
        {
            v = Stack[--top];
            isStack[v] = false;
            components[v] = comp;
        }
        while(u != v);
        comp++;
    }

}
bool vis[MX];
void DFS(int src)
{
    if(vis[src]) return;
    vis[src] = true;
    if(vec[src].size())
        DFS(vec[src][0]);
    return;
}


void findSCC()
{
    top = id = 0;
    comp = 1;
    clr(Index, -1);
    memset(Lowlink, 0x3f, sizeof Lowlink);
    clr(isStack, false);
    clr(components, 0);


    for(int i = 0; i < MX; i++)
    {
        if(V[i].size() && Index[i] == -1)
        {
            tarjan(i);
        }
    }

    for(int i = 0; i < MX; i++)
    {
        //cout<<i<<" "<<components[i]<<endl;
        if(V[i].size())
        {
            int u = i;
            for(int j = 0; j < V[i].size(); j++)
            {
                int v = V[i][j];
                if(components[u] != components[v])
                {
                    vec[components[u]].PB(components[v]);
                    in[components[v]]++;
                    out[components[u]]++;
                    //cout<<components[u]<<" "<<components[v]<<endl;
                }
            }
        }
    }

    DFS(components[0]);

    for(int i = 1; i < comp; i++)
    {
        if(!vis[i] || out[i] > 1 || in[i] > 1)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;


    return;
}


int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m, u, v;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n;
        while(n--)
        {
            cin>>m;
            for(i = 0; i < m; i++)
            {
                cin>>u>>v;
                V[u].PB(v);
            }
        }
        printf("Case %d: ", cases++);
        findSCC();

        for(i = 0; i < MX; i++)
        {
            V[i].clear();
            vec[i].clear();
            in[i] = out[i] = 0;
            vis[i] = false;
        }
    }

    return 0;
}

/*

1
2
5
0 1
1 0
1 2
2 3
3 1
3
4 5
5 6
6 4

*/
