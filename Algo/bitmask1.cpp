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
    int n,y;
    y=30;
    y = y | ( y >>1 ) ;
    cout<<y<<endl;
    y = y  | ( y >>2 );
    cout<<y<<endl;
    y = y  | ( y >>4 );
    cout<<y<<endl;
    y = y  | ( y >>8 );
    cout<<y<<endl;
    y = y  |  ( y >>16 ) ;
    cout<<y<<endl;
}
