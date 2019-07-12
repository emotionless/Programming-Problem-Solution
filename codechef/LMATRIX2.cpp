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
#define MOD 1000000007
#define N 1000007
#define PB push_back


using namespace std;

struct Z
{
    int x1,x2,y1,y2,k;
    Z() {}
    Z(int a, int b, int c, int d, int e)
    {
        x1=a;
        y1=b;
        x2=c;
        y2=d;
        k=e;
    }
};

int mat[100][100];
int A[100][100];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j;
    int  n,m;
    cin>>n>>m;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    vector<Z>V;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(A[i][j])
            {
                int baki=(mat[i][j]-A[i][j]);
                int cnt1=0, cnt2=0;
                for(int k=j; k<=m; k++)
                {
                    if((A[i][k]+baki)%mat[i][k]) break;
                    cnt1++;
                }
                for(int k=i; k<=n; k++)
                {
                    if((A[k][j]+baki)%mat[k][j]) break;
                    cnt2++;
                }
                int cnt3=0;

                for(int k=j; k<=m; k++)
                {
                    if((A[i][k]%mat[i][k])) cnt3++;
                    else  break;
                }
                int cnt4=0;
                for(int k=i; k<=n; k++)
                {
                    if((A[k][j]%mat[k][j])) cnt4++;
                    else  break;
                }
           //     cout<<cnt1<<" "<<cnt2<<endl;

                if(max(cnt1, cnt2)==1)
                {
                 //   cout<<cnt3<<" "<<cnt4<<endl;
                    if(cnt3>cnt4)
                    {
                        V.PB(Z(i,j,i,j+cnt3-1, baki));
                        for(int kk=j; kk<j+cnt3; kk++)
                            A[i][kk]=((A[i][kk]+baki)%mat[i][kk]);
                    }
                    else
                    {
                        V.PB(Z(i,j,i+cnt4-1,j, baki));
                        for(int kk=i; kk<i+cnt4; kk++)
                            A[kk][j]=((A[kk][j]+baki)%mat[kk][j]);
                    }
                    continue;
                }


                if(cnt1>=cnt2)
                {
                    V.PB(Z(i,j,i,j+cnt1-1, baki));
                    for(int k=j; k<j+cnt1; k++)
                        A[i][k]=0;
                }
                else
                {
                    V.PB(Z(i,j,i+cnt2-1,j,baki));
                    for(int k=i; k<i+cnt2; k++)
                        A[k][j]=0;
                }
            }
        }
    }
    int sz=V.size();
    cout<<sz<<endl;
    for(i=0; i<sz; i++)
        cout<<V[i].x1<<" "<<V[i].y1<<" "<<V[i].x2<<" "<<V[i].y2<<" "<<V[i].k<<endl;
    return 0;
}

/*

5 3
1000 1002 1003 1004 1005
S 0 2
G 0 3
S 0 2

*/
