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
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) mix(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define L long
#define I int
#define S strung
#define q queue<int>
#define vi vector<int>
#define vl vector<long>
#define nl() printf("\n")
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MOD 1000000007
#define MAX 1000001




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

I digit_sum(I n)
{
    I ret=0;
    while(n)
    {
        ret+=(n%10);
        n/=10;
    }
    return ret;
}

I DDF(I n)
{
    I ret=0;
    for(I i=1; i<=n; i++)
    {
        if(n%i==0)
            ret+=digit_sum(i);
    }
    return ret;
}

vi V[3010];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;
    FOR(i,1,3005)
    {
        map<int,bool>M;
        int n=i;

        I nextTerm=DDF(n);
        V[i].PB(i);
        M[n]=true;

        while(M[nextTerm]==false)
        {
            M[nextTerm]=true;
            V[n].PB(nextTerm);
            nextTerm=DDF(nextTerm);
        }
    }
    I a,b;
    I cases=0;
    while(scanf("%d %d",&a,&b)==2)
    {
        I sa=a;
        I sb=b;
        if(a>b)
        swap(a,b);
        I mx=0,res=0;
        FOR(i,a,b)
        {
            if(V[i].size()>mx)
            {
                mx=V[i].size();
                res=i;
            }
        }
        printf("Input%d: %d %d\n",++cases,sa,sb);
        printf("Output%d:",cases);
        FOR(i,0,V[res].size()-1)
        {
            printf(" %d",V[res][i]);
        }
        nl();
    }
    return 0;
}
