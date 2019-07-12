#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <cstdio>
#define MX 100001
#define LL long long

using namespace std;

struct Z
{
    int u,v;
    Z() {}
    Z(int a, int b)
    {
        u=a;
        v=b;
    }
};
int fib[30];
bool vis[MX+10];
bool visited[MX+10];
int rank[MX+10];
int p[MX+10];

LL FIND(LL x)
{
    if(p[x]==x)
        return x;
    return x=FIND(p[x]);
}
void UNION(LL x, LL y)
{
    if(rank[x]>rank[y])
        p[y]=x;
    else
    {
        p[x]=y;
        if(rank[x]==rank[y])
            rank[y]++;
    }
}


int main()
{
    int i,j,k, cases=1;

    memset(vis, false, sizeof vis);
    LL past=1;
    LL pre=2;
    i=2;
    fib[0]=1;
    fib[1]=2;
    vis[1]=true;
    vis[2]=true;
    LL num=0;
    while(num<100001)
    {
        fib[i]=num=pre+past;
        if(num<MX)
            vis[num]=true;
        i++;
        past=pre;
        pre=num;
    }
    LL t,u,v,c,n,m;
    cin>>t;
    while(t--)
    {

        cin>>n>>m;

        queue<Z>Q;

        for(i=0; i<m; i++)
        {
            cin>>u>>v>>c;
            if(c && (vis[u] && vis[v]))
            {
                Q.push(Z(u,v));
            }
        }

        printf("Case #%d: ", cases++);

        for(i=1; i<=n; i++)
        {
            p[i]=i;
            rank[i]=0;
        }

        bool ck=false;

        memset(visited, false , sizeof visited);

        while(!Q.empty())
        {
            Z tmp=Q.front();
            Q.pop();

            LL x=tmp.u;
            LL y=tmp.v;

            LL px=FIND(x);
            LL py=FIND(y);

            if(px==py)
            {
                cout<<"No"<<endl;
                ck=true;
                break;
            }
            UNION(px,py);

            visited[x]=true;
            visited[y]=true;
            //p[px]=py;
        }

        for(i=0; i<30 && fib[i]<=n; i++)
        {
            if(!visited[fib[i]] && !ck)
            {
                cout<<"No"<<endl;
                ck=true;
                break;
            }
        }

        if(!ck)
            cout<<"Yes"<<endl;
    }
    return 0;
}

/*

2
4 4
1 2 1
2 3 1
3 4 1
1 4 0
5 6
1 2 1
1 3 1
1 4 1
1 5 1
3 5 0
4 2 1



*/
