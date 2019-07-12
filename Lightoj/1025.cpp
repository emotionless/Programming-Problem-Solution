#include <bits/stdc++.h>

using namespace std;

long long dp[61][61];
char str[61];
inline long long solve(int i,int j)
{
    if(j<i) return 0;
    if(i==j) return dp[i][j]=1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(str[i]==str[j])
        dp[i][j]= 1+ solve(i+1, j)+ solve(i, j-1);
    else
        dp[i][j]= solve(i+1,j)+solve(i,j-1)-solve(i+1, j-1);
    return dp[i][j];
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");
    int t, cases=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int len=strlen(str);
        memset(dp, -1, sizeof dp);
        printf("Case %d: %lld\n",cases++, solve(0, len-1));

    }
    return 0;
}
