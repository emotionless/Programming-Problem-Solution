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
#define MOD 1000000007
#define MAX 1000001
#define N 10000001



using namespace std;
int dig[15];
LL dp[20][2];
LL power[21];
LL rec(int ind, bool is, bool chk)
{
    if(ind == 0) return !is;
    LL &ret = dp[ind][is];
    if(!chk && ret != -1) return ret;

    int mx = (!chk ? 9 : dig[ind]);
    ret = 0;
    for(int i = 0; i <= mx; i++)
    {
        if(is && i == 0)
        {
            if(!(chk && i == mx)) ret += power[ind - 1] + rec(ind -1, 1, 0);
            else
            {
                LL tmp = 0;
                for(int i = ind - 1; i > 0; i--)
                    tmp = tmp * 10 + dig[i];
                tmp++;
                ret += tmp + rec(ind - 1, 1, 1);
            }
        }
        else
            ret += rec(ind - 1, is || i!= 0, chk && i == mx);
    }

    return ret;
}

LL solve(LL n)
{
    if(n < 0) return 0;
    memset(dp, -1, sizeof dp);
    int k = 0;
    while(n > 0)
    {
        dig[++k] = n % 10;
        n = n / 10;
    }
    return rec(k, 0, 1);
}


int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    LL n,m;
    power[0] = 1;
    for(i = 1; i <20; i++)
        power[i] = power[i - 1] * 10;
    int t, cases = 1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n > m)
            swap(n, m);
        cout<<"Case "<<cases++ <<": "<<solve(m) - solve(n - 1)<<endl;
    }
    return 0;
}