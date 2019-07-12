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

int dp[101][22500];
int arr[101];
int t, n;
int solve(int ind, int tot, int sum)
{
    if(tot>=t) return 0;
    if(ind==n) return 0;

    int &ret=dp[ind][sum];
    if(ret!=-1) return ret;

    if(arr[ind]<=sum)
        ret=max( arr[ind]+solve(ind+1, tot+1, sum-arr[ind]), solve(ind+1, tot, sum) );
    else
        ret= solve(ind+1, tot, sum);
    return ret;
}



int main()
{
    int i,j,k;
    int cases=0;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int sum=0;

        for(i=0; i<n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        int mid=sum/2;
        memset(dp, -1, sizeof dp);

        t=n/2+(n%2);

        int res=solve(0,0,mid);
        int a=sum-res;
        if(a>res)
            swap(a, res);
        if(cases)
            cout<<endl;
        cases++;
        wcerr<<a<<" "<<res<<endl;
        memset(arr, 0, sizeof arr);
    }
    return 0;
}
/*

1
8
428
8
243

80
88
34
201
361


*/
