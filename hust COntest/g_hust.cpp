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


int arr[101];
int dp[101][101];
int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i, j, k;
    int t;
    int cases = 1;
    int K;
    int n, m;
    LL a, b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i = 1; i <= n; i++)
            cin>>arr[i];
        for(i = 0; i <= n; i++)
            for(j = i; j <= n; j++)
                dp[i][j] = j - i + 1;

        for(i = n - 1; i >= 1; i--)
        {
            for(j = i; j <= n; j++)
            {
                dp[i][j] = dp[i + 1][j] + 1;
                for(k = i + 1; k <=j; k++)
                {
                    if(arr[i] == arr[k])
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
        printf("Case %d: %d\n", cases++, dp[1][n]);
    }


    return 0;
}

/*

1
This can't be solved by brute force.

*/
