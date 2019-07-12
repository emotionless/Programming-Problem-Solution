#include <bits/stdc++.h>

using namespace std;

char str[105];
int dp[105][105];
int solve1(int i, int j)
{
    if(dp[i][j]!=-1) return dp[i][j];

    if(i>=j) return 0;
    if(str[i]==str[j])
        return solve1(i+1,j-1);
    else
    {
        dp[i][j]=1+min(solve1(i,j-1), solve1(i+1, j));

    }
    return dp[i][j];
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,t,cases=1;

    scanf("%d",&t);

    while(t--)
    {

        memset(dp,-1, sizeof dp);
        scanf("%s", str);
        int len=strlen(str);
        printf("Case %d: %d\n", cases++, solve1(0,len-1));
    }


    return 0;
}
