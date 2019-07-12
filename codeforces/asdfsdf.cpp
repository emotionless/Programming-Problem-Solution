
#include<bits/stdc++.h>
#define ll long long int
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
#define pii pair<int,int>
/**Define input**/
/** priority_queue<int,vector<int>, prioritycom > pq **/
/**  set<int>::iterator it **/
using namespace std;
/**Typedef**/
const int INF=0x7FFFFFFF;
/**Template & structure**/
struct prioritycom
{
    bool operator()(const int& l, const int& r)
    {
        return l < r;
    }
};/// priority queue compare function
template<typename T>T lcm(T a, T b)
{
    return a / __gcd(a,b) * b;
}
template <class T> inline T bigmod(T p,T e,T M)
{
    T ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class string> ll strton(string s)
{
    ll won;    /// convert string to number
    stringstream ss;
    ss<<s;
    ss>>won;
    return won;
}
template <class T> string ntostr(T n)
{
    stringstream ss;    /// convert a number to string
    ss << n;
    return ss.str();
}
template<class T> inline T mod(T n,T m)
{
    return (n%m+m)%m;   ///For Positive Negative No.
}
template<class T> bool isprime(T n)
{
    if(n%2==0)
    {
        if(n==2)return true;
        else return false;
    }
    T m=sqrt(n);
    for(T i=3; i<=m; i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}
bool isvowel(char ch)
{
    ch=toupper(ch);
    if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E') return true;
    return false;
}
bool isconsonant(char ch)
{
    if (isalpha(ch) && !isvowel(ch))return true;
    return false;
}
#define M 1000000007

/******************************End******************************/

string s1,s2;
ll lens1,lens2;
map<string,ll>m;
ll cnt2[30],cnt1[30];
int main()
{
    ll t;
    scanf("%lld",&t);
    while(t--)
    {
        m.clear();
        mem(cnt2,0);
        mem(cnt1,0);
        cin>>s1>>s2;
        lens1=s1.length(),lens2=s2.length();
        for(ll i=lens1-1; i>=0; i--)
        {
            cnt1[s1[i]-'a']++;
        }
        ll mx=0;
        string pre;
        string ans="-1";
        for(ll i=lens2-1; i>=lens2-lens1+1; i--)
        {
            pre=s2[i]+pre;
            cnt2[s2[i]-'a']++;
        }
        vector<string>tmp;
        tmp.pb(ans);
        for(ll i=lens2-lens1; i>=0; i--)
        {
            ll f=0;
            if(i<lens2-lens1)
            {
                pre.pop_back();
                cnt2[s2[i+lens1]-'a']--;
            }
            pre=s2[i]+pre;
            cnt2[s2[i]-'a']++;
            for(ll j=0; j<26; j++)
            {
                if(cnt2[j]!=cnt1[j])
                {
                    f=1;
                    break;
                }
            }
            if(f)
                continue;
            m[pre]++;
            if(m[pre]>=mx)
            {
                if(mx==m[pre])
                {
                    tmp.pb(pre);
                }
                else
                {
                    ans=pre;
                    mx=m[pre];
                    tmp.clear();
                    tmp.pb(ans);
                }
            }
        }
        sort(tmp.begin(), tmp.end());
        cout<<tmp[0]<<endl;
    }
}



