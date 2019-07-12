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

using namespace std;

long BigMod(long a, long p, long m);
long ModInverse(long n, long p);
void func();

long long fact[MAX];
long long mdI[MAX];



int main()
{
    int i,j,k;
    long long n,r;
    func();
    scanf("%lld %lld",&n,&r);
    long long temp=((fact[n-r]%1000003)*(fact[r]%1000003))%1000003;
    long long res=((fact[n]%1000003)* mdI[temp])%1000003;
    cout<<res<<endl;
    return 0;
}

long ModInverse(long n, long p)
{
    return BigMod(n,p-2,p);
}


long BigMod(long a, long p, long m)
{
    if(p==0) return 1;
    long x=BigMod(a,p/2,m)%m;
    x=(x*x)%m;
    if(p%2==1)
        x=(x*a)%m;
    return x;

}
void func()
{
    int i;
    fact[0]=1;
    mdI[0]=1;
    for(i=1; i<10; i++)
    {
        fact[i]=(fact[i-1]*i)%1000003;
        mdI[i]=(mdI[i-1]*ModInverse(i,1000003))%1000003;
        cout<<mdI[i]<<endl;
    }
}

