#include <bits/stdc++.h>

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
#define pll pair<ll, ll>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1ll<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

///**** Max/Min********///

#define _max(aa, bb) (aa = max(aa, bb))
#define max2(aa, bb) max(aa, bb)
#define max3(aa, bb, cc) max(aa, max(bb, cc))
#define max4(aa, bb, cc, dd) max(max(aa, dd), max(bb, cc))
#define _min(aa, bb) (aa = min(aa, bb))
#define min2(aa, bb) min(aa, bb)
#define min3(aa, bb, cc) min(aa, min(bb, cc))
#define min4(aa, bb, cc, dd) min(min(aa, dd), min(bb, cc))


///******* File *********///

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("A-large.in","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define s4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define nl printf("\n")
#define eps 1e-13
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 1001000000000000009ll
#define PI acos(-1.0)
#define piii pair<int, pii>
#define CLR(aa, nnn) for(int ii = 0; ii <= nnn; ii++) {aa[ii].clear();}

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

void sc(int &a)
{
    scanf("%d", &a);
}

void sc(ll &a)
{
    scanf("%lld", &a);
}

void sc(double &a)
{
    scanf("%lf", &a);
}

void sc(int &a, int &b)
{
    scanf("%d %d", &a, &b);
}

void sc(ll &a, ll &b)
{
    scanf("%lld %lld", &a, &b);
}

void sc(int &a, int &b, int &c)
{
    scanf("%d %d %d", &a, &b, &c);
}


void sc(int &a, int &b, ll &c)
{
    scanf("%d %d %lld", &a, &b, &c);
}


void sc(ll &a, ll &b, ll &c)
{
    scanf("%lld %lld %lld", &a, &b, &c);
}

void sc(string &str)
{
    cin>>str;
}


void sc(char *(str))
{
    scanf(" %s", str);
}

void sc(char &c)
{
    scanf(" %c", &c);
}


///****** fast scan ends here ***********///

//int dr[] = {-1, 0, 1, 0};
//int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


#define LEN(a) strlen(a)
#define ull unsigned long long

#define nl printf("\n")

//#define MX 10000000000000000ll
#define MX (lim*4 + 10)
#define lim 100    /// 10^5


///***** Template ends here *****///
///********************* Code starts here ****************************

int ar[MX];
int br[MX];
int n;

//map<int,char>mp;
//
//void init()
//{
//
//}

bool call(int x,int y,int z)
{
    for(int i=2;i<n && x;) {
//        if(!x) {break;}
//        int i=a;
        if(br[i]) i++;
        else if( (br[i-1]==1) || (br[i+1]==1) ) i++;
        else  br[i]=1,i+=2,x--;
//        for (int j = 1; j <= n; j++) {
//            cout << br[j] << ",";
//        }
//        cout << endl;
    }

//    pline;

//      for(int i=1;i<=n;i++)
//   {
//       cout << br[i] << ",";
//   }
//   cout << endl;

    for(int i=n-1;i>=1;){
        if(!y) {break;}
        if(br[i]) i--;
        else if( br[i-1]==2 || br[i+1]==2 ) i--;
        else br[i]=2,i-=2,y--;
//        i++;
    }
    for(int i=2;i<n;){
        if(!z) break;
        if(br[i]) i++;
        else if(br[i-1]==3 || br[i+1]==3) i++;
        else br[i]=3,i+=2,z--;
//        i--;
    }
    for(i 1; i <= n-1; i++) if(br[i]==br[i+1]) return false;
    if( (x+y+z)!=0 ) return false;
    for(i=1; i <= n; i++) {
        char ch;

        if(br[i]==1) ch='R';
        else if(br[i]==2) ch='Y';
        else ch='B';
        cout<<ch;
    }
    puts("");
    return true;
}

int main()
{
    int tc, cas;
    cin>>tc;

    for(cas=1; cas<= tc; cas++)
    {
        cin>>n;
        for(i=1; i <= 6; i++) cin>>ar[i];
        ar[2]=ar[3];
        ar[3]=ar[5];
        printf("Case #%d: ",cas);
        int flag=0;

        rep(i=1; i<=3; i++){
            for(j=i+1; j <= 3; j++){

                if(ar[i] && ar[j]){

                    clr(br, 0);

                    br[1]=i;
                    br[n]=j;

                    ar[i]--;
                    ar[j]--;

                    if( call(ar[1],ar[2],ar[3]) ) {
                        flag=1;
                        break;
                    }
                    ar[i]++;
                    ar[j]++;
                }
            }
            if(flag) break;
        }
        if(!flag) puts("IMPOSSIBLE");
    }





    return 0;
}

/*


3
3 1
2 3
2 4
4 4
-1 1 -1
-1 -1 1
-1 -1 -1
1 3
4 1
13 10
1 1000
10 8
5 5
-1 1 -1 -1
-1 -1 1 -1
-1 -1 -1 10
-1 -1 -1 -1
1 4
4 3
30 60
10 1000
12 5
20 1
-1 10 -1 31
10 -1 10 -1
-1 -1 -1 10
15 6 -1 -1
2 4
3 1
3 2





*/
