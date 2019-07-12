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
int n,S;
int arr[11];
int dp[12][11];
bool vis[10001];

void solve(int ind, int tot, int sum)
{
    if(ind>=n) return;
    if(tot==S)
    {
        vis[sum]=true;
        dp[ind][tot]=sum;
        return;
    }
    vis[sum]=true;

    solve(ind+1, tot, sum);

    solve(ind,tot+1, sum+arr[ind]);

}



int main()
{
    int i,j,k;
    int N;
    while(1)
    {
        cin>>S;
        if(!S) break;
        cin>>N;

        vector<int>res;
        int mx=0;
        while(N--)
        {
            cin>>n;
            memset(vis, false, sizeof vis);
            for(i=0; i<n; i++)
                cin>>arr[i];
            memset(dp, -1, sizeof dp);
            solve(0,0,0);
            int cnt=0;
            for(i=1; i<=10000; i++)
            {
                if(vis[i])
                    cnt++;
                else
                    break;
            }
            if(cnt==mx)
            {
                if(n<res.size())
                {
                    res.clear();

                    for(i=0; i<n; i++)
                        res.PB(arr[i]);
                }
                else if(n==res.size())
                {
                    for(j=n-1; j>=0; j--)
                    {
                        if(arr[j]==res[j]) continue;
                        if(arr[j]<res[j])
                        {
                            res.clear();
                            for(i=0; i<n; i++)
                                res.PB(arr[i]);
                            break;
                        }
                    }
                }
            }
            else if(cnt>mx)
            {
                mx=cnt;
                res.clear();
                for(i=0; i<n; i++)
                    res.PB(arr[i]);
            }

        }
        cout<<"max coverage ="<<setw(4)<<mx<<" :";
        for(i=0; i<res.size(); i++)
            cout<<setw(3)<<res[i];
        cout<<endl;
        res.clear();
    }
    return 0;
}
