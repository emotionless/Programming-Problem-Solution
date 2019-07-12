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
#define INF 1<<30



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
int n,t ,c;
int dp[1001][1001];
int arr[1001];

int func(int C)
{
    if(C==0) return 0;
    if(C<=10)  return -c;
    return (C-10)*(C-10);
}


int solve(int x, int y)
{
    int &res=dp[x][y];
    if(res!=-1) return res;
    if(x==0)
    {
        res=(y==0?0:INF);
        return res;
    }
    else
    {
        res=INF;
        int ans=0;
        for(int i=y; i>0; i--)
        {
            ans+=arr[i];
            if(ans>t) break;
            int tmp=solve(x-1, i-1);
            if(tmp!=INF)
                res=min(res, tmp+func(t-ans));
        }
        return res;
    }
}


int main()
{
    int i,j,k;
    int cases=0;
    while(cin>>n && n)
    {
        cin>>t>>c;
        for(i=1; i<=n; i++)
            cin>>arr[i];
        int tmp=0;
        int cnt=1;
        for(i=1; i<=n; i++)
        {
            tmp+=arr[i];
            if(tmp>t)
            {
                cnt++;
                tmp=arr[i];
            }
        }
       // memset(dp, -1, sizeof dp);
       for(i=0; i<=1000; i++)
       memset(dp[i], -1, sizeof dp[i]);
        if(cases)
            cout<<endl;
        cases++;
        printf("Case %d:\n", cases);
        cout<<"Minimum number of lectures: "<<cnt<<endl;
        int res=solve(cnt, n);
        cout<<"Total dissatisfaction index: "<<res<<endl;
        memset(arr, 0, sizeof arr);
       // cout<<endl;
    }


    return 0;
}
