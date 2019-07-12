#include <cstdio>
#include <vector>
#include <bits/stdc++.h>
#include <cstring>
#include <map>
#define MAXN 1000
#define SIZE (2*MAXN + 1)
using namespace std;

typedef vector <int> vi;

// Assuming vertices are labeled 1...V
vi G[SIZE], Grev[SIZE];
bool explored[SIZE];
int leader[SIZE], finish[SIZE], order[SIZE], t = 0, parent = 0;
map <int, bool> truthAssignment;

// running DFS on the reverse graph
void dfs_reverse(int i)
{
    explored[i] = true;
    for(vi::iterator it = Grev[i].begin(); it != Grev[i].end(); it++)
        if(!explored[*it])
            dfs_reverse(*it);
    t++;
    finish[i] = t;
}

// running DFS on the actual graph
void dfs(int i)
{
    explored[i] = true;
    leader[i] = parent;
    for(vi::iterator it = G[i].begin(); it != G[i].end(); it++)
        if(!explored[*it])
            dfs(*it);
}

// check if u & v are in the same connected component
bool stronglyConnected(int u, int v)
{
    return leader[u] == leader[v];
}

int main()
{

    int tcse = 1, cases = 1;
    cin>>tcse;
    while(tcse--)
    {
        int i=0, u, v, N, M;

        memset(explored, false, sizeof explored);
        memset(leader, 0, sizeof leader);
        memset(finish, 0, sizeof finish);
        memset(order, 0, sizeof order);
        parent = 0;
        t = 0;
        truthAssignment.clear();

        scanf("%d %d", &N, &M);
        for(i=0; i<M; i++)
        {
            scanf("%d %d", &u, &v);

            if(u > 0)
            {
                if(v > 0)
                {
                    G[N+u].push_back(v);
                    G[N+v].push_back(u);
                    Grev[v].push_back(N+u);
                    Grev[u].push_back(N+v);
                }
                else
                {
                    G[N+u].push_back(N-v);
                    G[-v].push_back(u);
                    Grev[N-v].push_back(N+u);
                    Grev[u].push_back(-v);
                }
            }
            else
            {
                if(v > 0)
                {
                    G[-u].push_back(v);
                    G[N+v].push_back(N-u);
                    Grev[v].push_back(-u);
                    Grev[N-u].push_back(N+v);
                }
                else
                {
                    G[-u].push_back(N-v);
                    G[-v].push_back(N-u);
                    Grev[N-v].push_back(-u);
                    Grev[N-u].push_back(-v);
                }
            }
        }

        // run dfs on the reverse graph to get reverse postorder
        memset(explored, false, (2*N + 1)*sizeof(bool));
        for(i=2*N; i>0; i--)
        {
            if(!explored[i])
                dfs_reverse(i);
            order[finish[i]] = i;
        }

        // run dfs on the actual graph in reverse postorder
        memset(explored, false, (2*N + 1)*sizeof(bool));
        for(i=2*N; i>0; i--)
            if(!explored[order[i]])
            {
                parent = order[i];
                dfs(order[i]);
            }

        // check if a variable and its complement belong in the same SCC in reverse postorder
        // and assign truth values to SCC
        for(i=2*N; i>0; i--)
        {
            u = order[i];
            if(u > N)
            {
                if(stronglyConnected(u, u-N)) break;
                if(truthAssignment.find(leader[u]) == truthAssignment.end())
                {
                    truthAssignment[leader[u]] = true;
                    truthAssignment[leader[u-N]] = false;
                }
            }
            else
            {
                if(stronglyConnected(u, N+u)) break;
                if(truthAssignment.find(leader[u]) == truthAssignment.end())
                {
                    truthAssignment[leader[u]] = true;
                    truthAssignment[leader[N+u]] = false;
                }
            }
        }
        printf("Case %d: ", cases++);
        if(i > 0)
            printf("No\n");
        else
        {
            printf("Yes\n");
        }

        for(int i = 0; i <= N; i++)
        {
            G[i].clear();
            Grev[i].clear();
        }


    }
    return 0;
}
