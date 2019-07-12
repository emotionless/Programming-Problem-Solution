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
#define MAX 1000001

using namespace std;
int factorial[MAX];

int fact1(int num)
{
    int cnt=0;
    int high=sqrt(num);
    for(int i=2; i<=high; i++)
    {
        if(num%i==0)
        {
            while(num%i==0 && num/i>0)
            {
                num=num/i;
                cnt++;
            }
        }
    }
    if(num!=1)
        cnt++;
    return cnt;
}


int main()
{
    int i,j,k;
    int n;
    factorial[2]=1;
    for(int i=3; i<MAX; i++)
    {
        factorial[i]=fact1(i)+ factorial[i-1];
    }
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",factorial[n]);
    }
    return 0;
}

