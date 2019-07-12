#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <limits>
#define MAX 101
using namespace std;

enum colors {BLACK, WHITE, GRAY};
int color[MAX], d[MAX], p[MAX], f[MAX], low[MAX], t, vertex, edge;
int NIL = numeric_limits<int>::min();
bool backEdge[MAX][MAX];

list<int> articPoints;
list<int>::iterator it;

void ARTICULATION_POINTS(vector<int>[]);
void DFS(vector<int>[]);
void DFS_VISIT(vector<int>[],int);

int main(void)
{
    //freopen("articpoints.txt", "r", stdin);
    vector<int> adjList[MAX];
    int u, v;
    cin >> vertex >> edge;
    for(int e=1; e<=edge; e++)
    {
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    ARTICULATION_POINTS(adjList);
    for(it=articPoints.begin(); it != articPoints.end(); ++it)
    {
        cout << *it << ends;
    }

    cout<<"now"<<endl;
    for(int i=1; i<=vertex; i++)
        cout<<d[i]<<" "<<low[i]<<endl;
    return 0;
}

void ARTICULATION_POINTS(vector<int> G[])
{
    DFS(G);
    articPoints.sort();
    articPoints.unique();
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
    d[u] = low[u] = t;
    color[u] = GRAY;
    //  cout<<endl<<"For : "<<u<<endl;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(color[v] == WHITE)
        {
            p[v] = u;
            DFS_VISIT(G,v);
            if(v==3)
                cout<<u<<" "<<d[u]<<" "<<low[v]<<endl;
            if(d[u] == 1)
            {
                if(G[u].size() >= 2)
                {
                    // special case for root
                    // root is an artic. point if there are two or more children
                    articPoints.push_front(u);
                }
            }
            else if(low[v] >= d[u])
            {
                articPoints.push_front(u);
            }
            low[u] = min(low[u],low[v]);
        }
        else if(p[u] != v)
        {
            low[u] = min(low[u],d[v]);
            //     cout<<endl<<u<<" "<<low[u]<<" "<<d[v]<<endl;
        }
        // cout<<v<<" ";
    }
    //cout<<"\n fin "<<u<<endl;
    color[u] = BLACK;
    t = t + 1;
    f[u] = t;
}


/*

3 3
1 2
2 3
3 1


6 7
1 3
3 4
1 4
1 5
1 2
2 6
5 6


*/
