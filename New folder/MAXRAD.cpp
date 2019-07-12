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

double dis[1001][1001];

int x[1001], y[1001];

double distance1(int i, int j)
{
    return sqrt( (y[i]-y[j])*(y[i]-y[j])+ (x[i]-x[j])*(x[i]-x[j]) );
}


int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b, cases=1;

    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        bool ck=false;

        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        memset(dis, 0, sizeof dis);

        for(i=0; i<n; i++)
            cin>>x[i]>>y[i];

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(i==j) continue;
                dis[i][j]=distance1(i,j)-1.0;
                if(dis[i][j]<1.0)
                    ck=true;
            }
        }
        if(ck)
        {
            printf("-1.000000000\n");
            continue;
        }
        double res=-1.00000000;
        for(i=0; i<n; i++)
        {
            double mn=10000000000.0;
            for(j=0; j<n; j++)
            {
                if(i==j) continue;

                mn=min(mn, dis[i][j]);
            }
            res=max(res, mn);
        }
        printf("%.9lf\n", res);
    }
    return 0;
}

/*

4544545454

*/
