#include<bits/stdc++.h>
#define LL long long

using namespace std;
int n;
int w[12], c[12];
bool arr[12][12];
int power[12];
int dp[12][2*59050];

inline void precal()
{
    power[0]=1;
    for(int i=1; i<11; i++)
        power[i]=power[i-1]*3;
}
int makeint(string str)
{
    int len=str.length();
    int ret=0;
    for(int i=0; i<len; i++)
    {
        int cn=str[i]-'0';
        ret= ret + cn*power[i];
    }
    return ret;
}

string make_string(int mask)
{
    string str="";
    for(int i=0; i<n; i++)
        str+="0";

    int i=0;
    while(mask>0)
    {
        str[i]=((mask%3)+'0');
        mask=mask/3;
        i++;
    }
    return str;
}


int solve(int ind, int mask)
{
    if(dp[ind][mask]!=-1) return dp[ind][mask];
    int ret=0;
    string str=make_string(mask);
    if(str[ind]=='2') return dp[ind][mask]=0;
    if(str[ind]=='0')
        ret=c[ind];
    int mx=0;
    str[ind]=str[ind]+1;

    int temp=makeint(str);
    for(int i=0; i<n; i++)
    {
        if(i==ind) continue;
        if(arr[ind][i]==false) continue;

        mx=max(mx, solve(i, temp));

    }
    return dp[ind][mask]=ret+mx;
}



int main()
{
    int i,j,k, u, v,m;

    precal();

    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        cin>>w[i];
    }

    for(i=0; i<n; i++)
    {
        cin>>c[i];
    }

    memset(arr, false, sizeof arr);

    for(i=0; i<m; i++)
    {
        cin>>u>>v;
        u--;
        v--;
        arr[u][v]=true;
        arr[v][u]=true;
    }
    int mx=0;
    memset(dp, -1, sizeof dp);
    for(i=0; i<n; i++)
    {
        //   memset(dp, -1, sizeof dp);
        mx=max(mx, solve(i,0));
    }
    cout<<mx<<endl;





    return 0;
}


/*

3 2         // n is the number of bits, m is the connection
1 1 2       // how many welcome
1 1 1       // cost
1 2
2 3

out: 3

THe graph:

1
 \
  2
   \
    3


6 5
1 2 2 1 2 2
1 1 1 1 1 1
1 2
2 6
2 3
3 4
4 5

Out: 6

Graph:
1
 \
  2---6
   \
    3
     \
      4
       \
        5

*/
