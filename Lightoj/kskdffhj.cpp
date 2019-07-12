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
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define MX 211
#define MAX 100009
#define PB push_back
#define inf 1e8



using namespace std;

bool arr[MAX];
int dp[101][2][4];
int n;
int solve(int ind, bool is, int cnt)
{
    if(ind == n)
    {
        return 0;
    }
    int &ret = dp[ind][is][cnt];
    if(ret != -1) return ret;
    ret = solve(ind + 1, 1, 2) + ((arr[ind]==1)?0:1);
    if(cnt == 1)
    {
        ret = min(ret,  ((arr[ind]==1)?0:1) +solve(ind + 1, 1, cnt + 1) );
    }
    else
    {
        ret = min(ret,  solve(ind + 1, 0, 1) );
    }

    return ret;
}

int main()
{
    int i,j,k;
    int cases=1;
    int u, v, w, t;
    int pre = 1;

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i = 0; i < n; i++)
            cin>>arr[i];
        memset(dp, -1, sizeof dp);
        int ans = solve(0, 0, 0);

        cout<<ans<<endl;
    }





    return 0;
}
/*


1
5
0 0 1 0 0

*/
