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
#define MAX 1000009



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
const int mx = 26;
struct node
{
    int nxt[mx];
    node()
    {
        memset(nxt, -1, sizeof nxt);
    }
};

node T[MAX];
int fl[MAX];
int ind[501];
int nw;
int val[MAX];

int ST[MAX];
int top;

void init()
{
    nw = 0;
    top = 0;
    memset(T, 0, sizeof T);
    memset(fl, 0, sizeof fl);
    memset(ind, 0, sizeof ind);
    memset(val, 0, sizeof val);
    T[0] = node();
}

void Aho(char S[], int pos)
{
    int len = strlen(S);
    int p = 0;
    for(int i = 0; i < len; i++)
    {
        int id = S[i] - 'a';
        if(T[p].nxt[id] == -1)
        {
            T[p].nxt[id] = (++nw);
            T[nw] = node();
        }
        p = T[p].nxt[id];
    }
    ind[pos] = p;
//    cout<<pos<<" "<<p<<endl;
}


void Failure()
{
//    cout<<"Failure is here\n";
    queue<int>Q;
    for(int i = 0; i < mx; i++)
    {
        if(T[0].nxt[i] != -1)
            Q.push(T[0].nxt[i]);
        else
            T[0].nxt[i] = 0;
    }
    fl[1] = 0;
    top = 0;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        ST[top++] = u;

        for(int i = 0; i < mx; i++)
        {
            int v = T[u].nxt[i];
            if(T[u].nxt[i] == -1)
            {
                T[u].nxt[i] = T[fl[u]].nxt[i];
                continue;
            }
            fl[v] = T[fl[u]].nxt[i];
            Q.push(v);
        }
    }
}

void Search(char tar[])
{
    int p = 0;
    int len = strlen(tar);
    for(int i = 0; i < len; i++)
    {
        int id = tar[i] - 'a';
        p = T[p].nxt[id];
        val[p]++;
//        cout<<p<<endl;
    }
    for(int i = top - 1; i >= 0; i--)
    {
        int id = ST[i];
        val[fl[id]] += val[id];
    }

    return;
}


char str[501][501];
char tar[MAX];

int main()
{
//    READ;
//    WRITE;
//    use_cin;

    int i, j, k;
    int cases = 1, S, q;
    int  m, n;
    int t;
    s1(t);

    while(t--)
    {
        scanf("%d", &n);
        scanf(" %s", tar);

        for(i = 0; i < n; i++)
            scanf(" %s", str[i]);

        nw = 0;
        init();

        for(i = 0; i < n; i++)
            Aho(str[i], i + 1);
        Failure();
        Search(tar);
        printf("Case %d:\n", cases++);
        for(i = 1; i <= n; i++)
            printf("%d\n", val[ind[i]]);
    }




    return 0;
}
/*



1
3
abac
ab
ab
ac


1
5
ababacbabc
aba
ba
ba
a
abc



*/
