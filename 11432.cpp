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
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define MX 120001
#define INF 120001



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
int D,G;
int dp[2][70][35][35][35];

int solve(int ind, int pos, int tot, int a, int b)
{
   // cout<<"FOR "<<ind<<" "<<pos<<" "<<tot<<" "<<a<<" "<<b<<endl;
    if(a>D || b>D) return 0;
    if(pos==(2*D) && a==b && a+b==(2*D)) return 1;

    int &ret=dp[ind][pos][tot][a][b];
    if(ret!=-1) return ret;

    ret=0;
    int tmp=0;
    int tmp=solve((ind+1)%2, pos+1, 1, ((ind+1)%2)==0?a+1:a, ((ind+1)%2)==1?b+1:b);
    if(tmp>0)
        ret+=tmp;
    if(tot<G)
    {
        tmp=solve(ind, pos+1, tot+1, ind==0?a+1:a, ind==1?b+1:b);
        if(tmp>0)
            ret+=tmp;
    }
    cout<<ind<<" "<<pos<<" "<<tot<<" "<<a<<" "<<b<<" "<<ret<<endl;
    return ret;
}


int main()
{
    int i,j,k;
    int cases=1;

    cin>>D>>G;

    memset(dp, -1, sizeof dp);

    int arr[2];
    arr[0]=arr[1]=0;

    int res=solve(0,0,0,0,0);
    cout<<res<<endl;

    return 0;
}
/*

2
SQ 1 0
SQ 0 0
SQ 6 0
SQ 5 0



*/
