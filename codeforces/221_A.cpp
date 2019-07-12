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

    long long i,j,k;
    string str;
    cin>>str;
    long l=str.length(), pos;

    for(i=0; i<l; i++)
    {
        if(str[i]=='^')
            pos=i;
    }

    long long left=0, right=0;
    for(i=pos+1; i<l; i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            right+=(str[i]-'0')*(i-pos);
        }
    }

    for(i=pos-1; i>=0; i--)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            left+=(str[i]-'0')*(pos-i);
        }
    }
    if(left==right)
        cout<<"balance"<<endl;
    else if(left>right)
        cout<<"left"<<endl;
    else
        cout<<"right"<<endl;



    return 0;
}

/*

4544545454

*/
