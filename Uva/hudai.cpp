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
#define check_bit(aa, bb) (aa &(1<<bb))
#define set_bit(aa, bb) (aa |(1<<bb))
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define mp make_pair

using namespace std;

int mat[15][15];

int dp[1<<14+5];
bool chk[1<<14+5];
int cost[1<<14+5];

int solve(int mask)
{
    if(mask == 0) return 0;
    if(chk[mask]) return dp[mask];
    chk[mask] = true;
    int ret = 10000000;
    for(int i = mask; i > 0; i = (mask & (i - 1)))
        ret = min(ret, cost[i] + solve(mask ^ i));
    return dp[mask] = ret;
}
int  main()
{
    int i, j, k;
    int cases = 1;
    int t;
    int n;
    scanf("%d", &t);
    for(t; t; t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        for(i = 0; i < (1<<n); i++)
        {
            int pre = i;
            vector<int>tmp;
            tmp.clear();
            for(j = 0; j < n; j++)
            {
                if(check_bit(i, j))
                {
                    tmp.PB(j);
                }
            }
            int sz = tmp.size();
            int lagbe = 0;
            for(j = 0; j < sz; j++)
            {
                for(k = 0; k < sz; k++)
                lagbe += mat[tmp[j]][tmp[k]];
            }
            cost[i] = lagbe;
        }
        clr(chk, false);
        int res = solve((1<<n) - 1);
        printf("Case %d: %d\n", cases++, res);
    }
    return 0;
}


/*


15 14 15
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
0 1 1
1 2 1
2 3 1
3 4 1
4 5 1
5 6 1
6 7 1
7 8 1
8 9 1
9 10 1
10 11 1
11 12 1
12 13 1
13 14 1



*/
