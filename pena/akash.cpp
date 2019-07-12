#include <iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<math.h>

#define MAXX 1000005
using namespace std;


int vis[MAXX];
int level[MAXX];

vector<int>vec[MAXX];

void init()
{
    for(int i=1; i<MAXX; i++)
    {
        vis[i]=0;
        level[i]=-1;
    }
}

void bfs(int s, int n)
{
    vis[s]=1;
    level[s]=0;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<vec[u].size(); i++)
        {
            int v=vec[u][i];

            if(vis[v]==0)
            {
                vis[v]=1;
                level[v]=level[u]+1;
                Q.push(v);
            }
        }
    }

}


int main()
{
    int N,kase=1;

    while(cin>>N)
    {
        init();
        if(N==0)
            break;
        int i;
        for(i=1; i<=N; i++)
        {
            int x,y;
            cin>>x>>y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }

        int path=0,s=0;

        while(cin>>s>>path)
        {
            bfs(s,path);
            if(s==0&&path==0)
                break;

            int cmt=0;
            for(i=0; i<MAXX; i++)
            {
                if(level[i]>path)
                    cmt++;
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",kase++,cmt,N,path);
        }
        for(i=0; i<=N; i++)
        {
            vec[i].clear();
        }
    }
    return 0;
}
