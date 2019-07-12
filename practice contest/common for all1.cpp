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
#define MX 1000009
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MOD 5000000
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define set_bit(a,b) (a | (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;


struct Z
{
    int v, id;
};

Z V[1000001];
int val[1000001];
LL fact[1000001];
bool vis[1000001];

LL cnt;
LL edge;
LL begal;


LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}



void DFS(int src)
{
    if(vis[src]) return;
    vis[src] = true;

    for(int i = 0; i < V[src].size(); i++)
    {
        if(col[V[src][i].id] == 0)
        {
            edge++;
            col[V[src][i].id] = 1;
            DFS(V[src][i].v);
        }
    }
    cnt++;
    begal = (begal * fact[val[src]])%MD;
    return;
}



int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int  K;
    int t;
    fact[0] = 1;
    for(LL i = 1; i < 1000001; i++)
        fact[i] = (fact[i - 1] * i)% MD;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;
        Z tm;
        for(i = 0; i < m; i++)
        {
            cin>>a>>b;
            tm.id = i;
            tm.v = b;
            V[a].PB(tm);
            tm.v = a;
            V[b].PB(tm);
            val[a]++;
            val[b]++;
        }
        LL res = 1;
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                cnt = 0;
                edge = 0;
                begal = 1;
                DFS(i);
                LL aa = (fact[cnt] * modinverse(begal, MD))%MD;
                res = (res * a)%MD;
            }
        }
        cout<<res<<endl;
    }
    cout<<"END"<<endl;
    return 0;
}

/*

20
14
2
5
15
8
9
20
4
14
2
5
15
8
9
20
4
4
5
6
7



*/
