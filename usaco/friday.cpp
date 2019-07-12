
/*
 ID: milon_c1
 LANG: C++
 PROG: friday
 */

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
#define eps 1e-9
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
int isLeap(int y)
{
    return y % 4 == 0 && (y % 100 != 0 || (y % 100 == 0 && y % 400 == 0));
}

int main()
{
    ofstream fout("friday.out");
    ifstream fin("friday.in");

    int nm[][12] = { { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
    int sum[8] = { 0};
    int N, d = 0, md = 0, wd = 3, m = 0, y = 1900;
    fin >> N;

    while (y < 1900 + N && ++d && ++md)
    {
        if (md == 13)
            sum[wd]++;
        if (d == 365 + isLeap(y))
            y++, m = md = d = 0;
        if (md == nm[isLeap(y)][m])
            m++, md = 0;
        wd = (wd % 7) + 1;
    }

    for (int i = 1; i < 7; i++)
        fout << sum[i] << " ";
    fout << sum[7] << endl;
    return 0;
}
