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
#define frr(i,a) for(i = a - 1; i >= 0; i--)
#define LL long long
#define ll long long int
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
#define sp printf(" ")
#define nl printf("\n")
#define eps 1e-9
#define deb cerr<<"I am here"<<endl
#define MAX (lim+7)
#define INF 1000000000000000ll
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

#define MX 10000000000000ll
#define MOD 1000000007
#define lim 50000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

/// DC3 is here

#define rep(i, a, b) for(int i = a; i <= b; i++)

const int N = 50009;

struct SUFFIX_ARRAY
{
    int wa[N],wb[N],ws[N],wv[N],r[N];
    int len;

    int rank[N]; // here rank said in which position a suffix is situated in the sorted suffix list.
    int height[N]; //height gives the LCP of id && id-1
    int sa[N]; //sa gives the sorted suffix indexes (staring index)

    int dp[N][21]; // for LCP

    int cmp(int *ar,int a,int b,int l)
    {
        return (ar[a]==ar[b]) && (ar[a+l]==ar[b+l]);
    }

    void DA(int n,int m)
    {
        int i,j,p,*x=wa,*y=wb,*t;
        for(i=0; i<m; i++) ws[i]=0;
        for(i=0; i<n; i++) ws[x[i]=r[i]]++;
        for(i=1; i<m; i++) ws[i]+=ws[i-1];
        for(i=n-1; i>=0; i--) sa[--ws[x[i]]]=i;
        for(j=1,p=1; p<n; j*=2,m=p)
        {
            for(p=0,i=n-j; i<n; i++) y[p++]=i;
            for(i=0; i<n; i++) if(sa[i]>=j) y[p++]=sa[i]-j;
            for(i=0; i<n; i++) wv[i]=x[y[i]];
            for(i=0; i<m; i++) ws[i]=0;
            for(i=0; i<n; i++) ws[wv[i]]++;
            for(i=1; i<m; i++) ws[i]+=ws[i-1];
            for(i=n-1; i>=0; i--) sa[--ws[wv[i]]]=y[i];
            for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1; i<n; i++)
                x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
            //printf("p = %d\n", p );
        }
    }

    void calheight(int n)
    {
        //  memset(height,0,sizeof(height));
        //  memset(rank,0,sizeof(rank));
        int i,j,k=0;
        for(i=1; i<=n; i++) rank[sa[i]]=i;
        for(i=0; i<n; height[rank[i++]] = k )
            for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
    }



    void generate(char *s)
    {
        int n;
        for (n=0; s[n] ; n++) r[n]=(int)s[n];
        r[n]=0;

        this->len  = n;

        DA(n+1,128);
        calheight(n);
    }

    void sparse_table()
    {
        int n =  len+1;

        for(int i=0; i<n; i++) dp[i][0]=i;

        for (int j=1; (1 << j) <= n; j++)
            for (int i = 0; i+(1 << j)-1<n; i++)
                dp[i][j] = (height[ dp[i][j-1] ]<=height[ dp[ i+(1<<(j-1))][j-1] ])? dp[i][j]=dp[i][j-1]:dp[i+(1<<(j-1))][j-1];
    }

    int find_lcp(int start,int end)
    {
        if(start>end) swap(start,end);
        start++;
        int diff=end-start;
        diff=31 - __builtin_clz(diff+1);
        return height[dp[start][diff]]<=height[dp[end-(1<<diff)+1][diff]]?height[dp[start][diff]]:height[dp[end-(1<<diff)+1][diff]];
    }

    void print()
    {
        cout << "length :  " << len << endl;

        cout << "s[n] = '$' " << endl;

        cout << "sorted suffix index(0 based) : " << endl;
        rep(i,0,len) cout << sa[i] << " , ";
        cout << endl;

        cout << "rank of suffix " << endl;
        rep(i,0,len) cout << rank[i] << " , ";
        cout << endl;


        cout << "LCP between i and i-1 " << endl;
        rep(i,0,len) cout << height[i] << " , ";
        cout << endl;
    }

} SA;


char str[50009];

int main()
{
//    freopen("inp.txt", "r", stdin);
    int n, i, j, k;
    int t, m, u, v, w;
    s1(t);
    while(t--)
    {
        scanf("%s", str);
        int nn = LEN(str);
        SA.generate(str);
        SA.sparse_table();

        ll ans = 0ll;
        for(i = 1; i <= nn; i++)
        {
            ans += (nn-SA.sa[i]) - SA.find_lcp(i, i-1);
//            cout<<i<<" "<<ans<<endl;
        }
        printf("%lld\n", ans);
    }




    return 0;
}

/*


1
ABC
ABC


*/
