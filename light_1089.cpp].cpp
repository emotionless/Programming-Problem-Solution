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
#define loop(n) for(int o=1;o<=n;o++)

using namespace std;

int main()
{
    int i,t,cases=0;

    int n,q,a,b;
    scanf("%d",&t);
    while(t--)
    {
        map<int,int>M;
        scanf("%d %d",&n,&q);
        int mx=0;
        loop(n)
        {
            scanf("%d %d",&a,&b);
            M[a]++;
            M[b+1]--;
            mx=max(mx,b);
        }
        int sum=0;
        for(i=0; i<=mx+1; i++)
        {
            M[i]=sum+M[i];
            sum=M[i];
        }
        printf("Case %d:\n",++cases);
        loop(q)
        {
            scanf("%d",&a);
            printf("%d\n",M[a]);
        }
    }
}
