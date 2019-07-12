#include<bits/stdc++.h>
/**Define file I/O **/
#define f_input freopen("input.txt","r",stdin)
#define f_output freopen("output.txt","w",stdout)
/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
/**Define function and object**/
#define SQR(x) ((x)*(x))
#define DIS(a,b,c,d) sqrt(SQR(a-c)+SQR(b-d))
/**Define constant value**/
#define ERR 1e-9
#define pi (2*acos(0))
#define pb push_back
#define mp make_pair
//#define M 1000000007
#define pii pair<ll,ll>
/**Define input**/
/** priority_queue<ll,vector<ll>, prioritycom > pq **/
/**  set<ll>::iterator it **/
using namespace std;
/**Typedef**/
typedef long long int ll;
const ll INF=0x7FFFFFFF;
/**Template & structure**/

/*template<class T>T bigmod(T n,T p,T m)
{
    if(p==0)return 1;
    if(p%2==0)
    {
        T t=bigmod(n,p/2,m);
        return (t*t)%m;
    }
    return (bigmod(n,p-1,m)*n)%m;
}
*/
#define M 1000000007
/******************************End******************************/
vector<ll>pms;
bool isp[10000005];
ll MX=10000005;
template <class T> inline T bigmod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
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
    pms.pb(2);
    for(ll i=3; i<=MX; i+=2)
    {
        if(!isp[i])
            pms.pb(i);
    }
}
int main()
{
    sieve();
    ll n;
    ll sz=pms.size();
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
            ll y=bigmod(pms[i],cnt,(ll)M);
            ans=(ans*y)%M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
