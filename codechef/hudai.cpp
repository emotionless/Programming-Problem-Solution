/*
******************************************
***** Bismillahir Rahmanir Rahim *********
***** Full Name: Faruk Hossain Milon *****
***** University: IIT-JU, BD ****************

***** Codechef username: emotionless *****
***** Topcoder handle: emotionless *******
***** UVA username: emotionless **********
***** Hust username: emotionless *********
***** Codeforces handle: milon ***********
******************************************
***** Sorry for bad written code **********
*/


#include<bits/stdc++.h>

#define LL long long
#define MX 100009        // 10^5 + 9
#define MD 1000000007   // 10^9 + 7
#define PB push_back
#define set_mask(a,b) (a|(1<<b))
#define check_mask(a,b) (a&(1<<b))
#define FOR(i, b) for(i = 0; i < b; i++)

using namespace std;
int arr[1001];
int dp[1001][9001];
int n;
int solve(int ind, int sum)
{
    if(ind == n) return sum;
    int &ret = dp[ind][sum];
    if(ret != -1) return ret;
    ret = 0;
    ret = solve(ind + 1, sum);
    ret = max(ret, solve(ind + 1, sum ^ arr[ind]));
return ret;
}


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int t,j,i,k;
    int m;
    string str;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i = 0; i < n; i++)
            cin>>arr[i];
        memset(dp, -1, sizeof dp);
        int res = solve(0, m);
        cout<<res<<endl;
    }

    return 0;
}

/*



*/
