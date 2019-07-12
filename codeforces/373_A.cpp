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

#define WRITE freopen("semipal.out","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("semipal.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 10000000000000
#define PI acos(-1.0)
#define piii pair<int, pii>

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
#define ull unsigned long long

#define MX 10000000000000000ll
#define lim 200000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

int arr[MAX];
int day[MAX];
int store[MAX];
int tmp[MAX];


int main()
{
//    use_cin;
//    WRITE;
//    READ;

    int i, j, k;
    int t, cases = 1, n, m;
    cin>>n>>t;
    string str;
    cin>>str;
    int pos = -1;
    for(i = 0;  i < n; i++)
    {
        if(str[i] == '.')
        {
            pos = i;
            break;
        }
    }
    if(pos == -1)
    {
        cout<<str<<endl;
        return 0;
    }

    assert(pos >= 0);
    int br = n;
    int ind = 0;
    for(i = pos + 1; i < n; i++)
    {
        arr[ind++] = str[i] - '0';
        if(str[i] >= '5')
        {
            break;
        }
    }
    if(i == n)
    {
        cout<<str<<endl;
        return 0;
    }
    if(arr[ind-1] >= 5)
    {
        arr[ind-1] = 10;
        t--;
    }
    bool ok = 0;
    for(i = ind - 1; i >= 0; i--)
    {
//        cout<<i<< " "<<arr[i]<<endl;
        if(arr[i] >= 10)
        {
            if(i == 0) ok = 1;
            else arr[i-1]++;
        }
        else
        {
            if(arr[i] >= 5 && t)
            {
                arr[i] = 10;
                t--;
                if(i == 0) ok = 1;
                else
                    arr[i-1]++;
            }
            else
                break;
        }
    }
    if(i >= 0)
    {
        for(j = 0; j < pos; j++)
            cout<<str[j];
        if(i>= 0) cout<<'.';
        for(j = 0; j <= i; j++) cout<<arr[j];

    }
    else if(ok)
    {
        for(i = 0; i < pos; i++)
            tmp[i] = str[i] - '0';
        tmp[pos] = 10;
        for(i = pos - 1; i >= 0; i--)
        {
            tmp[i] += tmp[i+1]/10;
            tmp[i+1] %= 10;
            if(tmp[i] <= 9) break;
        }
        if(i < 0)
        {
            cout<<1;
            for(i = 0; i < pos; i++) cout<<0;
        }
        else
        {
            for(j = 0; j < pos; j++)
                cout<<tmp[j];
        }
    }




    return 0;
}

/*




3 3
1.9



*/
