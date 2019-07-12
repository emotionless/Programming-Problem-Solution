#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define PB push_back
#define MP make_pair
#define mp make_pair
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define MOD 1000000007
#define MX 100009

using namespace std;
bool bl[1001][1001];
double dp[1001][1001];
double solve(int t, int d)
{
    if(t == 0) return 1.0;

    if(d == 0)
    {
        return 1.0/(double)(t + 1);
    }
    if(bl[t][d]) return dp[t][d];
    bl[t][d] = true;
    dp[t][d] = 0.0;
    double ret = 1.0;
    ret = 1+solve(t, d - 1)/5.0 + solve(t, d)/5.0 + solve(t-1, d-1)/5.0;
    if(t - 2 >= 0)
        ret += solve(t-2, d)/5.0;
    dp[t][d] = ret;
    return dp[t][d];
}

int main()
{
    int i, j, k;
    int t, cases = 1, tiger, dear;
    cin>>t;
    while(t--)
    {
        cin>>tiger>>dear;
        memset(bl, false, sizeof bl);
        cout<<solve(tiger, dear)<<endl;
    }

    return 0;
}

/*

5 5
1 2
2 3
3 4
2 4
2 5

*/
