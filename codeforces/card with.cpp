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

using namespace std;

vector< int>V[60001];
map<int, int>M;
int main()
{
    freopen("input.txt", "r", stdin);
 	freopen("output.txt", "w", stdout);
    int i,j;
    long n;
    scanf("%ld",&n);
    int ans=0;
    int k=1,a;
    int cnt=0;
    for(i=1; i<=2*n; i++)
    {
        scanf("%d",&a);
        V[a].PB(i);
    }
    int ms=0;
    for(i=1;i<=5000;i++)
    {
        if(V[i].size()%2!=0)ms++;
    }
    if(ms!=0)
    {
        cout<<-1<<endl;
        return 0 ;
    }
    for(i=1;i<=5000;i++)
    {
        for(j=0;j<V[i].size();j+=2)
        {
            if(j<V[i].size()-1)printf("%d %d\n",V[i][j],V[i][j+1]);
        }
    }
    return 0;
}
