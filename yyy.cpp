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
#define MAX 30048

using namespace std;
int find(int x);
void search(int x);

int f[MAX];
int main()
{
    int i,j,k;
    int n,x,t;
    string str;
    map<string, int>m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i = n; i>0; i--)
        {
            cin>>str;
            m[str] = i;
            f[i] =0;
        }
        long res=0;
        for(i=1; i<=n; i++)
        {
            cin>>str;
            search(x=m[str]);
            res+=find(x-1);
        }
        cout<<res<<endl;
        m.clear();
    }
    return 0;
}

void search(int x)
{
    for(; x<MAX; x+=(x & -x))
        ++f[x];
}
int find(int x)
{
    int sum = 0;
    for(; x; x -= (x & -x)) sum += f[x];
    return sum;
}
