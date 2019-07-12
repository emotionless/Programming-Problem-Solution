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
#define INF 2<<16
#define MOD 1000000007
#define MAX 1000001
#define N 10000001
#define chk_mask(aa, bb) (aa&(1<<bb))
#define set_mask(aa, bb) (aa|(1<<bb))



using namespace std;

int n,m;
int x[20];
int y[20];
int dp[16][1<<16];
int tot;

int solve(int ind, int mask)
{

    int &ret=dp[ind][mask];
    if(ret!=-1) return ret;
    if(mask==(1<<tot)-1)
    {
        return max(abs(x[ind]-x[0]), abs(y[ind]-y[0]));
    }

    ret=INF;

    for(int i=0; i<tot; i++)
    {
        if(chk_mask(mask, i)==0)
        {
            ret=min(ret, solve(i, set_mask(mask,i))+ max(abs(x[ind]-x[i]), abs(y[ind]-y[i])));
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
    string str;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        k=1;
        for(i=0; i<n; i++)
        {
            cin>>str;
            for(j=0; j<m; j++)
            {
                if(str[j]=='x')
                    x[0]=i, y[0]=j;
                if(str[j]=='g')
                {
                    x[k]=i;
                    y[k]=j;
                    k++;
                }
            }
        }
        tot=k;

        memset(dp, -1, sizeof dp);

        int res=solve(0, 0);
        printf("Case %d: %d\n", cases++, res);
    }
    return 0;
}
