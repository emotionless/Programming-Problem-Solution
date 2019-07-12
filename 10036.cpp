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
#define rep(i,a,b) for(i=a;i<b;i++)

using namespace std;
int N,K;
int dp[10001][101];
int arr[10001];

bool solve(int ind, int sum)
{
    sum=((sum%K)+K)%K;
    if(ind==N)
    {
        if(sum%K==0)
            return true;
        return false;
    }
    int &ret=dp[ind][sum];
    if(ret!=-1) return ret;
    ret=0;
    ret= ret|solve(ind+1, (sum+arr[ind])%K);
    ret= ret|solve(ind+1, (sum-arr[ind])%K);
    return ret;
}

int main()
{
    int i,j,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>K;
        rep(i,0,N)
        {
            cin>>arr[i];
            arr[i]=arr[i]%K;
        }

        memset(dp, -1, sizeof dp);
        bool res=solve(0,0);
        if(res==true)
            cout<<"Divisible"<<endl;
        else
            cout<<"Not divisible"<<endl;
    }
    return 0;
}

