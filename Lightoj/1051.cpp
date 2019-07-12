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
const int val[]= {0,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1};
int dp[51][51][51][2];
int n;
string str;
bool solve(int ind, int vow, int cons, bool isOk)
{
        if(vow == 3 || cons ==5) isOk = 1;

    int &ret = dp[ind][vow][cons][isOk];
    if(ind == n)
    {
        if(vow == 3 || cons == 5 || isOk)
            return ret = true;
        return ret = false;
    }
    if(ret != -1) return ret;




    if(str[ind] != '?')
    {
        if(val[str[ind] - 'A'] == 0)
            ret = solve(ind + 1, vow + 1, 0, isOk);
        else
            ret = solve(ind + 1, 0, cons + 1, isOk);
    }
    else
    {
        ret = solve(ind + 1, vow + 1, 0, isOk) || solve(ind + 1, 0, cons + 1, isOk);
    }
return ret;
}

int dp1[51][51][51][2];

int solve1(int ind, int vow, int cons, bool isOk)
{

    if(vow == 3 || cons ==5) isOk = 0;

    int &ret = dp[ind][vow][cons][isOk];
    if(ind == n)
    {
        if(isOk == false || vow == 3 || cons == 5)
            return 0;
        return 1;
    }

    if(ret != -1) return ret;


    if(str[ind] != '?')
    {
        if(val[str[ind] - 'A'] == 0)
            ret = solve1(ind + 1, vow + 1, 0, isOk);
        else
            ret = solve1(ind + 1, 0, cons + 1, isOk);
    }
    else
    {
        ret = solve1(ind + 1, vow + 1, 0, isOk) || solve1(ind + 1, 0, cons + 1, isOk);
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
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>str;
        n=str.length();

        memset(dp, -1, sizeof dp);
        int res=solve(0, 0, 0, 0);

        memset(dp, -1, sizeof dp);
        int res1=solve1(0, 0, 0, 1);

        printf("Case %d: ", cases++);
        if(res && res1)
            cout<<"MIXED"<<endl;
        else if(res)
        {
            cout<<"BAD"<<endl;
        }
        else
            cout<<"GOOD"<<endl;
    }
    return 0;
}

/*

???W??

???W?????R

*/
