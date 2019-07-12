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
#define MAX 1000000+7
#define MOD 1000000000+7
#define N 1000007


using namespace std;



int m[110];
int arr[101][101];


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q;
    int t;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>m[i];
        for(j=1; j<=m[i]; j++)
            cin>>arr[i][j];
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j) continue;
            int cnt=0;
            for(k=1; k<=m[i]; k++)
            {
                for(int x=1; x<=m[j]; x++)
                {
                    if(arr[i][k]==arr[j][x])
                        cnt++;
                }
            }
            if(cnt==m[j])
            {
                cout<<"NO"<<endl;
                break;
            }
        }
        if(j==n+1)
            cout<<"YES"<<endl;

    }



    return 0;
}

/*

5 3
1000 1002 1003 1004 1005
S 0 2
G 0 3
S 0 2

*/
