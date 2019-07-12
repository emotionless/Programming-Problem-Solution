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
#define MX 50009
#define mp make_pair

using namespace std;

int cost[MX];
bool vis[MX];
bool visited[MX];
vector<int>V[MX];
void BFS(int st, int ed)
{
    queue<int>Q;
    memset(vis, false, sizeof vis);
    memset(visited, false, sizeof visited);
    int dist[MX];
    memset(dist, -1, sizeof dist);
    Q.push(ed);
    dist[ed] = 0;

    while(!Q.empty())
    {
        int top = Q.front();
        Q.pop();
        if(top == st) break;
        if(vis[top]) continue;
        vis[top] = true;
        int sz = V[top].size();
        for(int i = 0; i < sz; i++)
        {
            int adjn = V[top][i];
            if(vis[adjn]) continue;
            if(dist[adjn] < 0)
            dist[adjn] = dist[top] + 1;
            Q.push(adjn);
        }
    }
    vector<int>res;
    res.clear();
    res.PB(st);
    while(st != ed)
    {
        int d = 100000;
        int next = 100000;
        int i;
        vis[st] = true;
        for(i = 0; i < V[st].size(); i++)
        {
            int ad = V[st][i];
            if(visited[ad]) continue;
            if(dist[ad] < 0) continue;
            visited[ad] = true;

            if(dist[ad] < d)
            {
                d = dist[ad];
                next = ad;
            }
            else if(dist[ad] == d)
                next = min(next, ad);
        }
        st = next;
        res.PB(st);
    }
    int sz = res.size();
    cout<<res[0];
    for(int i = 1; i < sz; i++)
    {
        cout<<" "<<res[i];
    }
    cout<<endl;


}
int arr[MX];

int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            cin>>arr[i];
        for(i = 0; i < n - 1; i++)
        {
            V[arr[i]].PB(arr[i+1]);
            V[arr[i+1]].PB(arr[i]);
        }
        int st = arr[0];
        int ed = arr[n - 1];
        printf("Case %d:\n", cases++);
        BFS(st, ed);
        for(i = 0; i < MX; i++)
        {
            V[i].clear();
            vis[i] = visited[i] = arr[i] = 0;
        }
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
