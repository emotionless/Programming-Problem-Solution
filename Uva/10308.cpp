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
#define vi vector<int>
#define nl() printf("\n")
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MAX 10001

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
    I n;
    I cost;
    node() {}
    node(I a, I b)
    {
        n=a;
        cost=b;
    }
};


I arr[MAX][MAX];
vi V[MAX];

bool vis[MAX];
I get=0;

L BFS(I s)
{

    queue<node>Q;
    Q.push(node(s,0));
    clr(vis,false);

    L mx=0;

    while(!Q.empty())
    {
        node top=Q.front();
        Q.pop();
        I cn=top.n;
        I cc=top.cost;
        if(cc>mx)
        {
            mx=cc;
            get=cn;
        }

        vis[cn]=true;
        I sz=V[cn].size();
        for(I i=0; i<sz; i++)
        {
            I v=V[cn][i];
            if(!vis[v])
            {
                vis[v]=true;
                Q.push(node(v,cc+arr[cn][v]));
            }
        }
    }
    return mx;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,u,v,w;
    string str;
    while(!cin.eof())
    {
        getline(cin,str);
        if(str=="")
        {
            cout<<0<<endl;
            continue;
        }

        while(!cin.eof() && str.length()>0)
        {
            stringstream ss(str);
            ss>>u;
            ss>>v;
            ss>>w;
            V[u].PB(v);
            V[v].PB(u);
            arr[v][u]=w;
            arr[u][v]=w;
            getline(cin,str);
        }
        BFS(1);
        cout<<BFS(get)<<endl;
        for(i=0; i<MAX; i++)
        {
            V[i].clear();
            vis[i]=false;
        }
    }
    return 0;
}
