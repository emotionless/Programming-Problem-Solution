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
#define eps 1e-9
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(i=a;i<=b;i++)

using namespace std;


int GCD(int a, int b);

int main()
{
    int i,j,k;
    int n,lob,hor,x,y;
    cin>>x>>y>>n;
    long double diff=1000001.0;
    if(y>n)
    {
        double p=(double)x/y;
    //    cout<<p<<endl;
        for(i=1; i<=n; i++)
        {
            long double q=p*(double)i;
      //      cout<<i<<ends<<q<<endl;
            int a=floor(q);
            int b=ceil(q);
            long double r=(double)a/i;
            long double s=(double)b/i;
            if(fabs(p-r)<diff)
            {
              //  cout<<1<<ends<<i<<ends<<diff<<ends<<fabs(p-r)<<endl;
                diff=fabs(p-r);
                lob=a;
                hor=i;
            }
            if(fabs(p-s)<diff)
            {

              //  cout<<i<<ends<<diff<<ends<<fabs(p-r)<<endl;
                diff=fabs(p-s);
                lob=b;
                hor=i;
            }
        }
        int t=GCD(lob,hor);
        cout<<lob/t<<"/"<<hor/t<<endl;
    }
    else
    {
        int t=GCD(x,y);
        cout<<x/t<<"/"<<y/t<<endl;
    }

}

int GCD(int a, int b)
{
    while(1)
    {
        a=a%b;
        if(a==0) return b;
        b=b%a;
        if(b==0) return a;
    }
}
