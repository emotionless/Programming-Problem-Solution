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
#define MX 100000



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
int val[]= {5, 10, 20, 50, 100, 200};
int res[7501];
int mn[7501];
int arr[6];
void pre()
{
    mn [0] = 0;

    for(int i=1; i<7500; i++)     mn[i]=MX;

    for ( int i = 0; i < 6; i++ )
        for ( int j = val [i]; j < 7500; j++ )
        {
            mn [j] =min(mn[j], 1+mn [j - val [i]]);
        }
}

int solve(int rem, int n)
{
    if(rem<=0 && n<0) return mn[-rem];
    else if(n<0) return MX;

    else if(!arr[n])
        return solve(rem, n-1);
    else
    {
        int y=solve(rem, n-1);
        arr[n]--;
        int x=solve(rem-val[n], n);
        arr[n]++;
        return min(y, x+1);
    }

}

int main()
{
    int i,j,k;
    int n;
    double cent;
    while(1){
    cin>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5];
    if(arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]==0) break;
    cin>>cent;

    for(i=0; i<7500; i++)
    {
        mn[i]=MX;
        res[i]=MX;
    }

    pre();
    int tar=((double)cent*100.0+.5);


    cout<<setw(3)<<solve(tar, 5)<<endl;

    memset(arr, 0, sizeof arr);
}





    return 0;
}
