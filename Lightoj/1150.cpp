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
#define MX 30
#define mp make_pair

using namespace std;

bool vis[MX * MX];
vector<int>V[MX * MX];
int par[MX * MX];
int n,m;

int lft[30][30];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

string mat[30];

vector<int>store;


bool DFS(int u)
{
    int i, j, k;
    for(i = 0; i < V[u].size(); i++)
    {
        int v = V[u][i];
        if(vis[v]) continue;
        vis[v] = true;
        if(par[v] == -1 || DFS(par[v]))
        {
            par[v] = u;
            return true;
        }
    }
    return false;
}

int getID(int i, int j)
{
    return n * (i) + j;
}
int BPM()
{
    int cnt = 0;
    int i, j, k;
    memset(par, -1, sizeof par);
    int sz = store.size();
    for(i = 0; i < sz; i+=2)
    {
        memset(vis, false, sizeof vis);
        if(DFS(getID(store[i], store[i + 1])))
            cnt++;
    }
    return cnt;
}


struct Z
{
    int x, y, c;
};

bool visited[MX][MX];
void BFS(int x, int y, int lim)
{
    queue<Z>Q;
    Z tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.c = 0;
    Q.push(tmp);
    memset(visited, false,sizeof visited);

    while(!Q.empty())
    {
        Z top = Q.front();
        Q.pop();
        int cx = top.x;
        int cy = top.y;
        int cc = top.c;

        if(visited[cx][cy]) continue;
        visited[cx][cy] = true;
        if(cc > lim) return;

        if(mat[cx][cy] == 'G')
        {
            V[getID(x, y)].PB(getID(cx, cy));
            //cout<<x<<" "<<y<<" "<<getID(x, y)<<" "<<getID(cx, cy)<<endl;
        }

        for(int i = 0; i < 4; i++)
        {
            int adjx = cx + dr[i];
            int adjy = cy + dc[i];
            if(adjx < 0 || adjx >= n || adjy < 0 || adjy >= n || visited[adjx][adjy] || mat[adjx][adjy] == '#') continue;

            tmp.x = adjx;
            tmp.y = adjy;
            tmp.c = cc + 1;
            Q.push(tmp);
        }
    }
    //  cin.get();

    return;
}





int tot;

bool solve(int lim)
{

    for(int i = 0; i <= n * n; i++)
        V[i].clear();

    int sz = store.size();

    for(int i = 0; i < sz; i+=2)
    {
            //if(mat[i][j] == 'H')
            {
                //cout<<i<<" "<<j<<endl;
                BFS(store[i], store[i + 1], lim);
            }
    }
    int ret = BPM();
//    cout<<lim<<" "<<ret<<endl;
    return ret == tot;
}





int BS()
{
    int st = 0, ed = 2500, mid;
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
    cin>>t;
    while(t--)
    {
        cin>>n;
        store.clear();
        for(int i = 0; i < n; i++)
            cin>>mat[i];
        tot = 0;
        for(int i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(mat[i][j] == 'H'){
                    tot++;
                    store.PB(i);
                    store.PB(j);
                }
            }
        }
        int ans = BS();
        printf("Case %d: ", cases++);
        if(ans == 2500)
            cout<<"Vuter Dol Kupokat"<<endl;
        else
            cout<< ans * 2 + 2 << endl;
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
