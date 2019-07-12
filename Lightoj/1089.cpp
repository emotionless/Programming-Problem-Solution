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

int seg[4*1000009+10];
int a[500010], b[500010];
int  l[500010];
void insert(int ind, int st, int ed, int l, int r)
{
    if(l==st && r==ed)
    {
        seg[ind]+=1;
        return;
    }
    int mid=(st+ed)/2;

    if(r<=mid)
        insert(ind*2, st, mid, l, r);
    else if(l>mid)
        insert(ind*2+1, mid+1, ed, l, r);
    else
    {
        insert(ind*2, st, mid, l, mid);
        insert(ind*2+1, mid+1, ed, mid+1, r);
    }
}

int query(int ind, int st, int ed, int pos, int sum)
{
    if(st==pos && ed==pos)
        return seg[ind]+sum;

    int mid=(st+ed)/2;
    if(pos<=mid)
        return query(ind*2, st, mid, pos, sum+seg[ind]);
    else
        return query(ind*2+1, mid+1, ed, pos, sum+seg[ind]);
}


int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k, n, qu;
    int t, cases=1;
    s1(t);

    vector<int>V;
    while(t--)
    {
        scanf("%d %d", &n, &qu);
        map<int, int>M;
        M.clear();
        V.clear();
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(l, 0, sizeof l);
        memset(seg, 0, sizeof seg);
        for(i=0; i<n; i++)
        {
            s1(a[i]);
            s1(b[i]);
            V.PB(a[i]);
            V.PB(b[i]);
        }
        for(i=0; i<qu; i++)
        {
            s1(l[i]);
            V.PB(l[i]);
        }
        sort(V.begin(), V.end());
        int sz=V.size();
        k=1;
        for(i=0; i<sz; i++)
        {
            if(!M[V[i]])
                M[V[i]]=k++;
        }
        for(i=0; i<n; i++)
        {
            int lft=M[a[i]];
            int rgt=M[b[i]];
            insert(1,1,k-1,lft, rgt);
        }
        printf("Case %d:\n", cases++);
        for(i=0; i<qu; i++)
        {
            int mv=M[l[i]];
            // cout<<l[i]+1<<" "<<mv<<endl;
            int res=query(1,1,k-1, mv, 0);
            printf("%d\n", res);
        }
    }

    return 0;
}
