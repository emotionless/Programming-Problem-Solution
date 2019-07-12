/*
 * Strongly Connected Component
 * Algorithm : Tarjan's Algorithm
 * Order : O( V+E )
 */
#include<stdio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define MAX 4007
#define pb push_back
long N,M;
vector<long> edge[MAX+7];
bool visit[MAX+7];
bool instk[MAX+7];
long low[MAX+7],I;
long ind[MAX+7];
stack<long> stk;
void SCC( long u ){
    visit[u] = true;
    instk[u] = true;
    ind[u] = ++I;
    low[u] = I;
    stk.push( u );
    long i;
    for( i=0; i<edge[u].size(); i++)
    {
        long v = edge[u][i];
        if( !visit[v] )
        {
            SCC( v );
            low[u] = min( low[u],low[v] );
        }
        else if( instk[v] )
        {
            low[u] = min( low[u],ind[v] );
        }
    }
    if( low[u]!=ind[u] ) return;
    // found new component
    while( stk.top()!=u )
    {
        long v = stk.top();
        stk.pop();
        instk[v] = false;
        cout<<v<<endl;
    }
    stk.pop();
    instk[u] = false;
}

int main( void )
{
    long i,j,u,v,Icase,k = 0;
    //freopen("text1.txt","r",stdin );
    scanf("%ld%ld",&N,&M );
    for( i=1; i<=M; i++)
    {
        scanf("%ld%ld",&u,&v );
        edge[u].pb( v );
    }
    for( i=1; i<=N; i++)
    {
        if( visit[i] ) continue;
        SCC( i );
    }
    return 0;
}
