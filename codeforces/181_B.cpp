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
#define vi vector<int>
#define I int
#define nl() printf("\n")
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)

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


void BFS(int s);


vi V[50];
vi CON[50];
int p[50];

bool vis[50];
int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,m;
    I a,b;
    cin>>n>>m;
    queue<int>Q3;
    queue<int>Q2;
    queue<int>FREE;
    FOR(i,0,m-1)
    {
        cin>>a>>b;
        V[a].PB(b);
        V[b].PB(a);
    }
    FOR(i,0,n)
    {
        p[i]=i;
        vis[i]=false;
    }
    for(i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            BFS(i);
        }
    }
    bool p=false;
    FOR(i,1,n)
    {
        int sz=CON[i].size();
        if(sz>2)
        {
            p=true;
            break;
        }
        else if(sz==2)
        {
            Q3.push(i);
            Q3.push(CON[i][0]);
            Q3.push(CON[i][1]);
        }
        else if(sz==1)
        {
            Q2.push(i);
            Q2.push(CON[i][0]);
        }
        else if(sz==0 && p[i]==i)
        {
            FREE.push(i);
        }
    }
    if(p)
        cout<<-1<<endl;
    else if((double)Q2.size()/(double)FREE.size()>2)
        cout<<-1<<endl;
    else
    {
        while(!Q3.empty())
        {
            I top=Q3.front();
            Q3.pop();
            cout<<top;

            top=Q3.front();
            Q3.pop();
            cout<<" "<<top;

            top=Q3.front();
            Q3.pop();
            cout<<" "<<top<<endl;
        }

        while(!Q2.empty())
        {
            I top=Q2.front();
            Q2.pop();
            cout<<top;


            top=Q2.front();
            Q2.pop();
            cout<<" "<<top;

            cout<<" "<<FREE.front()<<endl;
            FREE.pop();
        }
        while(!FREE.empty())
        {
            I top=FREE.front();
            FREE.pop();
            cout<<top;

            top=FREE.front();
            FREE.pop();
            cout<<" "<<top;

            top=FREE.front();
            FREE.pop();
            cout<<" "<<top<<endl;
        }
    }

}

void BFS(int s)
{
    queue<I>Q;
    Q.push(s);
    while(!Q.empty())
    {
        int top=Q.front();
        Q.pop();
        vis[top]=true;
        for(int i=0; i<V[top].size() ; i++)
        {
            if(!vis[V[top][i]])
            {
                p[V[top][i]]=s;
                CON[s].PB(V[top][i]);
                vis[V[top][i]]=true;
                Q.push(V[top][i]);
            }
        }
    }
}
