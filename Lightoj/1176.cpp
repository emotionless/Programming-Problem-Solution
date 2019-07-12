#include <bits/stdc++.h>

#define LL long long
#define MX 70
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;

vector<int>V[MX];
int cost[MX][MX];



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
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i, j;

    int n, m;
    map<string, int>M;
    M["XXL"] = 61;
    M["XL"] = 62;
    M["L"] = 63;
    M["M"] = 64;
    M["S"] = 65;
    M["XS"] = 66;
    int cases = 1;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i = 61; i <= 66; i++)
        {
            V[67].PB(i);
            cost[67][i] = n;
        }
        string str;
        for(i = 1; i <= m; i++)
        {
            cin>>str;
            V[M[str]].PB(i);
            V[i].PB(M[str]);

            cost[M[str]][i] = 1;
            cin>>str;
            V[M[str]].PB(i);

            V[i].PB(M[str]);
            cost[M[str]][i] = 1;
            V[i].PB(0);
            cost[i][0] = 1;
        }
        int res = max_flow(67, 0);
        printf("Case %d: ", cases++);
        if(res == m)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        for(i = 0; i < 70; i++)
            V[i].clear();
        memset(cost, 0, sizeof cost);
    }





    return 0;
}

/*

1
1 3
XL S
XL L
XL L



*/
