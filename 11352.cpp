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
#define S string
#define print(a) printf("%d\n",a)
#define len(a) a.length()
#define q queue<int>
#define vi vector<int>
#define vl vector<long>
#define nl() printf("\n")
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MOD 1000000007
#define MAX 1000001




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

struct node
{
    I x,y,cost;
    node() {}
    node(I a, I b, I c)
    {
        x=a;
        y=b;
        cost=c;
    }
};


I r[]= {-2,-1,1,2,2,1,-1,-2};
I c[]= {1,2,2,1,-1,-2,-2,-1};

I r1[]= {0,1,1,1,0,-1,-1,-1};
I c1[]= {1,1,0,-1,-1,-1,0,1};

I R,C;
S mat[201];

void ENEMY(I x, I y)
{
    for(I i=0; i<8; i++)
    {
        I cx=x+r[i];
        I cy=y+c[i];
        if(cx<0 || cx>=R || cy<0 || cy>=C || mat[cx][cy]=='B' || mat[cx][cy]=='Z')
            continue;
        mat[cx][cy]='X';
    }
    mat[x][y]='X';
}
bool vis[101][101];

I BFS(I x, I y)
{
    queue<node>Q;
    Q.push(node(x,y,0));

    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        I cx=top.x;
        I cy=top.y;
        I cc=top.cost;
        if(mat[cx][cy]=='B')
            return cc;

        if(vis[cx][cy]) continue;
        vis[cx][cy]=true;

        for(I i=0; i<8; i++)
        {
            I adjx=cx+r1[i];
            I adjy=cy+c1[i];
            if(adjx<0 || adjx>=R || adjy<0 || adjy>=C || mat[adjx][adjy]=='X')
                continue;
            Q.push(node(adjx,adjy,cc+1));
        }

    }
    return -1;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;
    I t;
    si(t);
    while(t--)
    {
        cin>>R>>C;
        for(i=0; i<R; i++)
        {
            for(j=0; j<C; j++)
            {
                vis[i][j]=false;
              //  mat[i][j]='.';
            }
        }
        bool getA=false;
        I sx,sy;
        FOR(i,0,R-1)
        {
            cin>>mat[i];
            if(!getA)
            {
                for(j=0; j<C; j++)
                    if(mat[i][j]=='A')
                    {
                        sx=i;
                        sy=j;
                        getA=true;
                    }

            }
        }
        for(i=0; i<R; i++)
        {
            for(j=0; j<C; j++)
            {
                if(mat[i][j]=='Z')
                {
                    ENEMY(i,j);
                }
            }
        }

        I res=BFS(sx,sy);
        if(res==-1)
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n",res);
    }
    return 0;
}
