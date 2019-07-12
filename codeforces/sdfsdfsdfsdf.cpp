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

#define WRITE freopen("C:\\Users\\back_bencher\\Desktop\\output.txt","w",stdout)
#define use_cin  ios_base::sync_with_stdio(0); cin.tie(0);
#define READ  freopen("C:\\Users\\back_bencher\\Desktop\\input.txt","r",stdin)

///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)
#define eps 1e-9
#define deb cout<<"I am here"<<endl
#define MOD 1000000007
#define MAX (lim+7)
#define INF 2000000000

using namespace std;


#define MX 1000000000000000000ll
#define lim 100000      /// 10^6

///***** Template ends here *****///
///********************* Code starts here ****************************

vector<int>V[MAX];
vector<int>C[MAX];
vector<int>G[MAX];
vector<int>CC[MAX];

bool visited[MAX];
pii level[MAX];

pii DFS(int u, int pre)
{
    if(visited[u]) return level[u];

    visited[u] = 1;

    int sz = V[u].size();
    int mx = 0;
    int cc = 0, c = 0;
    for(int i = 0; i < sz; i++)
    {
        if(V[u][i] == pre) continue;
        G[u].pb( V[u][i] );
        CC[u].pb( C[u][i] );
        pii p = DFS(V[u][i], u);
        p.yy += C[u][i];
        if(p.xx > cc)
        {
            cc = p.xx;
            c = p.yy;
        }
        else if(p.xx == cc)
        {
            c = max(c, p.yy);
        }
    }
    level[u].xx = cc + 1;
    level[u].yy = c;
//    cout<<u<<" "<<cc+1<<" "<<c<<endl;
    return level[u];
}

double mid;
int mn;
int tot;
void FOUL(int cn, int till, int cst)
{
//    cout<<cn<<" "<<till<<" "<<cst<<endl;

    int lvl = level[cn].xx;
    if(lvl < till) return;
    if(lvl*2 - 1 > tot)
    {
        mn = min(mn, level[cn].yy);
    }
    else if(lvl*2 - 1 < tot)
    {
        mn = min(mn, cst);
    }
    else
    {
        mn = min(mn, max(cst, level[cn].yy) );
    }
//    cout<<mn<<endl;
    int sz = G[cn].size();
    for(int i = 0; i < sz; i++)
    {
        FOUL(G[cn][i], till, cst + CC[cn][i]);
    }
    return;
}


int main()
{
    int n, e, i, u, v, t, w, j;
    scanf("%d", &t);
    while(t--)
    {
        s1(n);
        mn = 0;
        for(i = 0; i <= n; i++)
        {
            V[i].clear();
            G[i].clear();
            C[i].clear();
            CC[i].clear();
            level[i].xx=level[i].yy = 0;
            visited[i] = 0;

        }

        for(i = 1; i < n; i++)
        {
            s3(u, v, w);
            V[u].pb(v);
            C[u].pb(w);
            V[v].pb(u);
            C[v].pb(w);
        }

        DFS(1, -1);
        /// leveling ok.... :-)

        for(i = 1; i <= n; i++)
        {
            mn = INF;
            int sz = G[i].size();
//            cout<<endl<<i<<" ";
            int take1 = 0, take2 = 0, f = 0, s = 0;
            for(j = 0 ; j < sz; j++)
            {
                v = G[i][j];
                int tmp = CC[i][j];
//                cout<<v<<" ";
                int l = level[v].xx;
                if(l  == f)
                {
                    s = l;
                    take2 = level[v].yy+tmp;
                }
                else if(l > f)
                {
                    s = f;
                    take2 = take1;
                    f = l;
                    take1 = level[v].yy+tmp;
                }
                else if(l > s)
                {
                    s = l;
                    take2 = level[v].yy+tmp;
                }
            }
//            cout<<endl<<" "<<f<<" "<<s<<" "<<take1<<" "<<take2<<endl;

            for(j = 0; j < sz; j++)
            {
                v = G[i][j];
                if( level[v].xx == f)
                {
                    tot = f + s + 1;
                    mid = (double)(f + s + 2.0)/2.0;
                    int age = take2;
//                    cout<<v<<" "<<mid<<" "<<age<<endl;
//                    cin.get();
                    FOUL(v, tot - mid - 1, age+CC[i][j]);
                }
                else
                {
                    tot = f + level[v].xx + 1;
                    mid = (double)(f + level[v].xx +2.0)/2.0;
                    int age = take1;
                    FOUL(v, tot - mid - 1, age + CC[i][j]);
                    FOUL(i, tot - mid - 1, age);
                }
            }
            if(mn == INF)
                printf("0\n");
            else
                printf("%d\n", mn);
        }
    }


    return 0;
}
/*
6 7
1 2
2 3
3 1
2 4
4 5
5 6
6 4

4 4
1 2
1 3
2 3
1 4






4 3
2 1
1 3
4 3

*/
