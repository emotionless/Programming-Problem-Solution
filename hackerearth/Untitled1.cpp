#include<bits/stdc++.h>

#define LL long long
#define inf 1000000
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a,b) memset(a,b,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define MOD 1000000007ll
#define MP make_pair
#define MX 100000

using namespace std;
LL call(int x)
{
    int sq=sqrt(x);
    LL ret=0ll;
    for(int i=1; i<=sq; i++)
    {
        int xx=x/i;
        xx-=(i-1);
        ret+=(2ll*xx)-1ll;
    }
    return ret;
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int kase=1; kase<=test; kase++)
    {
        int n;
        scanf("%d",&n);
        LL cnt=0ll;
        for(int i=1; i<n; i++)
        {
            int mx=i*(n-i);
            cnt+=call(mx-1);
        }
        printf("%lld\n",cnt);
    }
    return 0;
}
