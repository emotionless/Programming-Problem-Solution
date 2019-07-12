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
#define MAX 1000010

using namespace std;
void  solve();
int n;

int num[MAX];

int main()
{
    int i,j,k,t=0;
    while(cin>>n && n)
    {
        for(i=0; i<n; i++)
            scanf("%d",&num[i]);
        if(t++)cout<<endl;
        solve();
    }
    return 0;
}


void  solve()
{
    int i,j;
    sort(num,num+n);
    vector<int>V[n];
    int pre=0,cur=0;
    int mx=0;
    while(cur<n)
    {
        pre=cur;
        while(cur<n && num[cur]==num[pre]) ++cur;
        mx=max(mx,cur-pre);
    }
    for(i=0; i<n; i++)
        V[i%mx].PB(num[i]);

    cout<<mx<<endl;
    for(i=0; i<mx; i++)
    {
        cout<<V[i][0];
        for(j=1; j<V[i].size(); j++)
            cout<<" "<<V[i][j];
        cout<<endl;
    }
    for(i=0; i<=n; i++)
        V[i].clear();
}
