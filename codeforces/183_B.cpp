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
#define S string
#define SS stringstream
#define print(a) printf("%d\n",a)
#define len(a) a.length()
#define q queue<int>
#define vi vector<int>
#define vl vector<long>
#define nl() printf("\n")
#define ULL unsigned long long
#define FOR(i,a,b) for(i=a;i<=b;i++)
#define loop(n) for(int o=1;o<=n;o++)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define MOD 1000000007
#define MAX 1000001




using namespace std;

/*

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}




bool is_prime[MAX];
L prime[MAX];

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

bool leap(I year)
{

    /* Check if the year is divisible by 4 or
    is divisible by 400 */
    return ((year % 4 == 0 && year % 100 != 0) || ( year % 400 == 0));

}


I get(I y, I m, I d)
{
    I sum=0;
    for(I i=1; i<m; i++)
    {
        if(i<=7)
        {
            if(i%2)
                sum+=31;
            else
            {
                if(i==2)
                {
                    if(leap(y))
                        sum+=29;
                    else
                        sum+=28;
                }
                else
                    sum+=30;
            }
        }
        else
        {
            if(i%2)
                sum+=30;
            else
                sum+=31;
        }
    }
    sum+=d;
    return sum;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    L i,j,k;
    int n;
    S str,str1;

    cin>>str;
    cin>>str1;
    if(str>str1)
    swap(str,str1);
    I y,m,d;

    S a=str.substr(0,4);
    S b=str.substr(5,2);
    S c=str.substr(8,2);
    SS ss(a);
    ss>>y;
    SS ss1(b);
    ss1>>m;
    SS ss2(c);
    ss2>>d;
    I tmp=get(y,m,d);
    L res=leap(y)?367-tmp:366-tmp;

   // cout<<res<<endl;
    I year,month,day;
    S aa=str1.substr(0,4);
    S bb=str1.substr(5,2);
    S cc=str1.substr(8,2);
    SS ss3(aa);
    ss3>>year;
    SS ss11(bb);
    ss11>>month;
    SS ss22(cc);
    ss22>>day;
    I tmp1=get(year,month,day);
    L res1=tmp1;

    I lp=0,no=0;
    I ed=year;
    //cout<<res1<<endl;
    for(i=y+1; i<ed; i++)
    {
        if(leap(i))
            lp++;
        else
            no++;
    }
    res+=(lp*366 + no*365);
    if(lp==0 && no==0)
    {
        I tmp2=get(y,m,d);
        cout<<tmp1-tmp2<<endl;

    }
    else
    cout<<res+res1-1<<endl;


}
