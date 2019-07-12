/***************************************
    codeforces = topcoder = sahedsohel
    IIT,Jahangirnagar University(42)
****************************************/
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

/*****************************************************************/

#define MX 30

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

struct Z
{
    int x, y;
    int  t;
    int cost;
    bool operator < (const Z& A) const
    {
        if(cost == A.cost) return t > A.t;
        return cost > A.cost;
    }
};

int T, n, f;
int posx[10], posy[10];

int arr[MX][MX];



    bool vis[MX][MX][MX];
    int cost[MX][MX][MX];


int DIJKSTRA(int x, int y)
{
    priority_queue<Z>PQ;
    Z tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.cost = 0;
    tmp.t = 0;
    for(int i = 0; i < MX; i++)
        for(int j = 0; j < MX; j++) for(int k = 0; k < MX; k++)
                cost[i][j][k] = INT_MAX, vis[i][j][k] = false;
    memset(vis, false, sizeof vis);
//    memset(cost, INT_MAX, sizeof cost);

    PQ.push(tmp);
    //cin>>x;
    while(!PQ.empty())
    {
        tmp = PQ.top();
        PQ.pop();
        int cx = tmp.x;
        int cy = tmp.y;
        int cc = tmp.cost;
        int ct = tmp.t;
        //cout<<cx<<" "<<cy<<" "<<cc<<" "<<ct<<endl;

        if(vis[cx][cy][ct]) continue;

        if(ct)
        {
            if(cost[cx][cy][ct - 1] < cc) continue;
        }

        if(ct > T) continue;

        vis[cx][cy][ct] = true;
        cost[cx][cy][ct] = cc;

        for(int i = 0; i < 4; i++)
        {
            int adjx = cx + dr[i];
            int adjy = cy + dc[i];
            if(adjx < 0 || adjx >= n || adjy < 0 || adjy >= n) continue;
            int adjc = cc + arr[adjx][adjy];
            int adjt = ct + 1;
            tmp.x = adjx;
            tmp.y = adjy;
            tmp.cost = adjc;
            tmp.t = adjt;
            PQ.push(tmp);
        }
    }
    int ret = 0;
    for(int i = 0; i < f; i++)
    {
        int mn = INT_MAX;
        {
            for(int j = 0; j <= T; j++)
            {
                mn = min(mn, cost[posx[i]][posy[i]][j]);
            }
        }
        if(mn == INT_MAX) return -1;
        ret += mn;
    }
    return ret;
}



int main()
{
    int t;
    int tc = 1;
    while(true)
    {
        scanf("%d", &n);
        scanf("%d", &f);
        scanf("%d", &T);

        if(n == 0 && f == 0 && T == 0) break;
        int i, j, k;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for(i = 0; i < f; i++)
        {

            scanf("%d %d", &posx[i], &posy[i]);
        }

        int mn = INT_MAX;
        int x = -1, y = -1;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                int get = DIJKSTRA(i, j);
                if(get == -1) continue;
                if(get < mn)
                {
                    mn = get;
                    x = i;
                    y = j;
                }
            }
        }
        printf("Case #%d: ", tc++);
        if(mn == INT_MAX)
            printf("Impossible.\n");
        else
            printf("Selected city (%d,%d) with minimum cost %d.\n",x, y, mn);

    }

    return 0;
}

/*


25 1 25
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1


*/
