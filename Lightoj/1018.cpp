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
#define MAX 1000001
#define N 10000001
#define check_mask(aa, bb) (aa&(1<<bb))
#define set_mask(aa, bb) (aa|(1<<bb))



using namespace std;
int n;
int x[16];
int y[16];
int dp[1<<17];
int cnt[16][16];

bool OK(int i, int j, int k)
{
    if(((y[j]-y[i])*(x[k]-x[j]))==((y[k]-y[j])*(x[j]-x[i]))) return true;
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

int solve(int mask)
{
    int &ret=dp[mask];
    if(ret!=INF) return ret;
    int cnt1=0;
    for(int i=0;i<n;i++) if(mask&(1<<i)) cnt1++;//cnt = __builtin_popcount(s);
    if(cnt1==0) return ret=0;
    if(cnt1<=2) return ret=1;
    int i,j,k;
    //cout<<mask<<endl;
    for(i=0; i<n; i++)
    {
        if(mask&(1<<i))
        {
            for(j=i+1; j<n; j++)
            {
                if(mask &(1<<j))
                    ret=min(ret, 1+solve(mask-(mask&cnt[i][j])));
            }
            break;
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
    int cases=1, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%d", &x[i]);
            scanf("%d", &y[i]);
        }
        init();
        fill(dp, dp+(1<<16), INF);
        int res=solve((1<<n) - 1);
        printf("Case %d: %d\n", cases++, res);
    }
    return 0;
}
