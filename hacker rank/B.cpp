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
#define pii pair<LL, LL>
#define mp make_pair

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
#define INF 10000000
#define MOD 1000000007
#define MAX 500009
#define N 500001
#define ll long long



using namespace std;


bool vis[MAX];
int arr[MAX];
int tot;
ll dp[1000009][2];

ll solve(int ind, int sum)
{
    if(ind == tot)
    {
        if(sum == 0) return 1ll;
        return 0ll;
    }
    ll &ret = dp[ind][sum];
    if(ret != -1ll) return ret;
    if(sum == 0)
    ret = 1ll;
    else
        ret = 0ll;
    ret = solve(ind + 1, sum);
    if((sum + arr[ind]) %2 == 0)
        ret = (ret + (solve(ind + 1, 0)) % MOD) % MOD;
    else
    ret = (ret + solve(ind + 1, 1)) % MOD;

//    cout<<ind<<" "<<sum<<" "<<ret<<endl;
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
    LL a, b, n, m;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int ind;
        ind = 0;
        int num;
        clr(arr, 0);
        clr(vis, false);
        for(i = 0; i <m; i++)
        {
            cin>>num;
            vis[num] = 1;
            if(num >= 10)
                arr[ind++] = log10(num);

        }
        sort(arr, arr + m);
        memset(dp, -1ll, sizeof dp);
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                arr[ind++] = log10(i);

            }
        }
        tot = ind;
        ll get = solve(0, 0);
        cout<<(get-1 + MOD)%MOD<<endl;
    }

    return 0;
}

/*

1
10 9 1 2 3 4 5 6 7 8 9

*/
