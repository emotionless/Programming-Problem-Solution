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
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;

vector<int>V[105];

bool BPM(int u, bool seen[], int match[])
{
    if(u==-1) return true;
    int sz=V[u].size();
    for(int i=0; i<sz; i++)
    {
        int v=V[u][i];
        seen[u]=true;
        if(!seen[v])
        {
            seen[v]=true;
            if(match[v]<0 || BPM(match[v], seen, match))
            {
                match[v]=u;
                match[u]=v;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;

    int t, u, v;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;

        for(i=0; i<105; i++)
            V[i].clear();

        for(i=0; i<m; i++)
        {
            cin>>u>>v;
            if(u!=v)
            {
                V[u].PB(v);
                V[v].PB(u);
            }
        }
        if(n%2)
        {
            cout<<"NO"<<endl;
            continue;
        }

        int match[n+5];

        memset(match, -1, sizeof match);
        for(i=1; i<=n; i++)
        {
            bool seen[n+5];
            memset(seen, false, sizeof seen);

            if(match[i]==-1)
            {
                BPM(i, seen, match);
            }
        }

        for(i=1; i<=n; i++)
        {
            if(match[i]==-1)
            {
                cout<<"NO"<<endl;
                break;
            }
        }
        if(i==n+1)
            cout<<"YES"<<endl;
    }
    return 0;
}

/*

1
4 5
1 2
2 3
1 3
2 4
3 4

*/
