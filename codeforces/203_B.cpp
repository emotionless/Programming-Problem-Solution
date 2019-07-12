#include <bits/stdc++.h>

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
#define PB push_back
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

struct Z
{
    int node;
    int cost;
};

vi V[100001];
I val[100001];
I arr[100001];
bool vis[100001];

vi solve(int s)
{
    queue<Z> Q;
    Z tmp;
    tmp.node=s;
    tmp.cost=1;

    vi hudai;
    hudai.clear();

    clr(vis,0);

    Q.push(tmp);

    while(!Q.empty())
    {

        tmp=Q.front();
        Q.pop();

        I cn=tmp.node;
        I cc=tmp.cost;


        if(vis[cn]) continue;
        if(val[cn]>1) continue;

        vis[cn]=true;

        for(int i=0; i<V[cn].size(); i++)
        {
            I adjn=V[cn][i];
            I adjc=cc+1;

            if(vis[adjn]) continue;

            if(val[adjn]>1) continue;
            if(arr[adjn]) continue;

            tmp.node=adjn;
            tmp.cost=adjc;

            Q.push(tmp);
        }
        hudai.PB(cn);

    }
    return hudai;
}

int main()
{
    int i,j,l,k;
    int n;
    vi SRC;
    SRC.clear();
    cin>>n;

    FOR(i,1,n+1)
    {
        cin>>arr[i];
        if(arr[i])
            SRC.PB(i);
    }
    I tmp;
    FOR(i,1,n+1)
    {
        cin>>tmp;
        if(tmp)
        {
            V[i].PB(tmp);
            val[tmp]++;
        }
    }

    vi res;
    I sz=SRC.size();
    FOR(i,0,sz)
    {
        vi tmp=solve(SRC[i]);
        if(tmp.size()>res.size())
            res=tmp;
    }
    I s=res.size();
    cout<<s<<endl;

    reverse(res.begin(),res.end());

    cout<<res[0];

    FOR(i,1,s)
    cout<<" "<<res[i];

}
