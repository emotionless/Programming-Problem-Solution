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
#define MAX 500009



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


int store[MAX];
int LB(int s, int e, int val)
{
    int st = s, ed = e, mid, ans = e;
    while(st <= ed)
    {
        mid = (st + ed)/2;
        if(val <= store[mid])
        {
            ed = mid - 1;
            ans = min(ans, mid);
        }
        else
            st = mid + 1;
    }
    return ans;
}


int UB(int s, int e, int val)
{
    int st = s, ed = e, mid, ans = s;
    while(st <= ed)
    {
        mid = (st + ed)/2;
        if(store[mid] <= val)
        {
            st = mid + 1;
            ans = max(ans, mid);
        }
        else
            ed = mid - 1;
    }
    return ans;
}







vector<int>V[MAX];
int cnt;
int mainID[MAX];
int lvl[MAX];
int st[MAX];
int ed[MAX];
vector<int>arr[MAX];
int mx;


void DFS(int u, int l)
{
    st[u] = (++cnt);
    lvl[u] = l;
    mx = max(mx, l);
    mainID[cnt] = u;

    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
        DFS(V[u][i], l + 1);
    ed[u] = cnt;
}

void BFS()
{
    queue<int>Q;
    Q.push(1);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        arr[lvl[u]].pb(st[u]);
        int  sz = V[u].size();
        for(int i = 0; i < sz; i++)
            Q.push(V[u][i]);

    }
}

int dp[30][MAX];

int start[MAX];
int en[MAX];

char str[MAX];

int main()
{
//    READ;
//    WRITE;
//    use_cin;

    int i, j, k;
    int cases = 1, T, S, q;
    int n, m, p;
//    cin>>n>>m;
    s2(n, m);


    for(i = 2; i <= n; i++)
    {
//        cin>>p;
        s1(p);
        V[p].pb(i);
    }
    DFS(1, 1);
    BFS();
    scanf(" %s", str + 1);
//    str = " " + str;
    int l = 0;
    for(i = 1; i <= mx; i++)
    {
        sort(arr[i].begin(), arr[i].end());
        int sz = arr[i].size();
        start[i] = l + 1;
        for(int j = 0; j < sz; j++)
            store[++l] = arr[i][j];
        en[i] = l;
    }

    for(i = 0; i < 26; i++)
    {
        int ch = 'a' + i;
        for(j = 1; j <= n; j++)
        {
            if(ch == str[ mainID[ store[j] ] ]) dp[i][j] = 1;
//            cout<< store[j] <<endl;
            dp[i][j] += dp[i][j - 1];
        }
    }
    int node, depth;

    while(m--)
    {
        s2(node, depth);
//        cin>>node>>depth;
        int id_start = st[node];
        int id_end = ed[node];
//        cout<<start[depth]<<" "<<en[depth]<<" "<<id_start<<" "<<id_end<<endl;
        int a = LB(start[depth], en[depth], id_start);
        int b = UB(start[depth], en[depth], id_end);

        int cnt = 0;

//        cout<<a<<" "<<b<<endl;

        for(i = 0; i < 26; i++)
        {
            cnt += (dp[i][b] - dp[i][a - 1]) % 2;
//            cout<<dp[i][b] - dp[i][a - 1]<<endl;
        }
        if(cnt > 1)
            printf("No\n");
        else
            printf("Yes\n");
    }

    return 0;
}
/*




*/
