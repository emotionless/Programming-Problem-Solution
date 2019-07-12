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

using namespace std;

void sieve();
int prime[500];

int somadan()
{

}



int main()
{
    int i,j,k;
    int n;
    sieve();
}

void sieve()
{
    bool is[1150];
    int ind=0;
    clr(is,true);
    prime[ind++]=2;
    for(i=4; i<=1150; i+=2)
        is[i]=false;
    int sq=sqrt(1150);
    for(i=3; i<=sq; i+=2)
    {
        if(is[i])
        {
            prime[ind++]=i;
            for(j=i*i; j<1150; j+=i)
                is[j]=false;
        }
    }
}
