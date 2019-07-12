#include <algorithm>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <iostream>

#define INF 100000
#define MX 250
#define PB push_back

using namespace std;
int f, st;
int cost[MX][MX];
int par[MX];
int num[MX];
int have[MX];
int x[MX];
int y[MX];
bool mat[MX][MX];



void augment(int v, int mn)
{
    //cout<<"\n asce "<<v<<" "<<par[v]<<endl;
    if(v == st) f = mn;
    else if (par[v] != -1)
    {
        int u = par[v];
        //cout<<v<<" "<<u<<endl;
        //cin.get();
        augment(u, min(mn, cost[u][v]));
        cost[u][v] -= f, cost[v][u] += f;
    }
}

double Distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}



int main()
{
    int n = 3;
    int m, u, v, i;
    int w;
    int t, cases = 1;
    double d;
    cin>>t;

    while(t--)
    {
        cin>>n>>d;
        int sum = 0;
        for(i = 1; i <= n; i++)
        {
            cin>>x[i]>>y[i];
            cin>>num[i]>>have[i];
            sum += num[i];
        }
        st = n * 2 + 1;
        memset(mat, false, sizeof mat);
        for(i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                if(Distance(x[i], y[i], x[j], y[j]) <= d)
                {
                    mat[i][j] = mat[j][i] = true;
                }
            }
        }
        vector<int>adj[MX];
        for(i = 1; i <= n; i++) adj[i].clear();
        int j;
        for(i = 1; i <= n; i++)
        {
            adj[st].PB(i);
            adj[i].PB(st);
            for(j = 1; j <= n; j++)
            {
                if(mat[i][j])
                {
                    adj[i + n].PB(j);
                    adj[j].PB(i + n);
                }
            }
            adj[i].PB(i + n);
            adj[i + n].PB(i);
        }
        printf("Case %d:", cases++);
        bool ck = true;
        for(int node = 1; node <= n; node++)
        {
            memset(cost, 0, sizeof cost);

            for(int i = 1; i <= n; i++)
            {
                cost[st][i] = num[i];
                for(j = 1; j <= n; j++)
                {
                    cost[i + n][j] = mat[i][j]?INF:0;
                }
                cost[i][n + i] = have[i];
            }

            cost[st][node] = 0;
            int tot = 0;
            while(true)
            {
                //      cout<<"again"<<endl;
                f = 0;
                for(int i = 1; i <= st; i++) par[i] = -1;
                par[st] = 0;
                queue<int>Q;
                Q.push(st);
                while(!Q.empty())
                {
                    int u = Q.front();
                    Q.pop();
                    if(u == node) break;
                    //cout<<u<<" dukay: ";
                    for(int i = 0; i < adj[u].size(); i++)
                    {
                        int v = adj[u][i];
                        // cout<<v<<" "<<cost[u][v]<<" "<<par[v]<<endl;
                        if(cost[u][v] > 0 && par[v] == -1)
                        {
                            Q.push(v);
                            par[v] = u;
                            // cout<<v<<" ";
                        }
                    }
                    //cout<<endl;
                }
                f = 0;
                augment(node, INF);
                if(f == 0) break;
                tot += f;
            }
            //cout<<tot<<endl;
            if(tot >= sum - num[node])
            {
                cout<<" "<<node-1;
                ck = 0;
            }
        }
        if(ck)
            printf(" -1");
        cout<<endl;
    }
    return 0;
}

/*

1
9 5
46 307 78 140 789 892 364
2 7 394
2 3 337
1 3 673
6 8 840
2 9 497


*/
