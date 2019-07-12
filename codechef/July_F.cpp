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
#define PB push_back
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
#define MAX_NUM  100001



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

vl V[MAX_NUM];
bool vis[MAX_NUM];
L cost[MAX_NUM];

L DFS(L s)
{
    L min_cost=cost[s];

    queue<long> Q;
    Q.push(s);

    while(!Q.empty())
    {
        L top=Q.front();
        Q.pop();


        if(vis[top]) continue;
        vis[top]=true;
        L sz=V[top].size();
        for(L i=0; i<sz; i++)
        {
            L adjn=V[top][i];
            min_cost=min(min_cost,cost[adjn]);
            if(!vis[adjn])
                Q.push(adjn);
        }
    }

    return min_cost;
}







int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    L i,j,k;
    L n,m,a,b;
    while(scanf("%ld %ld",&n,&m)==2)
    {
        loop(m)
        {
            s2(a,b);
            V[a].PB(b);
            V[b].PB(a);
        }

        for(i=1; i<=n; i++)
        {
            scanf("%ld",&cost[i]);
            if(cost[i]<0)
                cost[i]=MAX;
        }

        vl res;
        bool c=true;

        L mn=MAX;

        for(i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                L getMinCost=DFS(i);
                if(getMinCost==MAX)
                {
                    c=0;
                    //break;
                }
                res.PB(getMinCost);
                mn=min(mn,getMinCost);
            }
        }

       // cout<<res.size()<<endl;

        if(res.size()==1)
            printf("0\n");

        else if(!c)
            printf("-1\n");

        else
        {
            L ans=0;
            L sz=res.size();
            for(i=0; i<sz; i++)
                ans+=res[i];
            ans=ans+(sz-2)*mn;
            printf("%ld\n",ans);
        }

        res.clear();
        for(i=1; i<=n; i++)
        {
            V[i].clear();
            vis[i]=false;
            cost[i]=MAX;
        }
    }
    return 0;
}

/*

7 3
1 2
3 4
6 5
-1
2
5
5
6
9
0

*/
