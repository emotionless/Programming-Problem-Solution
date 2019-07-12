#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <climits>
#define LL long long
#define MX 120001



using namespace std;

/*

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}




bool is_prime[MAX];
L prime[MAX];

bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/
int n,L,D;
int dis[1001];
double p[1001];
double dp[1001];
bool vis[1001];
double solve(int ind)
{
    if(ind==n+1)
        return p[ind];
    if(ind>n) return 0;
    double &ret=dp[ind];
    if(vis[ind]) return ret;
    //cout<<"sdf";
    int cr=dis[ind]+L;
    ret=0.0;
    for(int i=ind+1; i<=n+1; i++)
    {
        if(dis[i]<=cr)
        {
            ret=max(ret, solve(i));
        }
        else
            break;
    }
    vis[ind]=true;
    //cout<<ret<<" "<<p[ind]<<endl;
    ret=ret*p[ind];
    return ret;
}


int main()
{
    int i,j,k;
    int cases=1;
    cin>>n>>L>>D;

    dis[0]=0;
    p[0]=1;
    dis[n+1]=D;
    p[n+1]=1;
    for(i=1; i<=n; i++)
        cin>>p[i];
    bool ck=false;
    for(i=1; i<=n; i++)
    {
        cin>>dis[i];
        if(dis[i]-dis[i-1]>L)
            ck=true;
    }
    if(dis[i]-dis[i-1]>L)
    ck=true;
    if(ck)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    memset(dp, -1.0, sizeof dp);

    double res=solve(0);
    printf("%.6lf\n", res);

    memset(vis, false, sizeof vis);

    return 0;
}