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

bool visited[101];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b,l,r;
    int n,g;
    cin>>n;

    cin>>a>>b;
    for(i=1; i<n; i++)
    {
        cin>>l>>r;
        if(l>r)
            swap(l,r);

        for(j=l+1; j<=r; j++)
            visited[j]=true;
    }
    int cnt=0;
    for(i=a+1; i<=b; i++)
    {
        if(!visited[i])
            cnt++;
    }
    cout<<cnt<<endl;
    memset(visited, false, sizeof visited);




    return 0;
}

/*

4544545454

*/
