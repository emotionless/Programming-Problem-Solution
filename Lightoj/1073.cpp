#include<bits/stdc++.h>

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
#define ll long long
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
#define MAX 20
#define MAXLG 20


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


string str[MAX];
int mat[MAX][MAX];


int match(int f, int s)
{
    int len = str[f].length();
    for(int i = 0; i < len; i++)
        if(str[f].substr(i) == str[s].substr(0, len - i)) return i;
    return len;
}


int dp[19][1<<17];
int n;
int solve(int ind, int mask)
{
    int &ret = dp[ind][mask];
    if(set_bit(mask, ind) == (1<<n) - 1) return ret = str[ind].length();
    if(ret != -1) return ret;
    ret = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        if(i == ind) continue;
        if(check_bit(mask, i)) continue;
        ret = min(ret,   mat[ind][i] + solve(i, set_bit(mask, i)) );
    }
    return ret;
}

string ans;

void construct(int ind, int mask, string s)
{
    if(set_bit(mask, ind) == (1<<n) - 1)
    {
        string tmp = s + str[ind];
        ans = min(ans, tmp);
        return;
    }
    if(s > ans) return;
    for(int i = 0; i < n; i++)
    {
        if(i == ind) continue;
        if((dp[i][set_bit(mask, i)] + mat[ind][i]) == dp[ind][mask])
        {
            construct(i, set_bit(mask, i), s + str[ind].substr( 0, mat[ind][i] ) );
        }
    }
    return;
}


int main()
{
//    READ;
//    WRITE;
    int i, j, type;
//    use_cin;
    int m, a, b, t, num, cases = 1;
    string inp;
    s1(t);
    while(t--)
    {
        scanf("%d", &n);
        fr(i, n)
        cin>>str[i];
        clr(mat, 0);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j) continue;
                if(str[i].find(str[j]) != string::npos)
                    str[j] = "";
            }
        }
        int k = 0;
        for(i = 0; i < n; i++)
            if(str[i] != "")
                str[k++] = str[i];
        n = k;

        sort(str, str + n);

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(i == j) continue;
                mat[i][j] = match(i, j);
            }
        }
        memset(dp, -1, sizeof dp);
        int mn = INT_MAX;
        for(i = 0; i < n; i++)
        {
            mn = min(mn, solve(i, 1<<i));
        }
        ans = "z";
        for(i  = 0; i < n; i++)
        {
            if(dp[i][1<<i] == mn)
            {
                construct(i, 1<<i, "");
            }
        }
        printf("Case %d: ", cases++);
        cout<<ans<<endl;


    }
    return 0;
}

/*





*/
