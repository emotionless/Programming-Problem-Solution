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

int arr[300];
int main()
{
    //   FILE * fin, * fout, *fp;
//     fp=fopen("out.txt", "w");

    int i,j;
    int a,b;
    int n,g;
    string str;
    cin>>str;

    memset(arr, 0, sizeof arr);

    int len=str.length();
    for(i=0; i<len; i++)
    {
        arr[str[i]]++;
    }
    int mn=min(arr['i'], min(arr['e']/3, arr['t']));

    if(mn==0)
    {
        cout<<mn<<endl;
        return 0;
    }
    if(mn==1)
    {
        if(arr['n']>=3)
            cout<<mn<<endl;
        else cout<<0<<endl;
        return 0;
    }

    if(arr['n']>=(mn+mn+1))
        cout<<mn<<endl;
    else
    {
        if(arr['n']%2==0) arr['n']--;
        cout<<arr['n']/2<<endl;
    }

    return 0;
}

/*

4544545454

*/
