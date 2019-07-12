#include <bits/stdc++.h>

/**********TYPE CASTING**********/
#define LL long long
#define L long
#define D double
#define LD long double
#define S string
#define I int
#define ULL unsigned long long
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

int n,m,c,q;
struct Z
{
    int mx;
    int l,r;
    int lc, rc;
};

Z seg[4*100001+10];

void insert(int ind, int st, int ed, int pos, int val)
{
    if(st==pos && ed==pos)
    {
        seg[ind].mx=1;
        seg[ind].l=1;
        seg[ind].r=1;
        seg[ind].lc=val;
        seg[ind].rc=val;

        return;
    }
    int mid=(st+ed)/2;

    if(pos<=mid)
        insert(ind*2, st, mid, pos, val);
    else
        insert(ind*2+1, mid+1, ed, pos, val);

    Z tmp;
    if(seg[ind*2].mx==0)
    {
        seg[ind]=seg[ind*2+1];

    }
    else if(seg[ind*2+1].mx==0)
    {
        seg[ind]=seg[ind*2];
    }
    else
    {
        tmp.mx=max(seg[ind*2].mx, seg[ind*2+1].mx);
        tmp.l=seg[ind*2].l;
        tmp.lc=seg[ind*2].lc;
        tmp.r=seg[ind*2+1].r;
        tmp.rc=seg[ind*2+1].rc;

        if(seg[ind*2].rc==seg[ind*2+1].lc)
        {
            int s=seg[ind*2].r+seg[ind*2+1].l;
            if(s>tmp.mx)
            {
                tmp.mx=s;
                if(seg[ind*2].lc==seg[ind*2].rc)
                    tmp.l=s;
                if(seg[ind*2+1].lc==seg[ind*2+1].rc)
                    tmp.r=s;
            }
        }
        seg[ind]=tmp;
    }

}


Z query(int ind, int st, int ed, int l, int r)
{
    if(st==l && ed==r)
    {
        return seg[ind];
    }
    int mid=(st+ed)/2;
    if(r<=mid)
        return query(ind*2, st, mid, l, r);
    else if(l>mid)
        return query(ind*2+1, mid+1,ed ,l, r);
    else
    {
        Z a=query(ind*2, st, mid, l, mid);
        Z b=query(ind*2+1,mid+1, ed, mid+1,r);
        Z tmp;

        tmp.mx=max(a.mx, b.mx);
        tmp.l=a.l;
        tmp.lc=a.lc;
        tmp.r=b.r;
        tmp.rc=b.rc;
        if(a.rc==b.lc)
        {
            int s=a.r+b.l;
            if(s>tmp.mx)
            {
                tmp.mx=s;
                if(a.lc==a.rc)
                    tmp.l=s;
                if(b.lc==b.rc)
                    tmp.r=s;
            }
        }
        return tmp;
    }
}



int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k, val;
    int t, cases=1;
    s1(t);
    while(t--)
    {
        // cin>>n>>c>>q;
        s1(n);
        s1(c);
        s1(q);
        for(i=0; i<n; i++)
        {
            s1(val);
            insert(1,1,n,i+1,val);
        }
        int a, b;


        printf("Case %d:\n", cases++);
        while(q--)
        {
            scanf("%d %d", &a, &b);
            Z res=query(1,1,n,a,b);
            printf("%d\n", res.mx);
        }
        for(i=0; i<=n*4; i++)
        {
            seg[i].mx=0;
            seg[i].l=0;
            seg[i].lc=0;
            seg[i].r=0;
            seg[i].rc=0;
        }
    }

    return 0;
}
/*

1
9 1 9
1 1 1 1 1 1 1 1 1

*/
