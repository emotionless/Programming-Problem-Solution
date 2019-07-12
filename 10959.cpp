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
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;

struct Z
{
    int node;
    int cost;
    Z() {}
    Z(int a, int b)
    {
        node=a;
        cost=b;
    }
};

int main()
{
    int i,j,k;
    int n,a,b,e;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&e);
        vector<int>V[1001];
        for(i=0; i<e; i++)
        {
            scanf("%d %d",&a,&b);
            V[a].PB(b);
            V[b].PB(a);
        }
        queue<Z>Q;
        Z tmp;
        tmp.node=0;
        tmp.cost=0;
        Q.push(tmp);
        bool vis[1001];
        int cost[1001];
        clr(vis,false);
        rep(i,0,1001)
        cost[i]=214748;
        cost[0]=0;
        while(!Q.empty())
        {
            tmp=Q.front();
            Q.pop();
            int cn=tmp.node;
            int cc=tmp.cost;
            if(vis[cn])
                continue;
            vis[cn]=true;
            int sz=V[cn].size();
            rep(i,0,sz-1)
            {
                int adjn=V[cn][i];
                int adjc=cc+1;
                if(adjc<cost[adjn])
                {
                    cost[adjn]=adjc;
                    Q.push(Z(adjn,cost[adjn]));
                }
            }
        }
        rep(i,1,n-1)
        {
            printf("%d\n",cost[i]);
            V[i].clear();
        }
        V[n].clear();
        if(t)
            printf("\n");
    }
    return 0;
}
