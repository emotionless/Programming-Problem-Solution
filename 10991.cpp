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
#define PI 3.141592653589793
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
double getAngle(double A, double B, double C);
double getArea(double A, double B, double C);

double getArea(double A, double B, double C)
{
    double s=(A+B+C)/2.0;
    return sqrt(s*(s-A)*(s-B)*(s-C));
}
double getAngle(double A,double B,double C)
{
    return acos((A*A+B*B-C*C)/(2*A*B));
}

int main()
{
    int i,j,k;
    int n;
    double r1,r2,r3;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&r1,&r2,&r3);
        double A=r1+r2;
        double B=r3+r2;
        double C=r1+r3;
        double area=getArea(A,B,C);
        double a1 = (PI*r3*r3)*(getAngle(B,C,A)/(2*PI));
        double a2 = (PI*r1*r1)*(getAngle(C,A,B)/(2*PI));
        double a3 = (PI*r2*r2)*(getAngle(A,B,C)/(2*PI));
        area=area-a1-a2-a3;
        printf("%.6lf\n",area);
    }
    return 0;
}

