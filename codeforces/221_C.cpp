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

int arr[10];

int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    long long i,j,k;

    string str;

    cin>>str;

    int len=str.length();

    for(i=0; i<len; i++)
    {
        int cn=str[i]-'0';
        arr[cn]++;
    }

    if(arr[2] || arr[3] || arr[4] || arr[5] || arr[7])
    {
        cout<<0<<endl;
        return 0;
    }

    if(arr[1]!=arr[8] || arr[6]!=arr[8] || arr[1]!=arr[9])
    {
        cout<<0<<endl;
        return 0;
    }
    for(i=0; i<arr[1]; i++)
    {
        cout<<1869;
        if(arr[0])
        {
            cout<<0;
            arr[0]--;
        }
    }




    return 0;
}

/*

4544545454

*/
