#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second

///***** Constant ******//
#define MAXN 1007      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
#define N 100007        // 10^5 + 7
#define MAXLOGN (int)(log(MAXN))


using namespace std;

LL gcd(LL a,LL b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

LL bigmod(LL p,LL e,LL M)
{
    if(e==0)return 1;
    if(e%2==0)
    {
        LL t=bigmod(p,e/2,M);
        return (t*t)%M;
    }
    return (bigmod(p,e-1,M)*p)%M;
}

LL modinverse(LL a,LL M)
{
    return bigmod(a,M-2,M);
}


/*


bool is_prime[MAX];
L prime[MAX];

bool sieve()
{
    long i,j;
    prime[0]=2;
    int k=1;
    int sq=(sqrt(MAX));
    for(i=3; i<=sq; i+=2)
    {
        if(!is_prime[i])
        {
            for(j=i*i; j<=MAX; j+=(2*i))
                is_prime[j]=1;
        }
    }
    for(j=3; j<=MAX; j+=2)
    {
        if(!is_prime[j])
        {
            prime[k++]=j;
        }
    }
}


long NOD(long n)
{
    int  i,j,k;
    long sq=sqrt(n);
    long res=1;
    for(i=0; prime[i]<=sq; i++)
    {
        int cnt=1;
        if(n%prime[i]==0)
        {
            while(n%prime[i]==0)
            {
                cnt++;
                n=n/prime[i];
                if(n==1) break;
            }
            res*=cnt;
            sq=sqrt(n);
        }
    }
    if(n>1) res*=2;
    return res;
}
*/

vector< int > adj[MAXN+1];

int n;
char flag[MAXN+1];
int root;
int L[MAXN+1];
int in[MAXN+1];
int father[MAXN+1];
int A[MAXN+1][100+1];
LL INF = 10000000;

void dfs(int cur)
{
    flag[cur] = true;
    int i;
    for(int i = 0; i < adj[cur].size(); i++)
    {
        if(!flag[adj[cur][i]])
        {
            father[adj[cur][i]] = cur;
            L[adj[cur][i]] = L[cur] + 1;
            dfs(adj[cur][i]);
        }
    }
}

void pre_process()
{
    int i,j;
    for(i = 1; i <= n; i++)
        for(j = 0; (1<<j) <= n; j++)
            A[i][j] = -1;
    for(i = 1; i <= n; i++)
        A[i][0] = father[i];
    for(j = 1; (1<<j) <= n; j++)
        for(i = 1; i <= n; i++)
            if(A[i][j-1] != -1)
                A[i][j] = A[A[i][j-1]][j-1];
}


int getLCA(int p, int q)
{
    int i,log;
    if(L[p] < L[q]) swap(p,q);
    for(log=1; (1<<log)<=L[p]; log++);
    log--;
    for(i=log; i>=0; i--)
        if(L[p] - (1<<i) >= L[q])
            p = A[p][i];
    if(p == q) return p;
    for(i=log; i>=0; i--)
    {
        if(A[p][i] != -1 && A[p][i] != A[q][i])
        {
            p = A[p][i];
            q = A[q][i];
        }
    }
    return father[p];
}


int main()
{
    int i,j,k;
    int cases=1;
    int t;
    int a, b;

    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(i = 1; i <= n; i++) adj[i].clear(), flag[i] = false;
        int m;
        for(i = 1; i <= n; i++)
        {
            cin>>m;
            while(m--)
            {
                int v;
                cin>>v;
                in[v]++;
                adj[v].PB(i);
                adj[i].PB(v);
            }
        }

        for(i = 1; i <= n; i++)
        {
            if(in[i] == 0) root = i;
            break;
        }
        father[root] = -1;
        L[root] = 0;
        dfs(root);

        pre_process();

        // query is here
        int q;
        cin>>q;
        int u;
        printf("Case %d:\n", cases++);
        int  v;
        while(q--)
        {
            cin>>u>>v;
            printf("%d\n", getLCA(u, v));
        }

    }
    return 0;
}
/*

2
SQ 1 0
SQ 0 0
SQ 6 0
SQ 5 0



*/
