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



using namespace std;




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


LL solve(LL x, LL p, LL n)
{
    if(x==1) return 1;

    LL mul=1;

    for(LL i=1; i<=p; i++)
    {
        if(mul>n)
            return mul/x;
        mul=mul*x;
    }
    return mul;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,x;
    vector<LL>V;

    cin>>n>>x;

    LL arr[100001], sum=0;

    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    if(arr[n-1]==0)
    {
        cout<<1<<endl;
        return 0;
    }
    LL m=arr[n-1];
    i=n-1;
    int cnt=0;
    while(i>=0 && arr[i]==m)
    {
        i--;
        cnt++;
    }

    if(cnt%x==0)
    cnt=cnt/x;
    else cnt=0;

    while(cnt>0)
    {
        m--;

        while(i>=0 && arr[i]==m)
        {
            i--;
            cnt++;
        }
        if(cnt%x==0)
        cnt=cnt/x;
        else
        cnt=0;
    }

    LL mx=max(0LL, m);
    cout<<bigmod(x, sum-mx, MOD)<<endl;
    return 0;
}

/*

5 3
2 2 3 3 3

*/
