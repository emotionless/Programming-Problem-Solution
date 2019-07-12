///                       بسم الله الرحمن الرحيم
///                   BIS-MILLAHIR RAHMANIR RAHIM

/// ==========================================================================
///
///                    S.M.SHAHEEN SHA
///
///                    Dept. of Computer Science and Engineering
///                    Jahangirnagar University , Bangladesh
///
///                    Email : shaheen.cse20@gmail.com
/// ==========================================================================

///#include<bits/stdc++.h>

#include<algorithm>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#include<deque>
#include<climits>
#include<complex>

using namespace std;

#define I1(n) scanf("%d",&n)
#define LL1(n) scanf("%lld",&n)
#define I2(n1,n2) scanf("%d%d",&n1,&n2)
#define LL2(n1,n2) scanf("%lld%lld",&n1,&n2)
#define I3(n1,n2,n3) scanf("%d%d%d",&n1,&n2,&n3)
#define LL3(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)

#define S scanf
#define P printf
#define P1(n) printf("%d\n",n);

#define LL long long int
#define ULL unsigned long long int

#define  F(i,a,b) for(i=a;i<b; i++)
#define FF(i,a,b) for(i=a;i<=b;i++)
#define FI(i,a,b) for((typeof(b)) i=a;i<=b;i++)
#define FR(i, a, b,inc) for(  i = (a); i <= (b); i+=inc )
#define RFR(i, a, b,dec) for(  i = (a); i >= (b); i-=dec )
#define FS(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
#define PR(x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++) {  cout << *it << " "; } cout << endl;

#define MEM(a,val) memset(a,val,sizeof(a));
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)

#define IN  freopen("C:\\Users\\shaheen\\Desktop\\input.txt","r",stdin)
#define OUT freopen("C:\\Users\\shaheen\\Desktop\\output.txt","w",stdout)
#define _cin  ios_base::sync_with_stdio(0); cin.tie(0);

#define Max(a,b) (a>b?a:b)
#define _Max(a,b,c) Max(a,Max(b,c))
#define Min(a,b) (a<b?a:b)
#define _Min(a,b,c) Min(a,Min(b,c))
#define SQR(n) (n*n)
#define eps (1e-9)
#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define D(ch) (ch-'0')

#define all(a) a.begin(),a.end()
#define pb push_back
#define X first
#define Y second

#define takecase cin>>tc;while(tc--)

#define CPC cout<<"Case "<<cas++<<": ";
#define CPCN cout<<"Case "<<cas++<<":"<<endl;
#define CNL cout<<endl;

#define PC  printf("Case %d: ",cas++);
#define PCN printf("Case %d:\n",cas++);
#define NL printf("\n");

#define LEFT (idx<<1)
#define RIGHT (LEFT+1)

template<typename T> T POW(T B,T P)
{
    if(P==0) return 1;
    if(P&1) return B*POW(B,P-1);
    else return SQR(POW(B,P/2));
}
template<typename T> T BIGMOD(T b,T p,T m)
{
    if(p==0) return 1;
    else if (!(p&1)) return SQR(Bigmod(b,p/2,m)) % m;
    else return ((b % m) * Bigmod(b,p-1,m)) % m;
}
template<typename T> T DIS(T x1,T y1,T x2, T y2)
{
    return sqrt( SQR(x1-x2) + SQR(y1-y2) );
}
template<typename T> T ANGLE(T x1,T y1,T x2, T y2)
{
    return atan( double(y1-y2) / double(x1-x2));
}
template<typename T> T DIFF(T a,T b)
{
    T d = a-b;
    if(d<0)return -d;
    else return d;
}
template<typename T> T ABS(T a)
{
    if(a<0)return -a;
    else return a;
}
template<typename T> T GCD(T a,T b)
{
    if(a<0)return gcd(-a,b);
    if(b<0)return gcd(a,-b);
    return (b==0)?a:gcd(b,a%b);
}
template<typename T> T LCM(T a,T b)
{
    if(a<0)return lcm(-a,b);
    if(b<0)return lcm(a,-b);
    return a*(b/gcd(a,b));
}
template<typename T> T EUCLIDE(T a,T b,T &x,T &y)
{
    if(a<0)
    {
        T d=euclide(-a,b,x,y);
        x=-x;
        return d;
    }
    if(b<0)
    {
        T d=euclide(a,-b,x,y);
        y=-y;
        return d;
    }
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    else
    {
        T d=euclide(b,a%b,x,y);
        T t=x;
        x=y;
        y=t-(a/b)*y;
        return d;
    }
}
template<typename T> T in()
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
template<typename T> LL isLeft(T a,T b,T c)
{
    return (c.x-a.x)*(b.y-a.y)-(b.x-a.x)*(c.y-a.y);
}

int    Check(int N,int pos)
{
    return (N & (1<<pos));
}
int    Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int    Reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool   isVowel(char ch)
{
    ch=toupper(ch);
    if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true;
    return false;
}
double DEG(double x)
{
    return (180.0*x)/(PI);
}
double RAD(double x)
{
    return (x*(double)PI)/(180.0);
}

void P_ARR(int *ar,int a,int b)
{
    if(a>b) swap(a,b);
    if(a<=b) cout << ar[a];
    for(int i=a+1; i<=b; i++) cout << " "<<ar[i];
    cout << endl;
}
void P_BIN(int n)
{
    if(n==0) return;
    P_BIN(n/2);
    printf("%d",n%2);
}

/// ======================================================================================================
//           0123456789
#define MX   200007
#define inf  1000000000
#define MOD  1000000007


struct data
{
    int key, priority;
    int left, right, size, fre;

    data()
    {
        size  = fre = 0;
        left  = right = 0;
    }

    void init()
    {
        left = right = 0;
        fre = size = 1;
        priority = rand();
    }

} nodes[MX<<1];

int ptr[MX<<1], HEAD, TAIL;

int newnode()
{
    int ret;
    if(HEAD) ret = ptr[--HEAD];
    else ret = ++TAIL;
    nodes[ret].init();
    return ret;
}

void INIT()
{
    HEAD = TAIL = 0;
}

struct treap
{
    int root;

    void init()
    {
        root = 0;
    }

    void update_size(int idx)
    {
        nodes[idx].size = nodes[nodes[idx].left].size + nodes[nodes[idx].right].size + nodes[idx].fre;
    }

    void left_rotate(int &root)
    {
        int tmp = nodes[root].right;
        nodes[root].right = nodes[nodes[root].right].left;
        nodes[tmp].left = root;
        update_size(root);
        update_size(tmp);
        root = tmp;
    }
    void right_rotate(int &root)
    {
        int tmp = nodes[root].left;
        nodes[root].left = nodes[nodes[root].left].right;
        nodes[tmp].right = root;
        update_size(root);
        update_size(tmp);
        root = tmp;
    }

    void insert(int val)
    {
        insert(root,val);
    }

    void insert(int& root,int val)
    {
//        cout<<root<<" "<<val<<" "<<nodes[root].left<<" "<<nodes[root].right<<endl;
        if (!root)
        {
            root = newnode();
            nodes[root].key = val;
            return;
        }

        if (nodes[root].key == val)
        {
            return; /// only one element can be inserted
            nodes[root].fre++;
            nodes[root].size++;
        }
        else if (val < nodes[root].key)
        {
            insert(nodes[root].left,val);
            cout<<nodes[root].left<<endl;
            if (nodes[nodes[root].left].priority > nodes[root].priority)  right_rotate(root);
        }
        else
        {
            insert(nodes[root].right,val);
            if (nodes[nodes[root].right].priority > nodes[root].priority)  left_rotate(root);
        }

        update_size(root);
    }

    void del(int k)
    {
        del(root, k);
    }

    void del(int &root, int k)
    {
        if (nodes[root].key == k)
        {
            if (!nodes[root].left && !nodes[root].right)
            {
                if (nodes[root].fre == 1)
                {
                    ptr[HEAD++] = root;
                    root = 0;
                }
                else
                {
                    nodes[root].fre--;
                    nodes[root].size--;
                }
                return;
            }
            if (nodes[nodes[root].left].priority > nodes[nodes[root].right].priority)
            {
                right_rotate(root);
                del(nodes[root].right, k);
            }
            else
            {
                left_rotate(root);
                del(nodes[root].left, k);
            }

        }
        else if ( nodes[root].key > k ) del(nodes[root].left, k);
        else del(nodes[root].right, k);

        update_size(root);
    }

    int find(int k)
    {
        return find(root, k);
    }

    int find(int root, int k)
    {
        if(!root) return 0;
        if(nodes[root].key == k) return nodes[nodes[root].left].size + nodes[root].fre;
        if(nodes[root].key > k) return find(nodes[root].left, k);
        return nodes[nodes[root].left].size + nodes[root].fre + find(nodes[root].right, k);
    }

    int find_kth(int k)
    {
        return find_kth(root,k);
    }

    int find_kth(int root,int k)
    {
        int lsz = nodes[ nodes[root].left ].size;
        int ase = lsz+1;
        if( ase==k ) return nodes[root].key;
        else if( ase<k ) return find_kth( nodes[root].right , k-ase );
        else return find_kth( nodes[root].left , k );
    }

} tree;


int main()
{
    _cin;
    int tc,cas=1;
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;

    while(cin>>q)
    {

        INIT();
        tree.init();


        char ch;

        F(j,0,q)
        {
            cin>>ch;

            if(ch=='I')
            {
                cin>>a;
                tree.insert(a);
            }
            else if(ch=='D')
            {
                cin>>a;
                tree.del(a);
            }
            else if(ch=='N')
            {
                cin>>x>>y;

                if(x==y) cout<<-1<<endl;
                else
                {
                    if(x>y) swap(x,y);

                    int res = INT_MAX;

                    x++;
                    y++;

                    int pre = tree.find_kth(x),now;

                    for(i=x+1; i<=y; i++)
                    {
                        now = tree.find_kth(i);
                        res = min( res , now-pre );
                        pre = now;
                    }

                    cout << res << endl;
                }
            }
            else if(ch=='X')
            {
                cin>>x>>y;
                if(x==y) cout<<-1<<endl;
                else
                {
                    if(x>y) swap(x,y);
                    x++;
                    y++;
                    cout << tree.find_kth(y)-tree.find_kth(x) << endl;
                }
            }
            else
            {
                cin>>a;
                cout << tree.find_kth(a) << endl;
            }
        }
    }


    return 0;
}
