#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MOD 1000000007
#define MX 50009

using namespace std;

int val[MX+10];
bool isStack[MX+10];
int Stack[MX+10];
int ind[MX+10];
int low[MX+10];
int to[MX+10];
int id, top;
int scc;
int mn_num[MX+10];

vector<int>V[MX];
vector<int>SCC[MX];

int tarjan(int u)
{
    ind[u] = low[u] = (id++);
    isStack[u] = 1;
    Stack[top++] = u;
    int v;
    int sz = V[u].size();
    for(int i = 0; i < sz; i++)
    {
        v = V[u][i];
        if(ind[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(isStack[v])
            low[u] = min(low[u], ind[v]);
    }

    if(ind[u] == low[u])
    {
        int cnt = 0;
        int mn = MX;
        // cout<<endl<<scc<<endl;
        do
        {
            v = Stack[--top];
            to[v] = scc;
            isStack[v] = 0;
            cnt++;
            SCC[scc].PB(v);
            mn = min(mn, v);
        }
        while(u != v);
        val[scc] = cnt;
        mn_num[scc] = mn;
        scc++;
    }
}

int dp[MX+10];
int DFS(int src)
{
    int &ret = dp[src];
    if(ret != -1) return ret;
    ret = val[src];
    for(int i = 0; i < SCC[src].size(); i++)
    {
        int u = SCC[src][i];
        for(int j = 0; j < V[u].size(); j++)
        {
            int v = V[u][j];
            if(to[u] != to[v])
                ret += DFS(to[v]);
        }
    }
    return ret;
}


int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n;
        int u, v;
        id = top = scc = 0;
        for(i = 0; i < n; i++)
        {
            cin>>u>>v;
            V[u].PB(v);
        }
        clr(ind, -1);
        for(i = 1; i <= n; i++)
        {
            if(ind[i] == -1 && V[i].size())
            {
                tarjan(i);
            }
        }
        int ans = 0, pos = MX;
        clr(dp, -1);
        for(i = 0; i < scc; i++)
        {
            int get = DFS(i);
            if(get > ans)
            {
                ans = get;
                pos = mn_num[i];
            }
            else if(get == ans)
                pos = min(pos, mn_num[i]);
        }
        //cout<<scc<<endl;
        printf("Case %d: %d\n", cases++, pos);

        // clear session is here
        for(i = 0; i < MX; i++)
        {
            V[i].clear();
            SCC[i].clear();
            to[i] = 0;
            mn_num[i] = MX ;
            isStack[i] = false;
            val[i] = 0;
        }
    }

    return 0;
}

/*

1
5
1 2
2 1
4 3
3 2
4 1

*/
