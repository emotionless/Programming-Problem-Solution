#include <bits/stdc++.h>

/**********TYPE CASTING**********/
#define LL long long
#define L long
#define D double
#define LD long double
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

LL dp[1001][15000];
int N,K,S;

LL solve(int ind, int sum)
{
    if(ind==N && sum==S) return 1;
    if(ind>=N || sum>S) return 0LL;
  //  if(ind==N-1 && sum==S) return dp[ind][sum]=1;
    if(dp[ind][sum]!=-1) return dp[ind][sum];

    LL tmp=0;
    for(int i=1; i<=K; i++)
    {
        tmp=(tmp+(solve(ind+1,sum+i)%MOD))%MOD;
    }
    tmp=(tmp+MOD)%MOD;
    return dp[ind][sum]=tmp;;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int cases=1;
    int t,Q,tot;

    si(t);

    while(t--)
    {
        clr(dp,-1);
        scanf("%d %d %d",&N,&K,&S);
        LL res=(solve(0,0)%MOD+MOD)%MOD;
        printf("Case %d: %lld\n",cases++,res);
    }
    return 0;
}
