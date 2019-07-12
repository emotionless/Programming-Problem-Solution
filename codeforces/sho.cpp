#include <bits/stdc++.h>

using namespace std;
struct st
{
    long long delicious,price;
    bool operator < (const st& a)const
    {
        if(delicious==a.delicious) return price>a.price;
        return delicious>a.delicious;
    }
} ar[100006];

long long ts[100006];
int main()
{
    long long n,k,q,i,j,tmp1,tmp2;
    scanf("%lld%lld",&n,&q);
    for(i=0;i<n;i++){
        scanf("%lld",&tmp1);
        ar[i].price=tmp1;
    }
    for(i=0;i<n;i++){
        scanf("%lld",&tmp1);
        ar[i].delicious=tmp1;
    }
    sort(ar,ar+n);
    for(i = 0; i < n; i++)
        ts[i] = ts[i - 1] + ar[i].price;
    for(i=0;i<q;i++){
        scanf("%lld",&k);
        printf("%lld\n",ts[k - 1]);
    }

    return 0;
}
/*
5 3
1 2 8 3 4
2 4 10 5 6
3
5
2
*/
