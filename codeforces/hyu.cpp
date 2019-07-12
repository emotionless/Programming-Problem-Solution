#include<stdio.h>
#include<memory.h>
#define INF_MAX 0xfffffff
#define SIZE_N 1010
#define SIZE_M 10100

typedef struct
{
    int to,leg;
    int next;
} SEdge;

SEdge eg[SIZE_M];
int head[SIZE_N];

void Add_edge(int f,int t,int l,int idx)
{
    eg[idx].to = t , eg[idx].leg = l;
    eg[idx].next = head[f] , head[f] = idx;
}

int Dijkstra(int n,int st,int et)
{
    int v,min,L,t;
    int i,j,idx;
    int set[2][SIZE_N],dis[2][SIZE_N];
    int num[2][SIZE_N];

    memset(set,0,sizeof(set));
    memset(dis,127,sizeof(dis));
    memset(num,0,sizeof(num));
    v = st , num[0][v] = 1 , idx = 0;
    set[0][st] = 1 , dis[0][st] = 0 ,min = 0;

    for(i = 1; i < 2 * n; i ++)
    {
        for(j = head[v]; j ; j = eg[j].next)
        {
            t = eg[j].to , L = eg[j].leg + min;
            if( L < dis[0][t])
            {
                dis[1][t] = dis[0][t];
                dis[0][t] = L;
                num[1][t] = num[0][t];
                num[0][t] = num[idx][v];
            }
            else if( L == dis[0][t]) num[0][t] += num[idx][v];
            else if( L < dis[1][t])
            {
                dis[1][t] = L , num[1][t] = num[idx][v];
            }
            else if( L == dis[1][t]) num[1][t] += num[idx][v];
        }
        min = INF_MAX;
        for(j = 1; j <= n; j ++)
        {
            if(!set[0][j] && dis[0][j] < min)
            {
                min = dis[0][j] , v = j, idx = 0;
            }
            if(!set[1][j] && dis[1][j] < min)
            {
                min = dis[1][j] , v = j, idx = 1;
            }
        }
        if(min == INF_MAX || (set[0][et] && set[1][et]))break;
        set[idx][v] = 1;
    }
    if(dis[0][et] == dis[1][et] - 1)
        num[0][et] += num[1][et];
    return num[0][et];
}
int main()
{
    int T,n,m;
    int s,v,l;
    int i,ans;
    scanf("%d",&T);
    while(T --)
    {
        memset(head,0,sizeof(head));
        scanf("%d%d",&n,&m);
        for(i = 1; i <= m; i ++)
        {
            scanf("%d%d%d",&s,&v,&l);
            Add_edge(s,v,l,i);
        }
        scanf("%d%d",&s,&v);
        ans = Dijkstra(n,s,v);
        printf("%d\n",ans);
    }
    return 0;
}
