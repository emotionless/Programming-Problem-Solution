#include<bits/stdc++.h>
/**Define file I/O **/
#define f_input freopen("input.txt","r",stdin)
#define f_output freopen("output.txt","w",stdout)
/**Define memory set function**/
#define mem(x,y) memset(x,y,sizeof(x))
#define CLEAR(x) memset(x,0,sizeof(x))
/**Define function and object**/
#define pb push_back
#define Sort(v) sort(all(v))
#define RSort(v) sort(v.rbegin(),v.rend())
#define CSort(v,C) sort(all(v),C)
#define all(v) (v).begin(),(v).end()
#define sqr(x) ((x)*(x))
#define find_dist(a,b) sqrt(sqr(a.x-b.x)+sqr(a.y-b.y))
/**Define constant value**/
#define ERR 1e-9
#define pi (2*acos(0))
#define PI 3.141592653589793
/**Define input**/
#define sci(a) scanf("%d",&a)
#define scL(a) scanf("%lld",&a)
#define scs(s) scanf("%s",s)
#define scl(l) scanf(" %[^\n]",l)
#define cinl(l) getline(cin,l)
#define fr0(i,n) for(ll i=0;i<n;i++)
#define fr1(i,n) for(ll i=1;i<=n;i++)
#define pn(t) printf("%lld\n",t);

#define v(t) vector<t>
#define v2(t) vector<v(t)>
#define Q(t) queue<t>
#define Q2(t) queue<Q(t)>
#define PQ(t) priority_queue<t,v(t),prioritycom>
#define PQC(t,c) priority_queue<t,v(t),c>
#define M(t1,t2) map<t1,t2>
#define stk(t) stack<t>
#define pp(t1,t2) pair<t1,t2>
#define sets(t) set<t>
#define stitrtr(t,it) set<t>::iterator it
using namespace std;
/**Typedef**/
typedef string str;
typedef int I;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long int ld;
typedef unsigned long int ul;
typedef double dbl;

const int inf=0x7FFFFFFF;
/**Template & structure**/
struct prioritycom{bool operator()(const int& l, const int& r){return l < r;}};/// priority queue compare function
template<class T>T gcd(T a,T b){T a1=max(a,b),b1=min(a,b);return b1 == 0 ? a1 : gcd(b1, a1 % b1);}
template<typename T>T lcm(T a, T b){return a / gcd(a,b) * b;}
template<class T>T bigmod(T n,T p,T m){if(p==0)return 1;if(p%2==0){T t=bigmod(n,p/2,m);return (t*t)%m;}return (bigmod(n,p-1,m)*n)%m;}
template <class string> ll strton(string s){ll won;stringstream ss;ss<<s;ss>>won;return won;}/// convert string to number
template <class T> string ntostr(T n){stringstream ss;ss << n;return ss.str();}/// convert a number to string
template<class T> inline T mod(T n,T m){return (n%m+m)%m;}   ///For Positive Negative No.
template<class T> bool isprime(T n){if(n%2==0){if(n==2)return true;else return false;}T m=sqrt(n);for(T i=3; i<=m; i+=2){if(n%i==0)return false;}return true;}
bool isvowel(char ch){ch=toupper(ch);if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true;return false;}
bool isconsonant(char ch){if (isalpha(ch) && !isvowel(ch))return true;return false;}

/******************************End******************************/

char inp[1009];
int f[30];
int main()
{
    int i,j,t,caseno=0,n;
    sci(t);
    while(t--)
    {
        sci(n);
        scanf("%s",inp);
        memset(f,0,sizeof f);
        int len=strlen(inp);
        for(i=0;i<len;i++)
            f[inp[i]-'a']++;
        int cnt=0;
        for(i=0;i<26;i++)
        {
            if(f[i]%2==1)cnt++;
        }
        if(cnt>1)
        {
            printf("impossible\n");
        }
        else
        {
            string ans="";
            int c=-1;
            for(i=0;i<26;i++)
            {
                int times=f[i]/2;
                if(f[i]%2==1)c=i;

                for(j=0;j<times;j++)
                    ans=ans+(char)(i+'a');
            }
            string res=ans;
            if(c!=-1)
            {
                res+=(char)(c+'a');
            }
            reverse(ans.begin(), ans.end());
            res+=ans;
            cout<<res<<endl;
        }

    }
    return 0;
}
