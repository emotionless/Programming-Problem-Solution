#include <cstdio>
#include <cstring>
#include <vector>
#include <bits/stdc++.h>

#define N 1000001
#define MOD 1000000007
#define LL long long

using namespace std;

vector <int> edges [N];
vector <int> rEdges [N];    // reversed edges
vector <int> sortedNode;

bool vis [N];

int comp [N];               // component number of a node
int inDegree [N];           // in-degree of a component

void reset ()
{
    for ( int i = 0; i < N; i++ )
    {
        edges [i].clear();
        rEdges [i].clear();
    }

    sortedNode.clear();

    memset (vis, false, sizeof vis);
    memset (inDegree, 0, sizeof inDegree);
}

void dfs1 (int x)
{
    vis [x] = true;

    for ( size_t u = 0; u < edges [x].size(); u++ )
    {
        if ( !vis [edges [x] [u]] )
                dfs1(edges [x] [u]);
    }

sortedNode.push_back(x);
}
vector<int>V;
void dfs2 (int x, int c)
{
    vis [x] = false;

    comp [x] = c;

    for ( size_t u = 0; u < rEdges [x].size(); u++ )
    {
        if ( vis [rEdges [x] [u]] )
                dfs2(rEdges [x] [u], c);
    }
    V.push_back(x);
}
LL cost[N];
int main ()
{
    int numberOfNodes;
    int numberOfEdges;
    cin>>numberOfNodes;
    reset ();

    for(int i=1; i<=numberOfNodes; i++)
        cin>>cost[i];
    cin>>numberOfEdges;
    int from, to;
    for ( int i = 0; i < numberOfEdges; i++ )
    {
        cin>> from;       // edges from
        cin>> to;         // edges to

        edges [from].push_back(to);
        rEdges [to].push_back(from);
    }

    for ( int i = 1; i <= numberOfNodes; i++ )
    {
        if ( !vis [i] ) dfs1 (i);
    }

    int componentId = 0;

    LL ans=0;
    LL res=1LL;
    for ( int i = sortedNode.size() - 1; i >= 0; i-- )
    {
        if ( vis [sortedNode [i]] ){
                V.clear();
                dfs2(sortedNode [i], ++componentId);
                LL tot=1;
                LL mn=1000000001LL;
                for(int j=0; j<V.size(); j++)
                {
                    if(cost[V[j]]<mn)
                    {
                        mn=cost[V[j]];
                        tot=1;
                    }
                    else if(cost[V[j]]==mn)
                        tot++;
                }
                res=(res*tot)%MOD;
                ans+=mn;
        }
    }
    cout<<ans<<" "<<res<<endl;

    return 0;
}
