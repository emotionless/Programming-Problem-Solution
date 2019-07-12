#include<bits/stdc++.h>
#define LL long long
#define PB push_back

using namespace std;


vector<int>V[101];
int cost[101][101];


bool BFS(int s, int t, int parent[])
{
    bool vis[101];

    memset(vis, false, sizeof vis);
    memset(parent, -1, sizeof parent);

    queue<int>Q;

    vis[s]=true;
    Q.push(s);

    while(!Q.empty())
    {
        int cn=Q.front();
        Q.pop();

        int sz=V[cn].size();

        for(int i=0; i<sz; i++)
        {
            int adjn=V[cn][i];
            if(vis[adjn]==false && cost[cn][adjn]>0)
            {
                Q.push(adjn);
                parent[adjn]=cn;
                vis[adjn]=true;
            }
        }
    }
    return vis[t];
}



int max_flow(int st, int ed)
{
    int parent[101];
    int res=0;

    while(BFS(st,ed, parent)==true)
    {
        int path_flow=INT_MAX, u,v;

        for(v=ed; v!=st; v=parent[v])
        {
            u=parent[v];
            path_flow=min(path_flow, cost[u][v]);
        }

        for(v=ed; v!=st; v=parent[v])
        {
            u=parent[v];

            cost[u][v]-=path_flow;
            cost[v][u]+=path_flow;
        }
        res+=path_flow;
    }
    return res;

}



int main()
{
    int i,j,k;
    int n,m,s,e;
    cout<<"Enter number of node(1 - ...), edge: ";
    cin>>n>>m;
    memset(cost, 0, sizeof cost);
    for(i=0; i<m; i++)
    {
        int u,v,w;
        scanf("%d %d %d", &u, &v, &w);
        V[u].PB(v);
        cost[u][v]=w;
    }
    cout<<"Start?: ";
    cin>>s;

    cout<<"End?: ";
    cin>>e;

    int res=max_flow(s,e);
    cout<<"Maximum flow is: "<<res<<endl;

    return 0;
}

/*

6 10
0 1 16
0 2 13
1 2 10
2 1 4
1 3 12
3 2 9
2 4 14
4 3 7
3 5 20
4 5 5
0 5



*/
