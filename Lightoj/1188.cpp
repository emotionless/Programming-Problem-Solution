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
int arr[100009];

struct Z
{
    int l,r,p;

    bool operator<(const Z &b) const
    {
        return r<b.r;
    }
};

int sum[4*100009];
Z seg[4*100009];
int val[100009];
int res[50009];

void insert(int ind, int st, int ed,int pos, int val)
{
    if(st==pos && ed==pos)
    {
        sum[ind]=val;
        return;
    }
    int mid=(st+ed)/2;

    if(pos<=mid)
        insert(ind*2, st, mid, pos, val);
    else
        insert(ind*2+1, mid+1, ed, pos, val);

    sum[ind]=sum[ind*2]+sum[ind*2+1];
}


int query(int ind, int st, int ed, int l, int r)
{
    if(st==l && ed==r)
        return sum[ind];

    int mid=(st+ed)/2;
    if(r<=mid)
        return query(ind*2, st, mid, l, r);
    else if(l>mid)
        query(ind*2+1, mid+1, ed, l, r);
    else
    {
        return query(ind*2, st, mid, l, mid)+ query(ind*2+1, mid+1, ed, mid+1, r);
    }
}


int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j;
    int n,qu, cases=1, t;
    s1(t);
    while(t--)
    {
        s1(n);
        s1(qu);

        memset(sum, 0, sizeof sum);
        memset(seg, 0, sizeof seg);
        memset(val, 0, sizeof val);
        memset(res, 0, sizeof res);

        for(i=1; i<=n; i++)
        {
            s1(arr[i]);
        }
        for(i=0; i<qu; i++)
        {
            seg[i].p=i;
            scanf("%d %d", &seg[i].l, &seg[i].r);
        }
        sort(seg, seg+qu);
        j=1;
        for(i=0; i<qu; i++)
        {
            for(; j<=seg[i].r; j++)
            {
                int cur=arr[j];
                if(val[cur]==0)
                {
                    insert(1,1,n,j,1);
                    val[cur]=j;
                }
                else
                {
                    insert(1,1,n,val[cur], 0);
                    insert(1,1,n,j,1);
                    val[cur]=j;
                }
            }
            int k=seg[i].p;
            res[k]=query(1,1,n,seg[i].l, seg[i]. r);
        }
        printf("Case %d:\n", cases++);
        for(i=0; i<qu; i++)
            printf("%d\n", res[i]);

    }
    return 0;
}
