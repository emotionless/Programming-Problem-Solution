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
#define MAX 1429432
#define N 100001



using namespace std;

struct Z
{
    int lft, rgt, sum;
} t[3*MAX + 10];

void buildTree(int l, int r, int k)
{
    t[k].lft = l;
    t[k].rgt = r;
    t[k].sum = 0;

    if(l>=r) return;

    int mid = (t[k].lft + t[k].rgt)/2;
    buildTree(l, mid, k * 2);
    buildTree(mid+1, r, k * 2 + 1);
}

void add(int n, int k, int c)
{
    if(t[k].lft == t[k].rgt && t[k].lft == n)
    {
        t[k].sum += c;
        return;
    }
    int  mid = (t[k].lft + t[k].rgt) / 2;

    if(n <= mid)
        add(n, k * 2, c);
    else
        add(n, k * 2 + 1, c);
    t[k].sum = t[k*2].sum + t[k*2+1].sum;
}
int query1(int n, int k)
{
    if(t[k].lft == t[k].rgt)
    {
        return t[k].lft;
    }
    int tmp = t[k * 2].sum;
    if(n <= tmp)
        return query1(n, k * 2);
    else
        return query1(n - tmp, k * 2 + 1);
}



void precal()
{
    for(int i = 1; i < MAX; i += 2)
        add(i, 1, 1);

    for(int i = 2; i < N; i++)
    {
      //  cout<<i<<endl;
        int cur = query1(i, 1);
        int del = 0;
        while(cur * (del + 1) - del <= MAX)
        {
            int num = query1(cur * (del + 1) - del, 1);
            add(num, 1, -1);
            del++;
        }
    }
}


int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    buildTree(1, MAX, 1);
    int cases = 1;
    precal();
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        printf("Case %d: ", cases++);
        cout<<query1(n, 1)<<endl;
    }
    return 0;
}
