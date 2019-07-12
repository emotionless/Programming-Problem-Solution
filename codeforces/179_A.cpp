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
    int n;
    int i,j,k;

    int val[1001];
    cin>>n;
    int mx=0;
    clr(val,0);
    rep(i,0,n-1)
    {
        cin>>k;
        val[k]++;
        mx=max(mx,val[k]);
    }
    if(n%2==0)
    {
        if(mx>n/2)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    else
    {
        if(mx>(n/2+1))
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}

