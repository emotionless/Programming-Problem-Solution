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
#define PB push_back


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

struct Z
{
    int l,r,dif;
    Z() {}
    Z(int a, int b, int c)
    {
        l=a;
        r=b;
        dif=c;
    }
    bool operator<(const Z& A)const
    {
        if(dif==A.dif)
        {
            return l<A.l;
        }
        else
            return dif>A.dif;
    }

};
vector<Z>V;


int main()
{
    int i,j,k;
    int n;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        V.clear();
        int num=0, sum=0, mx=0;
        int l=2;
        for(i=2; i<=n; i++)
        {
            cin>>num;
            sum+=num;
            if(sum<0)
            {
                l=i+1;
                sum=0;
            }

            else if(sum>mx)
            {
                V.clear();
                mx=sum;
                V.PB(Z(l,i,i-l));
            }
            else if(sum==mx)
            {
                V.PB(Z(l,i,i-l));
            }
        }
        if(V.size())
        {
            sort(V.begin(), V.end());
            printf("The nicest part of route %d is between stops %d and %d\n", cases++, V[0].l-1, V[0].r);
        }
        else
            printf("Route %d has no nice parts\n", cases++);
    }


    return 0;
}

/*
1
10
   4
  -5
   4
  -5
   4
  -5
  -4
   4
  -5



*/
