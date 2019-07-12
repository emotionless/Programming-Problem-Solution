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
#define nl() printf("\n")
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MAX 1000001

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}


using namespace std;




/*
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

struct node
{
    int x,y,t;
    node() {}
    node(I a, I b, I c)
    {
        x=a;
        y=b;
        t=c;
    }
};


I mat[501][503][4];
bool vis[501][503][4];



int main()
{

    int i,j,k;
    int n,m;
    // string inp;
    char inp[5];

    while(scanf("%d %d",&n,&m)==2)
    {



        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(i==n-1 && j==m-1)
                    break;
                //cin>>inp;
                scanf("%s",inp);
                clr(mat[i][j],0);
                clr(vis[i][j],0);
                for(k=0; k<strlen(inp); k++)
                {
                    if(inp[k]=='N') mat[i][j][0]=1;
                    if(inp[k]=='E') mat[i][j][1]=1;
                    if(inp[k]=='S') mat[i][j][2]=1;
                    if(inp[k]=='W') mat[i][j][3]=1;
                }
            }
        }

        bool prnt=true;

        queue< node>Q;
        Q.push(node(0,0,0));
        while(!Q.empty())
        {
            node top=Q.front();
            Q.pop();
            int cx=top.x;
            int cy=top.y;
            int ct=top.t;
            int tt=ct%4;
            if(cx==n-1 && cy==m-1)
            {
                printf("%d\n",ct);
                prnt=false;
                break;
            }
            if(vis[cx][cy][tt]) continue;
            vis[cx][cy][tt]=true;
            for(i=0; i<4; i++)
            {
                if(mat[cx][cy][i])
                {

                    I tmp=(i+tt)%4;
                    if(tmp==0 && cx-1>=0)
                    {
                        Q.push(node(cx-1,cy,ct+1));
                    }
                    else if(tmp==1 && cy+1<m)
                    {
                        Q.push(node(cx,cy+1,ct+1));
                    }
                    else if(tmp==2 && cx+1<n)
                    {
                        Q.push(node(cx+1,cy,ct+1));
                    }
                    else if(tmp==3 && cy-1>=0)
                    {
                        Q.push(node(cx,cy-1,ct+1));
                    }
                }
            }
        }
        if(prnt)
            printf("no path to exit\n");
        while(!Q.empty())
            Q.pop();

    }

    return 0;
}

/*

2 2
NES
S
SW

*/
