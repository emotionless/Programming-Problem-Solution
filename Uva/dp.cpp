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


int BIT(int n);

int res[1000001];

int main()
{
    int i,j,k;
    int n;
    res[0]=0;
    res[1]=1;
    res[2]=1;
    for(i=3; i<1000001; i++)
    {
        int bit=BIT(i);
        int rest1=i-(pow(2.0,(double)(bit-1)));
        int rest2=pow(2.0,(double)bit)-i;
        int temp1=res[rest1];
        int temp2=res[rest2];
        res[i]=1+min(temp1,temp2);
    }
    while(cin>>n)
    {
        cout<<res[n]<<endl;
    }
    return 0;

}

int BIT(int n)
{
    int cnt=0;
    while(n)
    {
        n=n>>1;
        cnt++;
    }
    return cnt;
}
