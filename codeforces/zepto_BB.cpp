#include<bits/stdc++.h>

#define xx first
#define yy second
#define vsort(v) sort(v.begin(),v.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define LL long long
#define pb push_back
#define MP make_pair
#define MOD 1000000007
#define MX 100000

using namespace std;


string str[2001];

int main()
{
    int i, j, k;
    int n, m;
    cin>>n>>m>>k;
    for(i=0; i < n; i++)
        cin>>str[i];

    for(j=0; j<m; j++)
    {
        int cnt=0;
        for(i=0; i<n; i++)
        {
            int x=i;
            int y=j;

            int adj= i;
            if(adj+j<m)
                cnt+=(str[i][adj+j]=='L'?1:0);
             //   cout<<cnt<<endl;
            if(i-adj>=0)
                cnt+=(str[i-adj][j]=='D'?1:0);
             //   cout<<cnt<<endl;
            if(j-adj>=0)
                cnt+=(str[i][j-adj]=='R'?1:0);
             //   cout<<cnt<<endl;
            if(adj+i<n)
                cnt+=(str[adj+i][j]=='U'?1:0);
            //    cout<<cnt<<endl;

        }
       //  cout<<endl;
       // break;
        cout<<cnt<<" ";
    }


    return 0;
}