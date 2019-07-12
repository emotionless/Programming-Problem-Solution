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
int main()
{
    int i,j,k;
    int n;
    cin>>n;
    int arr[100001];
    int res[100001];
    rep(i,1,n)
    {
        cin>>arr[i];
    }
    stack<int>ST;
    ST.push(1);
    rep(i,2,n)
    {
        int num=arr[i];
        while(!ST.empty() && arr[ST.top()]<num)
        {
            int top=ST.top();
            res[top]=i;
            ST.pop();
        }
        ST.push(i);
    }
    while(!ST.empty())
    {
        int ind=ST.top();
        res[ind]=0;
        ST.pop();
    }
    for(i=1; i<=n; i++)
    {
        cout<<res[i]<<endl;
    }
    return 0;
}


/*

6
3
2
6
1
1
1

*/
