#include<bits/stdc++.h>

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
#define mp make_pair
#define vi vector<int>
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


#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 100009



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


///***** Template ends here *****///
///********************* Code starts here ****************************


double dp[101][101][101];
bool vis[101][101][101];

double solve(int a, int b, int c)
{
    if(b == 0 || a == 0) return 0.0;
    if(c == 0) return 1.0;
    double &ret = dp[a][b][c];
    if(vis[a][b][c]) return ret;
    vis[a][b][c] = 1;
    ret = 0.0;
    int tot = a * b + b * c + c * a;
    double t = 0.0;
    t = (a*b*1.0)/(tot*1.0);
    ret += solve(a, b - 1, c)*t;

    t = (c*b*1.0)/(tot*1.0);
    ret += solve(a, b, c - 1)*t;

    t = (a*c*1.0)/(tot*1.0);
    ret += solve(a - 1, b, c)*t;

return ret;
}


int main()
{
    int i, j, k;
    string str, inp;
    int t, n;
    int cases = 1;
    int num, m;
    int a, b, c;
    cin>>a>>b>>c;
    clr(vis, false);

    printf("%.12lf\n",solve(a, b, c));
//    cout<<solve(a, b, c)<<endl;
    clr(vis, false);
    printf("%.12lf\n",solve(b, c, a));

    clr(vis, false);
    printf("%.12lf\n",solve(c, a, b));
//cout<<solve(c, a, b)<<endl;





    return 0;
}

/*

10 5
4 4 5 8 8

1 2 3 4
1 4 3 2
2 4 3 1

*/
