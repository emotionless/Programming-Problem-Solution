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

LL tot[10];
LL arr[10];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,m;

    cin>>m>>n;
    vector<LL>res;
    res.clear();
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            cin>>arr[j];

        for(j=1; j<=n; j++)
        {
            tot[j]=max(tot[j-1], tot[j])+arr[j];
           // cout<<tot[j]<<" \n";
        }
        res.PB(tot[j-1]);

    }
    int sz=res.size();
    for(i=0; i<sz; i++)
        cout<<res[i]<<" ";






    return 0;
}

/*

4544545454

*/
