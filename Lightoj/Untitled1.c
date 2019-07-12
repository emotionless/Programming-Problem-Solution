// @BEGIN_OF_SOURCE_CODE

#include <cstdio>
#include <cstring>
#include <vector>

#define N 1000000

using namespace std;

vector <int> edges [N];
vector <int> rEdges [N];    // reversed edges
vector <int> sortedNode;

bool vis [N];

int comp [N];               // component number of a node
int inDegree [N];           // in-degree of a component

void reset ()
{
    for ( int i = 0; i < N; i++ ) {
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

    for ( size_t u = 0; u < edges [x].size(); u++ ) {
        if ( !vis [edges [x] [u]] )
            dfs1(edges [x] [u]);
    }

    sortedNode.push_back(x);
}

void dfs2 (int x, int c)
{
    vis [x] = false;

    comp [x] = c;

    for ( size_t u = 0; u < rEdges [x].size(); u++ ) {
        if ( vis [rEdges [x] [u]] )
            dfs2(rEdges [x] [u], c);
    }
}

int main ()
{
    int numberOfNodes;
    int numberOfEdges;

    reset ();

    for ( int i = 0; i < numberOfEdges; i++ ) {
        int from;       // edges from
        int to;         // edges to

        // take input in "form" and "to"

        edges [from].push_back(to);
        rEdges [to].push_back(from);
    }

    for ( int i = 0; i < numberOfNodes; i++ ) {
        if ( !vis [i] )
            dfs1 (i);
    }

    int componentId = 0;

    for ( int i = sortedNode.size() - 1; i >= 0; i-- ) {
        if ( vis [sortedNode [i]] )
         dfs2(sortedNode [i], ++componentId);
    }

    // component indegree
    for ( int i = 0; i < numberOfNodes; i++ ) {
        for ( size_t j = 0; j < edges [i].size(); j++ ) {
            if ( comp [i] != comp [edges [i] [j]] )
                inDegree [comp [edges [i] [j]]]++;
        }
    }

    return 0;
}

// @END_OF_SOURCE_CODE
