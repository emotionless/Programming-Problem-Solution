#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 1000
#define mp make_pair
#define INF 10000000

using namespace std;
int st, ed;
int par[MX];

vector<int> adj[MX];
int cost[MX][MX];
int mat[MX][MX];
int f, K, n;


int augment(int v, int mn)
{
    //cout<<v<<endl;
    if(v == st) return f = mn;
    else if(par[v] != -1)
    {
        int u = par[v];
        augment(u, min(mn, cost[u][v]));
        cost[u][v] -= f, cost[v][u] += f;
    }
}


bool solve(int lim)
{
    clr(cost, 0);
    int i,j,k;
    // cout<<"\n when: "<<lim<<endl;
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(mat[i][j] > 0 && mat[i][j] <= lim)
            {
                cost[i + n][j] = INF;
                //cout<<i + n <<" "<<j<<" "<<" "<<mat[i][j]<<" "<<INF<<endl;
            }
        }
        if(i == 0)
            cost[i][i + n] = INF;
        else
            cost[i][i + n] = 1;
        //cout<<i<<" "<<i + n<<" "<<1<<endl;
    }

    int ret = 0;

    while(true)
    {
        queue<int>Q;
        Q.push(st);
        for(i = 0; i < MX; i++) par[i] = -1;
        par[st] = 0;
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            int sz = adj[u].size();
            if(u == ed) break;
            //cout<<endl<<u<<" can: "<<endl;

            for(int i = 0; i < sz; i++)
            {
                int v = adj[u][i];
                if(cost[u][v] > 0 && par[v] == -1)
                {
                    par[v] = u;
                    Q.push(v);
                    //cout<<v<<endl;
                }
            }
        }
        f = 0;
        augment(ed, INF);
        if(f == 0)
            break;
        ret += f;
    }
    //cin>>i;
    if(ret >= K) return true;
    return false;
}



int BS()
{
    int st = 0, ed = INF, mid;
    int ans = ed;

    while(st <= ed)
    {
        mid = (st + ed) / 2;

        if(solve(mid))
        {
            ed = mid - 1;
            ans = min(ans, mid);
        }
        else
            st = mid + 1;
    }
    return ans;
}


int main()
{
    int i, j, k;
    int t, cases = 1;


    int m, u, v, w;
    cin>>t;
    while(t--)
    {
        clr(mat, 0);
        clr(cost, 0);
        cin>>n>>m;
        n++;
        st = 0;
        ed = n;
        n++;
        for(i = 0; i < m; i++)
        {
            cin>>u>>v>>w;
            if(u > v) swap(u, v);
            adj[u + n].PB(v);
            adj[v].PB(u + n);
            adj[v + n].PB(u);
            adj[u].PB(v + n);
            mat[u][v] = mat[v][u] = w;
        }
        for(i = 0; i < n; i++)
            adj[i].PB(i + n);

        cin>>K;

        int res = BS();
        printf("Case %d: ", cases++);
        if(res == INF)
            cout<<"no solution"<<endl;
        else
            cout<<res<<endl;

        for(i = 0; i < MX; i++)
        {
            adj[i].clear();
        }
    }
    return 0;
}

/*

4
1
2
0 1 5
1 2 6
1


1
2
0 1 1
1 2 1
1


2
3
0 1 1
2 1 1
1 3 1
1

*/
