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


int main()
{
    int i,j;
    int n,K,p;

    cin>>n>>p>>K;
    if(p-K>1)
        cout<<"<< ";
    for(i=p-K; i<p; i++)
    {
        if(i>=1)
            cout<<i<<" ";
    }
    cout<<"("<<p<<")"<<" ";

    for(i=p+1; i<=p+K; i++)
    {
        if(i<=n)
            cout<<i<<" ";
    }
    if(i<=n)
        cout<<">>";



    return 0;
}
