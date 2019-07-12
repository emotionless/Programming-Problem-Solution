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
int dp[210][25];
int main()
{
    int i,j,k;
    int q,n,D,M,a[210],arr[210];
    int set=0;
    while(scanf("%d %d",&n,&q)==2 && (n || q))
    {
        for(i=0; i<n; i++)
            cin>>arr[i];
        printf("SET %d:\n",++set);
        int query=0;
        for(i=0; i<q; i++)
        {
            memset(dp,0,sizeof dp);
            cin>>D>>M;
            dp[0][0]=1;
            for(j=0; j<n; j++)
                a[j]=(arr[j]%D+D)%D;
            for(j=0; j<n; j++)
            {
                for(k=M-1; k>=0; k--)
                {
                    for(int t=0; t<D; t++)
                    {
                        dp[k+1][(t+a[j])%D]+=dp[k][t];
                    }
                }
            }
            printf("QUERY %d: %d\n",++query,dp[M][0]);
        }
    }
    return 0;
}
