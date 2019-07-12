#include<bits/stdc++.h>
#define LL long long
#define eps 1e-12

using namespace std;

int main()
{
    double n,k;
    double res=0.0;

    while(scanf("%lf %lf", &n, &k)==2)
    {
        double rest=n-k;
        double live=n-2.0*k;
        res=live/rest;
        if(res<=0) res=0.0;
        printf("%.10lf\n", res);
    }
    return 0;
}
