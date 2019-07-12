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
#define LL long long
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define MAX (200009)
#define PB push_back
#define MOD 1000000007
#define MX 1009
#define INF 1000000000000000000ll



using namespace std;

int flow[MX][MX];
int cap[MX][MX];
int level[MX];
int path[MX];

bool visit[MX];

vector < int > vertex[MX];


int constructBlockingFlow( int source, int sink )
{
    int ret = 0;
    stack< int > stk;
    memset( visit, 0, sizeof( visit ) );
    stk.push( source );
    while ( stk.empty() != true )
    {
        int now = stk.top();
        if ( now != sink )
        {
            for ( int i = 0; i < vertex[ now ].size() && stk.top() != now; ++i )
            {
                int next = vertex[ now ][ i ];
                cout<<next<<" ";
                if ( visit[ next ] || level[ next ] != level [ now ] + 1 )
                    continue;
                if ( cap[ now ][ next ] - flow[ now ][ next ] > 0 )
                    stk.push( next ), path[ next ] = now;
                else if ( flow[ now ][ next ] > 0 )
                    stk.push( next ), path[ next ] = -now;
            }

            if ( stk.top() == now )
                stk.pop(), visit[ now ] = 1;
        }
        else
        {
            int F = 1e9, bottleneck;
            for ( int cur = sink; cur != source; cur = abs( path[ cur ] ) )
                F = min( F, path[ cur ] > 0 ? cap[ path[ cur ] ][ cur ] - flow[ path[ cur ] ][ cur ] : flow[ cur ][ -path[ cur ] ] );
            for ( int cur = sink; cur != source; cur = abs( path[ cur ] ) )
            {
                if ( path[ cur ] > 0 )
                {
                    flow[ path[ cur ] ][ cur ] += F;
                    if ( cap[ path[ cur ] ][ cur ] - flow[ path[ cur ] ][ cur ] == 0 )
                        bottleneck = path[ cur ];
                }
                else
                {
                    flow[ cur ][ -path[ cur ] ] -= F;
                    if ( flow[ cur ][ -path[ cur ] ] == 0 )
                        bottleneck = -path[ cur ];
                }
            }
            while ( stk.empty() != true && stk.top() != bottleneck )
                stk.pop();
            ret += F;
        }
        cin.get();
    }
    return ret;
}


bool buildLevelGraph( int source, int sink )
{
    queue< int > que;
    memset( level, 0, sizeof( level ) );
    que.push( source );
    level[ source ] = 1;
    while ( que.empty() != true )
    {
        int now = que.front();
        que.pop();
        //cout<<endl<<now<<" dukay:"<<endl;
        for ( int i = 0; i < vertex[ now ].size(); ++i )
        {
            int next = vertex[ now ][ i ];

            if ( ( cap[ now ][ next ] - flow[ now ][ next ] > 0 || flow[ next ][ now ] > 0 ) && level[ next ] == 0 )
            {
                que.push( next );
                //cout<<next<<" ";
                level[ next ] = level[ now ] + 1;
            }
        }
    }
    return level[ sink ] != 0;
}


int Dinic( int source, int sink )
{
    int ret = 0;
    while ( buildLevelGraph( source, sink ) )
    {
        ret += constructBlockingFlow( source,sink );
        //cin.get();
    }
    return ret;
}

int main()
{
    int i, j, k;
    int n, n1, m, u, v, w;
    cin>>n>>n1>>m;
    for(i = 0; i < m; i++)
    {
        cin>>u>>v>>w;
        vertex[u].PB(v);
        cap[u][v] = w;
    }
    for(i = 1; i <= n; i++)
    {
        cap[0][i] = 100;
        vertex[0].PB(i);
    }
    for(i = n + 1; i <= n + n1; i++)
    {
        cap[i][n + n1 + 1] = 100;
        vertex[i].PB(n + n1 + 1);
    }


    cout<<Dinic(0, n + n1 + 1)<<endl;
}

/*

4 4 8
1 5 5
2 5 5
2 6 2
3 5 3
3 6 5
3 8 10
4 5 7
4 7 8


*/
