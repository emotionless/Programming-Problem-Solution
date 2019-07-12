#include <bits/stdc++.h>

/**********TYPE CASTING**********/
#define LL long long




using namespace std;
string str;
int A,B, K, l;
int dp[12][100][100][2];

int solve(int ind, int sum, int tot, bool is)
{
    if(l==ind)
    {
        if(tot%K==0 && sum%K==0)
            return 1;
        return 0;
    }

    int &ret=dp[ind][sum][tot][is];
    if(ret!=-1) return ret;
    ret=0;
    int cn=str[ind]-'0';
    for(int i=0; i<10; i++)
    {
        if(is && i>cn) break;
        ret+=solve(ind+1, (sum+i)%K, (tot*10+i)%K, i<cn?0:is);
    }
    return ret;
}





int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int t, cases=1;
    cin>>t;
    while(t--)
    {
        cin>>A>>B>>K;

        if(K>82)
        {
            printf("Case %d: %d\n", cases++, 0);
            continue;
        }
        if(K==1)
        {
            printf("Case %d: %d\n", cases++, B-A+1);
            continue;
        }

        A--;
        ostringstream ss, sss;
        ss<<A;

        str=ss.str();
        l=str.length();

        memset(dp, -1, sizeof dp);
        int res1=solve(0, 0, 0, 1);
        // cout<<res1<<endl;

        sss<<B;
        str=sss.str();
        l=str.length();

        memset(dp, -1, sizeof dp);
        int res2=solve(0,0,0,1);
        // cout<<res2<<endl;
        printf("Case %d: %d\n", cases++, res2-res1);
    }
    return 0;
}
