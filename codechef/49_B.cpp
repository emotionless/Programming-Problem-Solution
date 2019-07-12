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

vector < int >V[MX];
vector<int> tmp;
int arr[MX];
int tar[MX];
bool vis[MX];
bool visited[MX];
vector<int>hudai;

void DFS(int src)
{
    if(vis[src]) return;
    vis[src] = 1;
    for(int i = 0; i < V[src].size(); i++)
    {
        DFS(V[src][i]);
    }
    tmp.PB(src);
}

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int n, a, b;
    string str;
    int m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i = 1; i <= n; i++)
            cin>>arr[i];
        memset(visited, false, sizeof visited);
        memset(vis, false, sizeof vis);
        while(m--)
        {
            cin>>a>>b;
            V[a].PB(b);
            V[b].PB(a);
        }
        int c = 0;
        for(i = 1; i <= n; i++)
        {
            if(!vis[i])
            {
                tmp.clear();
                DFS(i);
                sort(tmp.begin(), tmp.end());
                tmp.erase( unique( tmp.begin(), tmp.end() ), tmp.end() );
                hudai.clear();
                int sz1 = tmp.size();
                for(j = 0; j < sz1; j++)
                    hudai.PB(arr[tmp[j]]);
                sort(hudai.begin(), hudai.end());
                for(j = 0; j < sz1; j++)
                {
                    if(tmp[j] == hudai[j])
                        visited[tmp[j]] = 1;
                    //cout<<tmp[j]<<" "<<hudai[j]<<endl;
                }
            }
        }

        for(i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                if(arr[i] == i) continue;
                //cout<<i<<" "<<tar[i]<<endl;
                cout<<"Impossible"<<endl;
                break;
            }
        }
        if(i == n + 1)
            cout<<"Possible"<<endl;
        for(i = 0; i <= n; i++)
        {
            V[i].clear();
        }
    }




    return 0;
}

/*

7 4
3 1 2 4 7 5 6
1 2
4 4
7 7
2 3

*/
