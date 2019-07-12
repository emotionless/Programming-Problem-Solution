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

    LL i,j;
    int a,b;
    LL n,g,m;

    cin>>n>>m;
    if(n==1 && m==0)
    {
        cout<<1<<endl;
        return 0;
    }
    if(m<n/2 || n==1)
    {
        cout<<-1<<endl;
        return 0;
    }
    LL rst=m-(n/2-1);

    cout<<rst<<" "<<rst*2;
    map<LL, bool>M;
    M.clear();
    M[rst]=true;
    M[rst*2]=true;
    LL cn=1;
    for(i=4; i<=n; i=i+2)
    {
        while(M[cn] || M[cn+1])
        {
            M[cn]=true;
            cn++;
        }
        cout<<" "<<cn<<" "<<cn+1;
        cn+=2;
    }
    if(n%2)
    {
        while(M[cn])
            cn++;
        cout<<" "<<cn<<endl;
    }





    return 0;
}

/*

4544545454

*/
