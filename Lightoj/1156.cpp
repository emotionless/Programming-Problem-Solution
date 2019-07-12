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
#define MX 209
#define MX1 209
#define mp make_pair
#define INF 1000000

using namespace std;
char c1[MX],c2;
int n, m;
LL dis[MX];
double d;


int f, st;
LL cost[MX][MX];
int par[MX];
bool mat[MX][MX];



void augment(int v, LL mn)
{
    //cout<<v<<" "<<mn<<endl;
    if(v == st) f = mn;
    else if (par[v] != -1)
    {
        int u = par[v];
        augment(u, min(mn, cost[u][v]));
        cost[u][v] -= f, cost[v][u] += f;
    }
}

vector<int>adj[MX];

int maxFlow(int lim)
{
    int i, j, k;
    //cout<<"For limit: ";
    //cout<<lim<<endl;
    clr(cost, 0);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(mat[i][j] && abs(dis[j] - dis[i]) <= lim)
            {
                cost[i + n][j] = INF;

                //cout<<i + n<<" "<<j<<" "<<INF<<endl;
            }
        }
        cost[i][i + n] = (c1[i] == 'B'?2:1);
        //cout<<i<<" "<<i + n<<" "<<cost[i][i + n]<<endl;
    }


    int tot = 0;
    while(true)
    {
        f = 0;
        for(int i = 1; i <= MX1; i++) par[i] = -1;
        par[st] = 0;
        queue<int>Q;
        Q.push(st);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            if(u == n + n - 1) break;
            //cout<<endl<<u<<" dukay : ";
            for(int i = 0; i < adj[u].size(); i++)
            {
                int v = adj[u][i];
                //cout<<v<<" "<<cost[u][v]<<" ";
                if(cost[u][v] > 0 && par[v] == -1)
                {
                    //cout<<v<<" ";
                    Q.push(v);
                    par[v] = u;
                    //cout<<v<<" "<<par[v]<<endl;
                }
                //cout<<endl;
            }
        }
        f = 0;
        augment(n + n - 1, INF);
        //cout<<f<<endl;
        //cout<<"ths is cost: "<<f<<endl;
        if(f == 0) break;
        tot += f;
    }
    // cin>>i;
    if(tot >= 2)
        return true;
    return false;
}



LL solve()
{
    LL st = 0, ed = d, mid, ans = d;
    while(st <= ed)
    {
        mid = (st + ed) / 2;
        if(maxFlow(mid))
        {
            ans = min(ans, mid);
            ed = mid - 1;
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
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        c1[0] = 'B';
        dis[0] = 0;
        clr(mat, false);
        for(i = 1; i <= n; i++)
        {
            cin>>c1[i]>>c2>>dis[i];
        }
        c1[n + 1] = 'B';
        dis[n + 1] = d;
        st = 0;
        n++;
        n++;
        for(i = 0; i < n; i++)
        {
            adj[i].PB(i + n);
            adj[i + n].PB(i);

            for(j = i + 1; j < n; j++)
            {
                adj[i + n].PB(j);
                adj[j].PB(i + n);
                adj[i].PB(j + n);
                adj[j + n].PB(i);
                mat[i][j] = mat[j][i] = true;
                //if(c1[j] == 'B') break;
            }
        }
        LL res = solve();
        printf("Case %d: %lld\n", cases++, res);
    }
    return 0;
}

/*

2 10
B-3 S-6

*/
