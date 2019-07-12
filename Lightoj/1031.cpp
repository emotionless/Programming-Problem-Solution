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
#define INF 99999999
#define MOD 1000000007
#define MAX 1000001
#define N 10000001



using namespace std;
int sum[101];
int dp[101][101];


int solve(int i, int j)
{
    int &ret=dp[i][j];
    if(ret>-INF) return ret;

    ret=sum[j]-sum[i-1];

    for(int k=i; k<=j; k++)
    {
        ret=max(ret,  sum[k]-sum[i-1]-solve(k+1, j) );
        ret=max(ret, sum[j]-sum[k-1]-solve(i, k-1));
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

    int i,j,k, n;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(sum, 0, sizeof sum);

        for(i=1; i<=n; i++)
        {
            for(j=i+1; j<=n; j++)
                dp[i][j]=-INF;
        }
        int num;
        for(i=1; i<=n; i++)
        {
            cin>>num;
            dp[i][i]=num;
            sum[i]=sum[i-1]+num;
        }

        int res=solve(1, n);
        printf("Case %d: %d\n", cases++, res);
    }

    return 0;
}
