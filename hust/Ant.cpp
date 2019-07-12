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
#define INF (1<<31-1)


using namespace std;

struct Z
{
    int u, v;
    int w;
    Z() {}
    Z(int _, int __, int ___)
    {
        u = _;
        v = __;
        w = ___;

    }
};

int n, m, K;
Z mat[10001];
int dis[10001];
int cnt;
bool bellman_ford()
{
    for(int i = 0; i <= n; i++)
    {
        dis[i] = INF;
    }
    dis[1] = 0;
    for(int k = 0; k < n - 1; k++)
    {
        bool flag = true;
        for(int i = 1; i <= cnt; i++)
        {
            int u = mat[i].u;
            int v = mat[i].v;
            int w = mat[i].w;
            if(dis[u] != INF)
            {
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    flag = false;
                }
            }
        }

        if(flag)
            break;
    }

    for(int i = 1; i <= cnt; i++)
        if(dis[mat[i].v] > dis[mat[i].u] + mat[i].w)
            return true;
    return false;
}


int main()
{
    int i,j,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>K;
        int u, v, w;
        cnt = 0;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v>>w;
            cnt++;
            mat[cnt]= Z(u, v, w);

            cnt++;
            mat[cnt]= Z(v, u, w);
        }
        for(i = 0; i < K; i++)
        {
            cin>>u>>v>>w;
            cnt++;
            mat[cnt]= Z(u, v, -w);
        }
        if(bellman_ford())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

/*



*/
