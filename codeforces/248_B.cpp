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
#define vi vector<int>
#define vll vector<long long>


using namespace std;

int n;
LL arr[100002];
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;

    cin>>n;
    LL mx=0;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        if(i)
            mx+=abs(arr[i]-arr[i-1]);
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    LL res=INT_MAX;
    for(i=0; i<n; i++)
    {

        if(i<n-1)
        {
            LL now=arr[i+1];
            LL tmp = mx -abs(arr[i+1]-arr[i]) - abs(arr[i]-arr[i-1]);
            tmp+=abs(arr[i-1]+now);
            res=min(res,tmp);
        }
        if(i-1>=0)
        {
            LL now=arr[i-1];
            LL tmp=0;
            tmp = mx -abs(arr[i+1]-arr[i]) - abs(arr[i]-arr[i-1]);
            tmp+=abs(arr[i-1]+now);
            res=min(res,tmp);
        }

    }
    cout<<res<<endl;



    return 0;
}

/*

7 3
5 5 5 5 5 5
1 3 4
4 5 2
6 3 1



*/
