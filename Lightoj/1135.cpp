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
int seg[4*100009];

void insert(int ind, int st, int ed, int l, int r)
{
    if(st==l && ed==r)
    {
        seg[ind]+=1;
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
}

int query(int ind, int st, int ed, int pos, int sum)
{
    if(st==pos && ed==pos)
        return seg[ind]+sum;

    int mid=(st+ed)/2;
    int lft=ind*2;
    int rgt=ind*2+1;

    if(pos<=mid)
        return query(lft, st, mid, pos, sum+seg[ind]);
    else
        return query(rgt, mid+1, ed, pos, sum+ seg[ind]);
}



int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,qu, l, r, op;
    int t, cases=1;
    s1(t);
    while(t--)
    {
        scanf("%d %d", &n, &qu);

        printf("Case %d:\n", cases++);
        for(i=1; i<=qu; i++)
        {
            scanf("%d", &op);
            scanf("%d %d", &l, &r);
            l++;
            r++;
            //   memset(seg, 0, sizeof seg);
            if(op==0)
            {
                insert(1,1,n,l,r);
            }
            else
            {
                int cnt=0;
                for(j=l; j<=r; j++)
                {
                    int res=query(1,1,n,j, 0);
                    if(res%3==0 && res>0)
                        cnt++;
                }
                printf("%d\n", cnt);
            }
        }

        memset(seg, 0, sizeof seg);

    }


    return 0;
}
