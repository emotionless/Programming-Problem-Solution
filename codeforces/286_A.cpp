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
#define MAX 30009
#define pii pair<int, int>
#define mp make_pair

#define INFILE() freopen("winning_at_sports.txt","r",stdin)
#define OUTFILE()freopen("OutC_final.txt","w",stdout)

using namespace std;
int n, mx;
int val[30009];
int dp[30009][600];
int d;
int solve(int ind, int pre)
{
    if(ind > mx || pre == 0) return 0;
    int dif = pre - d + 300;

    int &ret = dp[ind][dif];
    if(ret != -1) return ret;
    ret = 0;
    if(pre > 1)
        ret = max(ret, solve(ind + pre - 1, pre - 1));
    ret = max(ret, solve(ind + pre, pre));
    ret = max(ret, solve(ind + pre + 1, pre + 1));
    ret += val[ind];
//    cout<<ind<<" "<<pre<<" "<<ret<<endl;
    return ret;
}



int main()
{

    int tc,cs=1,i,j,k;
    int m, pos;
    cin>>n>>d;
    mx = 0;

    for(i = 0; i < n; i++)
    {
        cin>>pos;
        val[pos]++;
        mx = max(mx, pos);
    }
    memset(dp, -1, sizeof dp);

    int res = solve(d, d) + val[0];


    cout<<res<<endl;

    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
