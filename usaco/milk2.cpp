
/*
 ID: milon_c1
 LANG: C++
 PROG: milk2
 */
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


struct time
{
    int st,ed;
    bool operator <(const time& a) const
    {
        return st<a.st;
    }
};


int main()
{
    ofstream fout("milk2.out");
    ifstream fin("milk2.in");
    int n,i,a[5001],b[5001],s,e;
    fin>>n;
    //cin>>n;
    struct time data[n+1];
    FOR(i,1,n)
    {
        fin>>s>>e;
        //cin>>s>>e;
        data[i].st=s;
        data[i].ed=e;
    }
    sort(data+1,data+n+1);
    FOR(i,1,n)
    {
        a[i]=data[i].st;
        b[i]=data[i].ed;
    }
    int mxC=0;
    int mxD=0;
    int st=a[1],ed=b[1];
    FOR(i,1,n)
    {
        if(a[i]<=ed)
        {

            ed=max(ed,b[i]);
            int take=ed-st;
            mxC=max(mxC,take);
        }
        else
        {
            mxD=max(mxD,a[i]-ed);
            int take=ed-st;
            mxC=max(mxC,take);
            st=a[i];
            ed=b[i];
        }
    }
    mxC=max(mxC,ed-st);
    //cout<<mxC<<" "<<mxD<<endl;
    fout<<mxC<<" "<<mxD<<endl;
    return 0;
}
/*

6
300 1000
700 1200
1500 2100
2200 4400
5000 6000
6100 6200


4
100 200
201 301
302 402
403 503


10
2 3
4 5
6 7
8 9
10 11
12 13
14 15
16 17
18 19
1 20


*/

