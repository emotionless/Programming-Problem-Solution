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
#define INF 2<<15
#define MOD 100000007
#define MAX 1000001
#define N 10000001



using namespace std;

int arr[101];
int C[101];
int dp[10001];

int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, K;
    int t, cases=0;
    cin>>t;
    while(t--)
    {
        cases++;
        cin>>K>>n;

        memset(dp, 0, sizeof dp);

        for(i=1; i<=K; i++)
            cin>>arr[i];
        for(i=1; i<=K; i++)
            cin>>C[i];

        dp[0]=1;

        for(i=1; i<=K; i++)
        {
            for(j=n; j>0; j--)
            {
                for(k=1; k<=C[i]; k++)
                {
                    if(j-k*arr[i]>=0)
                    dp[j]=(dp[j]+dp[j-k*arr[i]])%MOD;
                }
            }
        }
        cout<<"Case "<<cases<<": ";
        cout<<dp[n]<<endl;
    }


    return 0;
}