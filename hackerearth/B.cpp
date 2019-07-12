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
#define MAX 100009



using namespace std;

vector<int>V[MAX];

struct Z
{
    int nd, c;

};
int cost[MAX];
bool vis[MAX];
void DFS(int u)
{
    queue<Z>Q;
    Z tmp;
    tmp.nd = u;
    tmp.c = 1;
    Q.push(tmp);
    memset(vis,false, sizeof vis);

    while(!Q.empty())
    {
        tmp = Q.front();
        Q.pop();
        int cn = tmp.nd;
        int cc = tmp.c;
        if(vis[cn]) continue;
        vis[cn] = true;
        cost[cn] = cc;
        int sz  = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            int v = V[cn][i];
            if(vis[v]) continue;
            tmp.nd = v;
            tmp.c = cc + 1;
            Q.push(tmp);
        }
    }
}

int edu[MAX];
int edv[MAX];

int main()
{
    int i,j;
    int n;
    int t, m, u, v;
    bool is = true;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        for(i=0; i <= n; i++)
        {
            V[i].clear();
        }
        v = 0;
        for(i = 0; i < m; i++)
        {
            scanf("%d %d", &u, &v);
            V[u].push_back(v);
            V[v].push_back(u);
            edu[i] = u;
            edv[i] = v;
        }


        for(i = 0; i < m; i++)
        {
            if(!vis[edu[i]] || !vis[edu[i]])
                DFS(edu[i]);
            if(abs(cost[edu[i]] - cost[edv[i]])%2 == 0)
            {
                printf("NO\n");
                break;
            }
        }
        if(i == m)
            printf("YES\n");
    }




    return 0;
}


/*

1
6 4
1 2
2 3
3 1

5 6


*/
