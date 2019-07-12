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
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
int main()
{
    ULL lb,ub;
    int i,j,k;
    cin>>lb>>ub;
    i=0;
    ULL num=ub;
    int count=0;
    while(num)
    {
        count++;
        num=num>>1;
    }
    i=count;
    cout<<i<<endl;
    for(j=i-1; j>=0; j--)
    {
        if((lb & 1<<j) &&(ub & 1<<j))
        {
            j=j;
            cout<<"Fierst : "<<j<<endl;
        }
        else if((lb & 1<<(j))==0 &&(ub & 1<<j)==0)
            j=j;
        else
        {
            cout<<j<<endl;
            break;
        }
    }
    ULL res=1;
    if(j==-1)
        cout<<"0\n";
    else
    {

        for(i=1; i<=j; i++)
            res=res*2;
        cout<<res*2-1<<endl;
    }
    cout<<(ub & 1<<29)<<endl;

    return 0;
}
// 34359738367
