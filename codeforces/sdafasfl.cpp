#include<bits/stdc++.h>
/**Define file I/O **/
#define f_input freopen("input.txt","r",stdin)
#define f_output freopen("output.txt","w",stdout)
/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
/**Define function and object**/
#define SQR(x) ((x)*(x))
#define DIS(a,b,c,d) sqrt(SQR(a-c)+SQR(b-d))
/**Define constant value**/
#define ERR 1e-9
#define pi (2*acos(0))
#define pb push_back
#define mp make_pair
#define M 1000000007
#define pii pair<int,int>
/**Define input**/
/** priority_queue<int,vector<int>, prioritycom > pq **/
/**  set<int>::iterator it **/
using namespace std;
/**Typedef**/
typedef long long int ll;
const int INF=0x7FFFFFFF;
/**Template & structure**/
struct prioritycom{bool operator()(const int& l, const int& r){return l < r;}};/// priority queue compare function
template<typename T>T lcm(T a, T b){return a / __gcd(a,b) * b;}
template<class T>T bigmod(T n,T p,T m){if(p==0)return 1;if(p%2==0){T t=bigmod(n,p/2,m);return (t*t)%m;}return (bigmod(n,p-1,m)*n)%m;}
template <class string> ll strton(string s){ll won;stringstream ss;ss<<s;ss>>won;return won;}/// convert string to number
template <class T> string ntostr(T n){stringstream ss;ss << n;return ss.str();}/// convert a number to string
template<class T> inline T mod(T n,T m){return (n%m+m)%m;}   ///For Positive Negative No.
template<class T> bool isprime(T n){if(n%2==0){if(n==2)return true;else return false;}T m=sqrt(n);for(T i=3; i<=m; i+=2){if(n%i==0)return false;}return true;}
bool isvowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true;return false;}
bool isconsonant(char ch){if (isalpha(ch) && !isvowel(ch))return true;return false;}
/******************************End******************************/
int tree[120005],a[30005],inf=999999;
void update(int node, int s, int e, int x, int v)
{
    if(x>e||x<s)
        return ;
    if(x<=s&&e<=x)
    {
        tree[node]=v;
        return ;
    }
    int lt, rt, mid;
    lt=node<<1;
    rt=lt+1;
    mid=(s+e)>>1;
    update(lt,s,mid,x,v);
    update(rt,mid+1,e,x,v);
    tree[node]=min(tree[lt],tree[rt]);
}
int query(int node, int s, int e, int l, int r)
{
    if(l>e||r<s)
        return inf;
    if(l<=s&&e<=r)
    {
        return tree[node];
    }
    int lt,rt,mid;
    lt=node<<1;
    rt=lt+1;
    mid=(s+e)>>1;
    int r1=inf,r2=inf;
    r1=query(lt,s,mid,l,r);
    r2=query(rt,mid+1,e,l,r);
    return min(r1,r2);
}
int storeLeft[30005];
int storeRight[30005];
int main()
{
    int t,cno=0;
    scanf("%d",&t);
    while(t--)
    {
        int n,ans=0;
        scanf("%d",&n);
        /*for(int i=0;i<4*n;i++)
        {
            tree[i]=inf;
        }*/
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            update(1,1,n,i,a[i]);
        }
        a[0] = 300000000;
        storeLeft[0] = 1;
        storeRight[0] = 1;
        for(int i=1;i<=n;i++)
        {
            int h=a[i];
            int lo=1,hi=i-1,mid,x,y;
            if(a[i] > a[i-1]) lo = i;
            else hi = storeLeft[i-1];
            while(lo<=hi)
            {

                mid=(lo+hi)>>1;
                int mn=query(1,1,n,mid,hi);
                if(mn>=h)
                    hi=mid-1;
                else  lo=mid+1;
            }
            x=lo;
            storeLeft[i] = x;
            lo=i+1,hi=n,mid;
            if(a[i] > a[i-1]) hi = storeRight[i-1];
            else lo = storeRight[i-1];

//            cout<<lo<<" "<<hi<<endl;


            while(lo<=hi)
            {
                mid=(lo+hi)>>1;
                int mn=query(1,1,n,lo,mid);
                if(mn>=h)
                    lo=mid+1;
                else  hi=mid-1;
            }
            y=lo-1;
            storeRight[i] = y;
            ans=max(ans,h*(y-x + 1));
//            cout<<i<<" "<<y<<" "<<x<<endl;
        }
        printf("Case %d: %d\n",++cno,ans);
    }
    return 0;
}
