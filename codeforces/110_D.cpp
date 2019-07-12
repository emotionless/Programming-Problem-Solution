#include<bits/stdc++.h>
#define PB push_back


using namespace std;

string str, tar;

int s1, s2;
int dp[2001][2001][2];

int solve(int i, int j, bool is)
{
    if(i == s1) return s2-j;
    else if(j == s2) return 0;
    int &ret = dp[i][j][is];
    if(ret != -1) return ret;
    ret = s2 - j;
    if(is)
    {
        if(str[i] == tar[j])
        ret = min(ret, solve(i + 1, j + 1, is));
        else
            ret = min(ret, 1 + solve(i + 1, j + 1, is));
    }
    else
    {
        ret = min(ret, solve(i + 1, j, 0));
        ret = min(ret, 1 + solve(i, j + 1, 0));
        ret = min(ret, 1 + solve(i + 1, j + 1, 1));
        if(str[i] == tar[j])
        ret = min(ret, solve(i + 1, j + 1, 1));
    }
return ret;
}



int main()
{
    int i,j,k;
    int n,m;
    cin>>str;
    cin>>tar;
    s1 = str.length();
    s2 = tar.length();

    memset(dp, -1, sizeof dp);


    int ans = solve(0, 0, 0);
    cout<<ans<<endl;





    return 0;
}

/*

juhlp
ycqugugk

zfinrlju
wiiegborjl


*/
