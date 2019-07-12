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
#define nl printf("\n")
#define sp printf(" ")
#define pii pair<int, int>
#define vll vector<long long>
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)

#define WRITE freopen("output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("D-small-attempt0.in","r",stdin)

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
#define INF 100000000
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

#define MX 10000000000000000ll
#define lim 100000      /// 10^5

///***** Template ends here *****///
///********************* Code starts here ****************************

#define rep(i, a, b) for(int i = 0; i <= b; i++)



const int N = 100007;

struct SUFFIX_ARRAY
{
    int wa[N],wb[N],ws[N],wv[N],r[N], backward[N];
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

    void calc()
    {
        for(int i = 0; i <= len; i++)
        {
            backward[ rank[i] ] = i;
        }
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

        cout << "Backward " << endl;
        rep(i,0,len) cout << backward[i] << " , ";
        cout << endl;


    }

    ll ans(int u, int v)
    {
        ll res = 0ll;
        int pre = -1;
//        cout<<"Fuck starts here"<<endl;
        rep(i, 0, len)
        {
//            cout<<sa[i]<<endl;
            if(sa[i] >= u && sa[i] <= v)
            {
                if(pre == -1)
                {
                    res += (v-sa[i]+1);
                }
                else
                    res += (v - sa[i] + 1) - min(find_lcp(i, pre), min(v-sa[i], v-sa[pre]) + 1);
//                cout<<"-------- "<<res<<endl;
                pre = i;
            }
        }
//        cout<<"Fuck ends here"<<endl;
        return res;
    }

} SA;


char str[MAX];

int main()
{
//    use_cin;
//    WRITE;
//    READ;
//freopen("inp.txt", "r", stdin);

    int j, k, i;
    int t, a, b, n,  m;
    int u, v;
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    SA.generate(str);
    SA.sparse_table();
//    SA.calc();
    SA.print();
    int f, s;
    while(m--)
    {
        s2(u, v);
        if(u > v) swap(u, v);
        printf("%lld\n", SA.ans(u, v));

    }




    return 0;
}

/*




*/
