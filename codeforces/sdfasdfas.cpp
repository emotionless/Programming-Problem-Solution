/********************************************
*                                           *
*    Solved By : Bir Bahadur Khatri(B'ru)   *
*      Be Positive,be Happy.                *
*                                           *
*********************************************/

#define ff first
#define D double
#define sz size()
#define ss second
#define PB push_back
#define MP make_pair
#define SQR(n) (n*n)
#define CHR getchar()
#define NL printf("\n")
#include<bits/stdc++.h>
#define ULL unsigned LL
#define PI 2.0*acos(0.0)
#define LL long long int
#define S1(a) a=in<int>()
#define SL1(a) a=in<LL>()
#define Max(a,b) ((a>b)?a:b)
#define Min(a,b) ((a<b)?a:b)
#define all(a) a.begin(),a.end()
#define _Max(a,b,c) Max(a,Max(b,c))
#define _Min(a,b,c) Min(a,Min(b,c))
#define SL2(a,b) a=in<LL>(),b=in<LL>()
#define F(i,a,b) for(int i=a;i<b; i++)
#define S2(a,b) a=in<int>(),b=in<int>()
#define R(i,a,b) for(int i=a-1;i>=b; i--)
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define SL3(a,b,c) a=in<LL>(),b=in<LL>(),c=in<LL>()
#define S3(a,b,c) a=in<int>(),b=in<int>(),c=in<int>()
#define _cin ios_base::sync_with_stdio(0); cin.tie(0)
#define cp printf("***** here here here here *****\n");
#define trace1(x)                cerr << #x << ": " << x << endl;
#define InpOut freopen("A.in","r",stdin),freopen("A1.out","w",stdout)
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

using namespace std;
template <typename T> T in()
{
    char ch;
    T n = 0;
    bool ng = false;
    while (1)
    {
        ch = getchar();
        if (ch == '-')
        {
            ng = true;
            ch = getchar();
            break;
        }
        if (ch>='0' && ch<='9')     break;
    }
    while (1)
    {
        n = n*10 + (ch - '0');
        ch = getchar();
        if (ch<'0' || ch>'9')   break;
    }
    return (ng?-n:n);
}
template<typename T>inline T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}
template<typename T>inline T Gcd(T a,T b)
{
    if(a<0)return Gcd(-a,b);
    if(b<0)return Gcd(a,-b);
    return (b==0)?a:Gcd(b,a%b);
}
template<typename T>inline T Lcm(T a,T b)
{
    if(a<0)return Lcm(-a,b);
    if(b<0)return Lcm(a,-b);
    return a*(b/Gcd(a,b));
}
long long Bigmod(long long base, long long power, long long MOD)
{
    long long ret=1;
    while(power)
    {
        if(power & 1)ret=(ret*base)%MOD;
        base=(base*base)%MOD;
        power>>=1;
    }
    return ret;
}
bool isVowel(char ch)
{
    ch=toupper(ch);
    if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true;
    return false;
}
template <typename T> LL isLeft(T a,T b,T c)
{
    return(a.x-b.x)*(b.y-c.y)-(b.x-c.x)*(a.y-b.y);
}
long long ModInverse(long long number, long long MOD)
{
    return Bigmod(number, MOD-2, MOD);
}
bool isConst(char ch)
{
    if (isalpha(ch) && !isVowel(ch)) return true;
    return false;
}
int toInt(string s)
{
    int sm;
    stringstream ss(s);
    ss>>sm;
    return sm;
}
///**********************************************************//

#define MD1 1000000007ULL
#define MD2 1000000009ULL
#define MD3 1000000021ULL
#define BS1 10000019ULL
#define BS2 10000079ULL
#define BS3 10000103ULL
#define PUL pair<ULL,ULL>
#define PLL pair<LL,LL>
#define PII pair<int,int>

///         0123456789
#define MX  200007
#define MOD 1000000007
#define INF 2000000000
#define EPS 1e-9


/// ==========================================////

int n,m;


struct Node
{
    int l,r,sum;
    Node()
    {
        l=r=0;
        sum=0;
    }
};

int avail,Root[MX];

Node Tree[20*MX];

bitset<1001> dp[MX+MX];
bitset<1001> save;
int nw;
int Id[MX*20];

int Build(int id,int l,int r,int pos)
{
    int u=++avail;
    Tree[u]=Tree[id];

    if(l==r)
    {
        ++nw;
        Id[u]=nw;
        return u;
    }

    int lft=2*id;
    int rgt=lft+1;
    int mid=(l+r)/2;
    if(pos<=mid)    Tree[u].l=Build(Tree[u].l,l,mid,pos);
    else            Tree[u].r=Build(Tree[u].r,mid+1,r,pos);
    return u;
}

int Toogle(int id,int l,int r,int pos,int p,int f)
{
    int u=++avail;
    Tree[u]=Tree[id];

    if(l==r)
    {
        ++nw;
        Id[u]=nw;
        dp[nw]=dp[ Id[id] ];
        int cnt=Tree[id].sum;
        int tp=dp[ nw ].test(p);
        if(f!=tp)
        {
            dp[ nw ].flip(p);
            if(f) cnt++;
            else cnt--;
        }

//        trace4(p,tp,f,cnt)

        Tree[u].sum=cnt;
        return u;
    }

    int lft=2*id;
    int rgt=lft+1;
    int mid=(l+r)/2;

    if(pos<=mid)        Tree[u].l=Toogle(Tree[u].l,l,mid,pos,p,f);
    else                Tree[u].r=Toogle(Tree[u].r,mid+1,r,pos,p,f);

    Tree[u].sum=Tree[ Tree[u].l ].sum+Tree[ Tree[u].r ].sum;
    return u;
}


int Update(int id,int l,int r,int pos)
{
    int u=++avail;
    Tree[u]=Tree[id];

    if(l==r)
    {

        ++nw;
        Id[u]=nw;

        dp[nw]=dp[ Id[id] ];
        int age=Tree[id].sum;
        age=m-age;
        Tree[u].sum=age;
        dp[nw]=dp[nw]^save;

        return u;
    }

    int lft=2*id;
    int rgt=lft+1;
    int mid=(l+r)/2;

    if(pos<=mid)        Tree[u].l=Update(Tree[u].l,l,mid,pos);
    else                Tree[u].r=Update(Tree[u].r,mid+1,r,pos);

    Tree[u].sum=Tree[ Tree[u].l ].sum+Tree[ Tree[u].r ].sum;
    return u;
}

int main()
{
    int q;
    S3(n,m,q);
    F(i,0,m) save.set(i);
    Root[0]=0;
    Tree[0]=Node();
    F(i,1,n+1){
        Root[0]=Build(Root[0],1,n,i);
        cout<<i<<" "<<Root[0]<<endl;
    }
    for(int i=1; i<=q; i++)
    {
        int tp;
        S1(tp);
        int x;
        S1(x);
        if(tp==1)
        {
            int y;
            S1(y);
            Root[i]=Toogle(Root[i-1],1,n,x,y-1,1);
        }
        else if(tp==2)
        {
            int y;
            S1(y);
            Root[i]=Toogle(Root[i-1],1,n,x,y-1,0);
        }
        else if(tp==3)
        {
            Root[i]=Update(Root[i-1],1,n,x);
        }
        else
        {
            Root[i]=Root[x];
        }
        printf("%d\n",Tree[ Root[i] ].sum);
    }

    return 0;
}
///============= Thank You ===================///
