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
#define MAX 101




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
    I n,cost;
    node() {}
    node(I a, I b)
    {
        n=a;
        cost=b;
    }
};

I cost1[MAX];
I cost2[MAX];

vi V[MAX];

bool vis[MAX];

void BFS1(I s)
{
    queue<node>Q;
    Q.push(node(s,0));
    cost1[s]=0;

    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        I cn=top.n;
        I cc=top.cost;
        if(vis[cn]) continue;
        vis[cn]=true;

        cost1[cn]=cc;
        I sz=V[cn].size();
        for(I i=0; i<sz; i++)
        {
            I adjn=V[cn][i];
            if(!vis[adjn])
            {
                cost1[adjn]=cc+1;
                Q.push(node(adjn,cc+1));
            }
        }
    }
}

void BFS2(I s)
{
    queue<node>Q;
    Q.push(node(s,0));
    cost2[s]=0;

    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        I cn=top.n;
        I cc=top.cost;
        if(vis[cn]) continue;
        vis[cn]=true;
        cost2[cn]=cc;
        I sz=V[cn].size();
        for(I i=0; i<sz; i++)
        {
            I adjn=V[cn][i];
            if(!vis[adjn])
            {
                cost2[adjn]=cc+1;
                Q.push(node(adjn,cc+1));
            }
        }
    }
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,m,u,t,v,cases=0;
    si(t);
    while(t--)
    {
        si(n);
        si(m);
        loop(m)
        {
            scanf("%d %d",&u,&v);
            V[u].PB(v);
            V[v].PB(u);
        }
        I s,e;
        scanf("%d %d",&s,&e);

        clr(vis,false);
        BFS1(s);
        clr(vis,false);
        BFS2(e);
        I res=-1;
        for(i=0; i<n; i++)
        {
            res=max(res,cost1[i]+cost2[i]);
        }
        printf("Case %d: %d\n",++cases,res);
        for(i=0;i<n;i++)
        V[i].clear();

    }
    return 0;
}
