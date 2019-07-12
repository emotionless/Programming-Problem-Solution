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
#define MAX 709


using namespace std;



int match[MAX];
LL dp[MAX][MAX][4][4];


LL solve(int l, int r, int lc, int rc)
{
    if(l >= r) return 1ll;
    LL &ret = dp[l][r][lc][rc];
    if(ret != -1) return ret;
    ret = 0ll;
    for(int i = 1; i < 3; i++)
    {
        if(i!=lc) ret = (ret + solve(l + 1, match[l] - 1, i, 0) *  solve(match[l] +1 , r, 0, rc)) % MOD;
        if(i != rc || match[l] != r) ret = (ret + solve(l + 1, match[l] - 1, 0, i) * solve(match[l] + 1, r, i, rc)) % MOD;
    }
return ret;
}



int main()
{
    int tc,cs=1,i,j,k;
    int n, m;
    string str;
    cin>>str;
    n = str.length();
    stack<int>ST;
    for(i = 0; i < n; i++)
    {
        if(str[i] == ')')
        {
            match[ST.top()] = i;
            ST.pop();
        }
        else
            ST.push(i);
    }

    memset(dp, -1, sizeof dp);
    LL ans = solve(0,n - 1, 0, 0);
    cout<<ans<<endl;













    return 0;
}

/*

3 2
-4 -60 -30
1 2
2 3



*/
