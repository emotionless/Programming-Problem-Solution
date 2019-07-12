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

LL arr[1001];
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g,m,K;
    cin>>n>>K;
    memset(arr, 0, sizeof arr);
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    vector<LL>V;

    V.clear();

    for(i=0; i<n; i++)
    {
        LL cn=arr[0]+K*i;
        if(cn==arr[i]) continue;
        if(arr[i]<cn)
        {
            V.PB('+');
            V.PB(i);
            V.PB(cn-arr[i]);
        }
        else if(arr[i]>cn)
        {
            V.PB('-');
            V.PB(i);
            V.PB(arr[i]-cn);
        }
    }
    int sz=V.size();
    cout<<sz/3<<endl;
    for(i=0; i<sz; i+=3)
        cout<<(char)V[i]<<" "<<V[i+1]+1<<" "<<V[i+2]<<endl;;
    V.clear();



    return 0;
}

/*

4544545454

*/
