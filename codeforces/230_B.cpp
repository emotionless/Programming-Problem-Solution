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
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;
int arr[180][180];
double A[180][180];
double B[180][180];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g;
    cin>>n;

    FOR(i,n)
    {
        FOR(j,n)
        cin>>arr[i][j];
    }

    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            int cn=arr[i][j]+arr[j][i];
            double mid=(double)cn/2.0;

            double dif=abs(arr[i][j]-arr[j][i])/2.0;
            if(mid+dif==arr[i][j])
            {
                A[i][j]=mid;
                B[i][j]=dif;
                A[j][i]=mid;
                B[j][i]=(-dif);
            }
            else
            {
                A[i][j]=mid;
                B[i][j]=(-dif);
                A[j][i]=mid;
                B[j][i]=(dif);
            }
        }
    }
    for(i=0; i<n; i++)
    {
        cout<<A[i][0];
        for(j=1; j<n; j++)
            cout<<" "<<A[i][j];
        cout<<endl;
    }

    for(i=0; i<n; i++)
    {
        cout<<B[i][0];
        for(j=1; j<n; j++)
            cout<<" "<<B[i][j];
        cout<<endl;
    }


    return 0;
}

/*

4544545454

*/
