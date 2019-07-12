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
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b, n;
    cin>>n;
    int cnt=0;
    bool vis[n+1][n+1];
    memset(vis, false, sizeof vis);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(!vis[i][j])
            {
                cnt++;
                vis[i+1][j]=true;
                vis[i-1][j]=true;
                vis[i][j+1]=true;
                vis[i][j-1]=true;
            }
        }
    }
    cout<<cnt<<endl;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(!vis[i][j])cout<<"C";
            else
                cout<<".";
        }
        cout<<endl;
    }



    return 0;
}

/*

4544545454

*/
