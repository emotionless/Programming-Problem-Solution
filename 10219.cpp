#include<bits/stdc++.h>
#define LL long long

using namespace std;

int main()
{
    int i,k,j;
    int t,n;

    while(cin>>n>>k)
    {
        double sum=0.0;
        for(i=max(n-k,k)+1; i<=n; i++)
            sum+=log10(i);
        for(i=1;i<=min(n-k,k);i++)
        sum-=log10(i);

        LL res=floor(sum)+1;
        cout<<res<<endl;
    }
    return 0;
}

/*

20 5
100 10
200 15

*/
