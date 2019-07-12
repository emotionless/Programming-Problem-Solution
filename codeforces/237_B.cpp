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

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;

    double a,d;
    int n;
    cin>>a>>d;
    cin>>n;

    double tot=4*a;

    d=d-((int)(d/tot))*tot;

    double curr, res;
    curr=0.0;
    for(i=1; i<=n; i++)
    {
        curr=curr+d;
        res=curr=curr-((int)(curr/tot))*tot;
        if(res<=a)
        {
            printf("%.10lf %.10lf\n", res, 0.0);
        }
        else if(res<=(2*a))
        {
            res=res-a;
            printf("%.10lf %.10lf\n", a, res);
        }
        else if(res<=(3*a))
        {
            res=res-(2*a);
            printf("%.10lf %.10lf\n", a-res, a);
        }
        else
        {
            res=res-(3*a);
            printf("%.10lf %.10lf\n", 0.0, a-res);
        }
    }

    return 0;
}

/*

4544545454

*/
