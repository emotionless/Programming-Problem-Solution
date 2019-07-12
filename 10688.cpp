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
#define MOD 1000000007
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define MAX 100001



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

#define MAXX INT_MAX

int dp[509][509];
int mem[509][509];
int arr[509];
int solve(int l, int r)
{
    if(l > r) return 0;
    if(l == r)
    {
        mem[l][r] = l;
        return 0;
    }
    int &ret = dp[l][r];
    if(ret != -1) return ret;
    ret = INT_MAX;
//    int a = solve(l + 1, r);
//    int b = solve(l, r - 1);
//    if(a < b)
//    {
//        ret = a;
//        mem[l][r] = mem[l + 1][r];
//    }
//    else
//    {
//        ret = b;
//        mem[l][r] = mem[l][r - 1];
//    }
//    int mn = min(mem[l + 1][r], mem[l][r - 1]);
//    int mx = max(mem[l + 1][r], mem[l][r - 1]);

    for(int i = l; i <= r; i++)
    {
        int tmp = arr[i]*(r - l + 1) + solve(l, i - 1) + solve(i + 1, r);
        if(tmp < ret)
        {
            ret = tmp;
            mem[l][r] = i;
        }
    }
return ret;
}






int main()
{

    int i,j;
    int cases=1;
    LL num;
    int t;
    int n, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(i = 1; i <= n; i++)
            arr[i] = k + i;
        memset(dp, -1, sizeof dp);
        int res = solve(1, n);
        printf("Case %d: %d\n", cases++, res);


    }





    return 0;
}
/*

3 2
0 2 0
2 0 3
0 3 0



*/
