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
#define rep(i,a,b) for(i=a;i<=b;i++)
#define MAX 10005

using namespace std;

void solve();

bool is[MAX];
int prime[MAX],res[MAX]= {};


int main()
{
    int i,j,k;
    int n;
    solve();
    while(cin>>n && n)
    {
        cout<<res[n]<<endl;
    }
    return 0;
}


void solve()
{
    int i,j;
    prime[0]=2;
    int top=0;
    for(i=3; i<MAX; i+=2)
    {
        if(!is[i])
        {
            prime[++top]=i;
            for(j=i+i; j<MAX; j+=i)
                is[j]=true;
        }
    }

    for(i=0; i<=top; i++)
    {
        int tmp=0;
        for(j=i; j<=top; j++)
        {
            tmp += prime[j];
            if(tmp>MAX)
                break;
            res[tmp]++;

        }
    }
}
