#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define mp make_pair
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define MOD 1000000007
#define MX 100009
#define set_mask(aa, bb) (aa|(1<<bb))
#define check_mask(aa, bb) (aa&(1<<bb))
#define off_mask(aa, bb) (aa & ~(1<<bb))

using namespace std;

int dp[16][16];
int deg[16];
int n;
void init()
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dp[i][k] != INT_MAX && dp[k][j] != INT_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
}

int mem[1<<17];

int solve(int mask)
{
    if(mask == 0) return 0;
    int &ret = mem[mask];
    if(ret != -1) return ret;
    ret = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(check_mask(mask, i) && check_mask(mask, j) && i!=j)
            {
                int tmp = mask;
                tmp = off_mask(tmp, i);
                tmp = off_mask(tmp, j);
                ret = min(ret, dp[i][j] + solve(tmp));
            }
        }
    }
    return ret;
}


int main()
{

    int i, j, k;
    int t, cases = 1;
    int m, u, v, w;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int sum = 0;
        for(i = 0; i < 16; i++)
            for(j = 0; j < 16; j++)
                dp[i][j] = INT_MAX, deg[i] = 0;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v>>w;
            u--;
            v--;
            sum += w;
            dp[u][v] = dp[v][u] = min(dp[u][v], w);
            deg[u]++;
            deg[v]++;
        }

        init();
        int mask = 0;

        for(i = 0; i < n; i++)
        {
            if(deg[i]&1)
                mask = set_mask(mask, i);
        }
        memset(mem, -1, sizeof mem);
        int res = solve(mask);
        printf("Case %d: %d\n", cases++, res + sum);
    }




    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
