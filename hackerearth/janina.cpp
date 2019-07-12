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
#define ll long long
#define MX 50009
#define MAXN 50009
#define MOD 1000000000+7
#define PB push_back
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define mp make_pair

using namespace std;
int n;
struct Z
{
    int u, v;
    int w;
    Z(int a, int b, int c)
    {
        u = a;
        v = b;
        w = c;
    }
};

bool operator < (Z A, Z B)
{
    return A.w > B.w;
}



int par[MX];
int ranking[MX];
bool mat[1001][1001];
int find(int x)
{
    if(par[x] == x) return x;
    return par[x] = find(par[x]);
}

void Union(int x, int y)
{
    if(ranking[x] > ranking[y])
        par[y] = x;
    else
    {
        par[x] = y;
        if(ranking[x] == ranking[y])
            ranking[x]++;
    }
}


int GCD(int a,int b)
{
    if(b==0)return a;
    return GCD(b,a%b);
}


int  main()
{

    int i, j, k;
    int m;
    int tc;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;
        int u, v;
        int w;
        priority_queue <Z> PQ;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v>>w;
            PQ.push(Z(u, v, w));
        }
        for(i = 0; i <= n; i++)
        {
            par[i] = i;
            ranking[i] = 0;
        }
        memset(mat, 0, sizeof mat);
        while(!PQ.empty())
        {
            Z tmp = PQ.top();
            PQ.pop();
            int x = tmp.u;
            int y = tmp.v;
            int cc = tmp.w;

            int px = find(x);
            int py = find(y);
            if(px != py)
            {
                Union(px, py);
                mat[x][y] = mat[y][x] = 1;
            }
        }

        int q;
        cin>>q;
        int t, s;
        int cnt = 0;
        int tot = q;
        while(q--)
        {
            cin>>s>>t;
            if(mat[s][t])
                cnt++;
        }
        int gcd = GCD(cnt, tot);
        cout<<cnt/gcd<<"/"<<tot/gcd<<endl;
    }

    return 0;
}

/*


1
7
10
1 2 5
1 4 3
1 5 12
1 6 5
4 5 1
5 6 2
5 3 1
3 6 16
4 7 1
2 4 1
3
3 6
1 6
6 1

*/
