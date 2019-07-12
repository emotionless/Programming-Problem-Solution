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
#define s(aa) scanf("%d", &aa)



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
int n,K;

int dr[]= {0, 1, 0};
int dc[]= {1, 0, -1};


int mat[76][76];
bool vis[76][76];
int dp[76][76][6][4];
bool is;

int solve(int x, int y, int cnt, int s)
{
    if(cnt>K) return -MX;
    if(x==n && y==n)
    {
        if(mat[x][y]<0)
        {
            if(cnt<K)
            {
                is=true;
                return mat[x][y];
            }
            return -MX;
        }
        is=true;
        return mat[x][y];
    }
    int &ret=dp[x][y][cnt][s];
    if(ret!=-1) return ret;
    vis[x][y]=true;
    ret=-100000;
    for(int i=0; i<3; i++)
    {
        int adjx=x+dr[i];
        int adjy=y+dc[i];
        if(adjx<1 || adjx>n || adjy<1 || adjy>n) continue;
        if(vis[adjx][adjy]) continue;
        if(mat[x][y]<0)
            ret=max(ret, mat[x][y]+solve(adjx, adjy, cnt+1, i));
        else
            ret=max(ret, mat[x][y]+solve(adjx, adjy, cnt, i));
    }
    //cout<<x<<" "<<y<<" "<<cnt<<" "<<ret<<endl;
    vis[x][y]=false;
    return ret;
}





int main()
{
    int i,j,k;
    int cases=1;
    while(1)
    {
        s(n);
        s(K);
        is=false;
        if(n+K==0) break;

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                s(mat[i][j]);
        }
        memset(dp, -1, sizeof dp);
        memset(vis, false, sizeof vis);
        LL res=solve(1,1,0, 0);
        printf("Case %d: ", cases++);
        if(is)
            cout<<res<<endl;
        else
            cout<<"impossible"<<endl;
        memset(mat, 0, sizeof mat);
    }
    return 0;
}
/*

4 1
1 2 3 -5
-10 6 0 -1
-10 -10 -10 2
0 0 0 1



*/
