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
void digit(long num);
int ld=0;
int sd=9;

bool res[1000001];

int main()
{
    int i,j,k;
    long num;
    for(i=1; i<10; i++)
        res[i]=true;
    res[0]=false;
    for(i=10; i<1000001; i++)
    {
        digit(i);
        int a=ld;
        int b=sd;
        if(b==0)
            res[i]=false;
        else
            res[i]=(res[i-a]==false?1:(res[i-b]==false?1:0));
    }
    while(cin>>num)
    {
        if(res[num])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}

void digit(long num)
{
    ld=0;
    sd=9;
    while(num)
    {
        int d=num%10;
        num=num/10;
        ld=max(ld,d);
        sd=min(sd,d);
    }

}
