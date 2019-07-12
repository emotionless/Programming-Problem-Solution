#include<bits/stdc++.h>
#define LL long long
#define PB push_back


using namespace std;

bool vis[1010];
int par[1010];
vector<int>V[1010];
int n;

bool bpm(int x)
{
    if(x<0) return false;
    int sz=V[x].size();

    for(int i=0; i<sz; i++)
    {
        int a=V[x][i];
        if(!vis[a])
        {
            vis[a]=true;
            if(par[a]==-1 || bpm(par[a]))
            {
                par[a]=x;
                // cout<<x<<" "<<a<<endl;
                return true;
            }

        }


    }
    return false;
}

int main()
{
    int i,j,k;
    int m,t,a,b, cases=1;

    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(i=0; i<m; i++)
        {
            cin>>a>>b;
            V[a].PB(b);
            V[b].PB(a);
        }
        int cnt=0;
        memset(par, -1, sizeof par);
        for(i=1; i<=n; i++)
        {
            memset(vis, false, sizeof vis);

            if(bpm(i)){
                cnt++;
            //    cout<<i<<" "<<cnt<<endl;
            }
        }
        cout<<"Case "<<cases++<<": "<<n-cnt/2<<endl;
        for(i=0; i<=n; i++)
        V[i].clear();
    }




    return 0;
}

/*

1

6 5
1 2
2 3
3 4
3 6
2 5

*/
