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
#define clr(aa, bb) memset(aa, bb, sizeof aa)
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define vi vector<int>
#define vll vector<long long>


using namespace std;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,m;
    cin>>n>>m;
    int sum = 0;
    for(i= 0 ; i < n; i++)
    {
        cin>>a;
        sum+=a;
    }
    int tot = (n-1)*10 + sum;
    if(tot>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    int ans = (n-1)*2;
    int baki = m - tot;
    ans += (baki/5);
    cout<<ans<<endl;





    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1

3 28
2 2 1

*/
