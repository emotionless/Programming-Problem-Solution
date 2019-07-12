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
int main()
{
	int i,j,k;
	int n;
	scanf("%d",&n);
	long res=0,num,ans[500];
	for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    {
	        scanf("%ld",&num);
	        if(i!=j)
                res=(res | num);
	    }
	    ans[i]=res;
	    res=0;
	}
	for(i=0;i<n;i++)
	{
	    printf("%ld",ans[i]);
	    if(i<n-1)
            printf(" ");
	}
	cout<<endl;
}
