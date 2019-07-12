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




/*
bool sieve()
{
    long i,j;
    prime[0]=2;
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
            prime[k++]=j;
        }
    }
}


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
double getProbability(vector <string> ratings)
{
    int num,tmp;
    vector<int>V;
    string str="";
    for(int i=0; i<ratings.size(); i++)
    {
        str+=ratings[i];

    }
    stringstream ss(str);
    ss>>num;
    V.PB(num);
    while(ss>>tmp)
    {
        V.PB(tmp);
    }
    sort(V.begin(),V.end());
    reverse(V.begin(),V.end());
    int room,j,sz=V.size();
    if(sz%20)
        room=(sz/20)+1;
    else
        room=(sz/20);
    int cnt=0,k;
    FOR(k,0,sz-1)
    {
        cnt++;
        if(V[k]==num)
            break;
    }

    if(V[0]==num || room==1)
        return 1.0;
    else
    {
        if(room==1)
            return 1.0;
        else if(cnt<=20 && cnt<=room)
            return 0.0;
        else
            return 1.0/room;
    }

}
int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;
    string num;
    vector<string> data;
    cin>>n;
    getchar();
    FOR(i,0,n-1)
    {
        getline(cin,num);
        data.PB(num);
    }

    cout<<getProbability(data);

    return 0;
}

/*
3
539 457 277 929 180 296 820 319 839 199 210 989 88
5 1033 1132 479 1023 425 340 828 843 934 1124 434
264 206 1117 569 388 351 972 348 176 1182 832


 */
