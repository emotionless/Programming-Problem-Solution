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
#define check_bit(a,b) (a & (1<<b))
#define PB push_back


using namespace std;
int n;
int arr[310];
int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j;
    int a,b;

    cin>>n;
    int mx=0;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        mx=max(mx, arr[i]);
    }
    mx=mx;
    string res="";
    while(mx--)
    {

        for(i=1; i<n; i++)
        {
            if(arr[i])
            {
                res+="RP";
                arr[i]--;
            }
            else
                res+="R";
        }

        for(i=n-2; i>=0; i--)
        {
            if(arr[i])
            {
                res+="LP";
                arr[i]--;
            }
            else
                res+="L";
        }

    }

    cout<<res<<endl;
    return 0;
}

/*

4544545454

*/
