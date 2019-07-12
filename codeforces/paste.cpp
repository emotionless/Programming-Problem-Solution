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


/*

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




bool is_prime[MAX];
L prime[MAX];

bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/

int r[]= {-2, -2, 2, 2};
int c[]= {-2, 2, 2, -2};

struct Z
{
    int x,y;
    Z() {}
    Z(int a, int b)
    {
        x=a;
        y=b;
    }
};


string mat[10];

bool vis1[10][10];
bool vis2[10][10];

void solve1(int x, int y)
{
    queue<Z>Q;
    Q.push(Z(x,y));

    while(!Q.empty())
    {
        Z top=Q.front();
        Q.pop();
        int cx=top.x;
        int cy=top.y;

        if(vis1[cx][cy]) continue;

        vis1[cx][cy]=true;

        for(int i=0; i<4; i++)
        {
            int adjx=r[i]+x;
            int adjy=c[i]+y;

            if(adjx>=0 && adjx<8 && adjy>=0 && adjy<8)
            {
                if(mat[adjx][adjy]!='#')
                {
                    if(vis1[adjx][adjy]) continue;

                    Q.push(Z(adjx, adjy));
                }
            }

        }


    }

}

void solve2(int x, int y)
{
    queue<Z>Q;
    Q.push(Z(x,y));

    while(!Q.empty())
    {
        Z top=Q.front();
        Q.pop();
        int cx=top.x;
        int cy=top.y;

        if(vis2[cx][cy]) continue;

        vis2[cx][cy]=true;

        for(int i=0; i<4; i++)
        {
            int adjx=r[i]+x;
            int adjy=c[i]+y;

            if(adjx>=0 && adjx<8 && adjy>=0 && adjy<8)
            {
                if(mat[adjx][adjy]!='#')
                {
                    if(vis2[adjx][adjy]) continue;

                    Q.push(Z(adjx, adjy));
                }
            }

        }
    }

}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;

    cin>>n;
    while(n--)
    {
        for(i=0; i<8; i++)
            cin>>mat[i];

        bool f=true;
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(mat[i][j]=='K')
                {
                    if(f)
                    {
                        solve1(i,j);
                        f=false;
                    }
                    else
                    {
                        solve2(i,j);
                    }
                }

            }
        }

        bool c=0;

        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                if(vis1[i][j]==true && vis2[i][j]==true && mat[i][j]!='#')
                {
                    cout<<"YES"<<endl;
                    c=1;
                    break;
                }
            }
            if(c)
                break;
        }
        if(!c)
        cout<<"NO"<<endl;
        clr(vis1, false);
        clr(vis2, false);

    }



    return 0;
}
