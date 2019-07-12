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

int arr[101];
int cnt[101];
int used[100001];
bool dp[100001];

int main()
{
    int i, j, k;
    int t, cases = 1;


    int n, m;
    scanf("%d", &t);
    while(t--)
    {
        cin>>n>>m;
        for(i = 0; i < n; i++)
            cin>>arr[i];

        for(i = 0; i < n; i++)
            cin>>cnt[i];
        int ans = 0;
        memset(dp, false, sizeof dp);
        dp[0] = true;
        for(i = 0; i < n; i++)
        {
            memset(used, 0, sizeof used);
            for(j = arr[i]; j <= m; j++)
            {
                if(!dp[j] && dp[j - arr[i]] && used[j - arr[i]] < cnt[i])
                {
                    used[j] = used[j - arr[i]] + 1;
                    dp[j] = true;
                    ans++;
                }
            }
        }
        printf("Case %d: %d\n", cases++, ans);
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
