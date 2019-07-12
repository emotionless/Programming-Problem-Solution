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
    long val[100005];
    int n;
    scanf("%d",&n);
    int h[100005];
    for(int i=0; i<n; i++)
    {
        h[i]=0;
        scanf("%ld",&val[i]);
    }
    int l=0;
    int mxv=0,mx=0;
    while(l<n)
    {

        for(i=l+1; i<n; i++)
        {
            if(val[l]<val[i])
            {
                h[l]++;
            }
            else
            {
                break;
            }
        }

        if(h[l]>mx)
        {
            mx=h[l];
            mxv=l;
        }
        l=i;
    }
    printf("%d\n",mxv);
    return 0;
}

/*

6
2 5 3 4 1 9

*/
