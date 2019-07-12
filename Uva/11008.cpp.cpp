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
#define INF 1<<16
#define MOD 1000000007
#define MAX 1<<16
#define N 10000001
#define check_mask(aa, bb) (aa&(1<<bb))
#define set_mask(aa, bb) (aa|(1<<bb))



using namespace std;
int n;
int x[16];
int y[16];
int dp[1<<17][17];
int cnt[16][16];

bool OK(int i, int j, int k)
{
    if(((y[j]-y[i])*(x[k]-x[i]))==((y[k]-y[i])*(x[j]-x[i]))) return true;
    return false;
}
void init()
{
    memset(cnt, 0, sizeof cnt);
    for(int i=0; i<n; i++)
    {
        int j,k;
        for(j=i+1; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                if(OK(i,j,k))
                    cnt[i][j]+=(1<<k);
            }
        }
    }
}

int solve(int mask, int tot)
{
    if(tot<=0) return 0;
    int &ret=dp[mask][tot];
    if(ret!=MAX) return ret;

    int bit=__builtin_popcount(mask);
    if(!bit) return 0;
    if(bit<=2) return 1;

    for(int i=0; i<n; i++)
    {
        if(mask&(1<<i))
        {
            for(int j=i+1; j<n; j++)
            {
                if(mask&(1<<j))
                {
                    int tmp=mask;
                    int total=0;
                    for(int k=0; k<n; k++)
                    {
                        if((mask&(1<<k) ) && OK(i,j,k))
                        {
                            tmp-=(1<<k);
                            total++;
                        }
                    }
                    ret=min(ret, solve(tmp, tot-total)+1);
                }
            }
        }
    }
    return ret;
}



int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int cases=1,  m;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;
        for(i=0; i<n; i++)
            cin>>x[i]>>y[i];

        init();

        for(i=0; i<=(1<<n); i++)
        {
            for(j=0; j<=17; j++)
                dp[i][j]=MAX;
        }
        int res=solve((1<<n)-1, m);
        if(cases>1)
            cout<<endl;
        printf("Case #%d:\n%d\n", cases++, res);
    }
    return 0;
}
