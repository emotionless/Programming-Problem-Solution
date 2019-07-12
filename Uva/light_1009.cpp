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
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MAX 20001
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




struct node
{
    int n,col;
    node() {}
    node(int a, int b)
    {
        n=a;
        col=b;
    }
};

vector<int>V[MAX];
bool vis[MAX];
int DFS(int s)
{
    int one=0,two=0;
    queue<node>Q;
    node tmp;
    tmp.n=s;
    tmp.col=1;
    Q.push(tmp);
    while(!Q.empty())
    {
        tmp=Q.front();
        Q.pop();
        int top=tmp.n;
        if(vis[top]) continue;
        vis[top]=true;
        int cc=tmp.col;
        if(cc==1)
            one++;
        else
            two++;
        for(int i=0; i<V[top].size(); i++)
        {
            int adj=V[top][i];
            if(!vis[adj])
            {
                tmp.n=adj;
                tmp.col=(cc%2+1);
                Q.push(tmp);
            }
        }
    }
    return max(one,two);
}



int main()
{
    int i,j,k;
    int n;
    int a,b,t,cases=0;
    si(t);
    while(t--)
    {
        scanf("%d",&n);
        queue<int>Q;
        FOR(i,0,n-1)
        {
            scanf("%d %d",&a,&b);
            Q.push(a);
        //    Q.push(b);
            V[a].PB(b);
            V[b].PB(a);
        }
        int sum=0;
        while(!Q.empty())
        {
            int top=Q.front();
            Q.pop();
            if(!vis[top])
            {
                int get=DFS(top);
                sum+=get;
              //  cout<<top<<" "<<get<<endl;
            }
        }
        printf("Case %d: %d\n",++cases,sum);
        FOR(i,0,MAX-1)
        {
            vis[i]=false;
            V[i].clear();
        }
    }
    return 0;
}
