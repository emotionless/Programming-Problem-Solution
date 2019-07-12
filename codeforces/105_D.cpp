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
#define MAX 200009
#define D double


using namespace std;
bool is[1009][1009][2];
double dp[1009][1009][2];

double solve(int n, int m, bool stp)
{

    if(is[n][m][stp]) return dp[n][m][stp];
    if(n == 0) return 0.0;
    is[n][m][stp] = true;
    double ret = 0.0;
    int tot = n + m;
    if(!stp)
    {
        ret = (D)n/(D)tot;
        if(m) ret += solve(n, m - 1, 1) * ((D)m/(D)tot);
    }
    else
    {
        if(!m) return dp[n][m][stp] = ret;
        double ret1 = (D)m/(D)tot;
        tot--;
        m--;
        if(n)
            ret += ret1*(solve(n - 1, m, 0) * (double)n/(double)tot);
        if(m)
            ret += ret1*(solve(n, m - 1, 0) * (double)m/(double)tot);
    }
    return dp[n][m][stp]= ret;
}




int main()
{
    int tc,cs=1,i,j,k;
    int n, m;

    cin>>n>>m;
    memset(is, false, sizeof is);
    printf("%.10lf\n", solve(n, m, 0));









    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
