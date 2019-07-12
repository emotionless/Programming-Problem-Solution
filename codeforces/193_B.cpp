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

/**********TYPE CASTING**********/
#define LL long long
#define L long
#define D double
#define LD long double
#define S string
#define I int
#define ULL unsigned long long
#define q queue<int>
#define vi vector<int>
#define vl vector<long>

/**********INPUT**********/
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%ld",&a)
#define s1(a) scanf("%d",&a)
#define s2(a,b) scanf("%d%d",&a,&b)
#define s3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sll(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",&a)
#define gc() getchar()

/**********OUTPUT**********/
#define p1(a) printf("%d\n",a)
#define p2(a,b) printf("%d %d\n",a,b)
#define pll(a) printf("%lld\n",a)
#define pd(a) printf("%.10lf\n",a)
#define pcs(a,n) printf("Case %d: %d\n",a,n)
#define nl() printf("\n")

/**********LOOP**********/
#define REV(i,e,s) for(i=e;i>=s;i--)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define loop(n) for(int o=1;o<=n;o++)

/********** min/max *******/
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) mix(a,max(b,c))
#define max4(a,b,c,d) max(max(a,b),max(c,d))
#define min4(a,b,c,d) min(min(a,b),min(c,d))

/**********SHORTCUT**********/
#define len(a) a.length()
#define SET(a,x) memset(a,x,sizeof a)
#define VI vector<int>
#define SZ size()
#define CLR clear()
#define PB(A) push_back(A)
#define clr(a,b) memset(a,b,sizeof(a))


/**********CONSTANT**********/
#define MIN INT_MIN
#define PI 2acos(-1.0)
#define INF 2<<15
#define MOD 1000000007
#define MAX 200001



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

struct Z
{
    LL max_num;
    I x;
};


LL sum[MAX];
LL arr[MAX];

Z mx[4*MAX];



void INSERT(int ind, int st, int ed, int poss, LL val)
{
    if(st==poss && ed==poss)
    {
        mx[ind].max_num=val;
        mx[ind].x=poss;
        return;
    }
    long mid=(st+ed)/2;
    if(poss<=mid) INSERT(ind*2, st, mid, poss, val);
    else INSERT(ind*2+1, mid+1, ed, poss, val);

    if(mx[ind*2+1].max_num>mx[ind*2].max_num)
    {
        mx[ind].max_num=mx[ind*2+1].max_num;
        mx[ind].x=mx[ind*2+1].x;
        return;
    }
    else
    mx[ind]=mx[ind*2];
}


Z query_MAX(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
        return mx[ind];
    int mid=(st+ed)/2;
    if(ul<=mid)
        return query_MAX(ind*2,st,mid,ll,ul);
    else if(ll>mid)
        return query_MAX(ind*2+1, mid+1, ed, ll, ul);
    else
    {
        Z a=query_MAX(ind*2, st, mid, ll, mid);
        Z b=query_MAX(ind*2+1, mid+1, ed, mid+1, ul);
        if(b.max_num>a.max_num)
            return b;
        return a;
    }
}


int main()
{
    I i,j,k;
    I n;
    LL val;
    cin>>n>>k;
    FOR(i,1,n+1)
    {
        cin>>val;
        sum[i]=sum[i-1]+val;
    }

    for(i=1; i<=n-k+1; i++)
    {
        arr[i]=sum[i+k-1]-sum[i-1];
         INSERT(1,1,MAX,i,arr[i]);
    }

    I res_a,res_b;
    LL maximum=0;
    for(i=1; i<=n-k+1; i++)
    {
        LL cs=arr[i];
        Z  get=query_MAX(1,1,MAX,i+k,MAX);
        if(cs+get.max_num>maximum)
        {
            res_a=i;
            res_b=get.x;
            maximum=cs+get.max_num;
  //          cout<<i<<" "<<get.x<<" "<<maximum<<endl;

        }
    }
    cout<<res_a<<" "<<res_b<<endl;
    clr(arr,0);
    clr(sum,0);

}
