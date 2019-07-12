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

LL arr[100001];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    LL a,b;
    LL n,g,m, num;

    cin>>n>>a>>b;
    for(i=0; i<n; i++)
    {
        cin>>num;
        LL res=(num*a)/b;
        LL need=ceil(((double)res*b)/(double)a);

        cout<<num-need<<" ";
    }



    return 0;
}

/*

4544545454

*/
