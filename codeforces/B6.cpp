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
    long i,j,k,n,t;
    cin>>n>>t;
    long sum[100001],arr[100001];
    sum[0]=0;
    for(i=1; i<=n; i++)
    {
        scanf("%ld",&arr[i]);
        sum[i]=sum[i-1]+arr[i];
        // cout<<i<<ends<<sum[i]<<endl;
    }
    long mx=0;
    for(i=1; i<=n; i++)
    {
        long temp=sum[i+mx]-sum[i-1];
        if(temp<=t)
        {
            for(j=i+mx; j<=n; j++)
            {
                long add=sum[j]-sum[i-1];
                if(add>t)break;
                mx=max(mx,(j-i+1));

            }
        }
    }    printf("%ld\n",mx);
}

/*
4 5
3 1 2 1

*/
