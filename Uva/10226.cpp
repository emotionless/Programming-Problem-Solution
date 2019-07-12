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
#define nl printf("\n")

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

int main()
{
    int i,j,k;
    int n;
    char in[100];
    vector<string>V;
    map<string, int>M;
    int t;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        int tot=0;
        while(gets(in) && in[0])
        {
            string str(in);
            if(!M[str])
                V.PB(str);
            M[str]++;
            tot++;
        }
        sort(V.begin(), V.end());
        int sz=V.size();
        for(i=0; i<sz; i++)
        {
            cout<<V[i]<<" ";
            printf("%.4lf\n",(M[V[i]]*100.00/tot));
        }
        if(t)
        nl;
        V.clear();
        M.clear();
    }
    return 0;
}
