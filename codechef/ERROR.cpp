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


int main()
{
    // FILE * fin, * fout;
    // fin=fopen("input.txt","r");
    // fout=fopen("output.txt","w");

    int i,j,k;
    int n, q,m;
    string str;

    int t;
    scanf("%d", &t);
    while(t--)
    {
        cin>>str;
        string sbstr="101";
        if(str.find(sbstr)==string::npos)
        {
            sbstr="010";
            if(str.find(sbstr)==string::npos)
                cout<<"Bad"<<endl;
            else
                cout<<"Good"<<endl;
        }
        else
            cout<<"Good"<<endl;
    }
    return 0;
}

/*

5 3
1000 1002 1003 1004 1005
S 0 2
G 0 3
S 0 2

*/
