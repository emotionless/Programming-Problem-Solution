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
#define FOR(aa,nn) for(aa=0; aa<nn; aa++)


using namespace std;
int arr[4];

int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g;

    string str;
    cin>>str;
    //str+="."
    int len=str.length();
    int cnt=0;
    j=0;
    for(i=0; i<len; i++)
    {
        if(str[i]!='|')
        {
            arr[j++]=cnt;
            cnt=0;
        }
        else
            cnt++;
    }
    arr[2]=cnt;
    if((arr[0]+arr[1])==arr[2])
    {
        cout<<str<<endl;
        return 0;
    }
    if((arr[0]+1+arr[1])==(arr[2]-1))
    {
        for(i=0; i<=arr[0]; i++)
            cout<<"|";
        cout<<"+";
        for(i=1; i<=arr[1]; i++)
            cout<<"|";
        cout<<"=";
        for(i=1; i<arr[2]; i++)
            cout<<"|";
    }

    else
        cout<<"Impossible"<<endl;



    return 0;
}

/*

4544545454

*/
