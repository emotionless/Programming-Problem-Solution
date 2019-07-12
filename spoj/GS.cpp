#include <bits/stdc++.h>

///***** Type casting ******///
#define LL long long
#define ll long long

///***** C++ **************///
#define set_bit(aa,bb) (aa|(1<<bb))
#define check_bit(aa,bb) (aa&(1<<bb))
#define PB push_back
#define mp(aa, bb) make_pair(aa, bb)
#define aa.xx aa.first
#define aa.yy aa.second
#define pi pair<int, int>
#define mp make_pair
#define fr(i, a) for(i = 0; i < a; i++)
#define sc(a) scanf("%d", &a)


///***** Constant ******//
#define MAX 500009      // 10^6 + 7
#define MOD 1000000007  // 10^9 + 7
//#define N 100007        // 10^5 + 7
#define eps 1e-9


using namespace std;

double mat[109][109];
double cof[109][109];
double x[109];
int st, ed, n;
double val[109];


void print()
{
    cout<<"Print is here"<<endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
            cout<<" "<<cof[i][j];
        cout<<endl;
    }

}

void gauss()
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        int ind = i;
        for(j = i + 1; j < n; j++)
            if(fabs(cof[j][i]) > fabs(cof[ind][i])) ind = j;

        if(fabs(cof[ind][i]) < eps) continue;

        if(ind != i)
            for(j = 0; j <= n; j++)
                swap(cof[ind][j], cof[i][j]);

        for(j = i + 1; j < n; j++)
        {
            double c = cof[j][i]/cof[i][i];
            for(k = 0; k <= n; k++)
            {
                cof[j][k] = cof[j][k] - c*cof[i][k];
            }
        }
    }
    x[n - 1] = cof[n - 1][n]/cof[n - 1][n - 1];

    for(i = n - 2; i >= 0; i--)
    {
        double sum = 0.0;
        for(j = i + 1; j < n; j++)
            sum += cof[i][j] * x[j];
        x[i] = (cof[i][n] - sum)/cof[i][i];
    }
}

int main()
{
    int i, j, k;
    int u, v;
    double w;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d %d %d", &n, &st, &ed);
        st--;
        ed--;
        memset(val, 0.0, sizeof val);
        memset(mat, 0.0, sizeof mat);
        memset(cof, 0.0, sizeof cof);
        memset(x, 0.0, sizeof x);
        for(i = 0; i < n - 1; i++)
        {
            scanf("%d %d %lf", &u, &v, &w);
            u--;
            v--;
            mat[u][v] = mat[v][u] = w;

        }

        for(i = 0; i < n; i++)
        {
            double p = 0.0;
            for(j = 0; j < n; j++)
                p += mat[i][j];

            if(i == ed)
            {
                cof[i][i] = 1.0;
                cof[i][n] = 0.0;
                continue;
            }
            for(j = 0; j < n; j++)
            {
                cof[i][j] = -mat[i][j]/p;
            }
            cof[i][n] = 1.0;
            cof[i][i] = 1.0;
        }
        cof[ed][ed] = 1;
        cof[ed][n] = 0.0;

        gauss();
        printf("%.5lf\n", x[st]);
    }

    return 0;
}
/*



3 2 3
1 2 1
2 3 1



*/
