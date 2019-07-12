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
#define LL int int
#define ULL unsigned int int
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;
int sieve();

bool is[10001];
int prime[3000];


int main()
{
    int i,j,k;
    int top=sieve();
    int ans=1,a,c;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&c);
        if(c%a==0)
        {
            ans=1;
            for(i=1; i<=top && prime[i]*prime[i]<=c; i++)
            {
                int t1=0,t2=0;
                while(c%prime[i]==0)
                {
                    c=c/prime[i];
                    t1++;
                }
                while(a%prime[i]==0)
                {
                    a=a/prime[i];
                    t2++;
                }
                if(t1>t2)
                {
                    for(j=0; j<t1; j++)
                        ans *= prime[i];
                }
            }
            if(c>1 && a==1)
                ans=ans*c;
            printf("%d\n",ans);
        }
        else
            printf("NO SOLUTION\n");
    }
    return 0;
}

int sieve()
{
    clr(is,true);
    int top=1;
    prime[1]=2;
    for(int i=3; i<10001; i+=2)
    {
        if(is[i])
        {
            for(int j=i*i; j<=10001; j+=i)
                is[j]=false;
            prime[++top]=i;
        }
    }
    return top;
}
