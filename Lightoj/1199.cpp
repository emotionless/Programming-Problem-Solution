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
#define fr(i, a) for(i = 0; i < a; i++)
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define MOD 1000000007
#define MX 100009

using namespace std;

int dp[10009];

int main()
{

    int i, j, k;
    int t, cases = 1;
    dp[1] = dp[2] = 0;
    dp[3] = 1;
    for(i = 4; i <= 10000; i++)
    {
        set<int>S;
        S.clear();
        for(j = 1; j <= i / 2; j++)
        {
            if(2*j == i) continue;
            int tmp = dp[j]^dp[i - j];
            S.insert(tmp);
        }
        int res = 0;
        set<int>::iterator it;
        for(; S.find(res) != S.end(); res++)
        {
        }
        dp[i] = res;
    }


    sc(t);
    int n;



    while(t--)
    {
        sc(n);
        int res = 0, a;
        fr(i, n)
        {
            sc(a);
            res = res ^ dp[a];
        }
        printf("Case %d: ", cases++);
        if(res)
            printf("Alice\n");
        else
            printf("Bob\n");
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
