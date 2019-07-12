#include <bits/stdc++.h>





using namespace std;

double dp[100001];

void init()
{
    dp[1]=0.0;
    for(int i=2; i<100001; i++)
    {
        int cnt=0;
        dp[i]=0;
        double sum=0.0;
        for(int j=1; j*j<=i; j++)
        {
            if((i%j)==0)
            {
                cnt++;
                sum+=dp[j];
                int tmp=i/j;
                if(tmp!=j)
                {
                    cnt++;
                    sum+=dp[tmp];
                }
            }
        }
       // cout<<i<<" "<<sum<<" "<<cnt<<endl;
        sum+=cnt;
       // cout<<sum<<endl;
        dp[i]=sum/(double)(cnt-1);
      //  cout<<dp[i]<<endl;
    }
}


int main()
{
    // ios_base::sync_with_stdio(0);
    //cin.tie(0);
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n;
    int t, cases=0;
    init();
    cin>>t;
    while(t--)
    {
        cin>>n;
        cases++;
        printf("Case %d: %.10lf\n", cases, dp[n]);
    }
    return 0;
}
