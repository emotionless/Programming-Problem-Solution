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

#define LL long long
#define MX 100009        // 10^5 + 9
#define MOD 1000000007   // 10^9 + 7
#define PB push_back
#define set_mask(a,b) (a|(1<<b))
#define check_mask(a,b) (a&(1<<b))
#define FOR(i, b) for(i = 0; i < b; i++)

using namespace std;

int in[MX];
int out[MX];
int cnt;
int tot;
vector<int>V[MX];
bool vis[MX];
void DFS(int src)
{
    if(vis[src]) return;
    vis[src] = 1;
    tot++;
    if(out[src] == 0)
        cnt++;
    for(int i = 0; i < V[src].size(); i++)
    {
        DFS(V[src][i]);
    }
}



int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int u, v;
        for(i = 1; i < n; i++)
        {
            cin>>u>>v;
            V[u].PB(v);
            V[v].PB(u);
            out[u]++;
        }
        int res = 0;

        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                cnt = 0;
                tot = 0;
                DFS(i);
                if(cnt == tot)
                    res+=cnt;
                else
                    res+= cnt + 1;
            }
        }
        cout<<res<<endl;
        memset(out, 0, sizeof out);
        for(i = 1; i <= n; i++)
            V[i].clear();
        memset(vis, 0, sizeof vis);

    }


    return 0;
}

/*



*/
