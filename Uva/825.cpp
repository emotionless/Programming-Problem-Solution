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
#define MX 120001



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

bool mat[1001][1001];
bool vis[1001][1001];
int cost[1001][1001];
int res[1001][1001];
int n, m;

int dr[]= {0, 1, 0, -1};
int dc[]= {1, 0, -1, 0};


struct Z
{
    int u, v, w;
    Z() {}
    Z(int a, int b, int c)
    {
        u=a;
        v=b;
        w=c;
    }
};



int BFS()
{
    queue<Z>Q;
    Q.push(Z(1,1,0));

    while(!Q.empty())
    {
        Z top=Q.front();
        Q.pop();

        int cx=top.u;
        int cy=top.v;
        int cw=top.w;

        if(vis[cx][cy]) continue;
        vis[cx][cy]=true;
        cost[cx][cy]=cw;
        if(cy+1<=m)
        {
            if(mat[cx][cy+1])
                Q.push(Z(cx, cy+1, cw+1));
        }
        if(cx+1<=n)
        {
            if(mat[cx+1][cy])
                Q.push(Z(cx+1, cy, cw+1));
        }
    }
    return cost[n][m];
}



int main()
{
    int i,j,k;
    int t, cases=0;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        getchar();
        string str;

        memset(mat, true, sizeof mat);
        memset(vis, false, sizeof vis);
        memset(cost, 0, sizeof cost);

        for(i=1; i<=n; i++)
        {
            getline(cin, str);
            stringstream ss(str);
            int num;
            ss>>num;
            while(ss>>num)
            {
                mat[i][num]=false;
            }
        }

        int get=BFS();
        mat[1][1]=false;
        res[1][1]=1;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                if(mat[i][j])
                {
                    res[i][j]=0;
                    if((cost[i-1][j]+1)==cost[i][j])
                        res[i][j]+=res[i-1][j];
                    if((cost[i][j-1]+1==cost[i][j]))
                        res[i][j]+=res[i][j-1];
                }
            }
        }
        if(cases)
        cout<<endl;
        cases++;
        cout<<res[n][m]<<endl;
    }
    return 0;
}
