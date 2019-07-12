#include<bits/stdc++.h>

#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define pb push_back
#define mp make_pair
///***** bit *****///
#define check_bit(a, b) (a&(1<<b))
#define set_bit(a, b) (a|(1<<b))
#define total_bit(a) __builtin_popcount(a)
///***** Input / Output *****///
#define s1(a) scanf("%d", &a)
#define s2(a, b) scanf("%d %d", &a, &b)
#define s3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define p1(a) printf("%d", a)
#define p2(a, b) printf("%d %d", a, b)
#define p3(a, b, c) printf("%d %d %d", a, b, c)

#define MOD 1000000007
#define MAX 109
#define LIMIT 1000000000000000ll
#define INT_MAX1 1000000000000001ll


using namespace std;

double mat[MAX][MAX];
double x[MAX];

int main()
{

    int i, j, k;
    int t, cases = 1;
    int n;
    cin>>n;

    for(i = 0;  i < n; i++)
    {
        for(j = 0; j <= n; j++)
            cin>>mat[i][j];
    }

    for(j = 0; j < n; j++)
    {
        for(i = j + 1; i < n; i++)
        {
            double c = mat[i][j]/mat[j][j];
            for(k = 0; k <= n; k++)
            {
                mat[i][k] = mat[i][k] - c*mat[j][k];
            }
        }
    }
    x[n - 1] = mat[n - 1][n]/mat[n - 1][n - 1];

    for(i = n - 2; i >= 0; i--)
    {
        double sum = 0.0;
        for(j = i + 1; j < n; j++)
            sum += mat[i][j] * x[j];
        x[i] = (mat[i][n] - sum)/mat[i][i];
    }


    for(i = 0; i < n; i++)
        cout<<i + 1<<" "<<x[i]<<endl;








    return 0;
}

/*

3
2	1	-1	8
-3	-1	2	-11
-2	1	2	-3



3
10 -7 3 5
-6 8 4 7
2 6 9  -1




*/
