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
#define EPS 1e-7

using namespace std;

int p,q,r,s,t,u;

double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double fd(double x)
{
    return -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x;

}

double newton()
{
    if (f(0)==0) return 0;
    for (double x=0.5; ;)              // initial guess x = 0.5
    {
        double x1 = x - f(x)/fd(x);      // x1 = next guess
        if (fabs(x1-x) < EPS) return x;  // the guess is accurate enough
        x = x1;
    }
}

int main()
{
    int i,j,k;
    while(scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)==6)
    {
        if(f(0)*f(1)>0)
            printf("No solution\n");
        else
            printf("%.4lf\n",newton());
    }
    return 0;
}
