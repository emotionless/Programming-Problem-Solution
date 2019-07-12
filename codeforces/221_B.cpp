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
***** Sorry for bad writen code **********
*/


#include <bits/stdc++.h>

#define LL long long
#define MX 5000+7
#define MOD 1000000000+7
#define N 1000007
#define PB push_back


using namespace std;

int arr[105];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n,m,a,b,w;
    memset(arr, 0, sizeof arr);
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>w;
        arr[a]+=w;
        arr[b]-=w;
    }
    int res=0;
    for(i=1; i<=n; i++)
    {
        if(arr[i]<0)
            res+=abs(arr[i]);
    }
    cout<<res<<endl;



    return 0;
}

/*

4544545454

*/
