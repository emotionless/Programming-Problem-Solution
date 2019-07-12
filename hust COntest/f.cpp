#include<bits/stdc++.h>

#define LL long long
#define pb push_back
#define MOD 1000000007
#define MX 1000

using namespace std;
vector<int>V[MX+10];
int indx;
int t[MX+10];

int cost[1010][1010];
int parent[1010];
bool act[1010];


bool bpm(int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int i = 0; i < V[u].size(); i++)
    {
        int v=V[u][i];
        if (!seen[v])
        {
            seen[v] = true; // Mark v as visited

            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in the above line, matchR[v]
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int dir[MX+10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    indx=1;
    bool say=true;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i]>>dir[i];
    }
    for(int i=1; i<=n; i++)
    {
        if(dir[i]==1)
        {
            // V[0].pb(i);
            for(int j=i-1; j>=1; j--)
            {
                if(dir[j]==0)
                {
                    if(t[i]<=t[j]+b)V[i].pb(j);
                    if(t[i]>=t[j]+a) V[i].pb(j);
                }
            }
        }
        //else V[i].pb(n+1);
    }
    int res=0;
    int matchR[n+5];
    memset(matchR, -1, sizeof(matchR));
    for (int u = 0; u <=n; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[n+5];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant 'u' can get a job
        if (bpm(u, seen, matchR))
        {
            res++;
        }
    }


    if(res==n/2)
    {
        cout<<"No reason"<<endl;
        for(int i=1; i<=n; i++)
        {
            if(matchR[i]!=-1)
                cout<<t[i]<<" "<<t[matchR[i]]<<endl;
        }
    }
    else
        cout<<"Liar"<<endl;

    return 0;
}
