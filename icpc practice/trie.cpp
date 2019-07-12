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

struct node
{
    bool endmark;
    int val;
    node *nxt[2];
    node()
    {
        endmark = false;
        val = 0;
        nxt[0] = nxt[1] = NULL;
    }
}*root;

void insert(int num)
{
//    cout<<"Insert: "<<num<<endl;
    node *cur = root;
    for(int i = 30; i >= 0; i--)
    {
        int id = (check_bit(num, i)?1:0);
        if(cur->nxt[id] == NULL) cur->nxt[id] = new node();
        cur = cur->nxt[id];
        cur->val++;
    }
    return;
}

bool check(int a, int i)
{
    return a&(1<<i);
}
int query(int num, int k)
{
    int ret = 0;
    node *cur = root;
    bool ck = 0;
    for(int i = 30; i >= 0; i--)
    {
        int id = check(num, i), q = check(k, i);

        if(q == 0)
        {
            if(cur->nxt[id] == NULL) return ret;
            cur = cur->nxt[id];
        }
        else
        {
            if(cur->nxt[id] != NULL) ret += cur->nxt[id]->val;
            if(cur->nxt[id^1] == NULL) return ret;
            cur = cur->nxt[id^1];
        }
    }
    return ret;
}

void del(node *cur)
{
    for(int i = 0; i < 2; i++)
        if(cur -> nxt[i] != NULL) del(cur->nxt[i]);
    delete(cur);
}

int main()
{
//    use_cin;
//    WRITE;
//    READ;
//freopen("inp.txt", "r", stdin);

    int j, k, i;
    int t, a, b,  m;
    int u, v, n;
    s1(t);
    while(t--)
    {
        s1(n);
        s1(k);
        root = new node();
        int sum = 0;
        ll ans = 0;
        insert(0);
        for(i = 0; i < n; i++)
        {
            s1(a);
            sum = sum ^ a;
            int get = query(sum, k);
            ans += get;
            insert(sum);
        }
        printf("%lld\n", ans);
        del(root);
    }



    return 0;
}

/*

3
5
3  7  7  7  0
5
3  8  2  6  4
5
3  8  2  6  4

1
5 10
1 1 1 1 1

*/
