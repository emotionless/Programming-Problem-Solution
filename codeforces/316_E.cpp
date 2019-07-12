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
#define pb push_back
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
// IO

#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)
#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);

#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9


#define MOD 1000000007
#define MD 1000000007
#define MAX 200009



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

//int dr[] = {-1, 0, 1, 0}; int dc[] = {0, 1, 0, -1}; /// 4 sides
//int dr[] = {-1, -1, 0, 1, 1, 1, 0, -1}; dc[] = {0, 1, 1, 1, 0, -1, -1, -1}; /// 8 sides


///***** Template ends here *****///
///********************* Code starts here ****************************


//char str[509][509];

string str[503];
int n, m;
int Hash[502][502],dp[125252][502];

int solve(int r1, int c1, int r2, int c2)
{
    if( r1>n || r2>n || r1<1 || r2<1 ) return 0;
    if( c1>m || c2>m || c1<1 || c2<1 ) return 0;
    if( r1>r2 || c1>c2 ) return 0;
    if( str[r1][c1]!=str[r2][c2] ) return 0;
    if( r1==r2 && c1==c2 ) return 1;
    if( abs(r1-r2)+abs(c1-c2)==1 ) return 1;


    int &ret = dp[Hash[r1][r2]][c1];

    if( ret!=-1 ) return ret;
    ret=0;
    ///Down
    ret=(ret+solve(r1+1,c1,r2,c2-1));
    if(ret>=MD)ret-=MD;
    ret=(ret+solve(r1+1,c1,r2-1,c2));
    if(ret>=MD)ret-=MD;
    ///RGt
    ret=(ret+solve(r1,c1+1,r2,c2-1));
    if(ret>=MD)ret-=MD;
    ret=(ret+solve(r1,c1+1,r2-1,c2));
    if(ret>=MD)ret-=MD;

    return ret;
}


int main()
{
//    READ;
//    WRITE;
//    use_cin;

    int i, j, k;
    int cases = 1, T, S, q;
//    s2(n, m);
    cin>>n>>m;
    for(i = 1; i<= n; i++)
    {
        cin>>str[i];
        str[i] = " " + str[i];
    }
    int cnt = 0;
    for(i = 1; i < 501; i++){
        for(j = 1; j < 501; j++)
        Hash[i][j] = (++cnt);
    }

    memset(dp, -1, sizeof dp);

    printf("%d\n", solve(1, 1, n , m));











    return 0;
}
/*




*/
