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

struct Z
{
    int x, y;
    Z() {}
    Z(int a, int b)
    {
        x=a;
        y=b;
    }
};

int arr[1001][101];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j, k;
    int a,b;
    int n, m, op;
    cin>>n>>m>>op;

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            cin>>arr[i][j];
    vector<Z>res;
    if(op==0)
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                int mn=arr[i][j];
                int mn_pos=j;
                for(k=j; k<m; k++)
                {
                    if(arr[i][k]<mn)
                    {
                        mn=arr[i][k];
                        mn_pos=k;
                    }
                }
                if(mn_pos!=j)
                {
                    res.PB(Z(j, mn_pos));
                    for(int l=i; l<n; l++)
                    {
                        if(arr[l][j]>arr[l][mn_pos])
                            swap(arr[l][j], arr[l][mn_pos]);
                    }
                }
            }
        }
    }
    else
    {
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                int mx=arr[i][j];
                int mx_pos=j;
                for(k=j; k<m; k++)
                {
                    if(arr[i][k]>mx)
                    {
                        mx=arr[i][k];
                        mx_pos=k;
                    }
                }
                if(mx_pos!=j)
                {
                    res.PB(Z(mx_pos, j));
                    for(int l=i; l<n; l++)
                    {
                        if(arr[l][j]<arr[l][mx_pos])
                            swap(arr[l][j], arr[l][mx_pos]);
                    }
                }
            }
        }
    }
    cout<<res.size()<<endl;
    for(i=0; i<res.size(); i++)
        cout<<res[i].x+1<<" "<<res[i].y+1<<endl;


    return 0;
}

/*

4544545454

*/
