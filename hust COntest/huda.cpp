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
#define MX 100001
#define MAXN 50009
#define MOD 1000000000+7
#define PB push_back
#define FOR(ii,aa,bb) for(ii=aa; ii<=bb; ii++)
#define loop(aa) for(int ii=0; ii<aa; ii++)
#define rep(i,bb) for(i=0; i<bb; i++)
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define mp make_pair

using namespace std;
int A, B, M, L, K;
bool chk[101][101];
int n;
int cost[101][101];
void Floyd_Warshall()
{
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
                if(k != i && k != j)
                {
                    int t = cost[i][k] + cost[k][j];
                    if(t < cost[i][j])
                    {
                        cost[i][j] = t;
                        if(k <= A && cost[i][j] <= L)
                            chk[i][j] = chk[j][i] = true;
                    }
                }
        }
    }
//    for(int i = 0; i < n; i++)
//        for(int j = 0; j < n; j++)
//        cout<<i<<" "<<j<<" "<<cost[i][j]<<endl;
}


int dp[101][101];

void get_minimum()
{
    memset(dp,  0x3f, sizeof dp);

    for(int i = 1; i <= n; i++)
        dp[i][0] = cost[1][i];
    for(int i = 0; i <= K; i++)
        dp[1][i] = 0;

    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= K; k++)
        {
            for(int j = 1; j <= i; j++)
            {
                if(chk[j][i])
                    dp[i][k] = min(dp[i][k], dp[j][k - 1]);
                dp[i][k] = min(dp[i][k],  dp[j][k] + cost[j][i]);
            }
        }
    }


}



int  main()
{
    int i, j, k, u, v, w, t;
    cin>>t;
    while(t--)
    {
        cin>>A>>B>>M>>L>>K;
        memset(chk, false, sizeof chk);
        n = A + B;
        memset(cost, 0x3f, sizeof cost);
        for(i = 0; i < M; i++)
        {
            cin>>u>>v>>w;
            cost[u][v] = cost[v][u] = w;
            if(w <= L)
                chk[u][v] = chk[v][u] = true;
        }
        Floyd_Warshall();
        get_minimum();
        cout<<dp[n][K]<<endl;
    }




    return 0;
}
/*

3 10 9
5 3 7

4 6 7
2 4 1 6

70 416035 416023
70034 70322 345689 345965 345701 70046 345737 345713 70166 345821 70010 345749 345677 345725 69962 345869 70178 70310 345785 69998 70070 69974 70058 346001 70106 345953 70226 70154 345929 69950 70298 346049 70346 345989 70286 69986 345893 70082 70238 345797 70250 345833 70334 345845 70094 70118 70202 345977 70262 70274 70190 345941 346025 345761 345773 70142 70022 70130 345881 345917 70358 345905 345665 346013 346061 345809 345857 346037 346073 70214

*/
