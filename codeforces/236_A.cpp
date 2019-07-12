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

int arr[1001];
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g,m,K;
    cin>>n>>K;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    vector<int>res,V;
    res.clear();
    V.clear();
    res.resize(1001);
    for(i=1; i<=1000; i++)
    {
        V.clear();

        for(j=0; j<n; j++)
        {
            int cn=i+j*K;
            if(arr[j]<cn)
            {
                V.PB('+');
                V.PB(j);
                V.PB(cn-arr[j]);
            }
            else if(arr[j]>cn)
            {
                V.PB('-');
                V.PB(j);
                V.PB(arr[j]-cn);
            }
        }
        if(V.size()<res.size()){
            res=V;
            //copy(V.begin(), V.end(), res.begin());
        }
    }

    int sz=res.size();
    cout<<sz/3<<endl;
    for(i=0; i<sz; i+=3)
        cout<<(char)res[i]<<" "<<res[i+1]+1<<" "<<res[i+2]<<endl;

    res.clear();

    return 0;
}

/*

4544545454

*/
