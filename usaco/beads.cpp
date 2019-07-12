
/*
 ID: milon_c1
 LANG: C++
 PROG: beads
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



int func(string str)
{
    int cnt=0,l,i;
    l=str.length();
    char got='a';
    for(i=0; i<l; i++)
    {
        char cc=str[i];
        if(cc=='w')
            cnt++;
        else
        {
            if(got=='a')
                got=cc;
            if(got==cc)
                cnt++;
            else
                break;
        }
    }
    got='a';
    for(i; i<l; i++)
    {
        char cc=str[i];
        if(cc=='w')
            cnt++;
        else
        {
            if(got=='a')
                got=cc;
            if(got==cc)
                cnt++;
            else
                break;
        }
    }
    return cnt;
}


int main()
{
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    int i,j,k;
    int n,t;
    string str,inp;
    fin>>t;
    fin>>inp;
    int l=inp.length();
    int res=0;
    for(i=0; i<l; i++)
    {
        str=inp.substr(i,l-i)+ inp.substr(0,i);
        int val=func(str);
        res=max(res,val);
    }
    fout<<res<<endl;
}
