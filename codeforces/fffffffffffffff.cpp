#include<iostream>

using namespace std;
char g[100][100];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int vis[100][100];
int level[100][100];
int n;
int ans;
struct node
{
    int x_cor, y_cor;
    node() {}
    node( int x_cor, int y_cor ) : x_cor(x_cor), y_cor(y_cor) {}
};

bool valid( int x, int y )
{
    return x >= 0 && x < n && y >= 0 && y < n;
}


void bfs( int xx, int yy )
{
    node q[100001];
    int frnt = 0, bck = 0;

    q[bck++] = node(xx, yy);
    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            vis[i][j]=0;
        }
    }
    int mx = 0;
    level[xx][yy] = 0;
    vis[xx][yy] = 1;

    while( frnt < bck )
    {
        node top = q[frnt];
        frnt++;

        for(int i = 0; i < 4; i++)
        {
            int x = dx[i] + top.x_cor;
            int y = dy[i] + top.y_cor;
            if( valid(x, y) )
            {
                if( g[x][y] == '1' || vis[x][y] ) continue;
                else if( g[x][y] == 'g' )
                {
                    vis[x][y] = 1;
                    level[x][y] = 1 + level[top.x_cor][top.y_cor];
                    mx = max( mx, level[x][y] );
                    q[bck++] = node(x, y);
                }
                else
                {
                    vis[x][y] = 1;
                    level[x][y] = 1 + level[top.x_cor][top.y_cor];
                    q[bck++] = node(x, y);
                }
            }
        }
    }
    if( mx  ) ans = min(ans, mx);
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>g[i];
    ans = 999999999;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if( g[i][j] == '0' )
            {
                bfs(i, j);
            }
        }
    }
    cout<<ans<<endl;


    return 0;
}
