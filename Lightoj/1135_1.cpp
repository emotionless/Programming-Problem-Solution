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

struct Z
{
    int cnt[3];
    int have;

} seg[4*100009+10];

void build(int ind, int st, int ed)
{
    if(st==ed)
    {
        seg[ind].have=0;
        seg[ind].cnt[0]=1;
        seg[ind].cnt[1]=0;
        seg[ind].cnt[2]=0;
        return;
    }
    int mid=(st+ed)/2;
    int lft=ind*2;
    int rgt=ind*2+1;
    seg[ind].cnt[0]=ed-st+1;
    seg[ind].have=0;
    seg[ind].cnt[1]=0;
    seg[ind].cnt[2]=0;

    build(lft, st, mid);
    build(rgt, mid+1, ed);
}

void insert(int ind, int st, int ed, int l, int r)
{
    if(st==l && ed==r)
    {
        seg[ind].have=(seg[ind].have+1)%3;
        int tmp=seg[ind].cnt[2];
        seg[ind].cnt[2]=seg[ind].cnt[1];
        seg[ind].cnt[1]=seg[ind].cnt[0];
        seg[ind].cnt[0]=tmp;
        return;
    }
    int mid=(st+ed)/2;
    int lft=ind*2;
    int rgt=ind*2+1;

    if(r<=mid)
        insert(lft, st, mid, l, r);
    else if(l>mid)
        insert(rgt, mid+1, ed, l, r);
    else
    {
        insert(lft, st, mid, l, mid);
        insert(rgt, mid+1, ed, mid+1, r);
    }
    seg[ind].cnt[0]=seg[lft].cnt[0]+ seg[rgt].cnt[0];
    seg[ind].cnt[1]=seg[lft].cnt[1]+ seg[rgt].cnt[1];
    seg[ind].cnt[2]=seg[lft].cnt[2]+ seg[rgt].cnt[2];
    if(seg[ind].have==1)
    {
        int temp=seg[ind].cnt[2];
        seg[ind].cnt[2]=seg[ind].cnt[1];
        seg[ind].cnt[1]=seg[ind].cnt[0];
        seg[ind].cnt[0]=temp;
    }
    else if(seg[ind].have==2)
    {
        int temp=seg[ind].cnt[2];
        seg[ind].cnt[2]=seg[ind].cnt[0];
        seg[ind].cnt[0]=seg[ind].cnt[1];
        seg[ind].cnt[1]=temp;
    }
}

Z query(int ind, int st, int ed, int l, int r)
{
    if(st==l && ed==r)
        return seg[ind];

    int mid=(st+ed)/2;
    Z ret;
    if(r<=mid)
        ret=query(ind*2, st, mid, l, r);
    else if(l>mid)
        ret=query(ind*2+1, mid+1, ed, l, r);
    else
    {
        Z a=query(ind*2, st, mid, l, mid);
        Z b=query(ind*2+1, mid+1, ed, mid+1, r);

        ret.cnt[0]=a.cnt[0]+b.cnt[0];
        ret.cnt[1]=a.cnt[1]+b.cnt[1];
        ret.cnt[2]=a.cnt[2]+b.cnt[2];
        // cout<<a.have<<" "<<a.cnt[0]<<" "<<a.cnt[1]<<" "<<a.cnt[2]<<endl;
        //  cout<<b.have<<" "<<b.cnt[0]<<" "<<b.cnt[1]<<" "<<b.cnt[2]<<endl;
    }
    if(seg[ind].have==1)
    {
        int tmp=ret.cnt[2];
        ret.cnt[2]=ret.cnt[1];
        ret.cnt[1]=ret.cnt[0];
        ret.cnt[0]=tmp;
    }
    else if(seg[ind].have==2)
    {
        int tmp=ret.cnt[2];
        ret.cnt[2]=ret.cnt[0];
        ret.cnt[0]=ret.cnt[1];
        ret.cnt[1]=tmp;
    }
    //cout<<ind<<" "<<seg[ind].have<<" "<<seg[ind].cnt[0]<<" "<<seg[ind].cnt[1]<<" "<<seg[ind].cnt[2]<<endl;
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

    int qu, n, op, l,r, t, cases=1;
    s1(t);
    while(t--)
    {
        s1(n);
        s1(qu);

        build(1,1,n);
        printf("Case %d:\n", cases++);
        for(j=0; j<qu; j++)
        {
            scanf("%d %d %d", &op, &l, &r);
            l++;
            r++;
            if(op==0)
            {
                insert(1,1,n,l,r);
            }
            else
            {
                Z res=query(1,1,n,l,r);
                printf("%d\n", res.cnt[0]);
            }
        }
        memset(seg, 0, sizeof seg);
    }
    return 0;
}

/*

10 9
0 0 9
0 3 7
0 1 4
0 2 2
1 2 4

*/
