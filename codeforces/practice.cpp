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
bool vis[6][MX][MX][MX];
int cost[6][MX][MX][MX];

int DIJKSTRA(int x, int y, int id)
{
    priority_queue<Z>PQ;
    Z tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.t = 0;
    tmp.cost = 0;


    PQ.push(tmp);

    while(!PQ.empty())
    {
        Z top = PQ.top();
        PQ.pop();

        int cx = top.x;
        int cy = top.y;
        int cc = top.cost;
        int ct = top.t;

        if(vis[id][cx][cy][ct]) continue;
        if(ct > T) continue;

        vis[id][cx][cy][ct] = true;
        cost[id][cx][cy][ct] = cc;
        //cout<<id<<" "<<cx<<" "<<cy<<" "<<ct<<" "<<cc<<endl;

        for(int i = 0; i < 4; i++)
        {
            int adjx = cx + dr[i];
            int adjy = cy + dc[i];
            if(adjx < 0 || adjx >= n || adjy < 0 || adjy >= n) continue;
            int adjt = ct + 1;
            int adjc = cc + arr[cx][cy];
            if(vis[id][adjx][adjy][adjt]) continue;
            tmp.x = adjx;
            tmp.y = adjy;
            tmp.t = adjt;
            tmp.cost = adjc;
            PQ.push(tmp);
        }
    }
}



int main()
{
    int t;
    int tc = 1;
    int l;
    while(true)
    {
        scanf("%d", &n);
        scanf("%d", &f);
        scanf("%d", &T);

        if(n == 0 && f == 0 && T == 0) break;
        int i, j, k;
        for(i = 0; i <= n; i++)
        {
            for(j = 0; j <= n; j++)
            {
                for(k = 0; k <= f; k++)
                {
                    for(l = 0; l <= T; l++)
                        cost[k][i][j][l] = INT_MAX, vis[k][i][j][l] = false;
                }
            }
        }
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
            DIJKSTRA(posx[i], posy[i], i + 1);
        }

        int mn = INT_MAX;
        int x = -1, y = -1;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                int tcost = 0;
                for(k = 1; k <= f; k++)
                {
                    int mm = INT_MAX;
                    for(l = 0; l <= T; l++)
                    {
                        mm = min(mm, cost[k][i][j][l]);

                    }
                    if(mm == INT_MAX)
                        break;
                    tcost += mm;
                }

//                cout<<i<<" "<<j<<" "<<k<<" "<<tcost<<endl;
                if(k == f + 1)
                {
                    if(tcost < mn)
                    {
                        mn = tcost;
                        x = i;
                        y = j;
//                        cout<<i<<" "<<j<<" "<<tcost<<endl;
                    }
                }
            }
        }
       // cout<<mn<<endl;


        printf("Case #%d: ", tc++);
        if(mn == INT_MAX)
            printf("Impossible.\n");
        else
            printf("Selected city (%d,%d) with minimum cost %d.\n",x, y, mn);

    }

    return 0;
}

/*


4 1 3
4 5 10 20
40 30 40 10
18 53 4 32
52 37 42 43
0 0


*/
