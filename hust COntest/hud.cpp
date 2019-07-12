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


#define PB push_back
#define LL long long
#define MX 100001


using namespace std;

struct Z
{
    int node;
    LL cost;
    Z() {}
    Z(int _, LL __)
    {
        node = _;
        cost = __;
    }
    bool operator <(const Z& A) const
    {
        return cost > A.cost;
    }
};

vector<Z>V[100001];
bool is[MX];
int stay[MX];
LL c;

LL BFS(int st, int ed)
{
    priority_queue<Z>PQ;
    Z tmp;
    tmp.node = st;
    tmp.cost = 0ll;

    bool vis[100001];
    memset(vis, false, sizeof vis);

    PQ.push(tmp);

    while(!PQ.empty())
    {
        Z top = PQ.top();
        PQ.pop();

        int cn = top.node;
        LL cc = top.cost;
        if(vis[cn]) continue;
        vis[cn] = true;
        if(cn == ed) return cc;
        int sz = V[cn].size();
        for(int i = 0; i < sz; i++)
        {
            tmp.node = V[cn][i].node;
            tmp.cost = cc + V[cn][i].cost;

            if(vis[tmp.node]) continue;
            PQ.push(tmp);
        }
        tmp.node = cn + 1;
        if(is[tmp.node] && !vis[tmp.node])
        {
            tmp.cost = cc + c;
            PQ.push(tmp);
        }
        tmp.node = cn - 1;
        if(is[tmp.node] && !vis[tmp.node])
        {
            tmp.cost = cc + c;
            PQ.push(tmp);
        }
    }
    return -1;
}

int main()
{
    int i,j,k;
    int m, t, n, cases = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %lld", &n, &m, &c);
        int u, v;

        LL w;

        for(i = 1; i <= n; i++)
            scanf("%d", &stay[i]), V[i].clear(), is[i] = false;

        for(i = 0; i < m; i++)
        {
            scanf("%d %d %lld", &u, &v, &w);
            u = stay[u];
            v = stay[v];
            is[u] = is[v] = true;
            V[u].PB(Z(v, w));
        }

        LL res = BFS(stay[1], stay[n]);
        printf("Case #%d: %lld\n", cases++, res);

    }
    return 0;
}

/*

 2
4 3 3
1 3 2 4
1 2 1
2 3 1
1 3 3

*/
