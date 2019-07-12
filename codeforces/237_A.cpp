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
    int a,b;
    int n,g,m;
    string str[301];

    cin>>n;
    for(i=0; i<n; i++)
        cin>>str[i];
    map<char, int>M;
    int cnt=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            char cc=str[i][j];
            if(!M[cc])
                cnt++;
            M[cc]++;
        }
    }
    if(cnt>2 || cnt<2)
        cout<<"NO"<<endl;
    else
    {
        int tot=1;
        char cc=str[0][0];
        for(i=1; i<n; i++)
        {
            if(str[i][i]==cc)
                tot++;
        }
        for(i=0; i<n; i++)
        {
            if(str[i][n-i-1]==cc && i!=(n/2))
                tot++;
        }
        if(M[cc]==tot && M[cc]==(n*2-1))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

/*

5
mwwwm
wmwmw
wwwww
wmwmw
mwmwm

*/
