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

int arr[101];
int val[101];
int lcs[101][101];
stack<int>ST;
void DFS(int x, int y)
{
    if(x<=0 || y<=0) return;
    if(arr[x]==val[y])
    {
        ST.push(arr[x]);
        DFS(x-1, y-1);
    }
    else
    {
        if(lcs[x-1][y]>lcs[x][y-1])
        {
            DFS(x-1, y);
        }
        else
            DFS(x, y-1);
    }
}

int main()
{
    int i,j,k;
    string inp;


    while(1)
    {
        map<string, int>M;
        map<int, string>mp;

        int tot=0;
        i=0;
        while(getline(cin,inp))
        {
            if(inp=="#")
                break;
            stringstream ss(inp);
            string str;
            while(ss>>str)
            {
                i++;
                if(M[str])
                    arr[i]=M[str];
                else
                {
                    arr[i]=M[str]=(++tot);
                    mp[tot]=str;
                }
            }
        }
        if(i==0) return 0;
        int n=i;
        i=0;
        while(getline(cin,inp))
        {
            if(inp=="#")
                break;

            stringstream ss(inp);
            string str;
            while(ss>>str)
            {
                i++;
                if(M[str])
                    val[i]=M[str];
                else
                {
                    val[i]=M[str]=(++tot);
                    mp[tot]=str;
                }
            }
        }
        int m=i;
        int mx=0, x=0, y=0;

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(arr[i]==val[j])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else
                {
                    lcs[i][j]=max(lcs[i-1][j], lcs[i][j-1]);
                }
                if(lcs[i][j]>mx)
                {
                    mx=lcs[i][j];
                    x=i;
                    y=j;
                }
            }
        }
        //cout<<lcs[n][m]<<endl;

        for(i=0; i<=n; i++)
            lcs[i][0]=-1;

        for(i=0; i<=m; i++)
            lcs[0][i]=-1;

        DFS(x,y);

        int sz=ST.size();
        if(sz)
        {
            string ans=mp[ST.top()];
            cout<<ans;
            ST.pop();
            while(!ST.empty())
            {
                ans=mp[ST.top()];
                cout<<" "<<ans;
                ST.pop();
            }
            cout<<endl;
        }

        memset(arr, 0, sizeof arr);
        memset(val, 0, sizeof val);
        memset(lcs, 0, sizeof lcs);
        M.clear();
        mp.clear();
    }
    return 0;
}

