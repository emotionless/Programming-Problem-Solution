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

LL mx1[100002];
LL mx2[100002];
LL arr[100002];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    LL i,j,k;
    LL n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        LL mx=LONG_MIN, sum=0LL;
        memset(mx1, 0, sizeof mx1);
        memset(mx2, 0, sizeof mx2);
        for(i=0; i<n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
            if(sum>mx)
            {
                mx=sum;
            }
            mx1[i]=mx;
            if(sum<0)
            {
                sum=0;
            }
            //  cout<<i<<" "<<mx1[i]<<endl;
        }
        sum=0LL;
        mx=LONG_MIN;
        for(i=n-1; i>=0; i--)
        {
            sum+=arr[i];
            if(sum>mx)
            {
                mx=sum;
            }
            mx2[i]=mx;
            if(sum<0)
            {
                sum=0;
            }
            // cout<<i<<" "<<mx2[i]<<endl;
        }
        LL res=LONG_MIN;
        for(i=0; i+k+1<n; i++)
        {
            res=max(res, mx1[i]+mx2[i+k+1]);
            //  cout<<i<<" "<<res<<endl;
        }
        cout<<res<<endl;
    }
    return 0;
}

/*

8
9 0
-3 -3 -3 3 3 3 3 3 -3
15
9 1
-3 -3 -3 3 3 3 3 3 -3
12
9 2
-3 -3 -3 3 3 3 3 3 -3
12
9 2
-3 -3 -3 3 3 3 3 3 -3
12



*/
