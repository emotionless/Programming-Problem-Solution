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
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) mix(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))
#define LL long long
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MAX 31650

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
bool sieve();
bool is_prime[MAX];



long NOD(long n);
int prime[3500];


int main()
{
    string s1,s2;
    bool check,conti;
    long base1,base2,power,i,sum1,sum2;
    while(cin>>s1>>s2)
    {
        check=false;

        for(base1=2; base1<=36; base1++)
        {
            for(base2=2; base2<=36; base2++)
            {
                sum1=0;
                power=0;
                conti=false;

                for(i=s1.length()-1; i>=0; i--)
                {
                    if(s1[i]>47 && s1[i]<58)
                    {
                        sum1+=(s1[i]-48)*pow(base1,power++);
                        if(s1[i]-48>=base1)
                            conti=true;
                    }

                    else
                    {
                        sum1+=(s1[i]-55)*pow(base1,power++);
                        if(s1[i]-55>=base1)
                            conti=true;
                    }
                }


                sum2=0;
                power=0;

                for(i=s2.length()-1; i>=0; i--)
                {
                    if(s2[i]>47 && s2[i]<58)
                    {
                        sum2+=(s2[i]-48)*pow(base2,power++);
                        if(s2[i]-48>=base2)
                            conti=true;
                    }

                    else
                    {
                        sum2+=(s2[i]-55)*pow(base2,power++);
                        if(s2[i]-55>=base2)
                            conti=true;
                    }
                }
                if(conti)
                    continue;

                if(sum1==sum2)
                {
                    check=true;
                    cout<<s1<<" (base "<<base1<<") = "<<s2<<" (base "<<base2<<")"<<endl;
                    break;
                }
            }
            if(check)
                break;
        }
        if(!check)
            cout<<s1<<" is not equal to "<<s2<<" in any base 2..36"<<endl;
    }
    return 0;
}

