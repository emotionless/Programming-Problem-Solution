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
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;

struct Z
{
    int x;
    int y;
    bool operator<(const Z& A) const
    {
        if(x==A.x) return y<A.y;
        return x<A.x;
    }
};

vector<Z>point;
vector<Z> hull(1001);


double cross(Z i, Z j, Z k)
{
    return ( (k.y - i.y) * (j.x - i.x) - (j.y - i.y) * (k.x - i.x) );
}

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    Z tmp;
    int n, x, y;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x>>y;
        tmp.x=x;
        tmp.y=y;
        point.PB(tmp);
    }
    // sort it according to x (if tie then y)
    sort(point.begin(), point.end());

    // Build lower hull
    int k=0;
    for(i=0; i<n; i++)
    {
        while(k>=2 && cross(hull[k-2], hull[k-1], point[i]) <= 0) k--;
        hull[k++] = point[i];
    }

    // Build upper hull
    int t = k + 1;      // t is the lowest point where it can comes
    for(i = n-2; i >= 0; i--)
    {
        while(k>=t && cross(hull[k-2], hull[k-1], point[i]) <= 0) k--;
        hull[k++] = point[i];
    }

    hull.resize(k);
    cout<<k<<endl;
    for(i=0; i<k; i++)
        cout<<hull[i].x<<" "<<hull[i].y<<endl;





    return 0;
}

/*

7
0 3
2 2
1 1
2 1
3 0
0 0
3 3



*/
