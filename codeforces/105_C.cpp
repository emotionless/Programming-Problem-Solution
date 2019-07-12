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
#define MAX (200009)
#define PB push_back
#define MOD 1000000007
#define MX 1e9
#define INF INT_MAX



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


#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define i64 long long

using namespace std;



int main()
{
    int i,j;
    int cases=1;
    int a, b, n;
    cin>>n>>a>>b;


    int sum = 1, mx = 1;
    if(a + 1 == n && b == 0)
    {
        if(a == 0) goto XX;
        cout<<-1<<endl;
        return 0;
    }
XX:{
    cout<<1;
    for(i = 2; i <= n; i++)
    {
        if(b)
        {
            cout<<" "<<sum + 1;

            mx = max(mx, sum + 1);
            sum = sum * 2 + 1;
            b--;
        }
        else if(sum == mx)
        {
            cout<<" "<<1;
            sum += 1;
        }
        else if(a)
        {
            cout<<" "<<mx + 1;
            mx = mx + 1;
            sum += mx;
            a--;
        }
        else{
            cout<<" "<<1;
            sum += 1;
        }
    }
}
    return 0;
}
/*




*/
