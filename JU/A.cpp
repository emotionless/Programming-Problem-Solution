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




int main()
{
    int i,j;
    int cases=1;
    int t, w;
    int n, k;
    while(scanf("%d %d", &n, &k)==2)
    {
        for(i  = 1; i <= k; i++)
            scanf("%d", &arr[i]);
        memset(dp, -1, sizeof dp);
        k++;
        arr[k] = n;
        printf("%d\n", solve(1, k));
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
