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

/**********TYPE CASTING**********/
#define LL long long
#define L long
#define D double
#define LD long double
#define S string
#define I int
#define ULL unsigned long long
#define q queue<int>
#define vi vector<int>
#define vl vector<long>

/**********INPUT**********/
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define s1(a) scanf("%d",&a)
#define s2(a,b) scanf("%d%d",&a,&b)
#define s3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sll(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",&a)
#define gc() getchar()

/**********OUTPUT**********/
#define p1(a) printf("%d\n",a)
#define p2(a,b) printf("%d %d\n",a,b)
#define pll(a) printf("%lld\n",a)
#define pd(a) printf("%.10lf\n",a)
#define pcs(a,n) printf("Case %d: %d\n",a,n)
#define nl() printf("\n")

/**********LOOP**********/
#define REV(i,e,s) for(i=e;i>=s;i--)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define loop(n) for(int o=1;o<=n;o++)

/********** min/max *******/
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) mix(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))

/**********SHORTCUT**********/
#define len(a) a.length()
#define SET(a,x) memset(a,x,sizeof a)
#define VI vector<int>
#define SZ size()
#define CLR clear()
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))


/**********CONSTANT**********/
#define MIN INT_MIN
#define PI 2acos(-1.0)
#define INF 2<<15
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
L cost[1001][1001];

int n,m;
S mat[1001];
bool vis[1001][1001];


struct Z
{
    int x,y,cost;
    Z() {}
    Z(I a, I b, I c)
    {
        x=a;
        y=b;
        cost=c;
    }
};


void GO(I x, I y)
{
    I i;
    queue<Z> Q;
    Q.push(Z(x,y,0));

    while(!Q.empty())
    {
        Z top=Q.front();
        Q.pop();

        I cx=top.x;
        I cy=top.y;
        I cc=top.cost;

        if(vis[cx][cy]) continue;
        vis[cx][cy]=true;

        cost[cx][cy]=cc;

        FOR(i,0,4)
        {
            I adjx=cx+r[i];
            I adjy=cy+c[i];
            I adjc=cc+1;

            if(adjx<0 || adjx>=n || adjy<0 || adjy>=m || vis[adjx][adjy] || mat[adjx][adjy]=='T') continue;

            if(adjc<cost[adjx][adjy])
                Q.push(Z(adjx,adjy,adjc));
        }

    }
}





int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k,sx,sy,ex,ey;
    cin>>n>>m;
    FOR(i,0,n)
    {
        cin>>mat[i];
        FOR(j,0,m)
        {
            if(mat[i][j]=='E')
            {
                ex=i;
                ey=j;
            }
            if(mat[i][j]=='S')
            {
                sx=i;
                sy=j;
            }
            cost[i][j]=INT_MAX;
        }
    }

    cost[ex][ey]=0;

    GO(ex,ey);

    LL cnt=0;
    FOR(i,0,n)
    {
        FOR(j,0,m)
        {
            if(cost[i][j]<=cost[sx][sy] && mat[i][j]>='0' && mat[i][j]<='9')
            {
                cnt+=mat[i][j]-'0';
            }
        }
    }

    cout<<cnt<<endl;



    return 0;
}

/*


5 7
000E0T3
T0TT0T0
010T0T0
2T0T0T0
0T0S000

*/
