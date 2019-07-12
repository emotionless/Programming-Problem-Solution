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
#define MX 100009
#define mp make_pair

using namespace std;
int bit[20];
LL dp[20][20];

LL DFS(int len, int l, int r, bool limit, bool ok)
{
    if(l < r)
    {
        return !limit || (limit && ok);
    }
    LL ret = 0;
    if(!limit && ~dp[len][l])
        return dp[len][l];
    ret = 0;
    int mx = limit ? bit[l]:9;
    for(int i = 0; i <= mx; i++)
    {
        if(l == len - 1 && i == 0) continue;
        int is = ok;
        if(is)
            is = (bit[r] >= i);
        else
            is = (bit[r] > i);
        ret += DFS(len, l - 1, r + 1, limit && i == mx, is);
    }
    if(!limit)
        dp[len][l] = ret;
   // cout<<len<<" "<<l<<" "<<r<<" "<<limit<<" "<<ok<<endl;
    return ret;
}


LL solve(LL n)
{

    int m = 0;
    if(n < 0) return 0;
    if(n == 0) return 1;
    while(n)
    {
        bit[m++] = n % 10;
        n = n / 10;
    }

    LL ret = 1;
    for(int i = m; i >= 1; i--)
        ret += DFS(i, i - 1, 0, i == m, 1);
    return ret;
}



int main()
{
    int i, j, k;
    int t, cases = 1;
    LL a, b;
    scanf("%d", &t);
    memset(dp, -1, sizeof dp);
    while(t--)
    {
        cin>>a>>b;
        if(a > b) swap(a, b);
        printf("Case %d: %lld\n", cases++, solve(b) - solve(a - 1));
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
