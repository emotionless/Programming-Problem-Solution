#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define M 1000000007

using namespace std;

/******************************End******************************/
ll  MX = 10000005;
ll pms[10000005];
bool isp[10000005];
int ind;
ll bigmod(ll p, ll e, ll m)
{
    ll ret=1;
    for(;e>0;e>>=1)
    {
        if(e&1) ret=(ret*p)%m;
        p=(p*p)%m;
    }
    return ret;
}
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
    for(ll i=3; i<=MX; i+=2)
    {
        if(!isp[i])
            pms[ind++] = i;
    }
}
int main()
{
    sieve();
    ll n;
    ll sz=ind;
    while(scanf("%lld",&n)==1&&n)
    {
        ll ans=1;
        for(ll i=0; pms[i]<=n&&i<sz; i++)
        {
            ll x=pms[i];
            ll cnt=0;
            while(n/x>0)
            {
                cnt+=n/x;
                x*=pms[i];
            }
            if(cnt%2==1)
                cnt--;
            ll y=bigmod(pms[i],(ll)cnt,(ll)M);
            ans=(ans*y)%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
