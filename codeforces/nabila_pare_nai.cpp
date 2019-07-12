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

long solve(int ind, int total, int cost);

int dp[101][501];
int C[101],W[101];

long h,n;

int main()
{
    int i,j,k;
    cin>>n>>h;
    for(i=0; i<n; i++)
    {
        scanf("%d %d",&W[i],&C[i]);
    }
    for(i=0; i<101; i++)
    {
        for(j=0; j<=500; j++)
            dp[i][j]=-1;
    }

    long res=solve(0,0,0);
    cout<<res;

}

long solve(int ind,int total, int cost)
{
    // cout<<"hm\n";
    if(total==h)
    {
        //   cout<<ind<<ends<<cost<<endl;
        return cost;

    }
    if(ind>=n)
        return 214748;
    if(total>h)
        return 214748;
    if(dp[ind][total]!=-1)
        return dp[ind][total];
    long c2=solve(ind+1,total,cost); // nibona
    long c3=solve(ind,total+W[ind],cost+C[ind]); // niyeci and abar nibo.
    long c1=solve(ind+1,total+W[ind],cost+C[ind]); // niyeci and porer ta nibo
    dp[ind][total]=min(min(c1,c2),c3);
    return dp[ind][total];
}

/*

2 15
3 2
5 3


5 20
2 3
4 5
2 6
2 5
5 3


*/
