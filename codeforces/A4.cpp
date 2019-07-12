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
#define eps 1e-9
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
int Bigmod ( long long a, int p, int m );

int main()
{
    int n,k,i,j;
    cin>>n>>k;
    int cnt=-1,sum=0,a,b;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        sum+=(b-a+1);
    }
    for(i=sum;;i++)
    {
        cnt++;
        if(i%k==0)
        break;
    }
    cout<<cnt<<endl;
    return 0;
}

/*
3 7
1 2
3 3
4 7
*/
