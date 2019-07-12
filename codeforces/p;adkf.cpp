
/*
2
0 0
2 1
*/
#include<bits/stdc++.h>
#define ll long long int
#define check(n,i) (n&(1<<i))
#define biton(n,i) (n|=(1<<i))
using namespace std;

int main()
{
    ll n,u,v,mx=0;
    vector<ll> a,f;
    scanf("%lld",&n);
    a.push_back(-10000000000);
    f.push_back(0);

    ll p;
    for(ll i=1; i<=n; i++)
    {
        f.push_back(0);
        scanf("%lld",&p);
        a.push_back(p);
        if(a[i]>a[mx])
        {
            mx=i;
        }
    }
    f[mx]=1;
    for(ll i=1; i<n; i++)
    {
        scanf("%lld%lld",&u,&v);
        if(u==mx)
        {
            if(!f[v])
            {
                a[v]++;
                f[v]=1;
            }
        }
        else if(v==mx)
        {
            if(!f[u])
            {
                a[u]++;
                f[u]=1;
            }
        }
    }

    ll mxn=-10000000000;
    for(ll i=1; i<=n; i++)
    {
        if(!f[i])
            a[i]+=2;
        mxn=max(mxn,a[i]);
    }
    printf("%lld\n",mxn);

    return 0;
}
