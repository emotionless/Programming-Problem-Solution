#include <bits/stdc++.h>

#define LL long long
#define MAX 109
#define MD 1000000007
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)
#define pii pair<int, int>
#define pll pair<LL, LL>
#define xx first
#define yy second

#define mp make_pair


using namespace std;

vector<int>V[109];
bool vis[109];

vector<int>vec;

void DFS(int u)
{
    if(vis[u]) return;
    vis[u] = 1;
    vec.PB(u);
    for(int i = 0; i < V[u].size(); i++)
    {
        if(!vis[V[u][i]])
            DFS(V[u][i]);
    }
    return;
}

int val[109];
int nn;
int dp[109][10000];
int solve(int ind, int sum)
{
    if(ind >= nn) return sum;
    int &ret = dp[ind][sum];
    if(ret != -1) return ret;
    ret = 0;
    ret = solve(ind + 1, sum);
    ret = max(ret, solve(ind + 1, sum ^ val[vec[ind]]));
return ret;
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int m;
    int n, t;
    string str;
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        cin>>str;
        for(j = 0; j < n; j++){
            if(str[j] == 'Y')
            V[i].PB(j);
        }
    }
    for(i = 0; i < n; i++)
        cin>>val[i];
    int mx = 0;
    for(i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            vec.clear();
            DFS(i);
            memset(dp, -1, sizeof dp);
            nn = vec.size();
            mx = max(mx, solve(0, 0));
        }
    }
    cout<<mx<<endl;








    return 0;
}

/*

5
NNNNN
NNNNN
NNNNN
NNNNN
NNNNN
0 4 8 32 512


*/
