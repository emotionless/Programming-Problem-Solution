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

pair<I,I>value[4*MAX];


L res[4*MAX];

L arr[MAX];

void INSERT(int ind, int st, int ed, int poss, long val)
{
    if(st==poss && ed==poss)
    {
        res[ind]=0;
        value[ind].first=val;
        value[ind].second=val;
        return;
    }
    long mid=(st+ed)/2;
    if(poss<=mid) INSERT(ind*2, st, mid, poss, val);
    else INSERT(ind*2+1, mid+1, ed, poss, val);

    res[ind]=res[ind*2]+res[ind*2+1]+(value[ind*2+1].first<value[ind*2].second?1:0);
    value[ind].first=value[ind*2].first;
    value[ind].second=value[ind*2+1].second;
}

long query_MAX(int ind, int st, int ed, int ll, int ul)
{
    if(st==ll && ed==ul)
        return res[ind];
    int mid=(st+ed)/2;
    if(ul<=mid)
        return query_MAX(ind*2,st,mid,ll,ul);
    else if(ll>mid)
        return query_MAX(ind*2+1, mid+1, ed, ll, ul);
    else
        return query_MAX(ind*2, st, mid, ll, mid) + query_MAX(ind*2+1, mid+1, ed, mid+1, ul) + (value[ind*2+1].first<value[ind*2].second?1:0);
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;
    cin>>n;

    map<L,L>M;

    for(i=1; i<=4*n; i++)
    {
        value[i].first=INT_MAX;
        value[i].second=INT_MAX;
    }

    FOR(i,1,n+1)
    {
        cin>>arr[i];

        M[arr[i]]=i;

        INSERT(1,1,n,arr[i],i);

        /*    cout<<"For "<<i<<" :\n";
            for(j=1; j<=9; j++)
            {
                cout<<j<<" "<<res[j]<<endl;
            }
            */
    }
    // cout<<res[1]<<" "<<value[5]<<endl;
    I qu,op,a,b;
    cin>>qu;
    loop(qu)
    {
        cin>>op>>a>>b;
        if(op==1)
        {
            cout<<1+query_MAX(1,1,n,a,b)<<endl;
        }
        else
        {
            I ta=a;
            I tb=b;
            M[arr[a]]=tb;
            M[arr[b]]=ta;

            swap(arr[a],arr[b]);

            INSERT(1,1,n,arr[a],a);
            INSERT(1,1,n,arr[b],b);

        }
    }


    return 0;
}

/*

5
1 3 4 2 5
3
1 1 5
2 2 4
1 1 5


*/
