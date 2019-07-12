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
#define MAX 1009
#define PB push_back
#define sc(a) scanf("%d", &a)



using namespace std;

int  dp[1001][1001];
int  com[1001][1001];
int  arr[1001];

int  solve(int l, int r)
{
    if(l >= r) return 0;
    int  &ret = dp[l][r];
    if(l + 1 == r)
    {
        com[l][r] = l;
        return ret = arr[r] - arr[l - 1];
    }
    if(ret != -1) return ret;
    int  a = solve(l, r - 1);
    int  b = solve(l + 1, r);
    if(a < b)
    {
        ret = a;
        com[l][r] = r - 1;
    }
    else
        ret = b, com[l][r] = l + 1;
    for(int i = com[l][r - 1]; i <= com[l + 1][r]; i++)
    {
        int  tmp = solve(l, i) + solve(i + 1, r);
        if(tmp < ret)
        {
            ret = tmp;
            com[l][r] = i;
        }
    }
    ret = ret + arr[r] - arr[l - 1];
    return ret;
}



int main()
{
    int i,j;
    int cases=1;
    int t, w;
    int n, k;
    while(scanf("%d", &n)==1 && n)
    {
        scanf("%d", &k);
        for(i  = 1; i <= k; i++)
            scanf("%d", &arr[i]);
        memset(dp, -1, sizeof dp);
        k++;
        arr[k] = n;
        printf("The minimum cutting is %d.\n", solve(1, k));
        memset(com, 0, sizeof com);
    }


    return 0;
}
/*

6 3
1
1
1
1
1
0

*/
