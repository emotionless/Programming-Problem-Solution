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

using namespace std;

int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int n, m, r, u, v;

    cin>>n;
    long long h = 0, l = 1000009, lft = 100000009, rgt = 0, x, y;
    for(i = 0; i < n; i++)
    {
        cin>>x>>y;
        h = max(h, y);
        l = min(l, h);

        lft = min(lft, x);
        rgt = max(rgt, x);
    }

    LL one = h - l + 1;
    LL two = rgt - lft + 1;
    cout<<2*(one + two)<<endl;






    return 0;
}
/*

2
SQ 1 0
SQ 0 0
SQ 6 0
SQ 5 0



*/
