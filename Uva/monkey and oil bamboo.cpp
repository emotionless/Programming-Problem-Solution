#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<climits>
#define PB(A) push_back(A)
#define INF long_MAX
#define MX 100010
using namespace std;
int main()
{
    long long int t,caseno=1;
    for(scanf("%lld",&t); caseno<=t; ++caseno)
    {
        long long int n,i,count=-1,a[100100];

        scanf("%lld",&n);

        a[0]=0;
        for(i=1; i<=n; ++i)
        {
            scanf("%lld",&a[i]);
        }

        for(i=0; i<n; i++)
        {
            a[i]=a[i+1]-a[i];
        }

        i--;
        for(; i>=0; i--)
        {
            if(a[i]>count) count = a[i];
            else if(a[i]==count) count++;
        }

        printf("Case %lld: %lld\n",caseno,count);
    }

    return 0;
}
