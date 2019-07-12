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
#define MOD 1000000009
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
#define lim 85      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

ll fibo[MAX];
set<string>ST;


void precal()
{
    int i, j;
    fibo[0] = fibo[1] = 1;
    for(i = 2; i < MAX; i++)
    {
        fibo[i] = fibo[i-1] + fibo[i-2];
    }
    stringstream ss;
    for(i = 0; i < MAX; i++)
    {
        for(j = 0; j < MAX; j++)
        {
            if(i == j) continue;
            ss.clear();
            ss<<fibo[i];
            string fst;
            ss>>fst;
            ss.clear();
            ss<<fibo[j];
            string snd;
            ss>>snd;
//            cout<<fst<<" "<<snd<<endl;
//            cin.get();
            ST.insert(fst+snd);
        }
    }
    return;
}


int dp[1000001][10];
int pre[10];

char str[1000001];

int main()
{
//    use_cin;
//    WRITE;
//    READ;
    int t,  i,k, j;
    int a, c,  x, q;
    set<string>::iterator it;

    precal();
    while(scanf("%s", str+1) != EOF)
    {
        int len = LEN(str+1);
        for(i = 0; i < 10; i++) pre[i] = len+1;

        for(i = len; i > 0; i--)
        {
            for(j = 0; j < 10; j++)
            {
                dp[i][j] = pre[j];
            }
            if(isdigit(str[i]))
                pre[ str[i]-'0' ] = i;

//            cout<<"\nFor "<<i<<endl;
//
//            for(j = 0; j < 10; j++)
//                cout<< dp[i][j]<<" ";

        }
        for(i = 0; i < 10; i++)
        {
            dp[0][i] = pre[i];
//            cout<<i<<" "<<dp[1][i]<<endl;
//        cin.get();
        }


        int cnt = 0;
        for(it = ST.begin(); it != ST.end(); ++it)
        {
            string current = (*it);
            int l = current.length();
            int x = 0;
            for(j = 0; j < l; j++)
            {
                x = dp[x][ current[j]-'0' ];

                if(x == len+1)
                    break;
            }
            if(j == l)
            {
//                cout<<current<<endl;
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}

/*



aaab
3
abcc
2



*/
