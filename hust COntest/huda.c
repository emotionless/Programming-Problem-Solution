#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int INDEG[MAX], node, edge;

vector<int> TOPOLOGICAL_SORT(int [][MAX]);

int main(void)
{
    //freopen("toposort.txt", "r", stdin);
    int adjMatrix[MAX][MAX];
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++) {
            adjMatrix[i][j] = 0;
            INDEG[i] = 0;
        }
    int M, N;
    cin >> node >> edge;
    for(int e=1; e<=edge; e++) {
        cin >> M >> N;
        adjMatrix[M][N] = 1;
        INDEG[N]++;
    }
    vector<int> orderedList = TOPOLOGICAL_SORT(adjMatrix);
    for(int i=0; i<orderedList.size(); i++) {
        cout << orderedList[i] << ends;
    }
    return 0;
}

vector<int> TOPOLOGICAL_SORT(int S[][MAX]) {

    queue<int> Q;

    for(int n=1; n<=node; n++) {
        if(INDEG[n] == 0) Q.push(n);
    }

    vector<int> topoList;

    while( !Q.empty()) {
        int N = Q.front(); Q.pop();
        topoList.push_back(N);
        for(int M=1; M<=node; M++) {
            if(S[N][M] == 1) {
                INDEG[M]--;
                if(INDEG[M] == 0) {
                    Q.push(M);
                }
            }
        }
    }
    return topoList;
}
