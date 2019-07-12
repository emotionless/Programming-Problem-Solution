#include<bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
    LL a,b;
    int cases=1;

    while(scanf("%lld %lld",&a, &b)==2 && a &&b)
    {
        a=(a*(a-1))/2;
        b=(b*(b-1))/2;
        printf("Case %d: %lld\n", cases++, a*b);
    }
    return 0;
}
