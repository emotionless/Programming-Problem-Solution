#include<bits/stdc++.h>
#define ll long long

template <class T> inline T bigmod(T p,T e,T M)
{
    ll ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}

#define M 1000000007
#define MX 10000005

using namespace std;

int pms[1000005];
bool isp[10000005];

int ind = 0;

void sieve()
{
    for(ll i=4; i<=MX; i+=2)
        isp[i]=1;
    for(ll i=3; i*i<=MX; i+=2)
    {
        if(!isp[i])
        {
            for(ll j=i*i; j<=MX; j+=2*i)
                isp[j]=1;
        }
    }
    pms[ind++] = 2;
    for(int i=3; i<=MX; i+=2)
    {
        if(!isp[i])
            pms[ind++] = i;
    }
}
int main()
{
    sieve();
    ll n, y;
    ll sz=ind;
    while(scanf("%lld",&n)==1 && n)
    {
        ll ans=1;
        for(int i=0; pms[i]<=n&&i<ind; i++)
        {
            ll x=pms[i];
            int cnt=0;
            while(n/x>0)
            {
                cnt+=n/x;
                x*=pms[i];
            }
            if(cnt%2==1)
                cnt--;
            y=bigmod((ll)pms[i],(ll)cnt,(ll)M);
            ans=(ans*y)%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
