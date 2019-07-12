#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define check_bit(a,b) (a & (1<<b))
#define PB push_back
#define s1(a) scanf("%d", &a)


using namespace std;

struct Z
{
    int x1, y1, x2, y2;
    Z() {}
    Z(int a, int b, int c, int d)
    {
        x1=a;
        y1=b;
        x2=c;
        y2=d;
    }
};
int mat[230][230];

int main()
{
    //   FILE * fin, * fout, *fp;
    //     fp=fopen("out.txt", "w");

    int i,j,k;
    int a,b, u, v;
    int n, m;
    scanf("%d %d", &n, &m);

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
            s1(mat[i][j]);
    }
    vector<Z>res;
    for(int i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(mat[i][j])
            {
                int cnt1=0, cnt2=0;
                for(k=i; k<n; k++)
                {
                    if(!mat[k][m])
                        break;
                    cnt1++;
                }

                for(k=j; k<m; k++)
                {
                    if(!mat[i][k]) break;
                    cnt2++;
                }

                if(cnt1>cnt2)
                {
                    res.PB(Z(i,j,i+cnt1-1,j));
                    for(k=i; k<i+cnt1; k++)
                        mat[i][k]=0;
                }
                else
                {
                    res.PB(Z(i,j,i, j+cnt2-1));
                    for(k=j; k<j+cnt2; k++)
                        mat[i][k]=0;
                }
            }
        }
    }
    int sz=res.size();
    cout<<sz<<endl;
    for(i=0; i<sz; i++)
        cout<<res[i].x1+1<<" "<<res[i].y1+1<<" "<<res[i].x2+1<<" "<<res[i].y2+1<<endl;

    return 0;
}

/*
8 7
1 0 0 0 1 0 1 0
1 2
2 3
3 4
4 5
3 6
6 7
4 8


*/
