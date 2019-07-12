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
#define scan(a) scanf("%d",&a);
#define s2(a,b) scanf("%d %d",&a,&b)
#define PI 2acos(-1.0)
#define s1(a) scanf("%d",&a);
#define INF 2<<15
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)
#define MAX 1000005
#define FM 10000000
#define PB(A) push_back(A)


using namespace std;

bool prime[MAX];
long hv;
long val[MAX];
vector<long>V;
void sieve()
{
    long i,j,k;
    long n=sqrt(MAX);
    hv=0;
    for(i=0; i<MAX; i++)
    {
        prime[i]=true;
    }
    for(i=4; i<MAX; i+=2)
    {
        prime[i]=false;
    }
    for(i=3; i<=n; i+=2)
    {
        if(prime[i])
        {
            for(j=i+i; j<MAX; j+=i)
                prime[j]=false;
        }
    }

    // take the prime here
    val[1]=2;
    k=2;
    for(i=3; i<MAX; i+=2)
    {
        if(prime[i])
        {
            val[k++]=i;
        }
    }
    hv=k;

    long long mul;
    for(i=1; i<hv && val[i]<MAX; i++)
    {
        mul=val[i];
        mul*=mul;
        while(mul<FM)
        {
            V.push_back(mul);
            mul=mul*val[i];
        }
    }
}


int main()
{
    long long a,b;
    sieve();
    sort(V.begin(),V.end());
    long l=V.size();
    while(1)
    {
        scanf("%lld %lld",&a,&b);
        long cnt=0;
        for(long i=0; i<l; i++)
        {
            if(V[i]>=a && V[i]<=b)
            {
                cnt++;
                cout<<V[i]<<ends;
            }
            if(V[i]>b)
                break;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
