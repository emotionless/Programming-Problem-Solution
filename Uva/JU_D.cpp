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
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long

using namespace std;
int main()
{
    int i,j,k;
    long n,m;
    while(cin>>n>>m)
    {
        if(n==0 &&m==0)
            cout<<"0 0\n";
        else if(n==0)
            cout<<"Impossible"<<endl;
        else if(m==0)
            cout<<n<<" "<<n<<endl;
        else
        {
            int ans=(m>=n)?m:n;
                cout<<ans<<" "<<n+m-1<<endl;
        }
    }
    return 0;
}
