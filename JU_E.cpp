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
LL func();
LL n;
int main()
{
    int i,j;
    cin>>n;
    if(n==1)
        cout<<"1";
    else if(n==2)
        cout<<"2";
    else
    {
        cout<<func();
    }
    cout<<endl;
    return 0;
}
LL func()
{
    LL res;
    if(n%2!=0)
        res=n*(n-1)*(n-2);
    else if(n%3!=0)
        res=n*(n-1)*(n-3);
    else
        res=(n-1)*(n-2)*(n-3);
return res;
}

