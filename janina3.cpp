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
#define D double
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

I r[]= {0,1,0,-1};
I c[]= {1,0,-1,0};

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

I cost[201][201];
I x[201];
I y[201];
I l[201];
bool vis[201][201];
I R,C,m;


D LEN(int x1,I y1, I x2, I y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}


I BFS()
{
    queue<node>Q;
    Q.push(node(0,0,0));
    cost[0][0]=0;
    I res=-1;

    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        I cx=top.x;
        I cy=top.y;
        I cc=top.cost;
        bool br=false;
        if(vis[cx][cy]) continue;
        vis[cx][cy]=true;

        //    cout<<cx<<" "<<cy<<" "<<cc<<endl;

        for(I i=0; i<m; i++)
        {
            D length=LEN(cx,cy,x[i],y[i]);
            if(length<=l[i] && l[i]>0)
            {
                br=true;
                //     cout<<"cuts: "<<cx<<" "<<cy<<endl;
                break;
            }
        }
        if(br)
            continue;

        if(cx==R-1 && cy==C-1)
        {
            res=cc;
            break;
        }

        for(I i=0; i<4; i++)
        {
            I adjx=cx+r[i];
            I adjy=cy+c[i];
            if(adjx<0 || adjx>=R || adjy<0 || adjy>=C)
                continue;
            Q.push(node(adjx,adjy,cc+1));
        }
    }
    return res;
}



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,a,b,c;
    while(scanf("%d %d",&R,&C)==2 && (R || C)){
    si(n);
    for(i=0; i<R; i++)
    {
        for(j=0; j<C; j++)
        {
            vis[i][j]=false;
        }
    }
    loop(n)
    {
        scanf("%d %d",&a,&b);
        vis[a-1][b-1]=true;
    }
    si(m);
    FOR(i,0,m-1)
    {
        scanf("%d %d %d",&a,&b,&c);
        x[i]=a-1;
        y[i]=b-1;
        l[i]=c;
    }
    int res=BFS();
    if(R==1 && C==1)
    print(0);
    else if(res==-1)
        printf("Impossible.\n");
    else
        printf("%d\n",res);
   }
       return 0;
}


/*

5 5
5
1 2
1 3
1 4
1 5
2 5
1
4 3 1

*/
