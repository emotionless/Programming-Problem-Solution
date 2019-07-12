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
    int n,num;

    while(scanf("%d",&n)==1 && n)
    {
        priority_queue<int, vector<int>, greater<int> >PQ;
        rep(i,0,n-1)
        {
            scanf("%d",&num);
            PQ.push(num);
        }
        long sum=0;
        while(PQ.size()>1)
        {
            num=PQ.top();
            PQ.pop();
            num+=PQ.top();
            PQ.pop();
            sum+=num;
            PQ.push(num);
        }
        printf("%ld\n",sum);
    }
    return 0;
}
