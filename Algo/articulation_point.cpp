#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define WHITE 0
#define BLACK 1


using namespace std;
const int NIL=-1000000000;
int vertex, edge;
vector<int>res;
int low[10001], d[10001], color[10001], p[10001], t;

void VISIT_DFS(vector<int>G[], int u)
{
    t=t+1;
    d[u]=low[u]=t;
    color[u]=BLACK;

    int i;
    for(i=0; i<G[u].size(); i++)
    {
        int v=G[u][i];
        if(color[v]==WHITE)
        {
            p[v]=u;
            VISIT_DFS(G, v);
            if(d[u]==1)
            {
                if(G[u].size()>=2 && low[v]>low[u])
                {
                    res.PB(u);
                }
            }
            else if(low[v]>=d[u])
                res.PB(u);
            low[u]=min(low[u], low[v]);
        }
        else if(p[u]!=v)
            low[u]=min(low[u], d[v]);
    }
    t=t+1;
}

void DFS(vector<int>G[])
{
    for(int i=0; i<=vertex; i++)
    {
        color[i]=WHITE;
        p[i]=NIL;
    }
    int i;
    for(i=1; i<=vertex; i++)
    {
        if(color[i]==WHITE)
        {
            VISIT_DFS(G,i);
        }
    }

}

void solve(vector<int>G[])
{


    DFS(G);
}







int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g,u,v,m;

    vector<int>V[10001];
    cin>>vertex>>edge;

    FOR(i,edge)
    {
        cin>>u>>v;
        V[u].PB(v);
        V[v].PB(u);
    }

    solve(V);
    cout<<res.size()<<endl;
    FOR(i,res.size())
    cout<<res[i]<<" ";

    return 0;
}

/*

6 7
3 4
4 1
1 3
1 5
1 2
2 6
5 6



*/
