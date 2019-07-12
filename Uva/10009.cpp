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
#define SS stringstream
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
    char name;
    I cost;
    node() {}
    node(char a, I b)
    {
        name=a;
        cost=b;
    }
};


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,m,t;
    vi V[100];
    vi path[100];
    S a,b;
    bool p=false;
    si(t);
    while(t--)
    {
        if(p)
            nl();
        p=true;
        si(n);
        si(m);
        loop(n)
        {
            cin>>a>>b;
            V[a[0]].PB(b[0]);
            V[b[0]].PB(a[0]);
        }
        loop(m)
        {
            queue<node>Q;
            S src,dst,tmp;
            cin>>src;
            cin>>dst;
            bool vis[100];
            I cost[100];
            clr(vis,false);
            clr(cost,10000);
            Q.push(node(src[0],0));
            cost[src[0]]=0;
            I cc;
            while(!Q.empty())
            {
                node tmp=Q.front();
                Q.pop();
                char cn=tmp.name;
                cc=tmp.cost;
                if(cn==dst[0]) break;
                if(vis[cn]) continue;
                vis[cn]=true;
                I sz=V[cn].size();
                for(i=0; i<sz; i++)
                {
                    if(!vis[V[cn][i]])
                    {
                        char adjn=V[cn][i];
                        I adjc=cc+1;
                        if(adjc<cost[adjn])
                        {
                            Q.push(node(adjn,adjc));
                            path[adjn].clear();
                            path[adjn].PB(cn);
                        }
                    }
                }
            }
            queue<char>qu;
            qu.push(dst[0]);
            S res="";
            I ct=0;
            while(!qu.empty())
            {
                char top=qu.front();
                if(top==src[0]) break;
                qu.pop();
                res+=(path[top][0]);
                qu.push(path[top][0]);
            }
            I siz=res.length();
            for(i=siz-1; i>=0; i--)
            {
                cout<<res[i];
            }
            cout<<dst[0];
            nl();
            while(!Q.empty())
                Q.pop();
            while(!qu.empty())
                qu.pop();
        }
        for(i=0; i<100; i++)
            V[i].clear();

    }
    return 0;
}

