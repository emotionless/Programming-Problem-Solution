#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define MOD 1000000007
#define MX 509
#define mp make_pair
#define eps 1e-10

using namespace std;

int go[MX];

int get_value(int id)
{
    if(go[id] != 0) return go[id];
//    if(id > 100) return -1;
    return id;
}

double cof[109][109];
double x[109];
int st, ed;
double val[109];

int n;

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
    for(i = 1; i < n; i++)
    {
        int ind = i;
        for(j = i + 1; j < n; j++)
            if(fabs(cof[j][i]) > fabs(cof[ind][i])) ind = j;

        if(fabs(cof[ind][i]) < eps) continue;

        if(ind != i)
            for(j = 1; j <= n; j++)
                swap(cof[ind][j], cof[i][j]);

        for(j = i + 1; j < n; j++)
        {
            double c = cof[j][i]/cof[i][i];
            for(k = 1; k <= n; k++)
            {
                cof[j][k] = cof[j][k] - c*cof[i][k];
            }
        }
    }
    x[n - 1] = cof[n - 1][n]/cof[n - 1][n - 1];

    for(i = n - 2; i > 0; i--)
    {
        double sum = 0.0;
        for(j = i + 1; j < n; j++)
            sum += cof[i][j] * x[j];
        x[i] = (cof[i][n] - sum)/cof[i][i];
//        cout<<i<<" "<<x[i]<<endl;
    }
}


int main()
{

    int i, j, k;
    int t, cases = 1;
    int u, v, m;
    n = 101;
    cin>>t;
    while(t--)
    {
        cin>>m;
        memset(go, 0, sizeof go);
        memset(cof, 0.0, sizeof cof);
        memset(x, 0.0, sizeof x);
        for(i = 0; i < m; i++)
        {
            cin>>u>>v;
            go[u] = v;
        }
        for(i = 1; i < 100; i++)
        {

            double div = 6.0; //min(6, 100 - i);
            cof[i][i] = 1.0;
            cof[i][n] = 1.0;
            for(j = i + 1; j <= i + 6; j++)
            {
                int id = get_value(j);
                if(j > 100)
                    id = i;
                cof[i][id] -= 1.0/div;
            }
        }
        cof[100][100] = 1.0;
        cof[100][101] = 0.0;
        gauss();
        printf("Case %d: %.10lf\n", cases++, x[1]);
    }
    return 0;
}

/*

3.08580806

*/
