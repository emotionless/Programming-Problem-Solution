#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <limits>
#define MAX 101
using namespace std;

enum colors {BLACK, WHITE, GRAY};
int color[MAX], d[MAX], p[MAX], f[MAX], t, vertex, edge, forest;
int NIL = numeric_limits<int>::min();

vector<int> sccVertex;
list<int> orderedList;
list<int>::iterator it;

void STRONGLY_CONNECTED_COMPONENTS(vector<int>[],vector<int>[]);
void DFS(vector<int>[]);
void DFS_VISIT(vector<int>[],int);
void DFS_GT(vector<int>[]);
void DFS_VISIT_GT(vector<int>[],int);

int main(void)
{
    //freopen("scc.txt", "r", stdin);
    vector<int> G[MAX];
    vector<int> GT[MAX];
    G[MAX].clear();
    int u, v;
    cin >> vertex >> edge;
    for(int e=1; e<=edge; e++)
    {
        cin >> u >> v;
        G[u].push_back(v);
        GT[v].push_back(u);
    }
    STRONGLY_CONNECTED_COMPONENTS(G,GT);
    return 0;
}

void STRONGLY_CONNECTED_COMPONENTS(vector<int> G[], vector<int> GT[])
{
    DFS(G);
//   while(!orderedList.empty())
//    {
//        int top=orderedList.front();
//        orderedList.pop_back();
//        cout<<top<<" ";
//    }
    DFS_GT(GT);
}

void DFS(vector<int> G[])
{
    for(int u=0; u<=vertex; u++)
    {
        color[u] = WHITE;
        p[u] = NIL;
    }
    t = 0;
    for(int u=1; u<=vertex; u++)
    {
        if(color[u] == WHITE)
        {
            DFS_VISIT(G,u);
        }
    }
}

void DFS_VISIT(vector<int> G[], int u)
{
    t = t + 1;
    d[u] = t;
    color[u] = GRAY;
    for(int v=0; v<G[u].size(); v++)
    {
        if(color[G[u][v]] == WHITE)
        {
            p[G[u][v]] = u;
            DFS_VISIT(G,G[u][v]);
        }
    }
    color[u] = BLACK;
    t = t + 1;
    f[u] = t;
    orderedList.push_front(u);
}

void DFS_GT(vector<int> G[])
{
    for(int u=0; u<=vertex; u++)
    {
        color[u] = WHITE;
        p[u] = NIL;
    }
    t = 0, forest = 0;
    int flag = orderedList.size()-1;
    for(it=orderedList.begin(); it != orderedList.end(); ++it)
    {
        if(color[*it] == WHITE)
        {
            cout<<(*it)<<" ";
            DFS_VISIT_GT(G,*it);
            forest++;
            sort(sccVertex.rbegin(), sccVertex.rend());
            while( !sccVertex.empty())
            {
                cout << sccVertex.back();
                sccVertex.pop_back();
            }
            cout<<endl;
        }
    }
    cout << endl;
}

void DFS_VISIT_GT(vector<int> G[], int u)
{
    t = t + 1;
    d[u] = t;
    color[u] = GRAY;
    for(int v=0; v<G[u].size(); v++)
    {
        if(color[G[u][v]] == WHITE)
        {
            p[G[u][v]] = u;
            DFS_VISIT_GT(G,G[u][v]);
        }
    }
    color[u] = BLACK;
    t = t + 1;
    f[u] = t;
    sccVertex.push_back(u);
}
