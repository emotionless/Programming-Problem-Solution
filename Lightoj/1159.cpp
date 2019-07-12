#include<bits/stdc++.h>
#define LL long long

using namespace std;
int dp[55][55][55];

int solve(string str1, string str2, string str3)
{
    memset(dp, 0, sizeof dp);
    str1=" "+str1;
    str2=" "+str2;
    str3=" "+str3;
    int len1=str1.size();
    int len2=str2.size();
    int len3=str3.size();

    for(int i=1; i<len1; i++)
    {
        for(int j=1; j<len2; j++)
        {
            for(int k=1; k<len3; k++)
            {

                if(str1[i]==str2[j] && str1[i]==str3[k])
                {
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                }
                else
                {
                    dp[i][j][k]=max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
                }
            }
        }
    }
    return dp[len1-1][len2-1][len3-1];
}

int main()
{
    int i,j,k, n, cases=1;
    string str1, str2, str3;

    scanf("%d", &n);

    while(n--)
    {
        cin>>str1;
        cin>>str2;
        cin>>str3;

        int res=solve(str1, str2, str3);
        printf("Case %d: %d\n", cases++, res);
    }
    return 0;
}
