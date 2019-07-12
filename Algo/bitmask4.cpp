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
#include <stdio.h>
#include <iostream>
#define BIT(i) (1LL << i)
#define OR(x,i) (x | BIT(i))
#define AND(x,i) (x & BIT(i))

int main()
{
	long long n, L, U, ans, i;
	scanf("%lld%lld%lld", &n, &L, &U);
	{
		ans = 0;
		for (i = 31; i >= 0; i--)
			if ( OR(ans, i) <= (AND(n, i) ? L: U) )
			{

			    ans |= BIT(i);
			    cout<<i<<ends<<ans<<endl;
			}
		//printf("%lld\n", ans);
	}
}
