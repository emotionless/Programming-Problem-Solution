#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn=220;

bool mp[maxn][maxn],used[maxn];
int linker[maxn],n,m;

bool dfs(int u)
{
    cout<<" "<<u<<" ";
    for(int i=1; i<=n; i++)
    {
        if(used[i]) continue;
        if(mp[u][i])
        {
            used[i]=true;
            if(linker[i]==-1||dfs(linker[i])==true)
            {
                linker[i]=u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ret=0;
    memset(linker,-1,sizeof(linker));
    for(int i=1; i<=n; i++)
    {
        memset(used,false,sizeof(used));{
        cout<<"\nFOr "<<i<<endl;
        if(dfs(i)) ret++;
        }
    }
    return ret;
}

int main()
{
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        scanf("%d%d",&n,&m);
        memset(mp,false,sizeof(mp));
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b]=true;
        }
        printf("%d\n",n-hungary());
    }
    return 0;
}
