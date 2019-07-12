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

bool mat[101][101];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a>>b;
        mat[a][b]=true;
    }
    int cnt1=0, cnt2=0;
    bool is=false;
    for(i=0; i<101; i++)
    {
        for(j=0; j<101; j++)
        {
            if(mat[i][j])
            {
                is=true;
            }
        }
        if(is)
            cnt1++;
        is=false;
    }
    is=false;

    for(j=0; j<101; j++)
    {
        for(i=0; i<101; i++)
        {
            if(mat[i][j])
            {
                is=true;
            }
        }
        if(is)
            cnt2++;
        is=false;
    }
    memset(mat, false, sizeof mat);
    cout<<min(cnt1, cnt2);





    return 0;
}

/*

4544545454

*/
