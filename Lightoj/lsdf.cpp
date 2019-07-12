/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad written code **********
*/


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
#define PB push_back
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
#define sc1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)


#define MOD 1000000007
#define MAX 209

using namespace std;
vector<int>V[MAX];
//vector<int>vec[MAX];
bool vis[MAX];
int arr[3000009];

bool mat[209][209];

void DFS(int cn, int u)
{
    if(vis[u]) return;
    vis[u] = true;
    mat[cn][u] = 1;
//    vec[cn].pb(u);
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        if(!vis[V[u][i]])
            DFS(cn, V[u][i]);
    }
    return;
}

int dp[300009][209];
int N;
int  K, M;

int solve(int ind, int pre)
{
    if(ind >= N)
        return 0;
    int &ret = dp[ind][pre];
    if(ret != -1) return ret;
    ret = 10000000;
    for(int i = pre; i <= M; i++)
    if(mat[arr[ind]][i]){
        ret = min(ret, (arr[ind]!=i) + solve(ind + 1, i));
        if(arr[ind] < i)
            break;
    }
    return ret;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");
    int i,j;
    int t;
    int a, b;


    sc1(t);
    while(t--)
    {

        scanf("%d %d %d", &M, &K, &N);
        for(i = 0; i < K; i++)
        {
            scanf("%d %d", &a, &b);
            V[a].PB(b);
            V[b].PB(a);
        }

        for(i = 1; i <= M; i++)
        {
            clr(vis, false);
            DFS(i, i);
//            UNIQUE(vec[i]);
        }

        for(i = 0; i < N; i++)
            sc1(arr[i]);
        memset(dp, -1, sizeof dp);
        int res = solve(0, 0);
        if(res < 10000000)
            printf("%d\n", res);
        else
            printf("-1\n");
        for(i = 1; i <= M; i++)
            V[i].clear();
        clr(mat, false);
    }
    return 0;
}

/*

4
-1 -2 2 1
4
-1 -1 1 1


6
1 2 -3 -4 3 4

*/
