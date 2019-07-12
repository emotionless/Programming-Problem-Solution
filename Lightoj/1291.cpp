#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>

#define PB push_back
#define MAX 10009

using namespace std;

vector<int> G[MAX], V[MAX];
vector<int>S[MAX];
int val[MAX];
bool vis[MAX];
bool visited[MAX];
void DFS(int n)
{
    if(visited[n]) return;

    visited[n] = true;
    for(int i = 0; i < V[n].size(); i++)
    {
        int adjn = V[n][i];
        if(visited[adjn]) continue;
        if(val[n] != val[adjn])
        {
            S[val[n]].PB(val[adjn]);
            S[val[adjn]].PB(val[n]);
        }
        DFS(adjn);
    }
}

vector<int>store;


int id;
int Index[MAX];
int low[MAX];
int Stack[MAX];
bool isStack[MAX];
int top;

// low for lowest id where the node can go.

int tarjan(int u, int par)
{
    Index[u] = low[u] = (id++);
    Stack[top++] = u;
    isStack[u] = true;
    int sz = G[u].size();
    for(int i = 0; i < sz; i++)
    {
        int v = G[u][i];
        if(v == par) continue;
        if(Index[v] == (-1))
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(isStack[v])
            low[u] = min(low[u], Index[v]);
    }
    int v;
    if(Index[u] == low[u])
    {
        do
        {
            v = Stack[--top];
            isStack[v] = false;
            val[v] = u;
        }
        while(v != u);
    }
}







//
//void DFS1(int u, int par)
//{
//    vis[u] = true;
//    for(int i = 0; i < G[u].size(); i++)
//    {
//        int v = G[u][i];
//        if(v == par) continue;
//        if(!vis[v])
//            DFS1(v, u);
//    }
//    tmp.PB(u);
//}
//
//void DFS2(int u, int par)
//{
//    vis[u] = false;
//    for(int i = 0; i < RG[u].size(); i++)
//    {
//        int v = RG[u][i];
//        if(v == par) continue;
//        if(vis[v])
//            DFS2(v, u);
//    }
//    store.PB(u);
//}


int main()
{
    int i, j, k;
    int n, m, u, v;
    int t, cases = 1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        store.clear();
        for(i = 0; i <= n; i++)
        {
            G[i].clear();
            V[i].clear();
            S[i].clear();
            vis[i] = visited[i] = false;
        }
        for(i = 0; i < m; i++)
        {
            cin>>u>>v;
            G[u].PB(v);
            G[v].PB(u);
            V[u].PB(v);
            V[v].PB(u);
        }
        for(i = 0; i <= n; i++)
        {
            S[i].clear();
            val[i] = i;
            Index[i] = (-1);
        }
        top = 0, id = 0;
        memset(low, 0x3f, sizeof low);
        memset(isStack, 0, sizeof isStack);

        for(i = 0; i < n; i++)
            if(Index[i] == (-1))
                tarjan(i, -1);


        /*
                for(i = 0; i < n; i++)
                {
                    if(!vis[i])
                    {
                        DFS1(i, -1);
                    }
                }
                for(i = tmp.size() - 1; i >= 0; i--)
                {
                    if(vis[tmp[i]])
                    {
                        store.clear();
                        DFS2(tmp[i], -1);
                        // cout<<tmp[i]<<" ";
                        int sz = store.size();
                       // cout<<store[0]<<" ";
                        for(j = 0; j < sz; j++)
                        {
                            //     cout<<store[j]<< " ";
                            val[store[j]] = val[store[0]];
                           // cout<<store[j]<<" ";
                        }
                       // cout<<endl;
                    }
                }

        */
        DFS(0);
        int cnt = 0;
        for(i = 0; i < n; i++)
        {
            sort(S[i].begin(), S[i].end());
            S[i].erase(unique(S[i].begin(), S[i].end()), S[i].end());
            if(S[i].size() == 1)
                cnt++;
            // cout<<i<<" "<<val[i]<<endl;
        }
        printf("Case %d: %d\n", cases++, (cnt + 1)/2);

    }

    return 0;
}

/*



*/
