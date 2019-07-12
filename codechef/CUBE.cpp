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
#define PB push_back


using namespace std;

struct Z
{
    int x,y,z;
    Z() {}
    Z(int a, int b, int c)
    {
        x=a;
        y=b;
        z=c;
    }
};


int dp[42][42][42];
vector<Z>V;

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int N;
    double P;
    string cak1, cak2;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>N>>P;
        cin>>cak1;
        cin>>cak2;
        char mat1[N+2][N+2][N+2];
        char mat2[N+2][N+2][N+2];
        int l=0;
        for(i=1; i<=N; i++)
        {
            for(j=1; j<=N; j++)
            {
                for(k=1; k<=N; k++)
                {
                    mat1[j][k][i]=cak1[l];
                    mat2[j][k][i]=cak2[l];
                    l++;
                    //     cout<<i<<" "<<j<<" "<<k<<" "<<mat1[i][j][k]<<" "<<mat2[i][j][k]<<endl;
                }
            }
        }
        int temp[45][45];
        memset(dp, 0, sizeof dp);
        for(k=1; k<=N; k++)
        {
            memset(temp, 0, sizeof temp);
            for(i=1; i<=N; i++)
            {
                for(j=1; j<=N; j++)
                {
                    temp[i][j]=temp[i-1][j]+temp[i][j-1]-temp[i-1][j-1]+(mat1[i][j][k]==mat2[i][j][k]?1:0);
                    dp[i][j][k]=dp[i][j][k-1]+temp[i][j];

                    // cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
                    //  cout<<dp[i][j][k-1]<<" "<<temp[i][j]<<" "<<mat1[i][j][k]<<" "<<mat2[i][j][k]<<endl;
                }
            }
        }
        int len=N;
        for(len=N-1; len>=0; len--)
        {
            for(k=1; k+len<=N; k++)
            {
                for(i=1; i+len<=N; i++)
                {
                    for(j=1; j+len<=N; j++)
                    {
                        int res=dp[i+len][j+len][k+len]-dp[i+len][j-1][k+len]-dp[i-1][j+len][k+len]+dp[i+len-1][j-len-1][k+len]-dp[i+len][j+len][k-1]+dp[i-1][j+len][k-1]+dp[i+len][j-1][k-1]-dp[i-1][j-1][k-1];
                        //   cout<<i<<" "<<j<<" "<<k<<" "<<len<<" "<<res<<endl;
                        double per=(double)(res*100.0)/(double)((len+1)*(len+1)*(len+1));
                        if(per>=P)
                        {
                            V.PB(Z(i,j,k));
                        }
                    }
                }
            }

            if(V.size())
            {
                break;
            }
        }
        if(len<0)
        {
            cout<<-1<<endl;
            continue;
        }
        int sz=V.size();
        int a=V[0].x;
        int b=V[0].y;
        int c=V[0].z;
        int res=1;
      //  cout<<len<<" "<<sz<<endl;
    //    cout<<V[0].x<<" "<<V[0].y<<" "<<V[0].z<<endl;
     //   cout<<V[1].x<<" "<<V[1].y<<" "<<V[1].z<<endl;
        for(i=1; i<sz; i++)
        {
            if(abs(V[i].x-a)>len || abs(V[i].y-b)>len || abs(V[i].z-c)>len)
            {
                res++;
                a=V[i].x;
                b=V[i].y;
                c=V[i].z;
            }
        }
        cout<<len+1<<" "<<res<<endl;
        V.clear();

    }

    return 0;
}

/*

2 40
abcdefgh
abcdefgh

*/
