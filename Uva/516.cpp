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
#define L long
#define I int
#define vi vector<int>
#define MAX 33000
#define nl() printf("\n")
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


vi V;
stack<LL>st;
bool is_prime[MAX];


bool sieve()
{
    long i,j;
    V.PB(2);
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            V.PB(j);
        }
    }
}

/*

long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/

void generate(LL n)
{
    L sq=sqrt(n);
    int sz=V.size(),i;
    for(i=0; i<sz && V[i]<=sq; i++)
    {
        if(n%V[i]==0)
        {
            int cnt=0;
            while(n%V[i]==0)
            {
                cnt++;
                n/=V[i];
            }
            st.push(V[i]);
            st.push(cnt);
        }
        if(n==1) break;
        sq=sqrt(n);
    }
    if(n>1)
    {
        st.push(n);
        st.push(1);
    }
}




int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;
    sieve();
    string str;
    while(getline(cin,str))
    {
        if(str=="0") return 0;
        stringstream ss(str);
        int num,exp;
        LL mul=1;
        while(ss>>num)
        {
            ss>>exp;
            mul*=(pow(num,(double)exp));
        }
        generate(mul-1);
        while(!st.empty())
        {
            int top1=st.top();
            st.pop();

            int top2=st.top();
            st.pop();
            cout<<top2<<" "<<top1;
            if(!st.empty())
                cout<<" ";
        }
        nl();
    }
    return 0;

}
