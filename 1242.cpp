#include<bits/stdc++.h>

#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define pb push_back
#define MP make_pair
#define MOD 1000000007
#define mp make_pair

#define MAX 100001
using namespace std;

int t;
vector<bool>flag[MAX];
vector<int>vec[MAX];


bool vis[MAX];

bool DFS(int u)
{
    int sz = vec[u].size();
    vis[u] = 1;
    for(int i = 0; i < sz; i++)
    {
        int v = vec[u][i];
        if(vis[v] == 1 || flag[u][i]) continue;
        if(v == t || DFS(v))
        {
            flag[u][i] = 1;
            return 1;
        }
    }
    return false;
}



int main()
{

    int i, j, k, u, v;
    int s, cases = 1;
    int p;
    int n, m;
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;

        for(i = 0; i < MAX; i++)
            vec[i].clear(), flag[i].clear();

        while(m--)
        {
            s2(u, v);
            vec[u].pb(v);
            vec[v].pb(u);

            flag[u].pb(0);
            flag[v].pb(0);
        }
        s2(s, t);
        clr(vis, 0);
        bool res = DFS(s);
        printf("Case %d: ", cases++);
        if(res)
        {
            clr(vis, 0);
            if(DFS(s))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
            printf("NO\n");


    }

    return 0;
}

/*

1
1 0
1



*/


/*


*/
