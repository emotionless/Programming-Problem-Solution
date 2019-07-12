#include<bits/stdc++.h>

#define mp make_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 100000000
#define PI acos(-1.0)

using namespace std;

///******* Template ********///

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        T t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}
template <class T> inline T gcd(T a,T b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);
}

/**
return (a * b) % m;
where a, b, m <= 10^18
**/
template <class T> inline T multimod(T a, T b, T m)
{
    T ans = 0ll;
    a%=m, b%=m;
    while(b)
    {
        if(b&1ll) ans = m - ans > a?(ans + a): (ans + a - m);
        b >>= 1ll;
        a = (m - a)>a?a+a:a+a-m;
    }
    return (T)ans;
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides

#define LEN(a) strlen(a)

#define MX 1000000000000000000ll
#define lim 200000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

int ansm[1009];
int ansp[1009];

int main()
{
    int i,  j, k, n, num;
    string str;

    int d[10];
    d[0] = 1;

    for(i = 1; i <= 9; i++)
        d[i] = d[i-1]*10;

    getline(cin, str);

    str = "+ "+str;
    int p = 0, m = 0;
    int len = str.length();
    for(i = 0; i < len; i++)
    {
        if(str[i] == '+') p++;
        if(str[i] == '-') m++;
    }
    int c = 0;
    num = 0;
    for( i = len - 1; i>= 0; i--)
    {
        if(str[i] == ' ') break;
        num = num + (str[i]-'0')*d[c++];
    }

    m++;
    if(m > p*num || p > m*num || (p == 1 && m>1))
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    int mm = m;
    int nn = p;
    int id = 0;
    if(p > m)
    {
        int ans = num;
        for(i = 0; i < m; i++)
            ansm[i] = num;

        for(i = 0; i < m; i++)
        {
            int cn = ansm[i];
            while((m-i-1) != p && cn && p)
            {
                ansp[id++] = 1;
                p--;
                cn--;
            }
            ansp[id-1]+=cn;
        }
    }
    else
    {
        int ans = num;
        for(i = 0; i < p; i++)
            ansp[i] = num;

        for(i = 0; i < p; i++)
        {
            int cn = ansp[i];
            while((p-i-1) != m && cn && m)
            {
                ansm[id++] = 1;
                m--;
                cn--;
            }
            ansm[id-1]+=cn;
        }
    }
    cout<<"Possible"<<endl;
    stringstream ss;
    ss<<str;
    string tmp, pre;
    ss>>tmp;
    pre = tmp;
    int pl = 0, mn = 0;
    while(ss >> tmp)
    {
        if(tmp == "?")
        {
            if(pre == "+")
                cout<<ansp[pl++]<<" ";
            else
                cout<<ansm[mn++]<<" ";
        }
        else
            cout<<tmp<<" ";
        pre = tmp;
    }
















    return 0;
}
/*

? + ? - ? - ? = 50




*/
