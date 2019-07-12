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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i,j,k;
    int n,lim;
    int cnt=101;
    int data[15][35];
    int arr[501];
    rep(i,1,12)
    {
        if(i==2)
            lim=28;
        else if(i==1 || i==3 || i==5 || i==7 || i==8 || i==10 || i==12)
            lim=31;
        else
            lim=30;
        rep(k,1,lim)
        data[i][k]=cnt++;
    }
    scanf("%d",&n);
    rep(i,1,500)
    arr[i]=0;
    int m,d,p,t;
    int maxn=0;
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d %d",&m,&d,&p,&t);
        int tmp=data[m][d];
        int td=tmp-t;
        rep(k,td,tmp-1)
        {
            arr[k]+=p;
            maxn=max(arr[k],maxn);
        }
    }
    cout<<maxn<<endl;
    return 0;
}
