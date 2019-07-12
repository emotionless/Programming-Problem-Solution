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
LL power (int base, int p)
{
    LL ret = 1;

    for ( int i = 1; i <= p; i++ ) ret *= base;

    return ret;
}

int main ()
{
    int testCase; scanf ("%d", &testCase);
    int cases = 0;

    while ( testCase-- ) {
        LL n;
        cin >> n;
        n++;
        int i;

        for ( i = 0; i < 70; i++ ) {
            if ( power (2, i) >= n ) break;
        }

        printf ("Case %d: %d\n", ++cases, i);
    }

	return 0;
}
