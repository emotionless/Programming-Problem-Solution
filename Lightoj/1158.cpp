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
#define check_bit(aa, bb) (aa & (1<<bb))
#define set_bit(aa, bb) (aa | (1<<bb))


using namespace std;
int dp[1<<11][1001];
int arr[12];
int n, m, d;
string str;
int solve(int mask, int rem)
{
    if(mask == ((1<<n) - 1))
    {
        if(rem % d == 0) return 1;
        return 0;
    }
    int &ret = dp[mask][rem];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < n; i++)
    {
        if(check_bit(mask, i) == 0)
        {
            ret += solve(set_bit(mask, i), (rem * 10 + str[i] - '0') % d);
        }
    }
   // cout<<mask<<" "<<ret<<endl;
    return ret;
}
LL fact[12];
int main()
{
    int i, j, k;
    int t, cases = 1;
    fact[0] = 1;
    for(i = 1; i < 10; i++)
        fact[i] = fact[i - 1] * i;
    scanf("%d", &t);
    while(t--)
    {
        cin>>str>>d;
        memset(dp, -1, sizeof dp);
        memset(arr, 0, sizeof arr);
        n = str.length();
        for(i = 0; i < n; i++)
            arr[str[i] - '0']++;
        int res = solve(0, 0);
        for(i = 0; i <10; i++)
            res = res / fact[arr[i]];
        printf("Case %d: %d\n", cases++, res);
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
