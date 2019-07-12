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
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
int solve(int ind, int sum);

int dp[101][10001];
int n,m,p[101],f[1001];


int main()
{
    int i,j,k;
    while(scanf("%d %d",&m,&n)==2 )
    {
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&p[i],&f[i]);
        }
        if(m>2000)
            m+=200;
        for(i=0; i<101; i++)
        {
            for(j=0; j<10001; j++)
            {
                dp[i][j]=-1;
            }
        }
        int res=solve(0,m);
        cout<<res<<endl;
    }
}


int solve(int ind, int sum)
{
    if(sum==0) return 0;
    if(ind>=n) return 0;
    if(sum<0) return 0;

    if(dp[ind][sum]!=-1) return dp[ind][sum];
    int res1=0,res2=0;
    if(sum-p[ind]>=0)
        res1=max(f[ind]+solve(ind+1,sum-p[ind]),solve(ind+1,sum));
    else
        res2=solve(ind+1,sum);

    return dp[ind][sum]=max(res1,res2);
}

/*

500 4
200 4
200 3
400 4
200 3


1981 75
3199 4
26 5
1114 1
1203 1
2341 2
2255 5
824 1
465 1
485 1
2977 2
2431 5
2197 3
1665 2
940 1
3619 2
2427 3
2269 2
1374 4
2825 2
2984 2
2558 2
2422 5
1635 1
1493 3
37 2
3918 1
2269 2
3470 4
2686 3
1281 1
2144 4
1472 2
2863 2
3794 5
1773 2
3555 4
1070 5
63 1
1213 5
1528 2
2728 1
67 5
3910 3
1632 3
649 5
898 3
2971 4
3555 1
1917 5
3871 5
3180 5
371 2
1752 5
3306 3
2340 2
917 3
2629 4
3118 1
1575 3
1484 4
13 5
1718 1
1453 1
1520 5
1676 4
3410 3
1519 1
1105 1
213 3
2939 2
1946 4
674 2
1894 4
3463 1
540 1

*/
