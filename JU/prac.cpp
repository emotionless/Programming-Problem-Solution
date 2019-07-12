#include <iostream>
#include <vector>
#include <stdlib.h>
#include <set>
#include <queue>
#include <stdio.h>
#include <string>
#include <map>

using namespace std;

int dp[500002][26];
char tr[500002][26];
char s[500002];
char ans[500002];

int main()
{
    //  freopen("in.txt", "r", stdin);
    //  freopen("out.txt", "w", stdout);
    int n, k;
    cin>>n>>k;
    cin>>s;


    for(int i=0; i<n; ++i)
        s[i]-='A';

    for(int i=0; i<n; ++i) for(int j=0; j<k; ++j) dp[i][j]=9999999;

    for(int i=0; i<k; ++i){
        dp[0][i]=((i==s[0])? 0 : 1);
        //cout<<dp[0][i]<<endl;
        }

    for(int i=1; i<n; ++i)
        for(int j=0; j<k; ++j)
            for(int l=0; l<k; ++l)
            {
                if(j==l) continue;
                if(dp[i][j]> dp[i-1][l] + ((j==s[i])? 0 : 1))
                {
                    dp[i][j] = dp[i-1][l] + ((j==s[i])? 0 : 1);
                    tr[i][j]=l;
                }
            }


    ans[n]='\0';
    int mmin=999999;
    int ind =- 1;
    for(int i=0; i<k; ++i)
        if(dp[n-1][i]<mmin)
            mmin=dp[n-1][i], ind=i;



    ans[n-1]=ind+'A';
    //cout<<ind<<endl;
    for(int i=n-1; i>0; --i)
    {
        ans[i-1]=tr[i][ind]+'A';
        ind = tr[i][ind];
    //    cout<<ind<<endl;
    }

    cout<<mmin<<endl<<ans<<endl;

    return 0;
}

/*

0 1
1 1
2 1
1 3


*/
