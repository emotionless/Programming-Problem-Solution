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

vector<int>V;
int mat[1001][1001];
bool vis[1001][1001];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    while(cin>>n)
    {

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                cin>>mat[i][j];
        }
        memset(vis, false, sizeof vis);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(vis[i][j]) continue;

                if(mat[i][j]==0) continue;
                int cnt=0;
                for(k=j+1; k<=n; k++)
                {
                    if(mat[i][k]==mat[i][j])
                        cnt++;
                    else
                        break;
                }
                V.PB(mat[i][j]);
                V.PB(i);
                V.PB(i);
                V.PB(j);
                V.PB(j+cnt);
                for(k=j; k<=j+cnt; k++)
                    vis[i][k]=true;
            }
        }
        int sz=V.size();
        int res=sz/5;

        cout<<res<<endl;
        if(res)
        {
            for(i=0; i<sz; i+=5)
                cout<<V[i]<<" "<<V[i+1]<<" "<<V[i+2]<<" "<<V[i+3]<<" "<<V[i+4]<<endl;
        }
        memset(mat, 0, sizeof mat);
        V.clear();
    }
    return 0;
}

/*

5
0 0 0 0 0
0 1 1 2 0
0 1 1 2 0
0 1 1 2 0
0 0 0 0 0

*/
