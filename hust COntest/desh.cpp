/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad written code **********
*/
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
#define MOD 1000000000+7
#define N 1000007
#define PB push_back
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)

using namespace std;

vector<int>V[131];
bool vis[131];
int par[131];

bool DFS(int src)
{
    int sz = V[src].size();
    for(int i = 0; i < sz; i++)
    {
        int adjn = V[src][i];
        if(vis[adjn]) continue;
        vis[adjn] = true;
        if((par[adjn] == (-1)) || (DFS(par[adjn]) == true))
        {
            par[adjn] = src;
            return true;
        }
    }
return false;
}

int in[131];
int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i, j, k;
    int t;
    int cases = 1;
    int K;
    int n, m, u, v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        clr(vis, false);
        clr(par, -1);
        for(i = 0; i <= n; i++)
            V[i].clear();
        clr(in, 0);

        for(i = 0; i < m; i++)
        {
            cin>>u>>v;
            V[u].PB(v);
            in[v]++;
        }
        int cnt = 0;
        for(i = 1; i <= n; i++)
        {
            clr(vis, false);
            if(DFS(i))
            {
                cnt++;
            }
        }
        cout<<n-cnt<<endl;
    }




    return 0;
}

/*

1
This can't be solved by brute force.

*/
