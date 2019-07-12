
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
    long i,j,k;
    long n,res=0;
    cin>>n;
    long l=sqrt(n)+1;
    long temp;
    for(i=2; i<=l; i++)
    {
        long x=n/i;
        res+=(i*(x-1));
        temp=(x*((n/x)-1));
        if(x!=i)
            res+=temp;

    }

    cout<<res-temp<<endl;
    return 0;
}

