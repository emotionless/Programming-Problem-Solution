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

struct Z
{
    int pos;
    int val[11];
} data[55];
int n,m;
int from[55];
int arr[55];

bool cmp(int a, int b)
{
    for(int i=0; i<m; i++)
    {
        if(data[a].val[i]>=data[b].val[i])
            return false;
    }
    return true;
}

void BT(int i)
{
    if(from[i]==i)
    {
        cout<<data[i].pos;
        return;
    }
    BT(from[i]);
    cout<<" "<<data[i].pos;
}


void LIS()
{
    arr[1]=1;

    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<i; j++)
        {
            if(cmp(j,i) && arr[j]+1>arr[i])
            {
                arr[i]=arr[j]+1;
                from[i]=j;
            }
        }
    }

    //    for(int i=1; i<=n; i++)
//    {
//        cout<<i<<" "<<arr[i]<<" "<<data[i].pos<<" ";
//        for(int j=0; j<m; j++)
//            cout<<data[i].val[j]<<" ";
//        cout<<endl;
//    }
    int mx=1, pos=1;
    for(int i=1; i<=n; i++)
    {
        if(arr[i]>mx)
        {
            mx=arr[i];
            pos=i;
        }
    }
    cout<<mx<<endl;
    BT(pos);
    cout<<endl;
}


int main()
{
    int i,j,k;

    while(cin>>n>>m)
    {
        for(i=1; i<=n; i++)
        {
            data[i].pos=i;
            for(j=0; j<m; j++)
                cin>>data[i].val[j];

            sort(data[i].val, data[i].val+m);
        }

        for(i=1; i<=n; i++)
        {
            arr[i]=1;
            from[i]=i;
            for(j=i+1; j<=n; j++)
            {
                if(cmp(j,i))
                    swap(data[i], data[j]);
            }
        }

        LIS();

        memset(arr, 0, sizeof arr);
        memset(from, 0, sizeof from);
        memset(data, 0, sizeof data);
    }
    return 0;
}
