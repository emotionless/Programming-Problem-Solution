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
int func(int s);


int f[1001];
int n,P[1001],V[1001];

void init()
{
    memset(f,0,sizeof f);
}

int main()
{
    int i,j,k;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>P[i]>>V[i];
        }
        int q,search,res=0;
        cin>>q;
        for(i=0; i<q; i++)
        {
            cin>>search;
            int c=func(search);
            res+=c;

        }
        cout<<res<<endl;
    }
    return 0;
}

int func(int s)
{
    init();
    for(int i=0; i<n; i++)
    {
        for(int j=s; j>=V[i]; j--)
        {
            f[j]=max(f[j],f[j-V[i]]+P[i]);
            //     cout<<f[j]<<endl;
        }
    }
    return f[s];
}
