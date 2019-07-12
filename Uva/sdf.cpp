#include <algorithm>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
#include <iostream>

#define MX 1001

using namespace std;

struct Z
{
    int side[3];
    double g;
    bool operator< (const Z& A) const
    {
        return g < A.g;
    }
};

Z arr[MX];

int dp[1001][1001][3];
int n;
int solve(int pre, int cur, int side)
{
    if(cur > n)
        return 0;

    int &ret = dp[pre][cur][side];
    if(ret != -1) return ret;
    ret = 0;

    ret = solve(pre, cur + 1, side);

    if(pre == 0)
    {
        for(int i = 0; i < 3; i++)
            ret = max(ret, 1 + solve(cur, cur + 1, i));
      //  cout<<pre<<" "<<cur<<" "<<side<<" "<<ret<<endl;
        return ret;
    }
    for(int i = 0; i < 3; i++)
    {
        if(i == side) continue;
        for(int j = 0; j < 3; j++)
        {
            if(arr[pre].side[i] == arr[cur].side[j] && arr[pre].g < arr[cur].g)
            {
                ret = max(ret, 1 + solve(cur, cur + 1, j));
            }
        }
    }
   // cout<<pre<<" "<<cur<<" "<<side<<" "<<ret<<endl;
    return ret;
}


int main()
{
    int m, u, v, i, j;
    long long w;
    int t;
    cin>>n;
    Z tmp;
    for(i = 1; i <= n; i++)
    {
        cin>>tmp.side[0]>>tmp.side[1]>>tmp.side[2]>>tmp.g;
        arr[i] = tmp;
    }
    sort(arr + 1, arr + n);

    memset(dp, -1, sizeof dp);

    int res = solve(0, 1, 0);

    cout<<res<<endl;








    return 0;
}

/*



1
3 4 4 0.4


*/
