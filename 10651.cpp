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

using namespace std;

int rec(LL n);


map<LL, int>M;
int cnt;

int main()
{
    int i,j,k;
    LL n=0;
    string str;
    cin>>str;
    for(i=0; i<12; i++)
    {
        if(str[i]=='o')
        {
            n=n | (1<<i);
            cout<<i<<endl;
        }
    }
    cnt=100;
    int res=rec(n);
    cout<<cnt<<endl;
}

int rec(LL n)
{
    if(M[n])
        return M[n];
    LL t=n;
    for(int i=0; i<10; i++)
    {
        if(n&(1<<i) && (n&(1<<(i+1))))
        {
            if(i+2<12 && (n&1<<(n+2)==0))
            {
                n=n|(1<<(i+2));
                n &= ~(1<<(i+1));
                n &= ~(1<<(i));
                M[n]=rec(n);
                n=t;
            }
            if(i-1>=0 && (n&(1<<(i-1))==0))
            {
                n=n|(1<<(i-1));
                n &= ~(1<<(i+1));
                n &= ~(1<<(i));
                M[n]=rec(n);
                n=t;
            }
        }
    }
    int c=0;
    for(int i=0; i<12; i++)
    {
        if(n&(1<<i))
            c++;
    }
    if(c<cnt)
        cnt=c;
return cnt;
}


//            ---oo-------
