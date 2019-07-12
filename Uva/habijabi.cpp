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

void prime_fact(int n);
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
int lcm(int a, int b)
{
    return (a*b)/GCD(a,b);

}

int LCM(int a, int b, int l)
{
    int l1=lcm(a,b);
    cout<<l1<<endl;
}



int main()
{
    int i,j,k;
    int a,b,l,c;
    cin>>a>>b>>l;
    LCM(a,b,l);


    return 0;
}

void prime_fact(int n)
{
    int sq=sqrt(n),i;
    for(i=2; i<=sq; i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n=n/i;
                cout<<i<<" ";
            }
            sq=sqrt(n);
        }
    }
    if(n!=1)
        cout<<" "<<n<<endl;
}


